/*
 * File     : CanvasRenderer.java
 * Brief    : CanvasRenderer 
 * Author   : Li XianJing <xianjimli@hotmail.com>
 * Web Site : http://www.tangide.com/
 *
 * Copyright (c) 2015 - 2015 Tangram HD.
 *
**/

package com.tangide;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.os.Process; 
import android.util.Log;
import android.opengl.GLES10;
import android.opengl.GLUtils;
import android.opengl.GLSurfaceView;

class CanvasRenderer implements GLSurfaceView.Renderer {
    private static final String LOGTAG = "com.tangide.cantk.CanvasRenderer";

	public CanvasRenderer() {
		super();
	}

	public void onDrawFrame(GL10 gl) {
		CanvasJNI.render();
	}

	public void onSurfaceChanged(GL10 gl, int width, int height) {
		CanvasJNI.surfaceChanged(width, height);
	}

	public void onSurfaceCreated(GL10 gl, EGLConfig config) {
		CanvasJNI.surfaceCreated();
	}
}
