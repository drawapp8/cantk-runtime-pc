#include "FileSystem.h"
FileSystem::FileSystem(){
}

FileSystem::~FileSystem(){
}


string FileSystem::readAsText(const char* src) {
}


string FileSystem::getCwd() const {
	return this->_cwd;
}

void FileSystem::setCwd(string cwd) {
	this->_cwd = cwd;
}


