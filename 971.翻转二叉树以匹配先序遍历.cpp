/*
 * @lc app=leetcode.cn id=971 lang=cpp
 *
 * [971] 翻转二叉树以匹配先序遍历
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
    vector<int> res;
    int i = 0;
    vector<int> voyage;
    bool canFlip = true;

    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        this->voyage = voyage;
        traverse(root);
        if(canFlip){
            return res;
        }
        return {-1};
    }
    void traverse(TreeNode* root){
        if(root == nullptr || !canFlip) return;
        if(root->val != voyage[i++]){
            canFlip = false;
            return;
        }
        if(root->left != nullptr && root->left->val != voyage[i]){
            TreeNode* temp = root->left;
            root->left = root->right;
            root->right = temp;
            res.push_back(root->val);
        }
        traverse(root->left);
        traverse(root->right);
    }
};
// @lc code=end

