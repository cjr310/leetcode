// Say you have an array for which the ith element is the price of a given stock on day i.

// Design an algorithm to find the maximum profit. You may complete at most two transactions.

// Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

// Example 1:

// Input: [3,3,5,0,0,3,1,4]
// Output: 6
// Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
//              Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

// Example 2:

// Input: [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
//              Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
//              engaging multiple transactions at the same time. You must sell before buying again.

// Example 3:

// Input: [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transaction is done, i.e. max profit = 0.




#include <vector>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int K=2;
        vector<vector<int>> hold(K, vector<int>(prices.size(),0)), unhold(K, vector<int>(prices.size(), 0));
        for(int i=0; i<K;i++){
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
};

// 思路：假设买入记为交易，那么状态是3维的，分别是当前天数i，截至今天交易的次数j，今天是否拥有股票。故状态转移方程为：
// hold[i][j] = max(unhold[i-1][j-1] - prices[i], hold[i-1][j]);
// unhold[i][j] = max(unhold[i-1][j], hold[i-1][j]+prices[i]);
//然后定义边界问题
