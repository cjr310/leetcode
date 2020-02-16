// Given a non negative integer number num. 
// For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.
// Example 1:

// Input: 2
// Output: [0,1,1]

// Example 2:

// Input: 5
// Output: [0,1,1,2,1,2]
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res={0};
        for(int i=1; i<=num; ++i){
            if(i%2==0) res.push_back(res[i/2]);
            else res.push_back(res[i/2]+1);
        }
        return res;
    }
};


//简化
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>dp(num+1,0);
        dp[0] = 0;
        for(int i=1; i<=num; i++)
            dp[i] = dp[i/2] + i%2; 
        return dp;
    }
};
//思路： 找规律，偶数1的个数等于偶数/2里1的个数，奇数1的个数等于奇数/2里1的个数加1；