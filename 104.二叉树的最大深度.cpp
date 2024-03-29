/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    // int maxDepth(TreeNode* root) {
    //     if(root == nullptr)
    //         return 0;
    //     int leftMax = maxDepth(root->left);
    //     int rightMax = maxDepth(root->right);
    //     return 1 + max(leftMax, rightMax);

    // }

    int depth = 0;
    int res = 0;
    int maxDepth(TreeNode* root){
        traverse(root);
        return res;
    }
    void traverse(TreeNode* root){
        if(root == nullptr) return;
        depth++;
        res = max(res, depth);
        traverse(root->left);
        traverse(root->right);
        depth--;
    }
};
// @lc code=end

