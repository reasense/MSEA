package eu.powet.groundcopter.events;

import java.util.EventObject;

import com.mavlink.messages.IMAVLinkMessage;

public class MavLinkEvent extends EventObject
{

    private IMAVLinkMessage msg;
    
    
    public MavLinkEvent(Object o,IMAVLinkMessage msg)
    {
        super(o);
        this.msg = msg;
    }

    public IMAVLinkMessage getIMAVLinkMessage()
    {
        return msg;
    }


      

}
