//=========================================================
//                    LIBC_FUNC.C                        
//=========================================================

#include "../inc/mastermind.h"

// COMPARES STRINGS AND RETURNS IT'S DIFFERENCE. 0 = MATCH
int my_strcmp(char* param_1, char* param_2){
    int i = 0;

    while (param_1[i] == param_2[i] && param_1[i])
		i++;
	return ((unsigned char)*param_1 - (unsigned char)*param_2);
}

// GETS THE LENGTH OF THE STRING
int my_strlen(char *s){
	int i = 0;
	while (s[i])
		i++;
	return i;
}

// RETURNS ASCII VALUE OF THE INTEGER
char int_to_ascii(int num){
	return '0' + num;
}

// PRINTS A CHARACTER IN STDIN
void my_putchar(char c){
	write(0, &c, 1);
}

// PRINTS A STRING IN STDIN
void my_putstr(char *str){
	int i = 0;
	while (str[i]){
		my_putchar(str[i]);
		i++;
	}
}

// PRINTS A NUMBER AS CHAR IN STDIN
// ONLY TO TEST IN STDIN
static void	overflow(void)
{
	my_putchar('-');
	my_putchar('2');
	my_putchar('1');
	my_putchar('4');
	my_putchar('7');
	my_putchar('4');
	my_putchar('8');
	my_putchar('3');
	my_putchar('6');
	my_putchar('4');
	my_putchar('8');
}

void my_putnbr(int nb){
	if (nb == -2147483648){
		overflow();
	}else{
		if (nb < 0){
			my_putchar('-');
			nb = nb * (-1);
		}
		if (nb >= 10)
			my_putnbr(nb / 10);
		my_putchar('0' + nb % 10);
	}
}
