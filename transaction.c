#include "readfile.c"
#include "list.c"
#include <stdio.h>
#include <string.h>

transaction_list_t *split_transactions(const char *contents, const int at) {
  if (contents == NULL) return NULL;
  transaction_list_t *list = new_transaction_list();

  unsigned long len = strnlen(contents, sizeof(contents) + 1);
  char *line = (char *) malloc(sizeof(char) * len);

  for (int i = 0; i < len; ++i) {
    if (contents[i] == '\n') {
      transaction_t *t = (transaction_t *) malloc(sizeof(transaction_t));
      t->value = strtof(line, NULL);
      add_transaction(list, t);
      line = (char *) malloc(sizeof(char) * len);
    }
    strncat(line, &contents[i], 1);
  }

  free(line);
  return list;
}

int main(int argc, char** args) {
  transaction_list_t *list = new_transaction_list();
  char *contents = read_transactions("transactions.txt");

  transaction_list_t *t = split_transactions(contents, 0);

  print_transactions(t);
  sumarize_transactions(t);

  free(list);
  free(contents);
  free(t);

  return EXIT_SUCCESS;
};

