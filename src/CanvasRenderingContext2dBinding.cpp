#include "CanvasRenderingContext2d.h"

#include "CanvasRenderingContext2dBinding.h"

NAN_METHOD(newCanvasRenderingContext2d) {
	NanScope();

	CanvasRenderingContext2d* obj = new CanvasRenderingContext2d();
	obj->Wrap(args.This());

	NanReturnValue(args.This());
}

NAN_METHOD(CanvasRenderingContext2dStroke) {
	NanScope();
	if(args.Length() < 0) {
		printf("invalid arguments for stroke.\n");
		return;
	}

	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());
	 obj->stroke();
	NanReturnUndefined();
}

NAN_METHOD(CanvasRenderingContext2dFill) {
	NanScope();
	if(args.Length() < 0) {
		printf("invalid arguments for fill.\n");
		return;
	}

	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());
	 obj->fill();
	NanReturnUndefined();
}

NAN_METHOD(CanvasRenderingContext2dBeginPath) {
	NanScope();
	if(args.Length() < 0) {
		printf("invalid arguments for beginPath.\n");
		return;
	}

	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());
	 obj->beginPath();
	NanReturnUndefined();
}

NAN_METHOD(CanvasRenderingContext2dClosePath) {
	NanScope();
	if(args.Length() < 0) {
		printf("invalid arguments for closePath.\n");
		return;
	}

	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());
	 obj->closePath();
	NanReturnUndefined();
}

NAN_METHOD(CanvasRenderingContext2dSave) {
	NanScope();
	if(args.Length() < 0) {
		printf("invalid arguments for save.\n");
		return;
	}

	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());
	 obj->save();
	NanReturnUndefined();
}

NAN_METHOD(CanvasRenderingContext2dRestore) {
	NanScope();
	if(args.Length() < 0) {
		printf("invalid arguments for restore.\n");
		return;
	}

	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());
	 obj->restore();
	NanReturnUndefined();
}

NAN_METHOD(CanvasRenderingContext2dRotate) {
	NanScope();
	if(args.Length() < 1) {
		printf("invalid arguments for rotate.\n");
		return;
	}
	double angle = args[0]->NumberValue();

	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());
	 obj->rotate(angle);
	NanReturnUndefined();
}

NAN_METHOD(CanvasRenderingContext2dScale) {
	NanScope();
	if(args.Length() < 2) {
		printf("invalid arguments for scale.\n");
		return;
	}
	double x = args[0]->NumberValue();
	double y = args[1]->NumberValue();

	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());
	 obj->scale(x, y);
	NanReturnUndefined();
}

NAN_METHOD(CanvasRenderingContext2dTranslate) {
	NanScope();
	if(args.Length() < 2) {
		printf("invalid arguments for translate.\n");
		return;
	}
	double x = args[0]->NumberValue();
	double y = args[1]->NumberValue();

	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());
	 obj->translate(x, y);
	NanReturnUndefined();
}

NAN_METHOD(CanvasRenderingContext2dTransform) {
	NanScope();
	if(args.Length() < 6) {
		printf("invalid arguments for transform.\n");
		return;
	}
	double a = args[0]->NumberValue();
	double b = args[1]->NumberValue();
	double c = args[2]->NumberValue();
	double d = args[3]->NumberValue();
	double e = args[4]->NumberValue();
	double f = args[5]->NumberValue();

	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());
	 obj->transform(a, b, c, d, e, f);
	NanReturnUndefined();
}

NAN_METHOD(CanvasRenderingContext2dResetTransform) {
	NanScope();
	if(args.Length() < 0) {
		printf("invalid arguments for resetTransform.\n");
		return;
	}

	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());
	 obj->resetTransform();
	NanReturnUndefined();
}

NAN_METHOD(CanvasRenderingContext2dClip) {
	NanScope();
	if(args.Length() < 0) {
		printf("invalid arguments for clip.\n");
		return;
	}

	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());
	 obj->clip();
	NanReturnUndefined();
}

