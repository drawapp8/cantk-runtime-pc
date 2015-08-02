package com.tangide;

import android.app.Activity;
import android.os.Bundle;

public class GameRunner extends Activity
{
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        CanvasView view = new CanvasView(this);
        this.setContentView(view);
    }
}
