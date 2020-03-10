// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

// Example:

// Input: [-2,1,-3,4,-1,2,1,-5,4],
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.


//dp
#include<vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        for(int i=1; i<nums.size(); i++){
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
            sum = max(sum, dp[i]);
        }
        return sum;
    }
};