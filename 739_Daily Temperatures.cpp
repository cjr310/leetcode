//  Given a list of daily temperatures T, return a list such that, 
// for each day in the input, tells you how many days you would have to wait until a warmer temperature. 
// If there is no future day for which this is possible, put 0 instead.

// For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

// Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100]. 
#include <vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> res(n,0);
        stack<int> st;
        for(int i=0; i<T.size(); ++i){
            while(!st.empty() && T[i]>T[st.top()]){
                auto t = st.top();
                st.pop();
                res[t] = i-t;
            }
            st.push(i);
        }
        return res;
    }
};

//思路：先建立一个栈，用栈记录各个数的位置，遍历原数组，栈顶元素为之前未满足条件的元素，如果当前元素大于栈顶元素证明符合条件，
//栈顶元素出栈，因为这样能保证每次入栈的元素是递减的。
