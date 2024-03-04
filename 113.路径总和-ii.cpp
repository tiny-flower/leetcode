/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<vector<int>> res;
    vector<int> curPath;
    int target;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        traverse(root);
        return res;
    }
    void traverse(TreeNode* root){
        if(root == nullptr) return;
        curPath.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr){
            if(accumulate(curPath.begin(), curPath.end(), 0) == target){
                res.push_back(curPath);
            }
        }
        traverse(root->left);
        traverse(root->right);
        curPath.pop_back();
    }
};
// @lc code=end

