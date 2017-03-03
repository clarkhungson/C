// Step 1: Create file a.out
// $ cc -g debug.c
// Step 2: laund gdb
// $ gdb a.out
// Step 3: Set up a break point inside C program
// $ break line_number
// Step 4: Execute the C program in gdb debugger
// run [args]
// Step 5: Printing the variable values inside gdb debugger
// print {variable}
// Step 6: Continue, stepping over and in - gdb commands
// l - list
// p - print
// c - continue
// s - step

# include <stdio.h>

int main()
{
	int i, num, j;
	printf ("Enter the number: ");
	scanf ("%d", &num );

	for (i=1; i<num; i++)
		j=j*i;    

	printf("The factorial of %d is %d\n",num,j);
}
