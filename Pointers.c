/* Examples of pointers
 * Pointers point to an address in memory
 * DataType * Identifier;
 * Kaitlin Berryman */
 #include <stdio.h>
 
 int main()
 {
	 printf("Test 2: \n");
	 // Typed pointers --> a specific type of data
	 int test = 20;
	 printf("Name \t Value \t Address \n");
	 printf("%s \t %d \t %p \n", "test", test, &test);
	 
	 int *pTest = &test;
	 printf("%s \t %d \t %p \n", "test", test, pTest);
	 
	 // & returns address of a particular variable
	 // * returns value which is inside a specified address
	
	 // Untyped pointer / generic pointer
	 // void * --> any type
	 
	 int test2 = 50;
	 int *pTest2;             // ptr is a common pointer name
	 pTest2 = &test2;
	
	 printf("\nTest 2: \n");	 // expected outputs
	 printf("%d \n", test2);     // test2
	 printf("%u \n", pTest2);    // address of test2   %u calls an unsigned int
	 printf("%u \n", &test2);    // address of test2
	 printf("%u \n", &pTest2);   // address of pTest2
	 printf("%d \n", *pTest2);   // test2 
	 printf("%d \n", *(&test2)); // test2
 }