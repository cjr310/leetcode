// You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

// Find out how many ways to assign symbols to make sum of integers equal to target S.

// Example 1:
// Input: nums is [1, 1, 1, 1, 1], S is 3. 
// Output: 5
// Explanation: 

// -1+1+1+1+1 = 3
// +1-1+1+1+1 = 3
// +1+1-1+1+1 = 3
// +1+1+1-1+1 = 3
// +1+1+1+1-1 = 3

// There are 5 ways to assign symbols to make the sum of nums be target 3.
// Note:
// The length of the given array is positive and will not exceed 20.
// The sum of elements in the given array will not exceed 1000.
// Your output answer is guaranteed to be fitted in a 32-bit integer.

#include <unordered_map>
#include <vector>
using namespace std;


//dfs
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int res=0;
        helper(nums, S, 0, res );
        return res;
    }
    void helper(vector<int>& nums, long S, int start, int& res){
        if(start == nums.size()) {
            if(S==0) res++; return;
            }
        helper(nums, S-nums[start], start+1, res);
        helper(nums, S+nums[start], start+1, res);
        
    }
    
};

//dp
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n+1);
        dp[0][0] = 1;
        for(int i=0; i<n; i++){
            for(auto &a : dp[i]){
                int sum = a.first, count = a.second;
                dp[i+1][sum+nums[i]] += count;
                dp[i+1][sum-nums[i]] += count;
            }
        }
        return dp[n][S];
    }
    
};

//思路：1.dfs 写个递归，记录当前位置以及剩余数的sum，
//2. dp 维护数组dp[i][j] 为到第i-1个数且和为j的所有情况数。 
//dp转移方程 dp[i+1][sum+nums[i]] += count;
//           dp[i+1][sum-nums[i]] += count;
//count的意思是  dp[n]下每个dp[n][j]的值， 
//那么到i+1的时候把这些i的情况都加上