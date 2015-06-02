#include <stdio.h>
#include <stdlib.h>


int checkboard(int b[], int n);
void displayboard(int b[], int n);

int main()
{
	int b[] = {1,3,0,2};

	int n = 4;

	int x;
	for (x=0; x<n; x++)
	{
		printf("%d ", b[x]);
	}
	printf("]\n\n");

	int return_val = checkboard(b, n);
	
	printf("Return val is: %d\n",return_val );

	printf("Here is your shuffled array: [ ");

	displayboard(b,n);
	
}

int checkboard(int b[], int n)
{
	for (int x = 0; x<n; x++)
	{
		for (int z = x+1; z<n; z++)
		{
			if (abs(x-(z)) == abs(b[x]-b[z]))
			{
				printf("FOUND A DIAG AT: %d,%d\n", x, z);
				return 0;
			}
			/*
			if (abs(x-(x+1)) == abs(b[z]-b[z+1]))
			{	
				printf("Found issue with: %d and %d\n",x, b[x]);
				return 0;
			}
			
			printf("Made it here: %d %d\n", x,z);
			
			
			if (z == b[x])
			{
				//printf("Made it here\n");
				//checks if there is a coord diagonal bottom left
				//of coord found
				for (int k=x; k<n; k++)
				{
					for (int f=z-1; f>-1; f--)
					{
						if (f == b[k+1])
						{
							printf("FOUND A DIAG AT: %d,%d\n", k, f);
							return 0;
						}
					}
				}
				//printf("Made it here\n");
				
				//checks if there is a coord diagonal bottom right
				//of coord found
				for (int k=x+1; k<n; k++)
				{
					printf("Made it here\n");
					for (int f=z+1; f<n; f++)
					{
						if (f == b[k])
						{	
							printf("FOUND A DIAG AT: %d,%d\n", k, f);
							return 0;
						}
					}
				}
				
			}
			*/
		}
	}

	return 1;
}

void displayboard(int b[], int n)
{
	for (int x=0; x<n; x++)
	{
		printf("\n");
		for (int i = 0; i < n; i++)
		{
			if (i == b[x])
			{
				printf("*");
			}
			else
				printf("-");
			
		}

		printf("\n");
	}
		
}


/*
if the current iteration is (0,3), then stop and check diag

check if the next row++ until n, column-1 -- until n is
also a coordinate (if column-1 == b[x(current row)]) 

- * - -
- - - *
* - - -
- - * -
*/