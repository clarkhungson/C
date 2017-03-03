#include <stdio.h>
#include <errno.h> /* header file de su dung cac ham va hang can thiet*/
#include <string.h>
#include <stdlib.h>

//extern int errno ;

int main ()
{
   FILE * pf;
   int errnum;
   printf("%d\n", errno);
   pf = fopen ("unexist.txt", "rb");
   if (pf == NULL)
   {
      errnum = errno;
      fprintf(stderr, "Gia tri cua errno la: %d\n", errno);
      perror("Error duoc in boi ham perror");
      printf("Loi xuat hien khi mo file: %s\n", strerror( errnum ));
      exit(-1);
   }
   else
   {
      fclose (pf);
   }
   
   printf("\n===========================\n");

   return 0;
}