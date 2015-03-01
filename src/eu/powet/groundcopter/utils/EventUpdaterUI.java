package eu.powet.groundcopter.utils;

import eu.powet.groundcopter.controller.Request;

public class EventUpdaterUI {

	private Request req;
	private Object data;
	
	public EventUpdaterUI(Request req){
		this.req = req;

	}
	public Request getReq() {
		return req;
	}
	
	public Object getData() {
		return data;
	}
	public void setData(Object value) {
		this.data = value;
	}

	
	
}
