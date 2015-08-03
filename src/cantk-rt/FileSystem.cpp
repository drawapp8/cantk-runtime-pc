#include <unistd.h>
#include "FileSystem.h"
FileSystem::FileSystem(){
}

FileSystem::~FileSystem(){
}


bool FileSystem::readAsText(const char* name, char** ret, int* length) {
  FILE* file = fopen(name, "rb");
  if (file == NULL) {
  	printf("open file failed: %s\n", name);
  	return false;
  }
  printf("open file ok: %s\n", name);

  fseek(file, 0, SEEK_END);
  int size = ftell(file);
  rewind(file);

  char* chars = new char[size + 1];
  chars[size] = '\0';
  for (int i = 0; i < size;) {
    int read = static_cast<int>(fread(&chars[i], 1, size - i, file));
    i += read;
  }
  fclose(file);

  *ret = chars;
  *length = size;
  printf("%d\n", size);
  return true;
}

string FileSystem::getCwd() const {
	char cwd[1024] = {0};
	getcwd(cwd, sizeof(cwd));

	return string(cwd);
}

void FileSystem::setCwd(string cwd) {
	chdir(cwd.c_str());
}


