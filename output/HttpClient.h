#ifndef _HTTPCLIENT_H
#define _HTTPCLIENT_H

#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <v8.h>
#include <nan/nan.h>

using namespace std;
using namespace v8;


class HttpClient: public ObjectWrap {
public:
	HttpClient();
	~HttpClient();

	bool send(NanCallback*  onProgress, NanCallback*  onDone);

	string getUrl() const;
	void setUrl(string url);

	string getReturnType() const;
	void setReturnType(string returnType);

	string getMethod() const;
	void setMethod(string method);

	string getRequestHeaders() const;
	void setRequestHeaders(string requestHeaders);

	string getRequestData() const;
	void setRequestData(string requestData);

	int32_t getStatus() const;
	void setStatus(int32_t status);

	string getStatusText() const;
	void setStatusText(string statusText);

	string getResponseHeaders() const;
	void setResponseHeaders(string responseHeaders);

	string getResponseText() const;
	void setResponseText(string responseText);

private:
	string _url;
	string _returnType;
	string _method;
	string _requestHeaders;
	string _requestData;
	int32_t _status;
	string _statusText;
	string _responseHeaders;
	string _responseText;
};

#endif
