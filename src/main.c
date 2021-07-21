//=========================================================
//                     MAIN.C                        
//=========================================================

#include "../inc/mastermind.h"

/**
* * ====== init_mastermind() -- INIT STRUCT
* * @param {mastermind *m}
* * @return {void}
* * INITIALIZES THE MASTERMIND STRUCT
*/

void init_mastermind(mastermind *m){
	m->attempts = 0;
	m->code_option = 0;
	m->attempt_option = 0;
	m->found_code = 0;
	m->found_attempt = 0;
	m->code_found = 0;
	m->well_placed = 0;
	m->miss_placed = 0;
    m->track_index = malloc(sizeof(int));
}


/**
* * ===== my_mastermind.c - main
* * @param {int argc, char**argv}
* * @return {Integer}
* 1. MALLOC AND INIT STRUCT
* 2. PARSE OPTIONS
* 3. GENERATE CODE / ATTEMPTS IF NECESSARY
* 4. INITIALIZE PROMPTS FOR TO START THE GAME
* 5. FREE ALLOCATED MEMORY
*/

int main(int argc, char **argv){
	struct s_mastermind *mm;
	mm = malloc(sizeof(struct s_mastermind));

	init_mastermind(mm);
	if (argc > 1){
		for (int i = 1; i < argc; i++)
			parse(mm, argv, i);
	}
	else{
		gen_code(mm);
		mm->attempts = 10;
	}
	init_prompt(mm);
	free(mm);
	return 0;
}