// Given a binary tree, find its minimum depth.

// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

// Note: A leaf is a node with no children.

// Example:

// Given binary tree [3,9,20,null,null,15,7],

//     3
//    / \
//   9  20
//     /  \
//    15   7

// return its minimum depth = 2.





#include<iostream>
#include<queue>

using namespace std;


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

  class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left) return 1+minDepth(root->right);
        if(!root->right) return 1+minDepth(root->left);
        return min(minDepth(root->left), minDepth(root->right))+1;
    }
};


class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int res=0;
        queue<TreeNode*> q{{root}};
        while(!q.empty()){
            res++;
            for(int i =q.size(); i>0; i--)
            {
                TreeNode* m = q.front(); q.pop();
                if(!m->left&&!m->right) return res;
                if(m->left) q.push(m->left);
                if(m->right) q.push(m->right);
            }
            
        }
        return -1;
    }
};

//思路:bfs,遍历每一层遇到叶子节点即是最小深度。