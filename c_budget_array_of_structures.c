/*
 *
 * Name:       c_budget_array_of_structures
 *
 * Purpose:    Keep track of a simple budget in a text file.
 *
 *	       You can create new transactions, display your
 *	       transactions, edit transactions, or delete
 *             transactions.
 *
 *             Each budget record will have the following:
 *
 *             Date, Amount, Type (Credit or Debit), and Description
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



/*
 *
 * Preprocessing directives
 *
 */
#include "c_budget_menus.h"
#include "c_budget_validation.h"
#include "c_budget_read_input.h"
#include "c_budget_crud_operations.h"



/*
 *
 * Function prototypes
 *
 */
 char *parse_transaction_string(char *transaction_field, char *complete_transaction_string);
 


/*
 *
 * Main function
 *
 */
int main(void)
{
   FILE *fp;
   
   struct transaction budget[MAX_TRANSACTIONS];
   
   char complete_transaction_string[MAX_TRANSACTION_LENGTH + 1];
   char main_menu_input_string[MENU_INPUT_LENGTH + 1];
   char *transaction_string_index;
   char date_string[DATE_LENGTH + 1];
   char amount_string[AMOUNT_LENGTH + 1];
   char type_string[TYPE_LENGTH + 1];
   char description_string[DESCRIPTION_LENGTH + 1];
   
   int number_of_transactions = 0;
   int menu_option_to_int;
   int read_input_return_code;
   /* int i; */
   
   /*
    * Check for the existence of budget.txt
    * Terminate if can't open for reading.
    * Otherwise, open the file and get the number of transactions in it.
    */
   fp = fopen(FILE_NAME, "r");
   if(fp == NULL)
   {
      printf("\nFile error.\n\n");
      printf("Please ensure %s exists, and try again.\n\n", FILE_NAME);
      return EXIT_FAILURE;
   }
   
   /*
    * Read the transactions from file. Stop filling the structure array after
    * we reach the max number of transactions. If we can read another
    * transaction, above the max, the file is too large, and we will exit.
    * 
    */
   while(
      fgets
         (complete_transaction_string, MAX_TRANSACTION_LENGTH + 1, fp) != NULL
      && number_of_transactions < MAX_TRANSACTIONS + 1)
   {
      /*
       * If we are able to read one transaction above the max, then the file
       * is too big. I'm defining this as a critical error since the program
       * deletes the original file in the Create(), Delete(), and Update()
       * functions and replaces the file's data up to (only) the maximum number
       * of transactions defined in THIS application. I don't want to allow
       * the possibility for the user to run this program on a large budget
       * file and possibly lose their data.
       */
      if(number_of_transactions > MAX_TRANSACTIONS - 1)
      {
         printf("\nThere is too much data in the file to read.\n\n");
         printf("The program will exit.\n\n");
         return EXIT_FAILURE;
      }
      
      /* Put the current line of the text file into the members of
       * the transactions structures in our array */
       
      /* Keep track of our position as we read from the
       * complete_transaction_string array */
      transaction_string_index = complete_transaction_string;
   
      transaction_string_index = parse_transaction_string(
         date_string, transaction_string_index);
      transaction_string_index = parse_transaction_string(
         amount_string, transaction_string_index);
      transaction_string_index = parse_transaction_string(
         type_string, transaction_string_index);
      transaction_string_index = parse_transaction_string(
         description_string, transaction_string_index);
         
      strcpy(budget[number_of_transactions].date, date_string);
      strcpy(budget[number_of_transactions].amount, amount_string);
      strcpy(budget[number_of_transactions].type, type_string);
      strcpy(budget[number_of_transactions].description, description_string);
      
      number_of_transactions++;
   }
   
   fclose(fp);
   
   /* Test code
   for(i = 0; i < number_of_transactions; i++)
   {
      printf("\n%d %s %s %s %s\n", i + 1, budget[i].date, budget[i].amount, budget[i].type, budget[i].description);
   }
   */
   
   for( ;; )
   {
      display_main_menu();
      
      read_input_return_code = read_menu_input(main_menu_input_string);
      
      /* Check to make sure there wasn't an input read error. */
      if(read_input_return_code == -10)
      {
         printf("\nThere was an error reading your input.\n\n");
         printf("Please try again.\n\n");
         return EXIT_FAILURE;
      }
      
      printf("\n");
      
      /* Main menu options */
      if(is_valid_main_menu_option(main_menu_input_string))
      {
         menu_option_to_int = atoi(main_menu_input_string);
         
         if(menu_option_to_int == 1)
         {
            /* 
             * Make sure the number of transactions in our file is LESS
             * than the total number of allowed transactions; otherwise,
             * we can't add a transaction if the file is maxed out.
             */
            if(number_of_transactions < MAX_TRANSACTIONS)
            {
               number_of_transactions = create_transaction(&number_of_transactions,
                  (struct transaction *)(budget));
            }
            else
            {
               printf("\n\nThe file contains the max number of lines.\n");
               printf("\nWe cannot add any more transactions.\n");
            }
         }
         else if(menu_option_to_int == 2)
         {
            /* We don't need to check the number of transactions because
             * the program exits above if too many records are found */
            number_of_transactions =
               read_transactions(&number_of_transactions,
               (struct transaction *)(budget));
         }
         else if(menu_option_to_int == 3)
         {
            /* Check to make sure we have transactions to edit in the file */
            if(number_of_transactions < 1)
            {
               printf("\nNo transactions were found in the file to edit.\n");
               printf("\nPlease create a transaction first.\n");
            }
            else
            {
               number_of_transactions =
                  update_transaction(&number_of_transactions,
                  (struct transaction *)(budget));
            }
         }
         else if(menu_option_to_int == 4)
         {
            /* Check to make sure we have transactions to delete in the file */
            if(number_of_transactions < 1)
            {
               printf("\nNo transactions were found in the file to delete.\n");
               printf("\nPlease create a transaction first.\n");
            }
            else
            {
               number_of_transactions =
                  delete_transaction(&number_of_transactions,
                  (struct transaction *)(budget));
            }
         }
         else if(menu_option_to_int == 5)
         {
            printf("\nOption 5: Save and Quit\n\n");
            return EXIT_SUCCESS;
         }
         else
         {
            printf("Invalid option entered. Please try again.\n");
         }
      }
      else
      {
         printf("Invalid option entered. Please try again.\n");
      }
   }
}



/* Separate a full transaction line from the budget file
 * into its component parts (i.e., date, amount, type,
 * and descirption
 */
char *parse_transaction_string(char *transaction_field, char *complete_transaction_string)
{
   char *p;
   p = transaction_field;
   
   while((*complete_transaction_string != '|') && (*complete_transaction_string))
   {
      *p = *complete_transaction_string++;
      p++;
   }
   
   *p = '\0';
   p = ++complete_transaction_string;
   
   return p;
}



