#include "CanvasRenderingContext2d.h"
CanvasRenderingContext2d::CanvasRenderingContext2d(){
}

CanvasRenderingContext2d::~CanvasRenderingContext2d(){
}


void CanvasRenderingContext2d::stroke() {
}

void CanvasRenderingContext2d::fill() {
}

void CanvasRenderingContext2d::beginPath() {
}

void CanvasRenderingContext2d::closePath() {
}

void CanvasRenderingContext2d::save() {
}

void CanvasRenderingContext2d::restore() {
}

void CanvasRenderingContext2d::rotate(double angle) {
}

void CanvasRenderingContext2d::scale(double x, double y) {
}

void CanvasRenderingContext2d::translate(double x, double y) {
}

void CanvasRenderingContext2d::transform(double a, double b, double c, double d, double e, double f) {
}

void CanvasRenderingContext2d::resetTransform() {
}

void CanvasRenderingContext2d::clip() {
}

void CanvasRenderingContext2d::clipRect(double x, double y, double w, double h) {
}

void CanvasRenderingContext2d::fillText(const char* text, double x, double y) {
}

void CanvasRenderingContext2d::strokeText(const char* text, double x, double y) {
}

double CanvasRenderingContext2d::measureText(const char* text) {
}

void CanvasRenderingContext2d::clearRect(double x, double y, double w, double h) {
}

void CanvasRenderingContext2d::fillRect(double x, double y, double w, double h) {
}

void CanvasRenderingContext2d::strokeRect(double x, double y, double w, double h) {
}

void CanvasRenderingContext2d::drawImage(Image* image, double dx, double dy) {
}

void CanvasRenderingContext2d::drawImage(Image* image, double dx, double dy, double dw, double dh) {
}

void CanvasRenderingContext2d::drawImage(Image* image, double sx, double sy, double sw, double sh, double dx, double dy, double dw, double dh) {
}

void CanvasRenderingContext2d::rect(double x, double y, double w, double h) {
}

void CanvasRenderingContext2d::moveTo(double x, double y) {
}

void CanvasRenderingContext2d::lineTo(double x, double y) {
}

void CanvasRenderingContext2d::bezierCurveTo(double cp1x, double cp1y, double cp2x, double cp2y, double x, double y) {
}

void CanvasRenderingContext2d::quadraticCurveTo(double cpx, double cpy, double x, double y) {
}

void CanvasRenderingContext2d::arcTo(double x1, double y1, double x2, double y2, double r) {
}

void CanvasRenderingContext2d::arc(double x, double y, double r, double sAngle, double eAngle, bool counterClockWise) {
}


double CanvasRenderingContext2d::getGlobalAlpha() const {
	return this->_globalAlpha;
}

void CanvasRenderingContext2d::setGlobalAlpha(double globalAlpha) {
	this->_globalAlpha = globalAlpha;
}


int32_t CanvasRenderingContext2d::getLineWidth() const {
	return this->_lineWidth;
}

void CanvasRenderingContext2d::setLineWidth(int32_t lineWidth) {
	this->_lineWidth = lineWidth;
}


int32_t CanvasRenderingContext2d::getGlobalCompositeOperation() const {
	return this->_globalCompositeOperation;
}

void CanvasRenderingContext2d::setGlobalCompositeOperation(int32_t globalCompositeOperation) {
	this->_globalCompositeOperation = globalCompositeOperation;
}


string CanvasRenderingContext2d::getStrokeStyle() const {
	return this->_strokeStyle;
}

void CanvasRenderingContext2d::setStrokeStyle(string strokeStyle) {
	this->_strokeStyle = strokeStyle;
}


string CanvasRenderingContext2d::getFillStyle() const {
	return this->_fillStyle;
}

void CanvasRenderingContext2d::setFillStyle(string fillStyle) {
	this->_fillStyle = fillStyle;
}


string CanvasRenderingContext2d::getFont() const {
	return this->_font;
}

void CanvasRenderingContext2d::setFont(string font) {
	this->_font = font;
}


string CanvasRenderingContext2d::getLineCap() const {
	return this->_lineCap;
}

void CanvasRenderingContext2d::setLineCap(string lineCap) {
	this->_lineCap = lineCap;
}


double CanvasRenderingContext2d::getMiterLimit() const {
	return this->_miterLimit;
}

void CanvasRenderingContext2d::setMiterLimit(double miterLimit) {
	this->_miterLimit = miterLimit;
}


string CanvasRenderingContext2d::getTextBaseline() const {
	return this->_textBaseline;
}

void CanvasRenderingContext2d::setTextBaseline(string textBaseline) {
	this->_textBaseline = textBaseline;
}


string CanvasRenderingContext2d::getTextAlign() const {
	return this->_textAlign;
}

void CanvasRenderingContext2d::setTextAlign(string textAlign) {
	this->_textAlign = textAlign;
}


string CanvasRenderingContext2d::getLineJoin() const {
	return this->_lineJoin;
}

void CanvasRenderingContext2d::setLineJoin(string lineJoin) {
	this->_lineJoin = lineJoin;
}


