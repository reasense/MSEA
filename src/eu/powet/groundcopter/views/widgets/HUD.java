package eu.powet.groundcopter.views.widgets;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Paint.Align;
import android.graphics.Paint.Style;
import android.graphics.PixelFormat;
import android.graphics.Rect;
import android.graphics.RectF;
import android.util.AttributeSet;
import android.view.Display;
import android.view.Surface;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.view.WindowManager;

public class HUD extends SurfaceView implements SurfaceHolder.Callback {
	
	private ScopeThread renderer;
	private int width;
	private int height;
	
	double roll = 0, pitch = 0, yaw = 0;
	
	Paint grid_paint = new Paint();
	Paint ground = new Paint();	
	Paint sky = new Paint();	
	Paint white = new Paint();
	Paint whiteCenter = new Paint();	
	Paint whitebar = new Paint();	
	Paint whiteStroke = new Paint();
	Paint statusText = new Paint();
	Paint state_arm_disarm = new Paint();

	
	Paint plane = new Paint();
	Paint redSolid = new Paint();
	private float altitude = 0;
	private double remainBatt = 0;
	private int battVolt = 0;
	private String gpsFix = "";
	private String navMode = "";

	int viewHeight=350;
	int viewWidth=350;
	public HUD(Context context ) {
		super(context);

//		getHolder().setFormat(PixelFormat.TRANSPARENT);

		getHolder().addCallback(this);

		grid_paint.setColor(Color.rgb(100, 100, 100));
		ground.setARGB(220, 148, 193, 31);
		sky.setARGB(220, 0, 113, 188);
		whitebar.setARGB(64, 255, 255, 255);
		
		white.setColor(Color.WHITE);
		white.setTextSize(15.0f * context.getResources().getDisplayMetrics().density);
		
		whiteCenter.setColor(Color.WHITE);
		whiteCenter.setTextSize(15.0f * context.getResources().getDisplayMetrics().density);
		whiteCenter.setTextAlign(Align.CENTER);
		
		statusText.setColor(Color.WHITE);
		statusText.setTextSize(25.0f * context.getResources().getDisplayMetrics().density);
								
		whiteStroke.setColor(Color.WHITE);
		whiteStroke.setStyle(Style.STROKE);
		whiteStroke.setStrokeWidth(3);
		
		plane.setColor(Color.RED);
		plane.setStyle(Style.STROKE);
		plane.setStrokeWidth(3);

		redSolid.setColor(Color.RED);
		
		state_arm_disarm.setColor(Color.RED);
		state_arm_disarm.setTextSize(25.0f * context.getResources().getDisplayMetrics().density);

		
		
		
	}

	@Override
	public void onLayout(boolean changed, int left, int top, int right, int bottom) {
	    if (changed) {
	        (this).layout(0, 0, viewWidth, viewHeight);
	    }
	}

	@Override
	protected void onDraw(Canvas canvas) {
   if( canvas != null){
		// clear screen
		canvas.drawColor(Color.rgb(20, 20, 20));
		canvas.translate(width/2, height/2);

		canvas.save();
			drawPitch(canvas);
		canvas.restore();
		canvas.save();
			drawRoll(canvas);
		canvas.restore();
		canvas.save();
			drawYaw(canvas);
		canvas.restore();
		canvas.save();
			drawText(canvas);
		canvas.restore();
		canvas.save();
			drawPlane(canvas);
		canvas.restore();
   }
	
	}

	private void drawPlane(Canvas canvas) {
		canvas.drawCircle(0, 0,  15, plane);
		
		canvas.drawLine(-15,   0, -25,   0, plane);
		canvas.drawLine( 15,   0,  25,   0, plane);
		canvas.drawLine(  0, -15,   0, -25, plane);
		
	}

    // Draw text aligned correctly.
	private void drawText(Canvas canvas, int i, String text, Paint p, boolean left){
		Rect bounds = new Rect();
		p.getTextBounds(text, 0, text.length(), bounds);
		
		float y = (float) (height/2.0 - i * bounds.height()*1.2) - (float)bounds.height()*0.3f; 
		
		if(left)
			canvas.drawText(text, (float)(-width/2.0 + bounds.height()*.2f), y, p);
		else
			canvas.drawText(text, (float)(width/2.0 - bounds.width() - bounds.height()*.2f), y, p);
		
	}
	
	private void drawText(Canvas canvas) {

		drawText(canvas, 2, "GPS Fix: "+gpsFix, statusText, true);
		drawText(canvas, 1, "Alt: " + altitude, statusText, true);
		


		drawText(canvas, 0, navMode,  state_arm_disarm, true);
				
		drawText(canvas, 1, remainBatt +"%", statusText, false);
		drawText(canvas, 0, battVolt/1000.0 + "V", statusText, false);
		
	}

	private void drawYaw(Canvas canvas) {
		canvas.drawRect(-width, -height/2, width,  -height/2 + 30, sky);
		canvas.drawLine(-width, -height/2+30, width, -height/2+30, white);
		
		// width / 2 == yawPosition
		// then round to nearest 5 degrees, and draw it.
		
		double centerDegrees = yaw;
		double numDegreesToShow = 50;
		double degreesPerPixel = (double)width / numDegreesToShow ;
		
		double mod = yaw%5;
		for( double angle = (centerDegrees-mod) - numDegreesToShow/2.0;
						  angle <= (centerDegrees-mod) + numDegreesToShow/2.0; 
						  angle+=5){
			
			// protect from wraparound
			double workAngle = (angle+360.0);
			while( workAngle >= 360)
				workAngle -= 360.0;
			
			// need to draw "angle"
			// How many pixels from center should it be?
			int distanceToCenter = (int) ((angle-centerDegrees) * degreesPerPixel);
			
			canvas.drawLine( distanceToCenter, -height/2+20, 
							 distanceToCenter, -height/2+40, white);
		
			if( workAngle%90 == 0){
				String compass[] = {"N", "E", "S", "W"};
				int index = (int) workAngle/90;
				canvas.drawText(compass[index], distanceToCenter, -height/2+20, whiteCenter);
				
			}else
				canvas.drawText((int)(workAngle)+"", distanceToCenter, -height/2+20, whiteCenter);
	
			
		}
		
		// Draw the center line
		canvas.drawLine( 0, -height/2, 
						 0, -height/2+40, plane);

	}

