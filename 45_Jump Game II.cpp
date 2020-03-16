// Given an array of non-negative integers, you are initially positioned at the first index of the array.

// Each element in the array represents your maximum jump length at that position.

// Your goal is to reach the last index in the minimum number of jumps.

// Example:

// Input: [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2.
//     Jump 1 step from index 0 to 1, then 3 steps to the last index.
// Note:

// You can assume that you can always reach the last index.


#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int last = 0;//上一步能到的最远距离
        int cur =0;//当前能到的最远距离
        int res =0;
        for(int i=0;i<n-1;i++){
            cur = max(cur, nums[i] + i);
            if(i == last){
                res++;
                last = cur;
                if(last >= n-1) break;
            }
        }
        return res;
    }
};

//思路：维护2个变量，一个是当前这一步能到达的最远距离，一个是上一步能到达的最远距离。
//last相当于走完上一步之后，对最大范围里的每一步进行扫描范围，这样到达上一步的最大范围之后更新这一步的last。
//cur则是在走完上一步之后，在他的扫描范围内更新可以到达的最远值，每个元素更新一次。
