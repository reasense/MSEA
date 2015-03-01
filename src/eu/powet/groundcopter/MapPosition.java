package eu.powet.groundcopter;



import org.osmdroid.views.MapView;

import android.content.Context;


import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Point;

public class MapPosition  extends  org.osmdroid.views.overlay.Overlay {

	private GeoPointMission positiongps =null;

	public enum Type {
		Quadcopter,
		User
	}
	Type t;

	public MapPosition(Context ctx,Type t) {
		super(ctx);
		this.t =t;
	}

	@Override
	protected void draw(Canvas canvas, MapView mapview, boolean arg2) {

		if(positiongps !=null)
		{
			Bitmap img=null;

			Paint lp3;
			lp3 = new Paint();
			lp3.setAntiAlias(true);
			lp3.setColor(Color.BLACK);
			
			Point p1=mapview.getProjection().toMapPixels(positiongps, null);

			if(t== Type.Quadcopter)
			{
				lp3.setColor(Color.BLUE);
			//	img = BitmapFactory.decodeResource(mapview.getResources(), R.drawable.copter);
				//canvas.drawBitmap(img, p1.x-img.getWidth()+50, p1.y-img.getHeight()+36, null);	
				canvas.drawCircle(p1.x, p1.y, 6, lp3);

			}else if(t == Type.User)
			{
			
				canvas.drawCircle(p1.x, p1.y, 5, lp3);
			}





		}

	}

	public GeoPointMission getPositiongps() {
		return positiongps;
	}

	public void setPositiongps(GeoPointMission positiongps) {
		this.positiongps = positiongps;
	}




}