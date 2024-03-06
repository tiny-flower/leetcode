/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if(root == nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            double totalNumber = 0;
            for(int i = 0; i < sz; i++){
                TreeNode* cur = q.front();
                q.pop();
                totalNumber += cur->val;
                if(cur->left != nullptr) q.push(cur->left);
                if(cur->right != nullptr) q.push(cur->right);
            }
            res.push_back(totalNumber/sz);
        }
        return res;
    }
};
// @lc code=end

