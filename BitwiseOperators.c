/* Binary logic using 
 * bitwise operators
 * Kaitlin Berryman */
 
#include<stdio.h>
int main()
{
	// note - variable names can't start with numbers
	// AND Operation
	int a = 12; 	  // 00001100
	int b = 25; 	  // 00011001
	
	int AND = a&b;	  // 00001000  which is 8
	int OR  = a|b;	  // 00011101  which is 29
	int XOR = a^b;	  // 00010101  which is 21  Exclusive OR
	int onesC = ~a;	  // 11110011  which is 243 One's Complement  Flipping the bits
	int twosC = ~a+1; // 11110100  which is 244	Two's Complement  Flipping the bits and adding one
	
	// Shift Right Operation
	
	// Shift Left Operation
	
	
	printf("AND - %d\n", AND);
	printf("OR - %d\n", OR);
	printf("XOR - %d\n", XOR);
	printf("One's Complement - %d\n", onesC);
	printf("Two's Complement - %d\n", twosC);

	return 0;
}
 