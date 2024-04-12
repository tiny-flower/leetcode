/*
 * @lc app=leetcode.cn id=1022 lang=cpp
 *
 * [1022] 从根到叶的二进制数之和
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
    int res = 0;
    int path = 0;
    int sumRootToLeaf(TreeNode* root) {
        if(root == nullptr ) return res;
        traverse(root);
        return res;
    }
    void traverse(TreeNode* root){
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr){
            res += path << 1;
            res += root->val;
            return;
        }
        path = path << 1;
        path += root->val;
        traverse(root->left);
        traverse(root->right);
        path = path >> 1;
    }
};
// @lc code=end

