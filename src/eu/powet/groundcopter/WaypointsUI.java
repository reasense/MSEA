package eu.powet.groundcopter;



import org.osmdroid.views.MapView;

import eu.powet.groundcopter.controller.IController;


import android.content.Context;

import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Point;

public class WaypointsUI extends  org.osmdroid.views.overlay.Overlay
{
	private IController controller;
	private final int sizecircle = 10;
	
	public WaypointsUI(Context ctx,IController c)
	{
		super(ctx);
		this.controller = c;
	}
	

	@Override
	protected void draw(Canvas canvas, MapView mapview, boolean arg2) {

		Paint lp3;
		lp3 = new Paint();
		lp3.setColor(Color.RED);
		lp3.setAntiAlias(true);

		Paint paint = new Paint(); 
		paint.setColor(Color.BLACK); 
		paint.setTextSize(20); 
		
		Paint paintreached = new Paint(); 
		paintreached.setColor(Color.GREEN); 
		paintreached.setTextSize(20); 
		
		Paint line = new Paint(); 
		line.setColor(Color.BLACK); 

		String msg;
		if(controller.getWaypoints().size() > 0)
		{
			for(int i=0;i<controller.getWaypoints().size();i++)
			{
			
				Point p1=mapview.getProjection().toMapPixels(controller.getWaypoints().get(i), null);
				canvas.drawCircle(p1.x, p1.y, sizecircle, lp3);
			
				if(i == 0)
				{
					msg  = "Home ("+controller.getWaypoints().get(i).getAltitude()+")";

				}else {
					msg = ""+i+"("+controller.getWaypoints().get(i).getAltitude()+")";
				}
				
				if(controller.getWaypoints().get(i).isReached())
				{
					canvas.drawText(msg,p1.x+sizecircle, p1.y+sizecircle/2,paintreached);
				}else {
					canvas.drawText(msg,p1.x+sizecircle, p1.y+sizecircle/2,paint);	
				}
				
				if(i >0)
				{
					Point last=mapview.getProjection().toMapPixels(controller.getWaypoints().get(i-1), null);
					canvas.drawLine(last.x, last.y, p1.x, p1.y, line);		
				}
			}

		}
	}





}
