package desktopapplication1;

import java.util.EventObject;

/**
 *
 * @author Michal Banasiak
 */
public abstract class ConnectionEvent extends EventObject {
    public ConnectionEvent(String oldMessageFrame, String newMessageFrame, Object source) {
        super(source);

        this.oldMessageFrame = oldMessageFrame;
        this.newMessageFrame = newMessageFrame;
    }

    public String getOldMessageFrame() {
        return this.oldMessageFrame;
    }

    public String getNewMessageFrame() {
        return this.newMessageFrame;
    }

    private String oldMessageFrame = "";
    private String newMessageFrame = "";
}
