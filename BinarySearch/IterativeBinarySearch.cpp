#include <iostream>
#include <cstdlib> //Needed for rand() and srand()

using namespace std;

int binarySearch(int nums[], int n, int target) 
{
	// search space is nums[low...high]
	int low = 0, high = n - 1;

	// Loop until the search space is exhausted
	while (low <= high)
	{
		// find the mid-value in the search space and compare it to target
		int mid = (low + high) / 2; // Overflow can happen

		// target value is found
		if (target == nums[mid])
		{
			return mid;
		}
		/*  if the target is less than the middle element, discard all elements
			in the rightward search space, including the middle element
		*/
		else if (target < nums[mid])
		{
			high = mid - 1;
		}

		/*  If the target is more than the middle element, discard all elements
			in the leftward search space, including the middle element
		*/
		else
		{
			low = mid + 1; // If target > mid, we reassign 'low' instead of 'high'
		}
	}

	// target doesn't exist in the array
	return -1;
}

int main()
{
	int* nums = new int[10000000];

	for (int i = 0; i < 10000000; i++)
	{
		srand((unsigned)time(NULL));
		nums[i] = rand();
	}
	int target = 12;

	int n = sizeof(nums) / sizeof(nums[0]);
	int index = binarySearch(nums, n, target);

	if (index != -1)
	{
		cout << "Element found at index: " << index << endl;
	}
	else {
		cout << "Element not found in the array" << endl;
	}

	return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
