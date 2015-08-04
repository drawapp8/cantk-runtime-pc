#include "Screen.h"
Screen::Screen(){
}

Screen::~Screen(){
}



int32_t Screen::getColorDepth() const {
	return this->_colorDepth;
}

void Screen::setColorDepth(int32_t colorDepth) {
	this->_colorDepth = colorDepth;
}


int32_t Screen::getPixelDepth() const {
	return this->_pixelDepth;
}

void Screen::setPixelDepth(int32_t pixelDepth) {
	this->_pixelDepth = pixelDepth;
}


int32_t Screen::getAvailLeft() const {
	return this->_availLeft;
}

void Screen::setAvailLeft(int32_t availLeft) {
	this->_availLeft = availLeft;
}


int32_t Screen::getAvailTop() const {
	return this->_availTop;
}

void Screen::setAvailTop(int32_t availTop) {
	this->_availTop = availTop;
}


int32_t Screen::getAvailWidth() const {
	return this->_availWidth;
}

void Screen::setAvailWidth(int32_t availWidth) {
	this->_availWidth = availWidth;
}


int32_t Screen::getAvailHeight() const {
	return this->_availHeight;
}

void Screen::setAvailHeight(int32_t availHeight) {
	this->_availHeight = availHeight;
}


int32_t Screen::getWidth() const {
	return this->_width;
}

void Screen::setWidth(int32_t width) {
	this->_width = width;
}


int32_t Screen::getHeight() const {
	return this->_height;
}

void Screen::setHeight(int32_t height) {
	this->_height = height;
}


