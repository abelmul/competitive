#include <openssl/md5.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// you need to provide -lcrypto to the compiler

// note that digest must have space available for md5 must be MD5_DIGEST_LENGTH
void compute_md5(char *str, unsigned char *md5) {
  MD5_CTX ctx;
  MD5_Init(&ctx);
  MD5_Update(&ctx, str, strlen(str));
  MD5_Final(md5, &ctx);
}

int check_6zeros(unsigned char *md5) {
  // for 5 zeros we can do (0x0f & md5[2]) == md5[2]
  return md5[0] == 0 && md5[1] == 0 && md5[2] == 0;
}

int main() {
  unsigned char md5[MD5_DIGEST_LENGTH];
  char *line, *buffer;
  size_t n = 0, len;
  int number = 0;

  buffer = calloc(100, 1);

  if (getline(&line, &n, stdin) < 0) {
    perror("can't get line");
    exit(EXIT_FAILURE);
  }

  len = strlen(line);
  line[len - 1] = '\0';

  // can we circumvent this?
  do {
    sprintf(buffer, "%s%d", line, number);

    compute_md5(buffer, md5);

    ++number;
  } while (check_6zeros(md5) != 1);

  printf("found number %d\n", number - 1);

  free(line);

  return 0;
}
