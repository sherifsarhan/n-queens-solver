//  Name:  Sherif Sarhan

// This program solves the n-queens problem

//include macros for dependencies
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//macros for seed and defining min and max functions
#define seed 5457

#define max(a,b) \
({ __typeof__ (a) _a = (a); \
__typeof__ (b) _b = (b); \
_a > _b ? _a : _b; })

#define min(a,b) \
({ __typeof__ (a) _a = (a); \
__typeof__ (b) _b = (b); \
_a < _b ? _a : _b; })

//initializing functions
int initializeArray(int [], const int);
void randperm(int b[], int n);
int checkboard(int b[], int n);
void displayboard(int b[], int n);
double factorial(double n);

int main()
{
	//seeds random number generator
	srandom(seed);

	//creates arrays for stats to be stored in
	int mini[21], maxi[21];
	double meani[21], sizei[21], sizei_f[21];

	//loops the code for every value of n from 4 until 20
	int n;
	for (n=4; n<=20; n++)
	{
		
		//printf("\nYour n value is: '%d'\n\n", n);
		
		//creates array of size n
		int b[n];

		//initiallizes array from 0 to n
		initializeArray(b,n);

		//shuffles array to make random perm
		//randperm(b,n);

		/*
		printf("Here is your shuffled array: [ ");
		int x;
		for (x=0; x<n; x++)
		{
			printf("%d ", b[x]);
		}
		printf("]\n\n");
		*/
		
		printf("~~~~~~~~~PRINTING FOR %d~~~~~~~~~~~~~\n",n);
		
		//creates total counter
		int total = 0;
		//loops for each n value 10 times
		int x;
		for (x = 0; x<10; x++)
		{	
			//count variable to count checkboard attempts
			//is reset to 1 every iteration to test efficiency of all loops
			int count = 1;
			//printf("%d\n",count );
			
			//randomizes the board
			randperm(b,n);
			
			//printf("checking board\n");

			//finds a solution
			while(!checkboard(b,n))
			{
				//printf("Entered checking.\n");
				
				//randomizes board
				randperm(b,n);
				
				//printf("RANDOMIZED\n");
				
				//increments counter
				count++;
				
				//printf("Count is: %d\n",count);
			}
			//printf("I FOUND SOMETHING!!!\n");
			//printf("It took %d times until I found a solution\n", count);
			//printf("Set min to count\n");
			
			//sets initial count value in min and max for comparison at n val
			if (x==0)
			{
				//sets min value for current n = to count if first iteration
				mini[n] = count;
				//printf("%d\n",min );
				//printf("Set max to count\n");
				maxi[n] = count;
				//printf("%d\n",max );
				
				//displays the first solution found for n value
				displayboard(b,n);
			}
				
			//printf("THE MINIMUM BEFORE IS: %d\n", min);
			
			//compares the current min value of n with the new count
			mini[n] = min(mini[n],count);

			//printf("THE MINIMUM AFTER IS: %d\n", min);

			//compares the current max value of n with te new count
			maxi[n] = max(maxi[n], count);		
			
			//increments total by count to add up all of the 10 iterations for current n
			total += count;

			//printf("THE TOTAL IS: %d\n", total );
			//printf("Iteration: %d\n",x);
			//printf("DONE\n");			
		}
		
		//calculates the mean for current n by dividing the total counts by 10
		meani[n] = total/10.0f;

		//printf("The mean for %d is %e\n",n, mean);

		//calculates the n^n and stores it in size
		double size = pow(n,n);
		//the value is stored in array of sizes just for current n value
		sizei[n] = size;

		//calculates n factorial
		double size_f = factorial(n);
		//stores the value into array of n factorials for current n value
		sizei_f[n] = size_f;

		/*
		printf("size: %d\n", n);
		printf("min: %d\n", mini[n]);
		printf("max: %d\n", maxi[n]);
		printf("mean: %.1e\n", meani[n]);
		printf("size**size: %.1e\n", sizei[n]);
		printf("size!: %.1e\n", sizei_f[n]);
		*/
		//printf("%d\t%d\t%d\t%.1e\t%.1e\t\t%.1e\n", n, mini, maxi, mean, size, size_f);	
		
	}
	//prints the titles of each column using 13 character space width
	printf("\n%13s%13s%13s%13s%13s%13s\n", "size", "min", "max", "mean", "size**size", "size!");

	//prints out each value of the array for all n values using 13 character space width
	int x;
	for (x=4; x<=20; x++)
	{
		printf("%13d%13d%13d%13.1e%13.1e%13.1e\n", x, mini[x], maxi[x], meani[x], sizei[x], sizei_f[x]);
	}

}

//initializes array
int initializeArray(int *a, const int arraySize)
{
	//fills in numbers in order from 0 to n
	int i;
	for (i=0; i<arraySize; i++)
	{
		a[i] = i;
	}
}

//shuffles array randomly
//void randperm(int *a, int arraySize)
void randperm(int b[], int n) //<corrected version>
{
	//performs shuffle
	int x;
	for (x=n-1; x>0; x--)
	{
		//performs swaps
		int j;
		int temp;
		j = random() % (x+1);
		temp = b[j];
		b[j] = b[x];
		b[x] = temp;
	}
}

int checkboard(int b[], int n)
{
	int x;
	for (x = 0; x<n; x++)
	{
		int z;
		for (z=x+1; z<n; z++)
		{
			//printf("%d %d",x,z);

			//checks if the absolute value between the rows
			//are equal to the absolute value between the columns of
			//one queen to the next
			if (abs(x-z) == abs(b[x]-b[z]))
			{	
				//if the distances are equal, then there is another queen
				//in the diagonal
				return 0;
			}
		}
	}
	//did not find a diagonal. return 1 for correct board.
	return 1;
}

void displayboard(int b[], int n)
{
	int x;
	for (x=0; x<n; x++)
	{
		int i;
		for (i = 0; i < n; i++)
		{
			//if current position matches a queen's coordinate's
			if (i == b[x])
			{
				//print a star to mark the spot
				printf("*");
			}
			else
				//otherwise put a dash.
				printf("-");
			
		}

		printf("\n");
	}
		
}

double factorial(double n)
{
	if (n==1)
	{
		return 1;
	}
	else
	{
		//recursively call the same function but using factorial calculation
		return n*factorial(n-1);
	}
	//printf("%d",n);


}