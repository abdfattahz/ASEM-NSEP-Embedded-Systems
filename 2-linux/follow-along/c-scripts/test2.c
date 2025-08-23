#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main () {
  char buffer[1024];
  FILE *fp = popen("ls -l *.sh", "r");
  uint32_t count = 0;

  if(fp == NULL) {
    perror("popen");
    return 1;
  }

  while(fgets(buffer, sizeof(buffer), fp) != NULL) {
    count++;
    printf("OUTPUT: %s ", buffer);
  }

  printf("There are: %u .sh files here \n", count);

  pclose(fp);
  return 0;
}

