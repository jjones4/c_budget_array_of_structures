/*
 *
 * Function Prototypes
 *
 */



#ifndef CRUD_OPERATIONS_H
#define CRUD_OPERATIONS_H
#include <stdio.h>
#include "c_budget_read_input.h"

int create_transaction(int *number_of_transactions, char complete_budget[MAX_TRANSACTION_LENGTH + 1]);
int read_transactions(int *number_of_transactions, char complete_budget[MAX_TRANSACTION_LENGTH + 1]);
int update_transaction(int *number_of_transactions, char complete_budget[MAX_TRANSACTION_LENGTH + 1]);
int delete_transaction(int *number_of_transactions, char complete_budget[MAX_TRANSACTION_LENGTH + 1]);

#endif



