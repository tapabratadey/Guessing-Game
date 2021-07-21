//=========================================================
//                   MASTERMIND.C                        
//=========================================================

#include "../inc/mastermind.h"

/**
* * ====== find_well_placed() -- FIND IF THE CODE IS PLACED CORRECTLY AT THE RIGHT POSITION
* * @param {mastermind *m, char *buff}
* * @return {void}
* * 1. CHECKS IF EACH CODE AND SECRET CODE INDEX MATCH WITH EACH OTHER
* * 2. IF ALL FOUND, THEN TRIGGER FLAG WHICH ENDS THE PROGRAM
*/

void find_well_placed(mastermind *m, char *buff){
	int i;
	for (i = 0; i < 4; i++){
		if (m->code[i] == buff[i]){
            // m->track_index[i] = i;//SAVE INDEX
			m->well_placed++;
        }
	}
	if (m->well_placed == 4){ //FULL CODE
		m->code_found = 1;
		my_putstr("Congratz! You did it!\n");
	}
}

/**
* * ====== stat_msg() -- MESSAGE TO PRINT IF CODE IS OR NOT PLACED CORRECTLY
* * @param {mastermind *m}
* * @return {void}
* * 1. SENDS OUT STAT MESSAGES (WELL PLACED && MISS PLACED)
*/

void stat_msg(mastermind *m){
	my_putstr("Well placed pieces: ");
	my_putchar(int_to_ascii(m->well_placed));
	my_putchar('\n');
	my_putstr("Misplaced pieces: ");
	my_putchar(int_to_ascii(m->miss_placed));
	my_putchar('\n');
}

/**
* * ====== find_miss_placed() -- FIND IF THE CODE IS PLACED CORRECTLY AT THE WRONG POSITION
* * @param {mastermind *m, char *buff}
* * @return {void}
* * 1. LOOPS THROUGH CODE AND BUFFER (READ IN STRING)
* * 2. KEEPS TRACK OF WRONG POSITION
*/

void find_miss_placed(mastermind *m, char *buff){
	int code_idx = 0;
	int buff_idx = 0;
	while (code_idx < 4){ // code
		buff_idx = 0;
		while (buff_idx < 4){ // buff
			if (buff[buff_idx] == m->code[code_idx] && code_idx != buff_idx){
                m->miss_placed++;
                break;
            }
			buff_idx++;
		}
		code_idx++;
	}
	if (m->well_placed != 4)
		stat_msg(m);
}


/**
* * ====== comp() -- COMPARE THE CODE WITH BUFF
* * @param {mastermind *m, char *buff}
* * @return {void}
* * 1. CALLS FUNC TO CHECK IF CODE IS PLACED CORRECTLY
* * 2. (DITTO ^) BUT CHECKS IF IT'S AT THE WRONG POSITION
*/

void comp(mastermind *m, char *buff){
	find_well_placed(m, buff);
	find_miss_placed(m, buff);
}

/**
* * ====== init_prompt() -- PROMPT THE USER TO ENTER THE CODE
* * @param {mastermind *m}
* * @return {void}
* * 1. INIT A BUFFER TO HOLD STDIN READ STRING
* * 2. SEND THE USER MESSAGES
* * 3. LOOP WHILE ATTEMPT_COUNTER < ATTEMPTS && IF THE CODE IS NOT FOUND
* * 4. SEND MESSAGES INSIDE THE LOOP 
* * 5. NULL TERMINATE THE BUFFER
* * 6. READ FROM STDIN FD = 0 
* * 7. IF ERROR CHECKS PASS THEN COMPARE USER INPUT AVEC SECRET CODE
* * 8. ITERATE ATTEMPT COUNTER
*/

void init_prompt(mastermind *m){
	char buff[64];
	int attempt_counter = 0;
	int rd = 0;

    init_prompt_msg(m);
	while (attempt_counter < m->attempts && !m->code_found){
		m->code_found = 0;
		msg_in_loop(attempt_counter);

        rd = read(0, buff, 64);
        buff[4] = '\0';
		if (rd == -1 || (rd > 5 || rd < 5))
                my_putstr("Wrong Input!\n");
        else{
            if (buff[0] == '\n' || atoi(buff) == 0)
                my_putstr("Wrong Input!\n");
            else{
                comp(m, buff); // FIND IF MATCH
                my_putchar('\n');
            }
        }
		attempt_counter++;
		m->well_placed = 0;
		m->miss_placed = 0;
	}
}