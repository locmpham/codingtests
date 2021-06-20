/*

    LEETCODE# 27

Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The relative order of the elements may be changed.

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int val = ...; // Value to remove
int[] expectedNums = [...]; // The expected answer with correct length.
                            // It is sorted with no values equaling val.

int k = removeElement(nums, val); // Calls your implementation

assert k == expectedNums.length;
sort(nums, 0, k); // Sort the first k elements of nums
for (int i = 0; i < actualLength; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.

 

Example 1:

Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
Note that the five elements can be returned in any order.
It does not matter what you leave beyond the returned k (hence they are underscores).
 

Constraints:

0 <= nums.length <= 100
0 <= nums[i] <= 50
0 <= val <= 100

*/

#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {
    int len = nums.size();

/*  // TC O(N**2)

    for (int i = 0; i < len; i++) {
        if (nums[i] == val) {
            for (int j = i+1; j < len; j++) {
                nums[j-1] = nums[j];
            }
            len--;
            i--;
        }
    }
*/
    // TC O(N)
    int wPointer = 0;
    for (int rPointer = 0; rPointer < len; rPointer++) {
        //cout << rPointer << "." << wPointer << "." << nums[rPointer] << endl;
        if (nums[rPointer] == val) {
            // Found, remove elem by moving next elem to its place
            if (rPointer < nums.size()-1)
                nums[wPointer] = nums[rPointer+1];
        }
        else {
            // Nope, copy elem to where wPointer is and advance wPointer to next elem
            nums[wPointer++] = nums[rPointer];
        }
    }
    return wPointer;
}

void printArray(vector<int> array, int len) {
    for (int i = 0; i < len; i++) {
        cout << array[i] << ",";
    }
    cout << endl;
}

int main() {
    vector<int> array = {0,1,3,2,2,3,4,5,4,2,3,0,1};
    int len = removeElement(array, 0);
    cout << "[0,1,3,2,2,3,4,5,4,2,3,0,1] remove 0 -> ";
    printArray(array, len);

    array = {0,1,3,2,2,3,4,5,4,2,3,0,1};
    len = removeElement(array, 1);
    cout << "[0,1,3,2,2,3,4,5,4,2,3,0,1] remove 1 -> ";
    printArray(array, len);

    array = {0,1,3,2,2,3,4,5,4,2,3,0,1};
    len = removeElement(array, 2);
    cout << "[0,1,3,2,2,3,4,5,4,2,3,0,1] remove 2 -> ";
    printArray(array, len);

    array = {0,1,3,2,2,3,4,5,4,2,3,0,1};
    len = removeElement(array, 3);
    cout << "[0,1,3,2,2,3,4,5,4,2,3,0,1] remove 3 -> ";
    printArray(array, len);

    array = {0,1,3,2,2,3,4,5,4,2,3,0,1};
    len = removeElement(array, 4);
    cout << "[0,1,3,2,2,3,4,5,4,2,3,0,1] remove 4 -> ";
    printArray(array, len);

    array = {0,1,3,2,2,3,4,5,4,2,3,0,1};
    len = removeElement(array, 5);
    cout << "[0,1,3,2,2,3,4,5,4,2,3,0,1] remove 5 -> ";
    printArray(array, len);

    return 0;
}

