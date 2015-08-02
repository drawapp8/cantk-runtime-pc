/*
 * File     : CanvasJNI.java
 * Brief    : canvas jni 
 * Author   : Li XianJing <xianjimli@hotmail.com>
 * Web Site : http://www.tangide.com/
 *
 * Copyright (c) 2015 - 2015 Tangram HD inc.
 *
**/

package com.tangide;

import android.graphics.Bitmap;

public class CanvasJNI {
    public static native void render();
	public static native void surfaceCreated();
	public static native void surfaceChanged(int width, int height);
	
	static {
		System.loadLibrary("cantkrt");
	}
}
