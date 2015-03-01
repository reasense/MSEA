package eu.powet.groundcopter.events;

import java.util.EventListener;

import com.mavlink.messages.IMAVLinkMessage;

public interface MavLinkEventListener extends EventListener {
	void receive(final MavLinkEvent evt,final IMAVLinkMessage msg);
	void connected(final MavLinkEvent evt);
	void disconnected(final MavLinkEvent evt);
}
