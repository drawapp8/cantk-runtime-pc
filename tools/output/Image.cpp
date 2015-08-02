#include "Image.h"
Image::Image(){
}

Image::~Image(){
}


bool Image::load(const char* src, NanCallback*  onDone) {
}

bool Image::unload() {
}


int32_t Image::getId() const {
	return this->_id;
}

void Image::setId(int32_t id) {
	this->_id = id;
}


string Image::getSrc() const {
	return this->_src;
}

void Image::setSrc(string src) {
	this->_src = src;
}


int32_t Image::getWidth() const {
	return this->_width;
}

void Image::setWidth(int32_t width) {
	this->_width = width;
}


int32_t Image::getHeight() const {
	return this->_height;
}

void Image::setHeight(int32_t height) {
	this->_height = height;
}