	private void drawRoll(Canvas canvas) {
		
		int r = (int)((double)width * 0.35); //250;
		RectF rec = new RectF(-r, -height/2 + 60 ,
							   r, -height/2 + 60 + 2*r);
		
		//Draw the arc
		canvas.drawArc(rec, -180+45, 90, false, whiteStroke);
		
		//draw the ticks
		//The center of the circle is at:
		// 0, -height/2 + 60 + r
		
		float centerY = -height/2 + 60+ r;
		for(int i = -45; i<= 45; i+= 15){
			// Draw ticks
			float dx = (float)Math.sin(i * Math.PI / 180) * r;
			float dy = (float)Math.cos(i * Math.PI / 180) * r;
			canvas.drawLine( dx, centerY - dy,
					 		 (dx + (dx/25)), centerY - (dy + dy/25),
					 		 whiteStroke);
		
			//Draw the labels
			if( i != 0){
				dx = (float)Math.sin(i * Math.PI / 180) * (r-30);
				dy = (float)Math.cos(i * Math.PI / 180) * (r-30);
				canvas.drawText(Math.abs(i)+"", 
								dx, centerY - dy,
								whiteCenter);
				
			}
		}
		
		float dx = (float)Math.sin(-roll * Math.PI / 180) * r;
		float dy = (float)Math.cos(-roll * Math.PI / 180) * r;
		canvas.drawCircle(dx, centerY-dy, 10, redSolid);

		
	}

	private void drawPitch(Canvas canvas) {

		int step = 40; //Pixels per 5 degree step
		
		canvas.translate(0, (int)(pitch * (step / 5)));
		canvas.rotate(-(int)roll);
		
		//Draw the background box
		canvas.drawRect(-width, 0, width,  5*height /*Go plenty low*/, ground);
		canvas.drawRect(-width, -5*height /*Go plenty high*/, width, 0  , sky);
		canvas.drawRect(-width, -20,
						 width,  20, whitebar);
		
		// Draw the vertical grid
		canvas.drawLine(-width, 0, width, 0, white);
		//canvas.f

		
		for(int i = -step*20; i < step*20; i+=step){
			if(i !=0 ){
				if( i%(2*step) == 0){
					canvas.drawLine(-50, i, 50, i, white);
					canvas.drawText(( 5 * i / -step ) +"", -90, i+5, white);
					
				}else
					canvas.drawLine(-20, i, 20, i, white);
			}
		}
	}
		
	@Override
	public void surfaceChanged(SurfaceHolder holder, int format, int width,	int height) {
		this.width = width;
		this.height = height;
		
	}

	@Override
	public void surfaceCreated(SurfaceHolder holder) {
		renderer = new ScopeThread(getHolder(), this);
		if(! renderer.isRunning()){
			renderer.setRunning(true);
			renderer.start();
		}
	}

	@Override
	public void surfaceDestroyed(SurfaceHolder holder) {
		boolean retry = true;
		renderer.setRunning(false);
		while (retry) {
			try {
				renderer.join();
				renderer = null;
				retry = false;
			} catch (InterruptedException e) {
				// we will try it again and again...
			}
		}
	}

	
	private class ScopeThread extends Thread {
		private SurfaceHolder _surfaceHolder;
		private HUD scope;
		private boolean running = false;

		public ScopeThread(SurfaceHolder surfaceHolder, HUD panel) {
			_surfaceHolder = surfaceHolder;
			scope = panel;
		}

		public boolean isRunning(){
			return running;
			
		}
		public void setRunning(boolean run) {
			running = run;

		}

		@Override
		public void run() {
			Canvas c;
			while (running) {
				c = null;
				try {
					c = _surfaceHolder.lockCanvas(null);
					synchronized (_surfaceHolder) {
						scope.onDraw(c);
					}
				} finally {
					// do this in a finally so that if an exception is thrown
					// during the above, we don't leave the Surface in an
					// inconsistent state
					if (c != null) {
						_surfaceHolder.unlockCanvasAndPost(c);
					}
				}
			}
		}
	}

	/**
	 * Receive current copter orientation
	 * @param roll
	 * @param pitch
	 * @param yaw
	 */
	public void newFlightData(float roll, float pitch, float yaw) {
		/*
		this.roll = ( roll * 180.0 / Math.PI);
		this.pitch =( pitch * 180.0 / Math.PI);
		this.yaw = ( yaw * 180.0 / Math.PI);
		*/
		
		this.roll = roll;
		this.pitch =pitch;
		this.yaw = yaw;
		
	}

	public void setAltitude(float alt) {
		altitude  = alt;
		
	}

	public void setBatteryRemaining(double d) {
		remainBatt = d;
		
	}

	public void setbatteryMVolt(int vbat) {
		battVolt = vbat;
		
	}

	public void setGPSFix(String s) {
		gpsFix = s;
		
	}

	public void setNavMode(String nav) {
		navMode  = nav;
		
	}
	
	public String getnavMode(){
		return navMode;
	}
}
