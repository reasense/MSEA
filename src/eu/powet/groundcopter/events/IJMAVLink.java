package eu.powet.groundcopter.events;

import com.mavlink.messages.IMAVLinkMessage;

/**
 * Created with IntelliJ IDEA.
 * User: jed
 * Date: 13/11/12
 * Time: 09:57
 * To change this template use File | Settings | File Templates.
 */
public interface IJMAVLink 
{
	
	public boolean connect(int baudrate);
	public void disconnect();
	public boolean writeMessage(IMAVLinkMessage msg);
	
    public void addEventListener (MavLinkEventListener listener);
    public void removeEventListener (MavLinkEventListener listener);
}
