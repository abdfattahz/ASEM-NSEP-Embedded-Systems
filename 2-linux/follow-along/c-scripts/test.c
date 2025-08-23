#include <stdio.h>
#include <stdlib.h>

int main () {
  char buffer[1024];
  FILE *fp = popen("ls -l", "r");

  if(fp == NULL) {
    perror("popen");
    return 1;
  }

  while(fgets(buffer, sizeof(buffer), fp) != NULL) {
  printf("OUTPUT: %s", buffer);
  }

  pclose(fp);
  return 0;
}

