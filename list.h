#ifndef list_h
#define list_h
typedef struct transactions transaction_list_t;
typedef struct transaction transaction_t;
typedef struct transaction_node node_t;
transaction_list_t *new_transaction_list();
node_t *new_node(transaction_t *, node_t *);
void add_transaction(transaction_list_t *, transaction_t *);
void summarize_transactions(transaction_list_t *);
void free_list(transaction_list_t *);
void print_transactions(transaction_list_t *);
#endif /* list_h */
