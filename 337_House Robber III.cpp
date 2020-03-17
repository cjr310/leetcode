// The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

// Determine the maximum amount of money the thief can rob tonight without alerting the police.

// Example 1:

// Input: [3,2,3,null,3,null,1]

//      3
//     / \
//    2   3
//     \   \ 
//      3   1

// Output: 7 
// Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
// Example 2:

// Input: [3,4,5,1,3,null,1]

//      3
//     / \
//    4   5
//   / \   \ 
//  1   3   1

// Output: 9
// Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.


#include<unordered_map>
#include<iostream>
#include<algorithm>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };


class Solution {
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode* , int> m;
        return helper(root, m);
    }
    int helper(TreeNode* root, unordered_map<TreeNode* , int> &m){
        if(!root) return 0;
        if(m.count(root)) return m[root];
        int val = 0;
        if(root->left) val += helper(root->left->left, m) + helper(root->left->right, m);
        if(root->right) val += helper(root->right->left, m) + helper(root->right->right, m);
        val = max(val + root->val, helper(root->left, m)+helper(root->right, m));
        m[root] = val;
        return val;
    }
};


//思路：这道题是强盗系列的第三题，题目要求是在二叉树的相邻的节点不能同时抢劫，那么可以使用递归，
//对于每棵二叉树来说，如果抢劫了父亲节点，那么左右子树就不能抢劫了，只能再到子树的下一层的左右子树抢劫。
//所以有抢劫root和不抢root两种情况。
//故有递归 val = max(val + root->val, helper(root->left, m)+helper(root->right, m));