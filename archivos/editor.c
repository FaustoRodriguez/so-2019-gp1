#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void writeWord(int file,char *word){
	write(file, word, strlen(word));
	write(file, " ", 1);
}

int main(int argc, char **argv){
	char *fileName = argv[1];
        char *old = argv[2];
        char *new = argv[3];
        char word[100];
	char c;
	int i=0;
	int fd = open(fileName,O_RDONLY);
	int temp= open("tmp.txt",O_WRONLY | O_CREAT, 0666);
	while(read(fd, &c, 1)){
		if(c != ' '){
			word[i++] = c;
		}
		else {
			word[i++] = c;
			word[i] = '\0';
			i=0;
                        if (!strcmp(old, word)) {
                          writeWord(temp, new);
                        } else {
                          writeWord(temp, word);
                        }
                }
	}
	word[i] = '\0';
        if (!strcmp(word, old)) {
          writeWord(temp, new);
        } else {
          writeWord(temp, word);
        }
        close(temp);
	close(fd);
	unlink(fileName);
	link("tmp.txt", fileName);
	unlink("tmp.txt");
	return 0;
}