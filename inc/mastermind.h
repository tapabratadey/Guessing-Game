#ifndef MASTERMIND_H
# define MASTERMIND_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

/**
* @file MASTERMIND.H
* @brief CONTAINS FLAGS, COUNTERS, AND SECRET CODE
*/

typedef struct s_mastermind{
	char code[5];
	int attempts;
	int code_option;
	int attempt_option;
	int found_code;	   //code flag
	int found_attempt; //attempt flag
	int code_found;
	int well_placed;
	int miss_placed;
    int *track_index;
} mastermind;

/**
* @file PARSE.C
* @brief IMPLEMENTATION OF LIBC FUNCTIONS
*/

int my_strcmp(char* param_1, char* param_2);
int my_strlen(char *s);
char int_to_ascii(int num);
void my_putchar(char c);
void my_putstr(char *str);
void my_putnbr(int nb);

/**
* @file PRINTING.C
* @brief PRINTS MESSAGES TO STDIN
*/

void init_prompt_msg(mastermind *m);
void msg_in_loop(int attempt_counter);

/**
* @file MASTERMIND.C
* @brief 1. CHECKS IF CODE IS PLACED CORRECTLY AT THE RIGHT POSITION 
* @brief 2. CHECKS IF CODE IS PLACED CORRECTLY AT THE WRONG POSITION 
* @brief 3. MESSAGE TO PRINT IF THE CODE IS/NOT PLACED CORRECTLY
* @brief 4. COMPARE THE SECRET CODE WITH THE STDIN BUFFER
* @brief 5. PROMPT THE USER TO ENTER THE CODE
*/

void find_well_placed(mastermind *m, char *buff);
void stat_msg(mastermind *m);
void find_miss_placed(mastermind *m, char *buff);
void comp(mastermind *m, char *buff);
void init_prompt(mastermind *m);

/**
* @file PARSE.C
* @brief 1. CHECKS FOR '-c'. '-t' OPTIONS
* @brief 2. SETS THE USER ENTERED CODE OR GENERATES
* @brief 3. SETS THE USER ATTEMPTS OR SETS DEFAULT
* @brief 4. GENERATES RANDOM CODE
* @brief 5. PARSES ARGUMENTS.
*/

void check_options(mastermind *m, int i, char **argv);
void set_code(mastermind *m, char **argv, int i);
void set_attempts(mastermind *m, char **argv, int i);
void gen_code(mastermind *m);
void parse(mastermind *m, char **argv, int i);

/**
* @file MAIN.C
* @brief 1. INITIALIZES THE MASTERMIND STRUCT
*/

void init_mastermind(mastermind *m);

#endif