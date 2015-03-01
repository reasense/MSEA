package eu.powet.groundcopter.events;

import com.mavlink.messages.IMAVLinkMessage;

public class MavlinkEventConnected extends MavLinkEvent {
 
	private static final long serialVersionUID = 1L;
	public String msg;
	public MavlinkEventConnected(Object o, IMAVLinkMessage msg) {
		super(o, msg);
	}

	
	
}