NAN_METHOD(CanvasRenderingContext2dClipRect) {
	NanScope();
	if(args.Length() < 4) {
		printf("invalid arguments for clipRect.\n");
		return;
	}
	double x = args[0]->NumberValue();
	double y = args[1]->NumberValue();
	double w = args[2]->NumberValue();
	double h = args[3]->NumberValue();

	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());
	 obj->clipRect(x, y, w, h);
	NanReturnUndefined();
}

NAN_METHOD(CanvasRenderingContext2dFillText) {
	NanScope();
	if(args.Length() < 3) {
		printf("invalid arguments for fillText.\n");
		return;
	}
	v8::String::Utf8Value text(args[0]);
	double x = args[1]->NumberValue();
	double y = args[2]->NumberValue();

	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());
	 obj->fillText(*text, x, y);
	NanReturnUndefined();
}

NAN_METHOD(CanvasRenderingContext2dStrokeText) {
	NanScope();
	if(args.Length() < 3) {
		printf("invalid arguments for strokeText.\n");
		return;
	}
	v8::String::Utf8Value text(args[0]);
	double x = args[1]->NumberValue();
	double y = args[2]->NumberValue();

	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());
	 obj->strokeText(*text, x, y);
	NanReturnUndefined();
}

NAN_METHOD(CanvasRenderingContext2dMeasureText) {
	NanScope();
	if(args.Length() < 1) {
		printf("invalid arguments for measureText.\n");
		return;
	}
	v8::String::Utf8Value text(args[0]);

	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());
	double retVal =  obj->measureText(*text);
	NanReturnValue(NanNew<Number>(retVal));
}

NAN_METHOD(CanvasRenderingContext2dClearRect) {
	NanScope();
	if(args.Length() < 4) {
		printf("invalid arguments for clearRect.\n");
		return;
	}
	double x = args[0]->NumberValue();
	double y = args[1]->NumberValue();
	double w = args[2]->NumberValue();
	double h = args[3]->NumberValue();

	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());
	 obj->clearRect(x, y, w, h);
	NanReturnUndefined();
}

NAN_METHOD(CanvasRenderingContext2dFillRect) {
	NanScope();
	if(args.Length() < 4) {
		printf("invalid arguments for fillRect.\n");
		return;
	}
	double x = args[0]->NumberValue();
	double y = args[1]->NumberValue();
	double w = args[2]->NumberValue();
	double h = args[3]->NumberValue();

	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());
	 obj->fillRect(x, y, w, h);
	NanReturnUndefined();
}

NAN_METHOD(CanvasRenderingContext2dStrokeRect) {
	NanScope();
	if(args.Length() < 4) {
		printf("invalid arguments for strokeRect.\n");
		return;
	}
	double x = args[0]->NumberValue();
	double y = args[1]->NumberValue();
	double w = args[2]->NumberValue();
	double h = args[3]->NumberValue();

	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());
	 obj->strokeRect(x, y, w, h);
	NanReturnUndefined();
}

NAN_METHOD(CanvasRenderingContext2dDrawImage1) {
	NanScope();
	
	Local<Object> imageObj = args[0]->ToObject();
	Image* image = ObjectWrap::Unwrap<Image>(imageObj);
	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());

	if(args.Length() == 3) {
		double dx = args[1]->NumberValue();
		double dy = args[2]->NumberValue();
	 	obj->drawImage(image, dx, dy);
	}
	else if(args.Length() == 5) {
		double dx = args[1]->NumberValue();
		double dy = args[2]->NumberValue();
		double dw = args[3]->NumberValue();
		double dh = args[4]->NumberValue();
		obj->drawImage(image, dx, dy, dw, dh);
	}
	else if(args.Length() == 9) {
		double sx = args[1]->NumberValue();
		double sy = args[2]->NumberValue();
		double sw = args[3]->NumberValue();
		double sh = args[4]->NumberValue();
		double dx = args[5]->NumberValue();
		double dy = args[6]->NumberValue();
		double dw = args[7]->NumberValue();
		double dh = args[8]->NumberValue();
		obj->drawImage(image, sx, sy, sw, sh, dx, dy, dw, dh);
	}
	else {
		printf("invalid arguments for drawImage.\n");
	}
	NanReturnUndefined();
}

