#include <stdio.h>

int main() {
  int numP;
  scanf("%d\n", &numP);
  int numAnt = numP;
  fprintf(stderr, "%d\n", numP);
  while (1) {
    int num;
    scanf("%d\n", &num);
    if (num == numAnt) {
      break;
    }
    if (num % numP != 0) {
      printf("%d\n", num);
    }
	numAnt=num;
  }
}