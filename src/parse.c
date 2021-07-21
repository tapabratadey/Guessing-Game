//=========================================================
//                     PARSE.C                        
//=========================================================

#include "../inc/mastermind.h"

/**
* * ====== check_options() -- CHECK IF USER PASSED OPTIONS
* * @param {mastermind *m, int i, char**argv}
* * @return {void}
* * 1. IF CODE OPTION '-c' THEN TRIGGER CODE_OPTION 
* * 2. IF ATTEMPT OPTION  '-t' THEN TRIGGER ATTEMPT_OPTION 
*/

void check_options(mastermind *m, int i, char **argv){
	if (argv[i][0] == '-' && argv[i][1] == 'c' )
		m->code_option = 1;
	else if (argv[i][0] == '-' && argv[i][1] == 't' )
		m->attempt_option = 1;
}

/**
* * ====== gen_code() -- GENERATES RANDOM CODE
* * @param {mastermind *m}
* * @return {void}
* * 1. GENERATES RANDOM 4-DIGIT CODE
*/

void gen_code(mastermind *m){
	time_t t;
	srand((unsigned)time(&t));

	char str[8] = "01234567";

	for (int i = 0; i < 4; i++)
		m->code[i] = str[rand() % 8];
}


/**
* * ====== set_code() -- SET THE CODE OR GENERATE A RANDOM CODE
* * @param {mastermind *m, char**argv, int i}
* * @return {void}
* * 1. IF CODE VALUE PRESENT AFTER OPTION '-c' 
* *    THEN SET THE SECRET CODE VALUE
* * 2. IF NOT PRESENT OR ERROR, THEN GENERATE A RANDOM CODE
*/

void set_code(mastermind *m, char **argv, int i){
	if (argv[i + 1]){
		int len = my_strlen(argv[i + 1]);
        if (len == 4)
		    strcpy(m->code, argv[i + 1]);
		else if (len != 4 || m->code[0] == '\0')
			gen_code(m);
	}
	else
		gen_code(m);
}

/**
* * ====== set_attempts() -- SET THE ATTEMPTS OR SET DEFAULT VALUE
* * @param {mastermind *m, char**argv, int i}
* * @return {void}
* * 1. IF ATTEMPT VALUE PRESENT AFTER OPTION '-t' 
* *    THEN SET THE ATTEMPTS 
* * 2. IF NOT PRESENT OR ERROR, THEN SET THE DEFAULT TO 10
*/

void set_attempts(mastermind *m, char **argv, int i){
	if (argv[i + 1]){
		int len = my_strlen(argv[i + 1]);
        if (len == 1)
		    m->attempts = atoi(argv[i + 1]);
		else if (len != 1 || m->attempts == 0)
			m->attempts = 10;
	}
	else
        m->attempts = 10;
}


/**
* * ====== parse() -- PARSE THE ARGUMENTS
* * @param {mastermind *m, char**argv, int i}
* * @return {void}
* * 1. CHECKS OPTIONS 
* * 2. IF CODE OPTION FOUND, THEN SET THE CODE
* * 3. IF ATTEMPT OPTION FOUND, THEN SET ATTEMPT
* * 4. IF OPTIONS NOT FOUND, GENERATE RANDOM CODE
* *    AND SET DEFAULT ATTEMPTS
*/

void parse(mastermind *m, char **argv, int i){
	check_options(m, i, argv);
	if (m->code_option == 1){
		m->found_code = 1;
		set_code(m, argv, i);
		m->code_option = 0;
	}
	else if (m->attempt_option == 1){
		m->found_attempt = 1;
		set_attempts(m, argv, i);
		m->attempt_option = 0;
	}
	if (m->attempt_option == 0 && m->found_attempt == 0){
		m->attempts = 10;
    }
	if (m->code_option == 0 && m->found_code == 0){
		gen_code(m);
    }
}