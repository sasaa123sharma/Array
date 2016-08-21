//Find the two repeating elements in a given array
//You are given an array of n+2 elements. All elements of the array are in range 1 to n. And all elements occur once except two numbers which occur twice. Find the two repeating numbers. 

#include <stdio.h>
#include <stdlib.h>

//Solutions - 

//Using two loops
//Search the whole array for all elements
//O(n*n)


//Using count array
//Scan the original array first, also increase count in count array of the correspond element
//And if count of any element is already set to one, print that element
//O(n) and space complexity O(n)


// Using XOR method
void FindTwoRepeat(int *arr, int size )
{
	int i = 0;
	int XOR = arr[0];

	for(i = 1; i < size ; i++)
		XOR = arr[i] ^ XOR;

	for(i = 1; i <= size-2 ; i++)
		XOR = XOR ^ i;
		
	//This XOR will contain XOR of two repeated elements  
	//Take right set bit of XOR
	int rsb = ~(XOR -1) & XOR;
	
	printf("XOR %d and rsb %d\n", XOR, rsb);
	
	int x = 0;
	int y = 0;

	//Keep one set which has same bit set as rsb
	//and another which is not
	for(i = 0; i < size ; i++)
	{
		if(arr[i] & rsb) 
			x = x ^ arr[i];
		else
			y = y ^ arr[i];
	}	
	
	for(i = 1; i <= size-2 ; i++)
	{
		if(i & rsb) 
			x = x ^ i;
		else
			y = y ^ i;
	}

	printf("x = %d and y = %d\n", x, y);
	return;
}


//Using array elements as index
void FindTwoRepeatother(int *a, int n)
{
	int i = 0;
	int temp = 0;

	for(i = 0; i < n ; i++)
	{
		if(a[i] < 0)
			temp = -1 * a[i];
		else
			temp = a[i];		

		if(a[temp -1] < 0)
			printf("repeated number %d\n", temp);
		else
			a[temp - 1] = -1 *a[temp -1];
	}

	return;
}

int main()
{
	int arr[] = {1, 2, 2, 3, 3, 4};

	FindTwoRepeat(arr, 6);
	FindTwoRepeatother(arr, 6);

	return 0;
}
