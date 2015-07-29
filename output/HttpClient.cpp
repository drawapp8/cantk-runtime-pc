#include "HttpClient.h"
HttpClient::HttpClient(){
}

HttpClient::~HttpClient(){
}


bool HttpClient::send(NanCallback*  onProgress, NanCallback*  onDone) {
}


string HttpClient::getUrl() const {
	return this->_url;
}

void HttpClient::setUrl(string url) {
	this->_url = url;
}


string HttpClient::getReturnType() const {
	return this->_returnType;
}

void HttpClient::setReturnType(string returnType) {
	this->_returnType = returnType;
}


string HttpClient::getMethod() const {
	return this->_method;
}

void HttpClient::setMethod(string method) {
	this->_method = method;
}


string HttpClient::getRequestHeaders() const {
	return this->_requestHeaders;
}

void HttpClient::setRequestHeaders(string requestHeaders) {
	this->_requestHeaders = requestHeaders;
}


string HttpClient::getRequestData() const {
	return this->_requestData;
}

void HttpClient::setRequestData(string requestData) {
	this->_requestData = requestData;
}


int32_t HttpClient::getStatus() const {
	return this->_status;
}

void HttpClient::setStatus(int32_t status) {
	this->_status = status;
}


string HttpClient::getStatusText() const {
	return this->_statusText;
}

void HttpClient::setStatusText(string statusText) {
	this->_statusText = statusText;
}


string HttpClient::getResponseHeaders() const {
	return this->_responseHeaders;
}

void HttpClient::setResponseHeaders(string responseHeaders) {
	this->_responseHeaders = responseHeaders;
}


string HttpClient::getResponseText() const {
	return this->_responseText;
}

void HttpClient::setResponseText(string responseText) {
	this->_responseText = responseText;
}


