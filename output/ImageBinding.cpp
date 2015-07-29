#include "Image.h"

#include "ImageBinding.h"

NAN_METHOD(newImage) {
	NanScope();

	Image* obj = new Image();
	obj->Wrap(args.This());

	NanReturnValue(args.This());
}

NAN_METHOD(ImageLoad) {
	NanScope();
	Image* obj = ObjectWrap::Unwrap<Image>(args.This());

	if(args.Length() == 2) {
		v8::String::Utf8Value src(args[0]);
		NanCallback* onDone = new NanCallback(args[1].As<Function>());

		bool retVal = obj->load(*src, onDone);
		NanReturnValue(NanNew<Boolean>(retVal));
		return;
	}

}

NAN_METHOD(ImageUnload) {
	NanScope();
	Image* obj = ObjectWrap::Unwrap<Image>(args.This());

	if(args.Length() == 0) {

		bool retVal = obj->unload();
		NanReturnValue(NanNew<Boolean>(retVal));
		return;
	}

}

NAN_GETTER(ImageGetId) {
	NanScope();
	Image* obj = ObjectWrap::Unwrap<Image>(args.This());
	NanReturnValue(NanNew<Int32>(obj->getId()));
}

NAN_SETTER(ImageSetId) {
	NanScope();
	Image* obj = ObjectWrap::Unwrap<Image>(args.This());
	if (value->IsInt32()) {
		int32_t nativeValue = value->Int32Value();
		obj->setId(nativeValue);
	}else{
		printf("invalid data type for Image.id\n");
	}
}

NAN_GETTER(ImageGetSrc) {
	NanScope();
	Image* obj = ObjectWrap::Unwrap<Image>(args.This());
	NanReturnValue(NanNew<String>(obj->getSrc()));
}

NAN_SETTER(ImageSetSrc) {
	NanScope();
	Image* obj = ObjectWrap::Unwrap<Image>(args.This());
	if (value->IsString()) {
		v8::String::Utf8Value nativeValue(value);
		obj->setSrc(*nativeValue);
	}else{
		printf("invalid data type for Image.src\n");
	}
}

NAN_GETTER(ImageGetWidth) {
	NanScope();
	Image* obj = ObjectWrap::Unwrap<Image>(args.This());
	NanReturnValue(NanNew<Int32>(obj->getWidth()));
}

NAN_SETTER(ImageSetWidth) {
	NanScope();
	Image* obj = ObjectWrap::Unwrap<Image>(args.This());
	if (value->IsInt32()) {
		int32_t nativeValue = value->Int32Value();
		obj->setWidth(nativeValue);
	}else{
		printf("invalid data type for Image.width\n");
	}
}

NAN_GETTER(ImageGetHeight) {
	NanScope();
	Image* obj = ObjectWrap::Unwrap<Image>(args.This());
	NanReturnValue(NanNew<Int32>(obj->getHeight()));
}

NAN_SETTER(ImageSetHeight) {
	NanScope();
	Image* obj = ObjectWrap::Unwrap<Image>(args.This());
	if (value->IsInt32()) {
		int32_t nativeValue = value->Int32Value();
		obj->setHeight(nativeValue);
	}else{
		printf("invalid data type for Image.height\n");
	}
}



static Persistent<FunctionTemplate> constructor;
void ImageInitBinding(Handle<Object> target) {
	NanScope();
	Local<FunctionTemplate> ctor = NanNew<FunctionTemplate>(newImage);
	NanAssignPersistent(constructor, ctor);
	ctor->InstanceTemplate()->SetInternalFieldCount(1);
	ctor->SetClassName(NanNew("Image"));
	Local<ObjectTemplate> proto = ctor->PrototypeTemplate();
	
	proto->SetAccessor(NanNew("id"), ImageGetId, ImageSetId);
	proto->SetAccessor(NanNew("src"), ImageGetSrc, ImageSetSrc);
	proto->SetAccessor(NanNew("width"), ImageGetWidth, ImageSetWidth);
	proto->SetAccessor(NanNew("height"), ImageGetHeight, ImageSetHeight);

	NAN_SET_PROTOTYPE_METHOD(ctor, "load", ImageLoad);
	NAN_SET_PROTOTYPE_METHOD(ctor, "unload", ImageUnload);


	target->Set(NanNew("Image"), ctor->GetFunction());

}
