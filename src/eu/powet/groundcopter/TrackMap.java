package eu.powet.groundcopter;
import org.osmdroid.util.GeoPoint;
import org.osmdroid.views.MapView;
import org.osmdroid.views.overlay.PathOverlay;

import android.app.Activity;
import android.content.Context;
import android.graphics.Color;
/**
 * Created by jed
 * User: jedartois@gmail.com
 */
public class TrackMap {

	private PathOverlay pathOverlay;
	private Context current;
	private MapView mapview; 


	public TrackMap(Context _current,MapView map)
	{
		this.current =_current;
		this.mapview =map;
		pathOverlay = new PathOverlay(Color.YELLOW, current);
		mapview.getOverlays().add(pathOverlay);
	}

	public void addPoint(GeoPoint gps)
	{
		try 
		{
			pathOverlay.addPoint(gps.getLatitudeE6(),gps.getLongitudeE6());
		}catch(Exception e){
			e.printStackTrace();
		}
	}
	
	public void clean(){
		pathOverlay.clearPath();
	}


}