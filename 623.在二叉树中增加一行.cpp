/*
 * @lc app=leetcode.cn id=623 lang=cpp
 *
 * [623] 在二叉树中增加一行
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
    int targetVal;
    int targetDepth;
    int currentDepth = 0;
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        targetDepth = depth;
        targetVal = val;
        if(targetDepth == 1){
            TreeNode* newRoot = new TreeNode(targetVal);
            newRoot->left = root;
            return newRoot;
        }
        traverse(root);
        return root;
    }
    void traverse(TreeNode* root){
        if(root == nullptr) return ;
        currentDepth++;
        if(currentDepth == targetDepth - 1){
            TreeNode* newLeft = new TreeNode(targetVal);
            TreeNode* newRight = new TreeNode(targetVal);
            newLeft->left = root->left;
            newRight->right = root->right;
            root->left = newLeft;
            root->right = newRight;
        }
        traverse(root->left);
        traverse(root->right);
        currentDepth--;
    }
};
// @lc code=end

