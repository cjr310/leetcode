//  Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

// Example:
// Given a binary tree

//           1
//          / \
//         2   3
//        / \     
//       4   5    

// Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

// Note: The length of path between two nodes is represented by the number of edges between them. 

#include<iostream>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int res=0;
        maxdepth(root, res);
        return res;
    }
    int maxdepth(TreeNode* node, int& res){
        if(!node) return 0;
        int left = maxdepth(node->left, res);
        int right = maxdepth(node->right, res);
        res = max(res, left+right);
        return max(left, right)+1;
    }
};

//思路：使用递归找出左右子树的深度，题目所求return的应该是根节点下最长子树的节点数目。