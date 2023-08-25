#include <stdio.h>
#include <stdlib.h>

int main() {
  char *line, *ptr;
  size_t n = 0;
  int floor = 0;

  if (getline(&line, &n, stdin) < 0) {
    perror("can't get line");
    exit(EXIT_FAILURE);
  }

  ptr = line;
  while(*ptr != '\0') {
    switch(*ptr) {
      case '(':
        ++floor;
        break;
      case ')':
        --floor;
        break;
    }
    if (floor == -1)
      break;
    ++ptr;
  }

  printf("%ld\n", ptr-line+1);

  free(line);

  return 0;
}
