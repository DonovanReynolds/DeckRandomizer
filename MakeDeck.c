#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void shuffle(int n, char array[]);
void swap(int n, char array[],int first, int second, int third, int fourth);


int main(void)
{

	time_t t;
	t = time(NULL);
	srand(t);
	
	
	char card[] = {'2','3','4','5','6','7','8','9','T','J','Q','K','A'};
	char suit[] = {'S', 'D' , 'H' , 'C'};
	
	char deck[104];
	char deck1[52];
	char deck2[52];
	
	int counter = 0;
	
	for (int i = 0; i < 13;i++)
	{
		for (int j = 0; j < 4; j++)
		{

			deck[counter] = card[i];
			counter++;
			deck[counter] = suit[j];
			counter++;
			
		}
	}
	
	shuffle(104,deck);
	printf("%s\n\n" , deck);
	
	for (int i = 0; i < 104; i++)
	{
		printf("%c" ,deck[i]);
		if (i == 51)
		{
			printf("\n");
		}
	}
	
	return 0;
}


void shuffle(int n, char array[])
{
	int loop = 0;
	while( loop < n)
	{
	
		for (int i = 0; i < n; i+=2)
		{
			int random = rand() % 104;
			
			if (random % 2 == 0)
			{
				swap(n,array,i,i+1,random,random+1);
			}
		}
		
		loop++;
	}
}

void swap(int n, char array[],int first, int second, int third, int fourth)
{
	char temp1, temp2;
	temp1 = array[first];
	temp2 = array[second];
	
	array[first] = array[third];
	array[second] = array[fourth];
	
	array[third] = temp1;
	array[fourth] = temp2;
}

