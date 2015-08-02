
window.timerID = 0;
window.tickTime = 0;
window.timerFuncs = {};
window.intervalFuncs = {};
window.requestAnimationFrameFuncs = {};

function setTimeout(callback, duration) {
	if(!callback) return;

	var id = window.timerID++;
	var info = {id:id, callback:callback};

	info.timeout = window.tickTime + duration/1000;

	window.timerFuncs[id] = info;

	return id;
}

function clearTimeout(id) {
	delete window.timerFuncs[id];
}

function setInterval(callback, duration) {
	if(!callback) return;

	var id = window.timerID++;
	var info = {id:id, callback:callback};

	info.duration = duration/1000;
	info.timeout = window.tickTime + info.duration;

	window.intervalFuncs[id] = info;

	return id;
}

function clearInterval(id) {
	delete window.intervalFuncs[id];
}

function requestAnimationFrame(callback) {
	if(!callback) return;

	var id = window.timerID++;
	window.requestAnimationFrameFuncs[id] = callback;

	return id;
}

function cancelRequestAnimationFrame(id) {
	delete window.requestAnimationFrameFuncs[id];
}

function tick(t, dt) {
	tick.time = t;
	tick.deltaTime = dt;
	window.tickTime = t;

	var arr = window.requestAnimationFrameFuncs;
	window.requestAnimationFrameFuncs = {};
	for(var id in arr) {
		var callback = arr[id];
		if(callback) {
			callback.call(window);
		}
	}
	arr.length = 0;

	arr = window.timerFuncs;
	window.timerFuncs = {};
	for(var id in arr) {
		var info = arr[id];
		if(info.timeout <= t) {
			var callback = info.callback;
			callback.call(window);
		}
		else {
			window.timerFuncs[id] = info;
		}
	}
	arr.length = 0;

	arr = window.intervalFuncs;
	for(var id in arr) {
		var info = arr[id];
		if(info.timeout <= t) {
			var callback = info.callback;
			callback.call(window);
			info.timeout += info.duration;
		}
	}

	return;
}

//////////////////////////////////////////////////////////

function console() {
}

console.log = function(str) {
	print(str);
}

window.console = console;
window.setTimeout = setTimeout;
window.clearTimeout = clearTimeout;
window.setInterval = setInterval;
window.clearInterval = clearInterval;
window.requestAnimationFrame = requestAnimationFrame;
window.cancelRequestAnimationFrame = cancelRequestAnimationFrame;

function document() {
}

document.createCanvas = function(type) {
	var canvas = new Canvas();

	canvas.ctx2d = new CanvasRenderingContext2d();
	canvas.style = {};
	canvas.getContext = function(type) {
		return this.ctx2d;
	}

	canvas.addEventListener = function(name, callback, capture) {
		//TOOD
	}

	return canvas;
}

DummyElement = function() {
	this.style = {};
}

DummyElement.prototype.appendChild = function(child) {
	console.log("appendChild");
}

DummyElement.prototype.removeChild = function(child) {
	console.log("removeChild");
}

document.createElement = function(tag) {
	if(tag === "canvas") {
		return document.createCanvas();
	}
	else {
		return new DummyElement();
	}
}

document.head = document.createElement('head');
document.body = document.createElement('body');

document.getElementById = function(id) {
	return null;
}

document.createElementNS = function(ns) {
	return {};
}

document.getElementsByTagName = function(tagName) {
	var tag = null;
	if(tagName === 'head') {
		tag = document.head;
	}
	else if(tagName === 'body') {
		tag = document.body;
	}

	return [tag];
}

document.getViewPort = function(){
	return {width:480, height:800};
}

document.documentElement = {tagName:"HTML", style:{}};

window.document = document;

var ACTION_UP = 0;
var ACTION_DOWN = 1;
var ACTION_REPEAT = 2;
var ACTION_MOVE = 3;

window.eventListeners = {};

function addEventListener(name, callback, capture) {
	var callbacks = window.eventListeners[name];

	if(!callbacks) {
		callbacks = [];
		window.eventListeners[name] = callbacks;
	}

	if(callback) {
		callbacks.push({callback:callback, capture:capture});
	}

	return;
}

function removeEventListener(name, callback, capture) {
	var callbacks = window.eventListeners[name];

	if(callbacks) {
		for(var i = 0; i < callbacks.length; i++) {
			var iter = callbacks[i];
			if(iter && iter.callback === callback && iter.capture === capture) {
				callbacks.splice(i, 1);
			}
		}
	}

	return;
}

