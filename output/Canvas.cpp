#include "Canvas.h"
Canvas::Canvas(){
}

Canvas::~Canvas(){
}


bool Canvas::init(int32_t type) {
}


int32_t Canvas::getWidth() const {
	return this->_width;
}

void Canvas::setWidth(int32_t width) {
	this->_width = width;
}


int32_t Canvas::getHeight() const {
	return this->_height;
}

void Canvas::setHeight(int32_t height) {
	this->_height = height;
}


int32_t Canvas::getType() const {
	return this->_type;
}

void Canvas::setType(int32_t type) {
	this->_type = type;
}


