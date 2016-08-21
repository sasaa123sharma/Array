//Given an array A[] and a number x, check for pair in A[] with sum as x

#include <stdio.h>
#include <stdlib.h>

//Solutions - 

// We can check (sum - a[i]) for each a[i] 
// Complexity -> O(n*n)
 
// Using sorting technique
// Sort the array
// then check(sum) elements from front and back together
// complexity -> O(nlogn) avg case
// This will work for negative numbers also

int QsortPart(int *a, int start, int end)
{
	int i = start; 
	int index = start;
	int pivot = a[end];
	int temp = 0;	
	
	for(; i < end ; i++)
	{
		if(a[i] < pivot)
		{
			temp = a[i];
			a[i] = a[index];
			a[index] = temp;	
			index++;
		}
	}

	//Now exchange pivot and a[index]
	temp = a[index];
	a[index] = pivot;
	a[end] = temp;	
	
	return index;
}

void Qsort(int *a, int start, int end)
{
	if(start < end)
	{
		int p = QsortPart(a, start, end);
		Qsort(a, start, p -1);
		Qsort(a, p +1, end);
	}	
	return;
}

void FindSumPair(int *a, int n, int sum)
{		
	//sort these elements first
	Qsort(a, 0, n-1);

	int i = 0;
	for(; i < n ; i++)
		printf("%d   ", a[i]);

	printf("\n\n");
	
	i = 0;

	while(i < n ) //for(i = 0; i < n ; i++)
	{			
		if((a[i] + a[n-1]) == sum)
		{
			if(i != n-1) //there could case where i and n-1 is same so above will be true 
				printf("pair = (%d, %d)\n", a[i], a[n-1]);
			i++;
		}
		else if((a[i] + a[n-1]) < sum)
			i++;

		else if((a[i] + a[n-1]) > sum)
			n--;
	}
	
	printf("\n");

	return;
}

// Using hashing technique 
// Complexity -> O(n)
// Space complexity -> O(R) --> range of integers
// Will work for negative integers also but we have to make everything positive
// we can add absolute of min number to everything to make positive

#define MAX 1000
void FindSumPairOther(int *a, int n , int sum)
{
	int i = 0;
	int temp = 0;
	int hash[MAX] = {0};

	for(; i < n ; i++)
	{
		temp = 	sum - a[i];
		if(temp > 0 && hash[temp] == 1)
			printf("pair = (%d, %d)\n", a[i], temp);
		else
			hash[a[i]] = 1;	
	}
	return;
}

int main()
{
	//int a[] = {12, 11, 45, 5, 6, 9, 7, 10, 1, -8, 4, 24};
	//int a[] = {12, 11, 45, 5, 6, 9, 7, 10, 1, -8, 4};
	int a[] = {12, 11, 45, 5, 6, 9, 7, 10, 1, 8, 4};
	
	int sum = 16;
	
	FindSumPair(a, sizeof(a)/sizeof(int), sum);
	FindSumPairOther(a, sizeof(a)/sizeof(int), sum);

	return 0;
}
