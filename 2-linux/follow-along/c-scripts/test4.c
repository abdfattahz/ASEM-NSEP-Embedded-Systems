#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
  char buffer[1024];
  FILE *fp = popen("df | grep /dev/sda2 | awk '{print $5}'", "r");

  if(fp == NULL) {
    perror("popen");
    return 1;
  }

  while(fgets(buffer, sizeof(buffer), fp) != NULL) {
    buffer[strcspn(buffer, "\n")] = '\0';
    
    int used = atoi(buffer);
    int free_space = 100 - used;

    printf("There are: %d%% free space", free_space);
  }

  pclose(fp);
  return 0;
}

