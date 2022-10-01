## c_budget

c_budget is a simple command line app which stores transactions in a file called budget.txt. Take a look at the budget.txt file to see the structure of the data storage system.

With c_budget, you can create a new transaction, read all transactions, update a transaction, or delete a transaction.

To compile and link c_budget's source files, I am using GCC and Make. You can compile c_budget using the following steps:

1. Download all the source files and the makefile into your chosen directory.
2. Point your terminal to the directory.
3. Use the makefile included with c_budget to compile and link the source files.
4. If you have installed Make, run the following command: make c_budget

I plan to use various data structures to improve c_budget. I am rebuilding c_budget in the following order (please see my repository for various versions of c_budget):

1. c_budget (original)
2. c_budget_2d_array
3. c_budget_array_of_structures
4. c_budget_linked_list
5. c_budget_ordered_list

Also, you can compile c_budget on Windows using the following command:

- cl -W4 c_budget c_budget.c c_budget_crud_operations.c c_budget_menus.c c_budget_read_input.c c_budget_validation.c -link -out:c_budget.exe
