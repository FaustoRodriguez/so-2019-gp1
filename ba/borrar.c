#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc,char **argv){
	char *name = argv[1];
	char *pwd = getcwd(NULL, 0);
	char path[strlen(name)+strlen(pwd)+2];
	sprintf(path, "%s/%s",pwd,name);
	int borrar=unlink(path);
    return 0;
}