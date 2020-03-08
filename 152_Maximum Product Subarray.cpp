// Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

// Example 1:

// Input: [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.

// Example 2:

// Input: [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.


#include <vector>
#include<iostream>
using namespace std;




class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int n = nums.size();
        vector<int> f(n, 0), g(n, 0);
        f[0]=nums[0];
        g[0]=nums[0];
        for(int i=1;i<n;i++){
            f[i] = max(max((f[i-1]*nums[i]), g[i-1]*nums[i]), nums[i]);
            g[i] = min(min((f[i-1]*nums[i]), g[i-1]*nums[i]), nums[i]);
            res = max(res, f[i]);
        }
        return res;
    }
};

//思路： 分析：由于数可能是正负两种，由当前值乘于前一状态的最大或最小值再与当前值比大小，得出最大值
//状态转移方程： f[i-1]为最大，g[i-1]为最小 
// dp[i] = max( max(f[i-1]*nums[i], g[i-1]*nums[i]), nums[i])