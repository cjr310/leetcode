#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    vector<string> generateParenthesis(int n){
        vector<string> res;
        generateParenthesisDFS(n,n,"",res);
        return res;
    }
    void generateParenthesisDFS(int left, int right,string out, vector<string>&res){
        if(left>right) return;
        std::cout<<out<<std::endl;
        if(left==0&&right==0)res.push_back(out);
        else{
            if(left>0) {generateParenthesisDFS(left-1, right,out+'(', res);}
            if(right>0) {generateParenthesisDFS(left, right-1, out+')', res);}
        }
    }
};

// 思路：dfs，保证左括号数量要多与右括号