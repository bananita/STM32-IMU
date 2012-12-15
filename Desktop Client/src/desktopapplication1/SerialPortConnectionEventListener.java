package desktopapplication1;

import java.util.EventListener;

/**
 *
 * @author Michal Banasiak
 */
public interface SerialPortConnectionEventListener extends EventListener {
    public void serialPortConnectionEventOccured(SerialPortConnectionEvent evt);
}
