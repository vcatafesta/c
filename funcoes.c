#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stddef.h>
#include <limits.h>

#define N 100
extern int xtemp; /*variavel global */
char *space(size_t n);
char minuscula(char ch);
char maiuscula(char ch);
int testemalloc();
void aloca();


/***********************************************************************************/

char minuscula(char ch)
{
	if(ch >= 'A' && ch <= 'Z')
		ch = ch + 'a' - 'A';
	return ch;		
}

/***********************************************************************************/

char maiuscula(char ch)
{
	if(ch >= 'a' && ch <= 'z')
		ch = ch + 'A' + 'a';
	return ch;		
}

/***********************************************************************************/

char *space(size_t n)
{
	char *pbuf = (char*)malloc(n * sizeof(char)); 
	if (pbuf == NULL) {
      printf ("Socorro! 1 malloc devolveu NULL!\n");
      exit (EXIT_FAILURE);
   }
   if(n){
		/*pbuf[n] = '\0'; */
		memset(pbuf, 65, n);
	}	
	return pbuf;
}

/***********************************************************************************/

int testemalloc()
{

        auto int i;
        void *ptr;
        printf("Testing using BRUTE FORCE\n");
        for (i=0; i<10; i++)
        {
                ptr = malloc(0);
                if (ptr == realloc(ptr, 65000))
                        printf("Iteration %d: possible\n", i);
                else
                {
                        printf("Failed for iteration %d\n", i);
                        break;
                }
        }
		free(ptr);
        return 0;
}

void aloca()
{
	char *ptr;
	unsigned long count = 0;
	
	while (1) {
		ptr = (char*)malloc(sizeof(char));
		if (ptr == NULL) {
			printf ("Socorro! 1 malloc devolveu NULL!\n");
			exit (EXIT_FAILURE);
		}		
		count++;
		memset(ptr, count, 1);
		printf("ponteiro=%p \tvalor=%d \titeracao=%u\n", ptr, *ptr, count);
	}
}

int main()
{
	char *cstr = space(UINT_MAX);
    int numbers[N];
	int ndx;
	size_t size;
 	
	for (ndx = 0; ndx < N; ++ndx)
        numbers[ndx] = ndx;
    
	size = sizeof numbers;
	printf("%s => %u \n", cstr, strlen(cstr));
	printf("UINT_MAX = %u\n", UINT_MAX);
	printf("size     = %u\n", size);
	system("pause");
	
	testemalloc();
	system("pause");
	
	printf("%c\n", minuscula(65));
	printf("%c\n", maiuscula(65));
	system("pause");
	
	aloca();
	system("pause");
	
	
	
	return 0;
}