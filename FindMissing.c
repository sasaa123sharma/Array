//Find missing number 
//You are given a list of n-1 integers and these integers are in the range of 1 to n. There are no duplicates in list
//Use XOR method to find missing number

#include <stdio.h>
#include <stdlib.h>

int FindMissing(int *arr, int n)
{
	int i = 0;
	int XOR = arr[0];

	for(i = 1; i < n; i++)
		XOR = arr[i] ^ XOR;		


	for(i = 1; i <= n+1; i++)
		XOR = i ^ XOR;		

	return XOR; 
}

int FindMissingOther(int *arr, int n)
{
	int i = 0;

	int sum = ((n+1) * (n+2))/2; //sum of n numbers (n *(n+1))/2

	for(i = 0; i < n ; i++)
		sum = sum - arr[i]; 

	return sum;
}

int main()
{
	int arr[] = {1, 2, 4, 5, 6};

	printf("missing number -> %d\n", FindMissing(arr, 5));

	printf("missing number -> %d\n", FindMissingOther(arr, 5));

	return 0;
}

