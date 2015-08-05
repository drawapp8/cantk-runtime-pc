/*
 * File     : canvas_jni.cpp
 * Brief    : canvas jni 
 * Author   : Li XianJing <xianjimli@hotmail.com>
 * Web Site : http://www.tangide.com/
 *
 * Copyright (c) 2015 - 2015 Tangram HD.
 *
**/

#include <jni.h>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <android/bitmap.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/time.h>    
#include <unistd.h>
#include "V8Wrapper.h"

static void graphic_context_resize(int w, int h, int dpi) {
	glClearDepthf(1.0f);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT|GL_STENCIL_BUFFER_BIT);

	glViewport(0, 0, w, h);

	return;
}


#define JNIAPI extern "C" JNIEXPORT void JNICALL
#define JNIAPIINT extern "C" JNIEXPORT int JNICALL

static double prevTime;
static double getTime () {
	struct timeval tv = {0};
	struct timezone tz = {0};

	gettimeofday (&tv, NULL);

	double t = (tv.tv_sec & 0xffff) * 1000 + (double)(tv.tv_usec)/1000000;

	return t;
}


JNIAPI Java_com_tangide_canvas_CanvasJNI_surfaceCreated(JNIEnv * env, jobject obj) 
{
	int argc = 3;
	char* argv[3] = {"android", "--startup=/mnt/sdcard-ext/cantk-rt-v8/scripts/startup.js", NULL};

	prevTime = getTime();
	LOGI("Java_com_tangide_canvas_CanvasJNI_surfaceCreated");

	V8Wrapper::init(argc, argv);
}

JNIAPI Java_com_tangide_canvas_CanvasJNI_surfaceChanged(JNIEnv * env, jobject obj,  
	jint width, jint height, jint density)
{
	V8Wrapper::resize(width, height);
	LOGI("Java_com_tangide_canvas_CanvasJNI_surfaceChanged");
}

JNIAPI Java_com_tangide_canvas_CanvasJNI_render(JNIEnv * env, jobject obj)
{
	glClearDepthf(1.0f);
    glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT|GL_STENCIL_BUFFER_BIT);

	double t = getTime();
	double dt = t - prevTime;

	V8Wrapper::tick(t, dt);
	prevTime = t;
}

