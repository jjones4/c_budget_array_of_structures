/*
 *
 * Name:       c_budget_validation.h
 *
 * Purpose:    Function prototypes for c_budget_validation.c
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



#ifndef C_BUDGET_VALIDATION_H
#define C_BUDGET_VALIDATION_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boolean.h"

BOOL is_valid_main_menu_option(const char *input);
BOOL is_valid_update_menu_option(const char *input);
BOOL is_valid_date(char *input);
BOOL is_valid_amount(char *input);
BOOL is_valid_type(char *input);
BOOL is_valid_description(char *input);

#endif