function dispatchEvent(event) {
	var name = event.name;
	var callbacks = window.eventListeners[name];

	if(callbacks) {
		var n = callbacks.length;

		//FIXME
		for(var i = 0; i < n; i++) {
			var iter = callbacks[i];
			var callback = iter.callback;
			if(iter.capture) {
				var ret = callback.call(window, event);
				if(!ret) break;
			}
		}

		n = callbacks.length;
		for(var i = n-1; i >= 0; i--) {
			var iter = callbacks[i];
			var callback = iter.callback;
			if(!iter.capture) {
				callback.call(window, event);
			}
		}
	}

	return;
}

window.dispatchEvent = dispatchEvent;
window.addEventListener = document.addEventListener = addEventListener;
window.removeEventListener = document.removeEventListener = removeEventListener;


function XMLHttpRequest() {
	this.requestHeaders = {};
	this.readyState = XMLHttpRequest.Uninitialized;
}

XMLHttpRequest.Uninitialized = 0;
XMLHttpRequest.Open = 1;
XMLHttpRequest.Sent = 2;
XMLHttpRequest.Receiving = 3;
XMLHttpRequest.Loaded = 4;

XMLHttpRequest.prototype.getAllResponseHeaders = function() {
	return this.respHeaders;
}

XMLHttpRequest.prototype.getResponseHeader = function(name) {
	var headers = this.respHeaders;
	if(!headers) return null;

	var n = headers.length;
	for(var i = 0; i < n; i++) {
		var iter = headers[i];
		if(iter.name === name) return iter.value;
	}

	return null;
}

XMLHttpRequest.prototype.setReadyState = function(readyState) {
	var httpClient = this.httpClient;
	this.readyState = readyState;

	if(readyState === XMLHttpRequest.Loaded) {
		this.status = httpClient.status;
		this.statusText = httpClient.statusText;
		this.responseText = httpClient.responseText;

		try {
			this.respHeaders = JSON.parse(httpClient.responseHeaders);
		}
		catch(e) {
			console.log("parse header failed:" + httpClient.responseHeaders);
		}

		this.httpClient = null;
	}

	if(this.onreadystatechange) {
		try {
			this.onreadystatechange();
		}catch(e) {
			console.log("onreadystatechange:" + e.message);
		}
	}

	return;
}

XMLHttpRequest.prototype.open = function(method, url, async, username, password) {
	var httpClient = new HttpClient();
	
	httpClient.url = url;
	httpClient.method = method;

	this.url = url;
	this.status = 0;
	this.statusText = "";
	this.responseText = "";
	this.respHeaders = [];
	this.requestHeaders = {};

	this.httpClient = httpClient;
	this.setReadyState(XMLHttpRequest.Open);

	return;
}

XMLHttpRequest.prototype.overrideMimeType = function(mimeType) {
}

XMLHttpRequest.prototype.send = function(body) {
	if(this.url.indexOf("http://") >= 0) {
		this.sendToRemote(body);
	}
	else {
		this.sendToLocal(body);
	}
}

XMLHttpRequest.prototype.sendToLocal = function(body) {
	this.httpClient = {};

	this.setReadyState(XMLHttpRequest.Sent);
	var text = window.fs.readAsText(this.url);
	this.setReadyState(XMLHttpRequest.Receiving);
	
	this.httpClient.status = 200;
	this.httpClient.statusText = "200 OK";
	this.httpClient.responseText = text;

	console.log(text.length);
	this.setReadyState(XMLHttpRequest.Loaded);
}

XMLHttpRequest.prototype.sendToRemote = function(body) {
	var me = this;
	var httpClient = this.httpClient;
	var requestHeaders = this.requestHeaders;

	var requestHeaderStr = "";
	for(var name in requestHeaders) {
		var value = requestHeaders[name];

		requestHeaderStr += name + ":" + value + "\r\n";
	}

	httpClient.requestHeaders = requestHeaderStr;
	httpClient.requestData = body ? body : "";

	httpClient.send(function onProgress(message, info) {
		me.setReadyState(XMLHttpRequest.Receiving);
	}, function onDone() {
		me.setReadyState(XMLHttpRequest.Loaded);
	});

	this.setReadyState(XMLHttpRequest.Sent);

	return;
}

XMLHttpRequest.prototype.abort = function() {
	this.onreadystatechange = null;
	return;
}

XMLHttpRequest.prototype.setRequestHeader = function(name, value) {
	this.requestHeaders[name] = value;

	return;
}

/////////////////////////////////////////////////////////
function navigator() {
}

navigator.language = "zh-CN";
navigator.userAgent = "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.65 Safari/537.36";
navigator.appVersion = "5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.65 Safari/537.36";

var location = {};
location.href = "/";
location.path = "/";
location.host = "localhost";
location.protocol = "http";
location.search = "";
document.location = location;

window.location = location;

window.fs = new FileSystem();

setTimeout(function() {	
	if(window.onload) {
		window.onload();
	}
	window.dispatchEvent({name:"load"});
}, 0);

//require("./app-cantk.js");
//require("./app-lwf.js");
require("./app-test.js");

