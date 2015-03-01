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
 * Time: 15:09
 */

import java.util.List;


import eu.powet.groundcopter.GeoPointMission;
import eu.powet.groundcopter.utils.ManagerUI;
import android.app.Activity;



public interface IController   {
	boolean  handleMessage(Request req);
	boolean handleMessage(Request req, Object data);
	boolean handleMessage(Request req,String key,  Object data);
	Object getMessage(Request req);
	List<GeoPointMission> getWaypoints();
	public ManagerUI getViewsmanager();
	Activity getCurrentActivity();
}
