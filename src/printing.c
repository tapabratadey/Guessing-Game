//=========================================================
//                      PRINTING.C                        
//=========================================================

#include "../inc/mastermind.h"

/**
* * ====== init_prompt_msg() -- BOILERPLATE MESSAGES TO DISPLAY BEFORE LOOP
* * @param {mastermind *m}
* * @return {void}
*/

void init_prompt_msg(mastermind *m){
    my_putstr("Don't Look: "); // ===================================>>>
	my_putstr(m->code); // PRINTING CODE ============================>>>
	my_putstr("\nWill you find the secret code?\n\nYou have total of ");
	if (m->attempts == 10)
		my_putstr("10");
	else
		my_putchar(int_to_ascii(m->attempts));
	my_putstr(" attempts. Good luck!\n\n");
}

/**
* * ====== msg_in_loop() -- BOILERPLATE MESSAGES TO DISPLAY AFTER INPUT
* * @param {int attempt_counter}
* * @return {void}
* * 1. SENDS OUT MESSAGES (ROUNDS)
*/

void msg_in_loop(int attempt_counter){
	my_putstr("Round ");
	if (attempt_counter + 1 == 10)
		my_putstr("10");
	else
		my_putchar(int_to_ascii(attempt_counter + 1));
	my_putchar('\n');
}
