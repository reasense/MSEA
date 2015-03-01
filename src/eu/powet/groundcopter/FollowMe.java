package eu.powet.groundcopter;

import org.osmdroid.util.GeoPoint;

import com.mavlink.messages.common.msg_mission_ack;

import eu.powet.groundcopter.controller.IController;
import eu.powet.groundcopter.controller.Request;
import eu.powet.groundcopter.events.JMAVLink;
import eu.powet.groundcopter.utils.MavlinkHelper;
import android.content.Context;
import android.location.Location;
import android.location.LocationListener;
import android.location.LocationManager;
import android.os.Bundle;
import android.widget.Toast;

public class FollowMe {

	private LocationManager locationMgr	= null;
	private LocationListener onLocationChange=null;
	private boolean enable = false;
	private int altitude = 10;
	private IController c;
		
	double meters2degrees_lat(double meters) {
		/* polar radius = 6,356,752.3142m
		// so, one degree = 2*PI*radius/360 degrees  =appx 110,946m */
		return meters / (2.0*Math.PI*6356752.3142/360.0);
	}
	double meters2degrees_lon(double meters) { /* convert meters longitude to degrees
		// equatorial radius = 6,378,137m
		// so, one degree = 2*PI*radius/360 degrees  =appx 111,319m */
		return (double)((meters / (2.0*Math.PI*6378137.0/360.0)));
	}

	double degrees_lat2meters(double degrees) { /* convert latitude degrees to meters
		// polar radius = 6,356,752.3142m
		// so, one degree = 2*PI*radius/360 degrees  =appx 110,946m */
		return degrees * (2.0*Math.PI*6356752.3142/360.0);
	}
	double degrees_lon2meters(double degrees) { /* convert meters longitude to degrees
		// equatorial radius = 6,378,137m
		// so, one degree = 2*PI*radius/360 degrees  =appx 111,319m */
		return degrees * (2.0*Math.PI*6378137.0/360.0);
	}

	double feet2meters(double feet) {
		return feet * 0.3048006096;
	}
	double meters2feet(double meters) {
		return meters / 0.3048006096;
	}

	double deg2rad2(double degrees) { /* convert degrees to radians */
		return degrees * (Math.PI/180.0);
	}

	double rad2deg2(double radians) { /* convert radian to degree */
		return radians * (180.0/Math.PI);
	}

	private GeoPointMission current=null;


public GeoPointMission secure_range(GeoPointMission p,int heading,int distance){
	
	  double width, height;	  	
	   /* calculate new location using trigonometry */
    if (heading < 90) {
            width  =  distance * Math.sin(deg2rad2(heading));
            height =  distance * Math.cos(deg2rad2(heading));
    } else if (heading< 180) {
            width  =  distance * Math.cos(deg2rad2(heading-90));
            height = -distance * Math.sin(deg2rad2(heading-90));
    } else if (heading < 270) {
            width  = -distance * Math.sin(deg2rad2(heading-180));
            height = -distance * Math.cos(deg2rad2(heading-180));
    } else {
            width  = -distance * Math.cos(deg2rad2(heading-270));
            height =  distance * Math.sin(deg2rad2(heading-270));
    }
   return new GeoPointMission(new GeoPoint(p.getLatitudeE6() - meters2degrees_lat(height), p.getLongitudeE6() - meters2degrees_lon(width), p.getAltitude()));
}

	public FollowMe(final Context ctx,final IController c)
	{
		
		this.c = c;
		onLocationChange	= new LocationListener() {
			@Override
			public void onLocationChanged(Location location)
			{
				double lat =    location.getLatitude();
				double lon =   location.getLongitude();

				GeoPointMission here = new GeoPointMission(new GeoPoint(lat, lon,altitude));
				c.handleMessage(Request.SET_USER_POSITION,here);
				c.handleMessage(Request.UPDATE_MAP);
				current = here;
				
				if(enable)
				{
				    c.handleMessage(Request.FLYHERE, here);
				}
			
			}

			@Override
			public void onStatusChanged(String s, int i, Bundle bundle) {

			}

			@Override
			public void onProviderEnabled(String s) {

			}

			@Override
			public void onProviderDisabled(String s) {

			}
		}  ;


		locationMgr = (LocationManager) ctx.getSystemService(Context.LOCATION_SERVICE);
		//  locationMgr.requestLocationUpdates(LocationManager.NETWORK_PROVIDER, 10000, 1, onLocationChange);
		locationMgr.requestLocationUpdates(LocationManager.GPS_PROVIDER, 500, 1, onLocationChange);
		//requestLocationUpdates(String provider, long minTime, float minDistance, PendingIntent intent)


	}
	public boolean isEnable() {
		return enable;
	}
	public void setEnable(boolean enable) {
		this.enable = enable;
		if(enable && current !=null)
		{
			   c.handleMessage(Request.FLYHERE, current);
		}
	}
	public int getAltitude() {
		return altitude;
	}
	public void setAltitude(int altitude) {
		this.altitude = altitude;
	}
	


}
