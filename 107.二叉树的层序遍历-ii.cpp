/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> level;
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* cur = q.front();
                q.pop();
                level.push_back(cur->val);
                if(cur->left != nullptr) q.push(cur->left);
                if(cur->right != nullptr) q.push(cur->right);
            }
            res.insert(res.begin(), level);
        }
        return res;
    }
};
// @lc code=end

