#include <stdio.h>
#include "./libhello.c"

int main(int argc,char **argv){
	for(int i=1;i<argc;i++){
        printHello(argv[i]);
    }
    return 0;
}