/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    // vector<vector<int>> levelOrder(TreeNode* root) {
    //     vector<vector<int>> res;
    //     if(root == nullptr) return res;
    //     queue<TreeNode*> q;
    //     q.push(root);
    //     while(!q.empty()){
    //         vector<int> level;
    //         int size = q.size();
    //         for(int i = 0; i < size; i++){
    //             TreeNode* cur = q.front();
    //             q.pop();
    //             level.push_back(cur->val);
    //             if(cur->left != nullptr) q.push(cur->left);
    //             if(cur->right != nullptr) q.push(cur->right);
    //         }
    //         res.push_back(level);
    //     }
    //     return res;
    // }
    vector<vector<int>> levelOrder(TreeNode* root){
        vector<vector<int>> result;
        dfs(root, 0, result);
        return result;
    }
    void dfs(TreeNode* root, int level, vector<vector<int>>& result){
        if(root == nullptr) return;
        if(level >= result.size()){
            result.push_back({});
        };
        result[level].push_back(root->val);
        dfs(root->left, level+1, result);
        dfs(root->right, level+1, result);
    }

};
// @lc code=end

