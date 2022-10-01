/*
 *
 * Name:       c_budget_crud_operations.h
 *
 * Purpose:    Function prototypes for c_budget_crud_operations.c
 *
 * Author:     jjones4
 *
 * Copyright (c) 2022 Jerad Jones
 * This file is part of c_budget_array_of_structures.
 * c_budget_array_of_structures may be freely distributed under the
 * MIT license.  For all details and documentation, see
 *
 * https://github.com/jjones4/c_budget_array_of_structures
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



