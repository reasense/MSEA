package com.mavlink.messages;

import java.io.Serializable;

public abstract class IMAVLinkMessage implements Serializable {
	public int messageType = -1;
	public int sysID = -1;
	public int componentID = -1;
}
