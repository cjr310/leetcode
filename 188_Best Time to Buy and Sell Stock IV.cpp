// Say you have an array for which the i-th element is the price of a given stock on day i.

// Design an algorithm to find the maximum profit. You may complete at most k transactions.

// Note:
// You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

// Example 1:

// Input: [2,4,1], k = 2
// Output: 2
// Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

// Example 2:

// Input: [3,2,6,5,0,3], k = 2
// Output: 7
// Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
//              Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.


#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) return 0;
        if(k==0) return 0;
        if(k > prices.size()/2) return maxProfit2(prices);
        vector<vector<int>> hold(k, vector<int>(prices.size(),0)), unhold(k, vector<int>(prices.size(), 0));
        for(int i=0; i<k;i++){
            for(int j=0; j<prices.size(); j++){
                if(j==0){
                    hold[i][j] = -prices[j];
                    unhold[i][j] = 0;
                }
                else{
                    hold[i][j] = max(hold[i][j-1], (i==0?0:unhold[i-1][j-1]) - prices[j]);
                    unhold[i][j] = max(hold[i][j-1] + prices[j], unhold[i][j-1]);
                }
            }
        }
        return unhold.back().back();
    }
    int maxProfit2(vector<int>& prices){
        int res=0;
        for(int i =1; i<(int)prices.size(); i++){
            if(prices[i-1]<prices[i]){
                res += prices[i]-prices[i-1];
            }
        }
        return res;
    }
};

//思路：这题是系列3的拓展，假设买入记为交易，那么状态是3维的，分别是当前天数i，截至今天交易的次数j，今天是否拥有股票。故状态转移方程为：
// hold[i][j] = max(unhold[i-1][j-1] - prices[i], hold[i-1][j]);
// unhold[i][j] = max(unhold[i-1][j], hold[i-1][j]+prices[i]);
//然后定义边界问题
//注意如果交易次数远大于天数，就回到系列2的情况，只需遍历所有数，只要当天价格比前一天高就加入最后的结果。