NAN_METHOD(CanvasRenderingContext2dDrawImage) {
	NanScope();
	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());

	if(args.Length() == 3) {
		Local<Object> imageObj = args[0]->ToObject();
		Image* image = ObjectWrap::Unwrap<Image>(imageObj);
		double dx = args[1]->NumberValue();
		double dy = args[2]->NumberValue();

		obj->drawImage(image, dx, dy);
		NanReturnUndefined();
		return;
	}

	if(args.Length() == 5) {
		Local<Object> imageObj = args[0]->ToObject();
		Image* image = ObjectWrap::Unwrap<Image>(imageObj);
		double dx = args[1]->NumberValue();
		double dy = args[2]->NumberValue();
		double dw = args[3]->NumberValue();
		double dh = args[4]->NumberValue();

		obj->drawImage(image, dx, dy, dw, dh);
		NanReturnUndefined();
		return;
	}

	if(args.Length() == 9) {
		Local<Object> imageObj = args[0]->ToObject();
		Image* image = ObjectWrap::Unwrap<Image>(imageObj);
		double sx = args[1]->NumberValue();
		double sy = args[2]->NumberValue();
		double sw = args[3]->NumberValue();
		double sh = args[4]->NumberValue();
		double dx = args[5]->NumberValue();
		double dy = args[6]->NumberValue();
		double dw = args[7]->NumberValue();
		double dh = args[8]->NumberValue();

		obj->drawImage(image, sx, sy, sw, sh, dx, dy, dw, dh);
		NanReturnUndefined();
		return;
	}

}

NAN_METHOD(CanvasRenderingContext2dRect) {
	NanScope();
	if(args.Length() < 4) {
		printf("invalid arguments for rect.\n");
		return;
	}
	double x = args[0]->NumberValue();
	double y = args[1]->NumberValue();
	double w = args[2]->NumberValue();
	double h = args[3]->NumberValue();

	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());
	 obj->rect(x, y, w, h);
	NanReturnUndefined();
}

NAN_METHOD(CanvasRenderingContext2dMoveTo) {
	NanScope();
	if(args.Length() < 2) {
		printf("invalid arguments for moveTo.\n");
		return;
	}
	double x = args[0]->NumberValue();
	double y = args[1]->NumberValue();

	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());
	 obj->moveTo(x, y);
	NanReturnUndefined();
}

NAN_METHOD(CanvasRenderingContext2dLineTo) {
	NanScope();
	if(args.Length() < 2) {
		printf("invalid arguments for lineTo.\n");
		return;
	}
	double x = args[0]->NumberValue();
	double y = args[1]->NumberValue();

	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());
	 obj->lineTo(x, y);
	NanReturnUndefined();
}

NAN_METHOD(CanvasRenderingContext2dBezierCurveTo) {
	NanScope();
	if(args.Length() < 6) {
		printf("invalid arguments for bezierCurveTo.\n");
		return;
	}
	double cp1x = args[0]->NumberValue();
	double cp1y = args[1]->NumberValue();
	double cp2x = args[2]->NumberValue();
	double cp2y = args[3]->NumberValue();
	double x = args[4]->NumberValue();
	double y = args[5]->NumberValue();

	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());
	 obj->bezierCurveTo(cp1x, cp1y, cp2x, cp2y, x, y);
	NanReturnUndefined();
}

NAN_METHOD(CanvasRenderingContext2dQuadraticCurveTo) {
	NanScope();
	if(args.Length() < 4) {
		printf("invalid arguments for quadraticCurveTo.\n");
		return;
	}
	double cpx = args[0]->NumberValue();
	double cpy = args[1]->NumberValue();
	double x = args[2]->NumberValue();
	double y = args[3]->NumberValue();

	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());
	 obj->quadraticCurveTo(cpx, cpy, x, y);
	NanReturnUndefined();
}

NAN_METHOD(CanvasRenderingContext2dArcTo) {
	NanScope();
	if(args.Length() < 5) {
		printf("invalid arguments for arcTo.\n");
		return;
	}
	double x1 = args[0]->NumberValue();
	double y1 = args[1]->NumberValue();
	double x2 = args[2]->NumberValue();
	double y2 = args[3]->NumberValue();
	double r = args[4]->NumberValue();

	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());
	 obj->arcTo(x1, y1, x2, y2, r);
	NanReturnUndefined();
}

