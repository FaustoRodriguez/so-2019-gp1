#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int forever=1;

void signalHandler(int sgn){
	printf("Received signal:%d\n",sgn);
	forever=0;
}

int main(){
	int pid;
	signal(10,signalHandler);
	pid = fork();
	if(pid == 0){
		//Soy el hijo del papá
		signal(10,signalHandler);
		//Codigo hijo
		printf("Soy el proceso hijo\n");
		while(forever){};
		printf("Saliendo del ciclo infinito\n");
	}else{
		printf("Soy el proceso padre y mi hijo es: %d\n",pid);
		sleep(5);
		kill(pid,10);
		//Codigo padre
		for(;;){}
	}
}