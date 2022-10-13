#include <iostream>
#include <cstdlib>

using namespace std;

int recursiveBinarySearch(int nums[], int low, int high, int target)
{
	// Base condition (search space is exhausted)
	if (low > high)
	{
		return -1;
	}

	// Find the mid-value in search space and compare it with target
	int mid = (low + high) / 2; // Overflow can happen

	// Base condition (target value is found)
	if (target == nums[mid])
	{
		return mid;
	}
	/*Discard all elements in rightward search space, including middle element */ 
	else if (target < nums[mid]) 
	{
		return recursiveBinarySearch(nums, low, mid - 1, target);
	}
	else // Discard all elements in leftward search space, including middle element
	{
		return recursiveBinarySearch(nums, mid + 1, high, target);
	}
}

int main(void)
{
	int nums[] = { 2, 5, 6, 8, 9, 10 };
	int target = 5;

	int n = sizeof(nums) / sizeof(nums[0]);

	int low = 0, high = n - 1;
	int index = recursiveBinarySearch(nums, low, high, target);

	if (index != -1)
	{
		cout << "Element fount at index: " << index << endl;
	}
	else
	{
		cout << "Element not found in the array." << endl;
	}

	return 0;
}