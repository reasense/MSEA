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

/**
 * Created by jed
 * User: jedartois@gmail.com
 * Date: 08/03/12
 * Time: 16:00
 */
public enum Request {
	IS_ARMED,IS_DISARMED,
	UPDATE_HUD_ALTITUDE,
	UPDATE_IA_INFO,
	UPDATE_HUD_GPSFIX,
	UPDATE_FLIGHTDATA,
	SYS_STATUS,
	UPDATE_MAP,
	TOAST_MSG,
	GET_USER_POSITION,
	SET_USER_POSITION,
	SET_DRONE_POSITION,
	ADD_TRACK,
	FLYHERE,
	ANIMATE_TO_MAP_WAYPOINT,
	CLEAN_TRACK,
	ENABLE_LOG,
	DISABLE_LOG,
	GET_STATUS_LOG,
	ADD_LINEARLAYOUT,HEARTBEAT,
	SET_ARMED,SET_DISARMED,
	START_FOLLOWME,STOP_FOLLOWME,SET_FOLLOWME_ALTITUDE,
	ENABLE_HUD,DISABLE_HUD,
    ENABLE_BUTTONS,DISABLE_BUTTONS,ADD_WAYPOINT,DELETE_WAYPOINTS,
    READ_WAYPOINTS,WRITE_WAYPOINTS,CLEAR_UI_WAYPOINTS,RETURN_TO_LAUNCH,
    START_STREAM,STOP_STREAM,PILOT_AUTO,PILOT_MANUEL,CONNECT,DISCONNECT,EXIT,MAVLINK_ISCONNECTED,MAVLINK_ISDISCONNECTED,CHANGE_BAUDRATE;
}
