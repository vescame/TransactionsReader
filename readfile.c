#include "readfile.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

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

  char *contents = (char *) malloc(sizeof(char) * 4);
  char *c = malloc(sizeof(char));
  while (read(reader.fd, c, sizeof(char)) > 0) {
    strncat(contents, c, 1);
  }

  free(c);

  close(reader.fd);

  return contents;
}