NAN_METHOD(CanvasRenderingContext2dArc) {
	NanScope();
	if(args.Length() < 6) {
		printf("invalid arguments for arc.\n");
		return;
	}
	double x = args[0]->NumberValue();
	double y = args[1]->NumberValue();
	double r = args[2]->NumberValue();
	double sAngle = args[3]->NumberValue();
	double eAngle = args[4]->NumberValue();
	bool counterClockWise = args[5]->BooleanValue();

	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());
	 obj->arc(x, y, r, sAngle, eAngle, counterClockWise);
	NanReturnUndefined();
}

NAN_GETTER(CanvasRenderingContext2dGetGlobalAlpha) {
	NanScope();
	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());
	NanReturnValue(NanNew<Number>(obj->getGlobalAlpha()));
}

NAN_SETTER(CanvasRenderingContext2dSetGlobalAlpha) {
	NanScope();
	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());
	if (value->IsNumber()) {
		double nativeValue = value->NumberValue();
		obj->setGlobalAlpha(nativeValue);
	}else{
		printf("invalid data type for CanvasRenderingContext2d.globalAlpha\n");
	}
}

NAN_GETTER(CanvasRenderingContext2dGetLineWidth) {
	NanScope();
	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());
	NanReturnValue(NanNew<Int32>(obj->getLineWidth()));
}

NAN_SETTER(CanvasRenderingContext2dSetLineWidth) {
	NanScope();
	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());
	if (value->IsInt32()) {
		int32_t nativeValue = value->Int32Value();
		obj->setLineWidth(nativeValue);
	}else{
		printf("invalid data type for CanvasRenderingContext2d.lineWidth\n");
	}
}

NAN_GETTER(CanvasRenderingContext2dGetGlobalCompositeOperation) {
	NanScope();
	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());
	NanReturnValue(NanNew<Int32>(obj->getGlobalCompositeOperation()));
}

NAN_SETTER(CanvasRenderingContext2dSetGlobalCompositeOperation) {
	NanScope();
	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());
	if (value->IsInt32()) {
		int32_t nativeValue = value->Int32Value();
		obj->setGlobalCompositeOperation(nativeValue);
	}else{
		printf("invalid data type for CanvasRenderingContext2d.globalCompositeOperation\n");
	}
}

NAN_GETTER(CanvasRenderingContext2dGetStrokeStyle) {
	NanScope();
	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());
	NanReturnValue(NanNew<String>(obj->getStrokeStyle()));
}

NAN_SETTER(CanvasRenderingContext2dSetStrokeStyle) {
	NanScope();
	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());
	if (value->IsString()) {
		v8::String::Utf8Value nativeValue(value);
		obj->setStrokeStyle(*nativeValue);
	}else{
		printf("invalid data type for CanvasRenderingContext2d.strokeStyle\n");
	}
}

NAN_GETTER(CanvasRenderingContext2dGetFillStyle) {
	NanScope();
	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());
	NanReturnValue(NanNew<String>(obj->getFillStyle()));
}

NAN_SETTER(CanvasRenderingContext2dSetFillStyle) {
	NanScope();
	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());
	if (value->IsString()) {
		v8::String::Utf8Value nativeValue(value);
		obj->setFillStyle(*nativeValue);
	}else{
		printf("invalid data type for CanvasRenderingContext2d.fillStyle\n");
	}
}

NAN_GETTER(CanvasRenderingContext2dGetFont) {
	NanScope();
	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());
	NanReturnValue(NanNew<String>(obj->getFont()));
}

NAN_SETTER(CanvasRenderingContext2dSetFont) {
	NanScope();
	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());
	if (value->IsString()) {
		v8::String::Utf8Value nativeValue(value);
		obj->setFont(*nativeValue);
	}else{
		printf("invalid data type for CanvasRenderingContext2d.font\n");
	}
}

NAN_GETTER(CanvasRenderingContext2dGetLineCap) {
	NanScope();
	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());
	NanReturnValue(NanNew<String>(obj->getLineCap()));
}

