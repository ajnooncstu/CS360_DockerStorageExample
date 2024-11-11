#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

int main (int argc, char *argv[]) {
    FILE *output;
    char hostname[HOST_NAME_MAX + 1];
    if (argc == 1) {
      printf("No file argument\n");
      return -1;
    }
    gethostname(hostname, HOST_NAME_MAX + 1);

    for (int i = 0; i < 50; i++) {
      output = fopen(argv[1], "a+");
      fprintf(output, "Host: %s\tLoop number %i\n", hostname, i);
      fclose(output);
      sleep(1);
    }
}
