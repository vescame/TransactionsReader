#include "readfile.c"
#include "list.c"
#include <stdio.h>
#include <string.h>

transaction_list_t *split_transactions(const char *contents) {
  if (contents == NULL) return NULL;
  transaction_list_t *list = new_transaction_list();

  unsigned long len = strnlen(contents, BUFLEN);
  char *line = (char *) malloc(sizeof(char) * len);

  for (int i = 0; i < len; ++i) {
    strncat(line, &contents[i], sizeof(char));
    if (contents[i] == '\n') {
      transaction_t *t = (transaction_t *) malloc(sizeof(transaction_t));
      t->value = strtof(line, NULL);
      add_transaction(list, t);
      line = (char *) malloc(sizeof(char) * len);
    }
  }

  free(line);

  return list;
}

int main(int argc, char** args) {
  char *contents = read_transactions("transactions.txt");

  transaction_list_t *tlist = split_transactions(contents);

  print_transactions(tlist);
  summarize_transactions(tlist);

  free(tlist);
  free(contents);

  return EXIT_SUCCESS;
};

