#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_vowel(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int is_unallowed(char first, char second) {
  if ((first == 'a' && second == 'b') || (first == 'c' && second == 'd') ||
      (first == 'p' && second == 'q') || (first == 'x' && second == 'y')) {
    return 1;
  }

  return 0;
}

int main() {
  char *line, *ptr;
  size_t n = 0;
  int vowels, contains_double, contains_unallowed, nice_strings = 0;

  while (getline(&line, &n, stdin) > 0) {
    vowels = 0;
    contains_double = 0;
    contains_unallowed = 0;

    // remove \n
    line[strlen(line) - 1] = '\0';

    // if the string only contains 1 character it is not nice
    if (line[1] == '\0') {
      continue;
    }

    ptr = line;

    do {
      if (is_vowel(*ptr)) {
        ++vowels;
      }

      ++ptr;

      if (is_unallowed(*(ptr-1), *ptr) == 1) {
        contains_unallowed = 1;
        break;
      }

      if (contains_double == 0 && *ptr == *(ptr - 1)) {
        contains_double = 1;
      }
    } while (*ptr != '\0');

    if (contains_unallowed == 0 && vowels >= 3 && contains_double == 1) {
      ++nice_strings;
    }
  }

  printf("%d nice strings in input\n", nice_strings);

  free(line);

  return 0;
}
