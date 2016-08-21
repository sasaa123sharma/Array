// Remove duplicates from integer array
// Given an array which contains duplicates, could be one or more.
// For ex-> 1, 2, 1, 2, 3, 4, 5

#include <stdio.h>
#include <stdlib.h>


//By taking temporary array
//complexity -> O(n3)
//Space complexity -> O(n)
int RemDups(int *a, int n)
{
	int i = 0;
	int j = 0;
	int k = 0;	

	int arr[n];
	
	arr[j] = a[i];
	
	j++;

	for(i = 1; i < n ; i++)
	{	
		k = 0;
		while(k < j)
		{
			if(a[i] == a[k])
				break;
			k++;
		}

		if(k == j)//in case we did not find duplicate in temporary array
		{	
			arr[j] = a[i];
			j++;
		}	
	}
	
	k = 0;
	
	while(k < j)
	{
		a[k] = arr[k];
		k++;
	}

	return j;
}

int main()
{
	int i = 0;
	int a[] = {11, 13, 11, 12, 13};
	int size = sizeof(a)/sizeof(int);	
	size = RemDups(a, size);

	for(i = 0; i < size; i++)
		printf("%d  ", a[i]);
	
	printf("\n");

	return 0;
}
