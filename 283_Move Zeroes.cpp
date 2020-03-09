// Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Example:

// Input: [0,1,0,3,12]
// Output: [1,3,12,0,0]

// Note:

//     You must do this in-place without making a copy of the array.
//     Minimize the total number of operations.

#include<vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i=0, j=0; i<nums.size(); i++){
            if(nums[i]){
                swap(nums[i], nums[j++]);
            }
        }
    }
};

//思路： 使用2个指针，一个不断往后扫，找到非零位置，然后和前面那个指针交换位置即可。
//相当于是一个记录扫描到的位置，一个记录非零末尾的位置（下一个就是0），将他们进行交换。