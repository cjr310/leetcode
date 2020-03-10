// Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

// For example:
// Given binary tree [3,9,20,null,null,15,7],

//     3
//    / \
//   9  20
//     /  \
//    15   7

// return its level order traversal as:

// [
//   [3],
//   [9,20],
//   [15,7]
// ]

#include<vector>
#include<queue>

using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };


//bfs
class Solution{
    vector<vector<int>> levelOrder(TreeNode* root){
        if(!root) return {};
        vector<vector<int>> res;
        queue<TreeNode* >q{{root}};
        while(!q.empty())
        {
            vector<int> oneLevel;
            for(int i=q.size(); i>0; i--){
            TreeNode* m = q.front(); q.pop();
            oneLevel.push_back(m->val);
            if(m->left) q.push(m->left);
            if(m->right) q.push(m->right);
            }
            res.push_back(oneLevel);
        }
        return res;
    }
};


//dfs
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        levelorder(root, 0, res);
        return res;
    }
    void levelorder(TreeNode* node, int level, vector<vector<int>>& res){
        if(!node) return;
        if(res.size()==level) res.push_back({});
        res[level].push_back(node->val);
        if(node->left) levelorder(node->left, level+1, res);
        if(node->right) levelorder(node->right, level+1, res);
    }
};
//思路：dfs中的if(res.size()==level)表示如果当前层数在res里是否有创建，没有就创建一个新的vector来存放这层的数。