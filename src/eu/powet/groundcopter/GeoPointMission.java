package eu.powet.groundcopter;

import org.osmdroid.util.GeoPoint;

public class GeoPointMission  extends GeoPoint{

	private float delay = 0;
	private boolean reached = false;

	
	public GeoPointMission(GeoPoint p){
		super(p);
	}
	
	
	public GeoPointMission(GeoPoint p,float delay){
		super(p);
		this.delay = delay;
	}

	public float getDelay() {
		return delay;
	}

	public void setDelay(float delay) {
		this.delay = delay;
	}

	public boolean isReached() {
		return reached;
	}

	public void setReached(boolean reached) {
		this.reached = reached;
	}
	
	
	
	public boolean equals(GeoPointMission c){
		if(super.getLatitudeE6() == c.getLatitudeE6() && super.getLongitudeE6() == c.getLongitudeE6() && super.getAltitude() == c.getAltitude() && c.getDelay() == delay){
			return true;
		}
		
		return false;
	}
	
	
	

}
