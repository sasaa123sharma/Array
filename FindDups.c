//Find duplicates in O(n) time and O(1) extra space
//Given an array of n elements which contains elements from 0 to n-1, with any of these numbers appearing any number of times

#include <stdio.h>
#include <stdlib.h>

//Use element as indexes
void FindDup(int *a, int n)
{
	int i = 0;
	int temp = 0;

	for(;i < n; i++)
	{
		temp = a[i];	
		if(a[i] < 0)
			temp = -1 *temp;
	
		if(a[temp] < 0)
			printf("repeated element %d\n", temp);
		else
			a[temp] = a[temp] * -1;		
	}
	return ;
}

int main()
{
	int a[] = {1, 2, 3, 1, 3, 6, 6};

	FindDup(a, sizeof(a)/sizeof(int));

	return 0;
}

