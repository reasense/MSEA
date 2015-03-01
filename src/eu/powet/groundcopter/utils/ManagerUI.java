package eu.powet.groundcopter.utils;

import android.util.Log;

public class ManagerUI implements IChangeListener {
    private static final String TAG = "ManagerUI";
	private  EventListenerList listenerList = new EventListenerList();

	@Override
	public void addEventListener(ViewChangeListener listener) {
		 listenerList.add(ViewChangeListener.class, listener);
	}

	@Override
	public void removeEventListener(ViewChangeListener listener) {
		listenerList.remove(ViewChangeListener.class, listener);
	}

    public void updateUI (EventUpdaterUI evt)
    {
    //	Log.d(TAG,"updateUI("+evt.getTarget()+" "+evt.getReq()+");");
        Object[] listeners = listenerList.getListenerList();
        for (int i = 0; i < listeners.length; i += 2)
        {
            if (evt instanceof EventUpdaterUI)
            {
                ((ViewChangeListener) listeners[i + 1]).update(evt);
            } 
        }
    }

}
