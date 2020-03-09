// Given an unsorted array of integers, find the length of longest increasing subsequence.

// Example:

// Input: [10,9,2,5,3,7,101,18]
// Output: 4 
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 

// Note:

//     There may be more than one LIS combination, it is only necessary for you to return the length.
//     Your algorithm should run in O(n2) complexity.

// Follow up: Could you improve it to O(n log n) time complexity?

#include <iostream>
#include <vector>

using namespace std;

//dp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        int res=0;
        for(int i = 0; i < nums.size() ; i++){
            for(int j = 0; j<i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
            res = max(dp[i], res);
        }
        return res;
    }
};
//思路：设dp[i]为包含当前元素的子序列长度，则只要遍历该元素前的所有元素得到结果，状态转移方程: dp[i] = max(dp[j]+1, dp[i])， 
//再比较各个dp[i]的大小得到最后结果



//binary search
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> ends{nums[0]};
        for(auto a : nums){
            if(a < ends[0]) ends[0] = a;
            else if(a > ends.back()) ends.push_back(a);
            else{
                int left = 0, right = ends.size();
                while(left<right){
                    int mid = left + (right - left)/2;
                    if(ends[mid] < a) left = mid + 1;
                    else right = mid;
                }
                ends[right] = a;
            }
        }
       return ends.size();
    }
};

//思路： 维护一个数组存放最长的子序列，先遍历整个序列，如果当前元素大于数组里的最大值，直接append到最后，
//如果小于末尾元素，则使用二分查找找到第一个大于当前元素的值，并用当前元素替换他。
//注意： dp 数组的值可能不是一个真实的 LIS，
//比如若输入数组 nums 为 {4, 2， 4， 5， 3， 7}，那么算完后的 ends 数组为 {2， 3， 5， 7}，
//可以发现它不是一个原数组的 LIS，只是长度相等而已，
