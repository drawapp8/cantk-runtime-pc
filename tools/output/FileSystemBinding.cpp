#include "FileSystem.h"

#include "FileSystemBinding.h"

NAN_METHOD(newFileSystem) {
	NanScope();

	FileSystem* obj = new FileSystem();
	obj->Wrap(args.This());

	NanReturnValue(args.This());
}

NAN_METHOD(FileSystemReadAsText) {
	NanScope();
	FileSystem* obj = ObjectWrap::Unwrap<FileSystem>(args.This());

	if(args.Length() == 1) {
		v8::String::Utf8Value src(args[0]);

		string retVal = obj->readAsText(*src);
		NanReturnValue(NanNew<String>(retVal.c_str()));
		return;
	}

}

NAN_GETTER(FileSystemGetCwd) {
	NanScope();
	FileSystem* obj = ObjectWrap::Unwrap<FileSystem>(args.This());
	NanReturnValue(NanNew<String>(obj->getCwd()));
}

NAN_SETTER(FileSystemSetCwd) {
	NanScope();
	FileSystem* obj = ObjectWrap::Unwrap<FileSystem>(args.This());
	if (value->IsString()) {
		v8::String::Utf8Value nativeValue(value);
		obj->setCwd(*nativeValue);
	}else{
		printf("invalid data type for FileSystem.cwd\n");
	}
}



static Persistent<FunctionTemplate> constructor;
void FileSystemInitBinding(Handle<Object> target) {
	NanScope();
	Local<FunctionTemplate> ctor = NanNew<FunctionTemplate>(newFileSystem);
	NanAssignPersistent(constructor, ctor);
	ctor->InstanceTemplate()->SetInternalFieldCount(1);
	ctor->SetClassName(NanNew("FileSystem"));
	Local<ObjectTemplate> proto = ctor->PrototypeTemplate();
	
	proto->SetAccessor(NanNew("cwd"), FileSystemGetCwd, FileSystemSetCwd);

	NAN_SET_PROTOTYPE_METHOD(ctor, "readAsText", FileSystemReadAsText);


	target->Set(NanNew("FileSystem"), ctor->GetFunction());

}
