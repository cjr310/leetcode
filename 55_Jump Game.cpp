// Given an array of non-negative integers, you are initially positioned at the first index of the array.

// Each element in the array represents your maximum jump length at that position.

// Determine if you are able to reach the last index.

// Example 1:

// Input: [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
// Example 2:

// Input: [3,2,1,0,4]
// Output: false
// Explanation: You will always arrive at index 3 no matter what. Its maximum
//              jump length is 0, which makes it impossible to reach the last index.

#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

//greedy
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int reach = 0;
        for(int i = 0; i<n; i++){
            if(reach>n-1 || reach<i) break;
            reach = max(nums[i]+i, reach);
        }
        return reach>=n-1;
    }
};


//dp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        for(int i = 1; i<nums.size(); i++){
            if(dp[i-1]<i) return false;
            dp[i] = max(dp[i-1], i+nums[i]);
            if(dp[i] >= nums.size()-1) return true;
        }
        return false;
    }
};

//思路：题目的意思是，给出一个数组，从头开始以自己的值进行index的跳跃，如果能到达或者超越数组末尾就返回true，否则false
//1.维护一个变量reach，表示到达的最远位置，遍历数组，如果reach到达最后一位或者小于i跳出循环。
//2.使用dp，和1相似，设dp为当前位置及之前所能到达的最远位置，跟1的reach相同，状态转移方程为 dp[i] = max(dp[i-1], i+nums[i]);