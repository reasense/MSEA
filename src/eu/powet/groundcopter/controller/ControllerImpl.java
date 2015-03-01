/**
 * Licensed under the GNU LESSER GENERAL PUBLIC LICENSE, Version 3, 29 June 2007;
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.gnu.org/licenses/lgpl-3.0.txt
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
/**
 * Licensed under the GNU LESSER GENERAL PUBLIC LICENSE, Version 3, 29 June 2007;
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * 	http://www.gnu.org/licenses/lgpl-3.0.txt
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package eu.powet.groundcopter.controller;

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.List;

import eu.powet.groundcopter.FollowMe;
import eu.powet.groundcopter.GeoPointMission;
import eu.powet.groundcopter.utils.FTDriver;
import eu.powet.groundcopter.utils.ManagerUI;
import eu.powet.groundcopter.utils.MavlinkManager;
import eu.powet.groundcopter.utils.MavlinkHelper;
import eu.powet.groundcopter.utils.EventUpdaterUI;
import android.app.Activity;

import android.util.Log;
import android.widget.LinearLayout;
import android.widget.Toast;

public class ControllerImpl implements IController 
{
	private static final String TAG = ControllerImpl.class.getSimpleName();
	private MavlinkManager mavlinkmanager = null;
	private Activity ctx;
	private int baudrate = FTDriver.BAUD115200;
	private ManagerUI uiManager;
	private Boolean logging = false;
	private FollowMe fme ;
	private LinkedList<GeoPointMission> waypoints = new LinkedList<GeoPointMission>();

	public ControllerImpl(Activity act) {
		this.ctx = act;
		uiManager = new ManagerUI();
		mavlinkmanager = new MavlinkManager(this, act);
		fme = new FollowMe(ctx, this);
	}

	

	@Override
	public boolean handleMessage(final Request req) 
	{
		ctx.runOnUiThread(new Runnable() {
			@Override
			public void run() 
			{
				switch (req) 
				{
				case CONNECT:
					mavlinkmanager.getMavlink().connect(baudrate);
					break;

				case ENABLE_LOG:
					logging = true;
				break;
				
				case DISABLE_LOG:
					logging = false;
					break;
					
				case HEARTBEAT:
			
					break;
				
				case SET_ARMED:
					MavlinkHelper.set_armed(mavlinkmanager.getMavlink(), true);
					break;

				case START_FOLLOWME:
					fme.setEnable(true);
					break;

				case STOP_FOLLOWME:
					fme.setEnable(false);
					break;
				case SET_DISARMED:
					MavlinkHelper.set_armed(mavlinkmanager.getMavlink(), false);
					break;

				case IS_ARMED:
					uiManager.updateUI(new EventUpdaterUI(Request.IS_ARMED));
					break;

				case IS_DISARMED:
					uiManager.updateUI(new EventUpdaterUI(Request.IS_DISARMED));
					break;

				case ENABLE_HUD:
					uiManager.updateUI(new EventUpdaterUI(Request.ENABLE_HUD));
					break;

				case DISABLE_HUD:
					uiManager.updateUI(new EventUpdaterUI(Request.DISABLE_HUD));
					break;

				case ENABLE_BUTTONS:
					uiManager.updateUI(new EventUpdaterUI(Request.ENABLE_BUTTONS));
					break;

				case DISABLE_BUTTONS:
					uiManager.updateUI(new EventUpdaterUI(Request.DISABLE_BUTTONS));
					break;

				case EXIT:
					System.exit(0);
					break;

				case WRITE_WAYPOINTS:

					synchronized(this) {			
						Log.d(TAG, "handleMessage(" + req +" Waypoints "+ waypoints.size()+");");
						MavlinkHelper.initialize_procedure_addwaypoints(mavlinkmanager.getMavlink(), waypoints.size());
					}
					break;

				case READ_WAYPOINTS:
					Log.d(TAG, "handleMessage(" + req + ");");
					MavlinkHelper.request_list_waypoints(mavlinkmanager.getMavlink());
					break;

				case UPDATE_MAP:
					uiManager.updateUI(new EventUpdaterUI(Request.UPDATE_MAP));
					break;

				case CLEAR_UI_WAYPOINTS:
					synchronized(this) {
						waypoints.clear();
					}	
					break;
					
				case PILOT_AUTO:
					MavlinkHelper.set_auto(mavlinkmanager.getMavlink(),true);
					
					break;
					
				case PILOT_MANUEL:
					MavlinkHelper.set_auto(mavlinkmanager.getMavlink(),false);
					break;

				case DELETE_WAYPOINTS:
					if (MavlinkHelper.clear_waypoints(mavlinkmanager.getMavlink())) 
					{
						handleMessage(Request.CLEAR_UI_WAYPOINTS);
						handleMessage(Request.CLEAN_TRACK);
					}
					break;

				case RETURN_TO_LAUNCH:
					MavlinkHelper.nav_return_to_launch(mavlinkmanager.getMavlink());
					break;

				case DISCONNECT:
					mavlinkmanager.getMavlink().disconnect();
					break;

				case START_STREAM:
					MavlinkHelper.helper_stream(mavlinkmanager.getMavlink(),true);
					break;

				case STOP_STREAM:
					MavlinkHelper.helper_stream(mavlinkmanager.getMavlink(),false);
					break;
				default:
					Log.e(TAG, "THE Controller can't handle this message "+ req);
					break;
				}
			}
		});
		return false;
	}

	@Override
	public  boolean handleMessage(final Request req, final Object data) {

		Log.d(TAG, "handleMessage(" + req + "," + data + ");");

		ctx.runOnUiThread(new Runnable() {
			@Override
			public void run() {
				switch (req) {
				case ADD_WAYPOINT:
					synchronized(this) 
					{
						boolean found = false;
						GeoPointMission toadd = (GeoPointMission) data;
						for(GeoPointMission p : waypoints){
							if(p.equals(toadd)){
								found = true;
							}
						}
						if(!found){
							waypoints.add(toadd);		
						}

					}
					handleMessage(Request.UPDATE_MAP);
					break;

				case ANIMATE_TO_MAP_WAYPOINT:
					EventUpdaterUI movemap = new EventUpdaterUI(Request.ANIMATE_TO_MAP_WAYPOINT);
					movemap.setData(data);
					uiManager.updateUI(movemap);
					break;

				case SET_FOLLOWME_ALTITUDE:
					fme.setAltitude((Integer)data);		
					break;
				case TOAST_MSG:
					Toast.makeText(ctx, data.toString(), Toast.LENGTH_SHORT).show();
					break;

				case CHANGE_BAUDRATE:
					baudrate = (Integer) data;
					break;

				case MAVLINK_ISCONNECTED:
					// data == evt
					handleMessage(Request.ENABLE_BUTTONS);
					break;

				case MAVLINK_ISDISCONNECTED:
					// data == evt
					handleMessage(Request.DISABLE_BUTTONS);
					break;

				case UPDATE_HUD_ALTITUDE:
					EventUpdaterUI uphud = new EventUpdaterUI(Request.UPDATE_HUD_ALTITUDE);
					uphud.setData(data);
					uiManager.updateUI(uphud);
					break;

				case UPDATE_HUD_GPSFIX:
					EventUpdaterUI hudgps = new EventUpdaterUI(Request.UPDATE_HUD_GPSFIX);
					hudgps.setData(data);
					uiManager.updateUI(hudgps);
					break;

				case FLYHERE:
					MavlinkHelper.flyhere(mavlinkmanager.getMavlink(),(GeoPointMission)data);
					break;

				case SET_USER_POSITION:
					EventUpdaterUI userposition = new EventUpdaterUI(Request.SET_USER_POSITION);
					userposition.setData(data);
					uiManager.updateUI(userposition);
					break;

				case UPDATE_IA_INFO:
					EventUpdaterUI c = new EventUpdaterUI(Request.UPDATE_IA_INFO);
					c.setData(data);
					uiManager.updateUI(c);
					break;
				case ADD_TRACK:
					EventUpdaterUI addtrack = new EventUpdaterUI(Request.ADD_TRACK);
					addtrack.setData(data);
					uiManager.updateUI(addtrack);
					break;

				case SET_DRONE_POSITION:
					EventUpdaterUI droneposition = new EventUpdaterUI(Request.SET_DRONE_POSITION);
					droneposition.setData(data);
					uiManager.updateUI(droneposition);
					break;

				case SYS_STATUS:
					EventUpdaterUI sysstatus = new EventUpdaterUI(Request.SYS_STATUS);
					sysstatus.setData(data);
					uiManager.updateUI(sysstatus);
					break;
				case UPDATE_FLIGHTDATA:
					EventUpdaterUI flightdata = new EventUpdaterUI(Request.UPDATE_FLIGHTDATA);
					flightdata.setData(data);
					uiManager.updateUI(flightdata);
					break;
				default:
					Log.e(TAG, "THE Controller can't handle this message "
							+ req);
					break;
				}
			}
		});
		return true;
	}

	@Override
	public ManagerUI getViewsmanager() {
		return uiManager;
	}

	@Override
	public Activity getCurrentActivity() {
		return ctx;
	}

	@Override
	public boolean handleMessage(Request req, String key, Object data) {

		switch (req) {

		case ADD_LINEARLAYOUT:
			getCurrentActivity().setContentView((LinearLayout) data);
			return true;

		}

		return false;
	}

	public List<GeoPointMission> getWaypoints() {
		return waypoints;
	}

	public void setWaypoints(LinkedList<GeoPointMission> waypoints) {
		this.waypoints = waypoints;
	}

	@Override
	public Object getMessage(Request req) {
		switch(req){

		case GET_USER_POSITION:
			//todo

			break;
		case GET_STATUS_LOG:
			return logging;
		 
		}
		return null;
	}

}