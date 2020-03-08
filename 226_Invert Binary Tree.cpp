// Invert a binary tree.

// Example:

// Input:

//      4
//    /   \
//   2     7
//  / \   / \
// 1   3 6   9

// Output:

//      4
//    /   \
//   7     2
//  / \   / \
// 9   6 3   1

#include <iostream>
#include<stack>
using namespace std;


 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

// 思路：递归交换左右节点。
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        TreeNode* tmp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(tmp);
        return root;
    }
};
// 思路：非递归，利用栈通过先序遍历交换左右节点

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        stack<TreeNode*> m;
        m.push(root);
        while(!m.empty()){
            TreeNode* cur = m.top();
            m.pop();
            TreeNode* tmp = cur->left;
            cur->left = cur->right;
            cur->right = tmp;
            if(cur->right) m.push(cur->right);
            if(cur->left) m.push(cur->left);
        }
        return root;
        }
};