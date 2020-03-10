// Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

// Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

// Note: You are not suppose to use the library's sort function for this problem.

// Example:

// Input: [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

// Follow up:

//     A rather straight forward solution is a two-pass algorithm using counting sort.
//     First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
//     Could you come up with a one-pass algorithm using only constant space?

#include<vector>

using namespace std;


class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> m(3);
        for(int num: nums){
            m[num]++;
        }
        for(int i=0,cur=0; i<m.size(); i++){
            for(int j=0; j<m[i]; j++){
                nums[cur++] = i;
            }
        }
    }
};


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red =0, blue = nums.size()-1;
        for(int i = 0; i<=blue; i++){
            if(nums[i]==0){
                swap(nums[i], nums[red++]);
            }
            else if(nums[i]==2){
                swap(nums[i--], nums[blue--]);
            }
        }
    }
};

//思路：1.遍历数组存入vector，然后更新数组
//2.使用2个指针，red 指针指向开头位置，blue 指针指向末尾位置，遍历i时遇到0与red交换，此时red++，i++；
//遇到2时与blue交换，此时blue--，i--;遇到1时继续遍历。