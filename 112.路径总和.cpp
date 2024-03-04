/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    // int curSum = 0;
    // bool found = false;
    // bool hasPathSum(TreeNode* root, int targetSum) {
    //     traverse(root, targetSum);
    //     return found;
    // }
    // void traverse(TreeNode* root, int targetSum){
    //     if(root == nullptr) return ;
    //     curSum += root->val;
    //     if(root->left == nullptr && root->right == nullptr){
    //         if(curSum == targetSum) found = true;
    //     }
    //     traverse(root->left, targetSum);
    //     traverse(root->right, targetSum);
    //     curSum -= root->val;
    // }
    bool hasPathSum(TreeNode* root, int targetSum){
        if(root == nullptr) return false;
        else if(root->left == nullptr && root->right == nullptr) return targetSum == root->val;
        return hasPathSum(root->left, targetSum-root->val) || hasPathSum(root->right, targetSum-root->val);
    }
};
// @lc code=end

