/*
*	Let's "paint" different CheckMarks in terminal emulator
*	using only *
*
*	minimal "picture" corresponds to (*argv[1])=1 and looks
*
*	                                                    |
*	                                                    V
*
*	                                                       *
*	                                                      *
*	                                                   * *
*	                                                    *
*/

#include  <stdio.h> /* puts()   ,   printf() */
#include <stdlib.h> /* system()              */

void usage(void)
{
	puts("program usage: ./checkmars N\n\
               N is a natural number \
that belongs to the open interval (0;10).");
}

int main(int argc, char *argv[])
{
	if ( argc != 2 )
	{
		puts("ERROR: wrong quantity of parameters\n");
		usage();

		return 1;
	}
	else
	{
		/* transform ASCII symbol (*argv[1]) to corresponding number */
		signed char sym2num = (signed char)(*argv[1]) - 48;

		if ( (sym2num < 1) || (sym2num > 9) )
		{
			puts("ERROR: your N doesn't belong to the open interval (0;10)\n");
			usage();

			return 2;
		}
		else
		{
		  /*
			* for upper strings with only one * symbol
			* quantity of whitespace depends on sym2num
			*/
			signed char stars = 3 * sym2num + 1;

			system("clear");

			/* "painting" upper strings */
			for( ; sym2num > -1 ; sym2num-- )
			{
				for ( argc = 0 ;  argc < stars; argc++ )
					printf(" ");

				--stars;
				printf("*\n");
			}

			stars /= 2;

			/* "painting" bottom strings without only last */
			for ( argc = 0 ; argc < stars ; argc++ )
			{
				for ( sym2num = 0; sym2num < argc ; sym2num++ )
					printf(" ");

				printf("*");

				for ( sym2num = 0 ; sym2num < 2*(stars - argc) - 1 ; sym2num++)
					printf(" ");

				printf("*\n");
			}

			/* "painting" last string */
			do
			{
				printf(" ");
				--stars;
			}
			while ( stars > 0 );

			puts("*");

			/* as if we didn't touch it */
			argc = sym2num+1;

			return 0;
		}
	}
}
