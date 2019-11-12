#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc,char **argv){
	char *newName = argv[2];
	char *oldName = argv[1];
	char *pwd = getcwd(NULL, 0);
	char pathOld[strlen(oldName)+strlen(pwd)+2];
	char pathNew[strlen(newName)+strlen(pwd)+2];
	sprintf(pathOld, "%s/%s",pwd,oldName);
	sprintf(pathNew, "%s/%s",pwd,newName);
    int cambiar=link(pathOld,pathNew);
	int borrar=unlink(pathOld);
    return 0;
}