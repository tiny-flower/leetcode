/*
 * @lc app=leetcode.cn id=1315 lang=cpp
 *
 * [1315] 祖父节点值为偶数的节点和
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
    int sum = 0;
    int sumEvenGrandparent(TreeNode* root) {
        if(root == nullptr) return sum;
        traverse(root);
        return sum;
    }
    void traverse(TreeNode* root){
        if(root == nullptr) return;
        if(root->val % 2 == 0){
            if(root->left != nullptr){
                if(root->left->left != nullptr) sum += root->left->left->val;
                if(root->left->right != nullptr) sum += root->left->right->val;
            }
            if(root->right != nullptr){
                if(root->right->left != nullptr) sum += root->right->left->val;
                if(root->right->right != nullptr) sum += root->right->right->val;
            }
        }
        traverse(root->left);
        traverse(root->right);
    }
};
// @lc code=end