NAN_SETTER(CanvasRenderingContext2dSetLineCap) {
	NanScope();
	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());
	if (value->IsString()) {
		v8::String::Utf8Value nativeValue(value);
		obj->setLineCap(*nativeValue);
	}else{
		printf("invalid data type for CanvasRenderingContext2d.lineCap\n");
	}
}

NAN_GETTER(CanvasRenderingContext2dGetMiterLimit) {
	NanScope();
	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());
	NanReturnValue(NanNew<Number>(obj->getMiterLimit()));
}

NAN_SETTER(CanvasRenderingContext2dSetMiterLimit) {
	NanScope();
	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());
	if (value->IsNumber()) {
		double nativeValue = value->NumberValue();
		obj->setMiterLimit(nativeValue);
	}else{
		printf("invalid data type for CanvasRenderingContext2d.miterLimit\n");
	}
}

NAN_GETTER(CanvasRenderingContext2dGetTextBaseline) {
	NanScope();
	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());
	NanReturnValue(NanNew<String>(obj->getTextBaseline()));
}

NAN_SETTER(CanvasRenderingContext2dSetTextBaseline) {
	NanScope();
	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());
	if (value->IsString()) {
		v8::String::Utf8Value nativeValue(value);
		obj->setTextBaseline(*nativeValue);
	}else{
		printf("invalid data type for CanvasRenderingContext2d.textBaseline\n");
	}
}

NAN_GETTER(CanvasRenderingContext2dGetTextAlign) {
	NanScope();
	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());
	NanReturnValue(NanNew<String>(obj->getTextAlign()));
}

NAN_SETTER(CanvasRenderingContext2dSetTextAlign) {
	NanScope();
	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());
	if (value->IsString()) {
		v8::String::Utf8Value nativeValue(value);
		obj->setTextAlign(*nativeValue);
	}else{
		printf("invalid data type for CanvasRenderingContext2d.textAlign\n");
	}
}

NAN_GETTER(CanvasRenderingContext2dGetLineJoin) {
	NanScope();
	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());
	NanReturnValue(NanNew<String>(obj->getLineJoin()));
}

NAN_SETTER(CanvasRenderingContext2dSetLineJoin) {
	NanScope();
	CanvasRenderingContext2d* obj = ObjectWrap::Unwrap<CanvasRenderingContext2d>(args.This());
	if (value->IsString()) {
		v8::String::Utf8Value nativeValue(value);
		obj->setLineJoin(*nativeValue);
	}else{
		printf("invalid data type for CanvasRenderingContext2d.lineJoin\n");
	}
}



