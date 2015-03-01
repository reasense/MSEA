package eu.powet.groundcopter;

import java.util.EventObject;

import com.mavlink.messages.IMAVLinkMessage;

import eu.powet.groundcopter.events.JMAVLink;
import eu.powet.groundcopter.events.MavLinkEvent;



public class MavlinkNative extends EventObject  
{
	private JMAVLink events=null;
	
	public MavlinkNative(JMAVLink o)
	{
		super(o);
		events = o;
		System.loadLibrary("jmavlink");
		registerCallbacks();
	}

	public  native void registerCallbacks();
	public  native void forward(int len,byte[]  c);
	 public native byte[] createMessage(IMAVLinkMessage msg);
	 
	public  void postEventFromNative(Object msg){
		if(msg instanceof IMAVLinkMessage)
		{
		    events.fireEvent(new MavLinkEvent(this,(IMAVLinkMessage)msg));
		}else {
			System.err.println("object is not IMAVLinkMessage");
		}
	}


	
}
