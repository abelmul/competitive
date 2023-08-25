#include <stdio.h>
#include <stdlib.h>

size_t min(size_t x, size_t y) { return x > y ? y : x; }

size_t min3(size_t x, size_t y, size_t z) {
  return min(min(x, y), z);
}

int main() {
  char *line;
  size_t n = 0;
  int length, width, height;

  size_t front_perimeter, side_perimeter, up_perimeter, ribbon_size = 0;

  while (getline(&line, &n, stdin) > 0) {
    sscanf(line, "%dx%dx%d\n", &length, &width, &height);

    front_perimeter = 2 * (length + height);
    side_perimeter = 2 * (width + height);
    up_perimeter = 2 * (length + width);

    ribbon_size += min3(front_perimeter, side_perimeter, up_perimeter) + (length * width * height);
  }

  printf("total ribbon length %zu ft\n", ribbon_size);

  free(line);

  return 0;
}