static Persistent<FunctionTemplate> constructor;
void CanvasRenderingContext2dInitBinding(Handle<Object> target) {
	NanScope();
	Local<FunctionTemplate> ctor = NanNew<FunctionTemplate>(newCanvasRenderingContext2d);
	NanAssignPersistent(constructor, ctor);
	ctor->InstanceTemplate()->SetInternalFieldCount(1);
	ctor->SetClassName(NanNew("CanvasRenderingContext2d"));
	Local<ObjectTemplate> proto = ctor->PrototypeTemplate();
	
	proto->SetAccessor(NanNew("globalAlpha"), CanvasRenderingContext2dGetGlobalAlpha, CanvasRenderingContext2dSetGlobalAlpha);
	proto->SetAccessor(NanNew("lineWidth"), CanvasRenderingContext2dGetLineWidth, CanvasRenderingContext2dSetLineWidth);
	proto->SetAccessor(NanNew("globalCompositeOperation"), CanvasRenderingContext2dGetGlobalCompositeOperation, CanvasRenderingContext2dSetGlobalCompositeOperation);
	proto->SetAccessor(NanNew("strokeStyle"), CanvasRenderingContext2dGetStrokeStyle, CanvasRenderingContext2dSetStrokeStyle);
	proto->SetAccessor(NanNew("fillStyle"), CanvasRenderingContext2dGetFillStyle, CanvasRenderingContext2dSetFillStyle);
	proto->SetAccessor(NanNew("font"), CanvasRenderingContext2dGetFont, CanvasRenderingContext2dSetFont);
	proto->SetAccessor(NanNew("lineCap"), CanvasRenderingContext2dGetLineCap, CanvasRenderingContext2dSetLineCap);
	proto->SetAccessor(NanNew("miterLimit"), CanvasRenderingContext2dGetMiterLimit, CanvasRenderingContext2dSetMiterLimit);
	proto->SetAccessor(NanNew("textBaseline"), CanvasRenderingContext2dGetTextBaseline, CanvasRenderingContext2dSetTextBaseline);
	proto->SetAccessor(NanNew("textAlign"), CanvasRenderingContext2dGetTextAlign, CanvasRenderingContext2dSetTextAlign);
	proto->SetAccessor(NanNew("lineJoin"), CanvasRenderingContext2dGetLineJoin, CanvasRenderingContext2dSetLineJoin);

	NAN_SET_PROTOTYPE_METHOD(ctor, "stroke", CanvasRenderingContext2dStroke);
	NAN_SET_PROTOTYPE_METHOD(ctor, "fill", CanvasRenderingContext2dFill);
	NAN_SET_PROTOTYPE_METHOD(ctor, "beginPath", CanvasRenderingContext2dBeginPath);
	NAN_SET_PROTOTYPE_METHOD(ctor, "closePath", CanvasRenderingContext2dClosePath);
	NAN_SET_PROTOTYPE_METHOD(ctor, "save", CanvasRenderingContext2dSave);
	NAN_SET_PROTOTYPE_METHOD(ctor, "restore", CanvasRenderingContext2dRestore);
	NAN_SET_PROTOTYPE_METHOD(ctor, "rotate", CanvasRenderingContext2dRotate);
	NAN_SET_PROTOTYPE_METHOD(ctor, "scale", CanvasRenderingContext2dScale);
	NAN_SET_PROTOTYPE_METHOD(ctor, "translate", CanvasRenderingContext2dTranslate);
	NAN_SET_PROTOTYPE_METHOD(ctor, "transform", CanvasRenderingContext2dTransform);
	NAN_SET_PROTOTYPE_METHOD(ctor, "resetTransform", CanvasRenderingContext2dResetTransform);
	NAN_SET_PROTOTYPE_METHOD(ctor, "clip", CanvasRenderingContext2dClip);
	NAN_SET_PROTOTYPE_METHOD(ctor, "clipRect", CanvasRenderingContext2dClipRect);
	NAN_SET_PROTOTYPE_METHOD(ctor, "fillText", CanvasRenderingContext2dFillText);
	NAN_SET_PROTOTYPE_METHOD(ctor, "strokeText", CanvasRenderingContext2dStrokeText);
	NAN_SET_PROTOTYPE_METHOD(ctor, "measureText", CanvasRenderingContext2dMeasureText);
	NAN_SET_PROTOTYPE_METHOD(ctor, "clearRect", CanvasRenderingContext2dClearRect);
	NAN_SET_PROTOTYPE_METHOD(ctor, "fillRect", CanvasRenderingContext2dFillRect);
	NAN_SET_PROTOTYPE_METHOD(ctor, "strokeRect", CanvasRenderingContext2dStrokeRect);
	NAN_SET_PROTOTYPE_METHOD(ctor, "drawImage", CanvasRenderingContext2dDrawImage);
	NAN_SET_PROTOTYPE_METHOD(ctor, "rect", CanvasRenderingContext2dRect);
	NAN_SET_PROTOTYPE_METHOD(ctor, "moveTo", CanvasRenderingContext2dMoveTo);
	NAN_SET_PROTOTYPE_METHOD(ctor, "lineTo", CanvasRenderingContext2dLineTo);
	NAN_SET_PROTOTYPE_METHOD(ctor, "bezierCurveTo", CanvasRenderingContext2dBezierCurveTo);
	NAN_SET_PROTOTYPE_METHOD(ctor, "quadraticCurveTo", CanvasRenderingContext2dQuadraticCurveTo);
	NAN_SET_PROTOTYPE_METHOD(ctor, "arcTo", CanvasRenderingContext2dArcTo);
	NAN_SET_PROTOTYPE_METHOD(ctor, "arc", CanvasRenderingContext2dArc);


	target->Set(NanNew("CanvasRenderingContext2d"), ctor->GetFunction());

}
