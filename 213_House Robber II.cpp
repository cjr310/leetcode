// Share
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

// Example 1:

// Input: [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
//              because they are adjacent houses.
// Example 2:

// Input: [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
//              Total amount you can rob = 1 + 3 = 4.


#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;


class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[1], nums[0]);
        if(nums.size()==3) return max(nums[1], max(nums[0], nums[2]));
        int res1 =0;
        int res2 =0;
        int res;
        vector<int> dp(nums.size(), 0);
        vector<int> dp1(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = nums[0]+nums[2];
        for(int i = 3; i<nums.size(); i++){
            dp[i] = max(dp[i-2]+nums[i], dp[i-3]+nums[i]);
        }
        res1 = max(dp[nums.size()-2], dp[nums.size()-3]);
        dp1[0] = 0;
        dp1[1] = nums[1];
        dp1[2] = nums[2];
        for(int i = 3; i<nums.size(); i++){
            dp1[i] = max(dp1[i-2]+nums[i], dp1[i-3]+nums[i]);
        }
        res2 = max(dp1[nums.size()-1], dp1[nums.size()-2]);
        return max(res1, res2);
    }
};


//思路：本题要求抢劫不能收尾相连，那么就可以变通一下，求2个最大值，一个去掉第一天，另外一个去掉最后一天，求他们两个的最大值，剩下的思路与系列1一样。