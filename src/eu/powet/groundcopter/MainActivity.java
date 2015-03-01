package eu.powet.groundcopter;

import eu.powet.groundcopter.controller.ControllerImpl;
import eu.powet.groundcopter.controller.IController;
import eu.powet.groundcopter.controller.Request;
import eu.powet.groundcopter.views.BaseGroundCopterUI;
import android.app.Activity;
import android.os.Bundle;


public class MainActivity extends Activity {
	
	private  IController controller=null;
	@Override
	protected void onCreate(Bundle savedInstanceState) 
	{
		super.onCreate(savedInstanceState);
        controller = new ControllerImpl(this);
        BaseGroundCopterUI baseUI = new BaseGroundCopterUI(controller);
        controller.handleMessage(Request.ADD_LINEARLAYOUT,BaseGroundCopterUI.class.toString(),baseUI);
        
        controller.handleMessage(Request.DISABLE_BUTTONS);
        
        /*
        GeoPointMission here = new GeoPointMission(new GeoPoint(48.1166,-1.640594, 15));
        controller.handleMessage(Request.SET_DRONE_POSITION,here);
        controller.handleMessage(Request.UPDATE_MAP);
*/
        
	}

}
