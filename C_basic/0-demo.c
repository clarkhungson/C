#include <stdio.h>
#include <errno.h> /* header file de su dung cac ham va hang can thiet*/
#include <string.h>

extern int errno ;

int main ()
{
   perror("Error duoc in boi ham perror");
   
   printf("\n===========================\n");
   return 0;
}