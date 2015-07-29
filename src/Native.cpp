#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <string>

#include "Native.h"
#include "CanvasBinding.h"
#include "ImageBinding.h"
#include "HttpClientBinding.h"
#include "CanvasRenderingContext2dBinding.h"

void nativeInitBinding(Handle<Object> target) {
	ImageInitBinding(target);
	CanvasInitBinding(target);
	HttpClientInitBinding(target);
	CanvasRenderingContext2dInitBinding(target);
	return;
}

