// Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

// For example:
// Given binary tree [3,9,20,null,null,15,7],

//     3
//    / \
//   9  20
//     /  \
//    15   7

// return its bottom-up level order traversal as:

// [
//   [15,7],
//   [9,20],
//   [3]
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


class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return{};
        vector<vector<int>> res;
        queue<TreeNode*> q{{root}};
        while(!q.empty()){
            vector<int> oneLevel;
            for(int i=q.size(); i>0; i--){
                TreeNode* m =q.front(); q.pop();
                oneLevel.push_back(m->val);
                if(m->left) q.push(m->left);
                if(m->right) q.push(m->right);
            }
            res.insert(res.begin(),oneLevel);
        }
        return res;    
    }
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return{};
        vector<vector<int>> res;
        levelorderbottom(root, 0, res);
        return vector<vector<int>>(res.rbegin(), res.rend());
    }
    void levelorderbottom(TreeNode* node, int level, vector<vector<int>>& res){
        if(res.size()==level) res.push_back({});
        res[level].push_back(node->val);
        if(node->left) levelorderbottom(node->left, level+1, res);
        if(node->right) levelorderbottom(node->right, level+1, res);
    }
};

//思路：跟系列1相同只是最后存放的方式不一样而已。