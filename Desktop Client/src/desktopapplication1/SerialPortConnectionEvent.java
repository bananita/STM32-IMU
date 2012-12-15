package desktopapplication1;

/**
 *
 * @author Michal Banasiak
 */
public class SerialPortConnectionEvent extends ConnectionEvent {
    public SerialPortConnectionEvent(String oldMessageFrame, String newMessageFrame, SerialPortConnection source) {
        super(oldMessageFrame, newMessageFrame, source);
    }   
}