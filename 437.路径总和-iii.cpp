/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
    unordered_map<int, int> preSumCount;
    int pathSum, targetSum;
    int res = 0;
    int pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return 0;
        this->pathSum = 0;
        this->preSumCount[0] = 1;
        this->targetSum = targetSum;
        traverse(root);
        return res;
    }
    void traverse(TreeNode* root){
        if(root == nullptr) return;
        pathSum += root->val;
        traverse(root->left);
        traverse(root->right);
    }
};
// @lc code=end

