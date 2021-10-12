#include "readfile.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFLEN 1024

struct freader
{
  int fd;
};

char *read_transactions(char *fname)
{
  char err_msg[] = { "failed to open file "};
  strncat(err_msg, fname, strlen(fname));

  if (access(fname, F_OK)) {
    perror(err_msg);
    exit(EXIT_FAILURE);
  }

  int fd = open(fname, O_RDONLY | R_OK);

  if (fd == -1) {
    perror(err_msg);
    exit(EXIT_FAILURE);
  }

  file_reader_t reader = { .fd = fd };

  char buf[BUFLEN];
  char *c = calloc(sizeof(char *), sizeof(char *));
  while (read(reader.fd, c, sizeof(char *)) > 0) {
    strncat(buf, c, sizeof(char *));
  }

  free(c);

  close(reader.fd);

  unsigned long len = strlen(buf);
  char *contents = malloc(len);
  strncpy(contents, buf, len);

  return contents;
}

