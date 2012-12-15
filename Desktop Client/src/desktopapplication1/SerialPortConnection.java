package desktopapplication1;

import gnu.io.*;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintStream;
import javax.swing.event.EventListenerList;

/**
 *
 * @author Michal Banasiak
 */
public class SerialPortConnection implements SerialPortEventListener {  
   
    public SerialPortConnection() { 
        closeConnection();
        
        try {
//            CommPortIdentifier portIdentifier = CommPortIdentifier.getPortIdentifier("/dev/ttyUSB0");
            CommPortIdentifier portIdentifier = CommPortIdentifier.getPortIdentifier("COM3");
            CommPort commPort = portIdentifier.open(this.getClass().getName(),2000);
        
            if ( commPort instanceof SerialPort ) {
                serialPort = (SerialPort) commPort;
                serialPort.setSerialPortParams(115200,SerialPort.DATABITS_8,SerialPort.STOPBITS_1,SerialPort.PARITY_NONE);
                
                in = serialPort.getInputStream();
                out = new PrintStream(serialPort.getOutputStream());                     
              
                serialPort.addEventListener(this);
                serialPort.notifyOnDataAvailable(true);       
             }
        }
        catch(Exception e) {
            e.printStackTrace();
        }
    }
    
    public void SendString(String stringToSend) {
        out.println(stringToSend);
    }
    
    public void closeConnection() {
        if ( serialPort instanceof SerialPort)
            serialPort.close();
    }
    
    @Override
    public void serialEvent(SerialPortEvent arg0) {
        int data;
          
        try {
            int len = 0;
            while ( ( data = in.read()) > -1 ) {
                if ( data == 10 ) 
                    break;
                    
                buffer[len++] = (byte) data;
            }
            
            oldMessageString = newMessageString;
            newMessageString = ( (new String(buffer,0,len)));
            
            this.fireSerialPortConnectionEvent();
        }
            
        catch ( IOException e ) {
            e.printStackTrace();
        }             
    }
    
    public void addSerialPortConnectionEventListener(SerialPortConnectionEventListener listener) {
        eventListenerList.add(SerialPortConnectionEventListener.class, listener);
    }
    
    public void removeSerialPortConnectionEventListener(SerialPortConnectionEventListener listener) {
        eventListenerList.remove(SerialPortConnectionEventListener.class, listener);
    }
    
    private void fireSerialPortConnectionEvent() {
        SerialPortConnectionEvent serialPortConnectionevent = null;
        Object[] listeners = eventListenerList.getListenerList();
        
        for (int i = listeners.length-2; i>=0; i-=2) {
            if (listeners[i] == SerialPortConnectionEventListener.class) {
                //lazy initialization, thanks to twi ;)
                if (serialPortConnectionevent == null)
                    serialPortConnectionevent = new SerialPortConnectionEvent(oldMessageString, newMessageString, this);
             
                ((SerialPortConnectionEventListener)listeners[i+1]).serialPortConnectionEventOccured(serialPortConnectionevent);
            }
        }
    }
    
    private EventListenerList eventListenerList = new EventListenerList();
    
    private SerialPort serialPort;
    
    private String oldMessageString = "";
    private String newMessageString = "";
    
    private InputStream in;
    private PrintStream out;
    private byte[] buffer = new byte[1024];
}