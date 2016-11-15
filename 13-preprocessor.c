// Talking about Preprocessor: 
// gcc -E -c 13-preprocessor.c


#define NUM1 5
#define NUM2 8

#define SUM(x,y) x+y

// This is my comment number 2
int main(int argc, char *argv[])
{
	int i;
	int k;

	int sum;

	i = NUM1;
	k = NUM2;

	sum = SUM(NUM1, NUM2);

	//This is my comment

	return 0;
}