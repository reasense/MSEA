package eu.powet.groundcopter.events;

import com.mavlink.messages.IMAVLinkMessage;

public class MavlinkEventDisconnected extends MavLinkEvent {
	
	private static final long serialVersionUID = 1L;
	public String msg;
	public MavlinkEventDisconnected(Object o, IMAVLinkMessage msg) {
		super(o, msg);
	}

}
