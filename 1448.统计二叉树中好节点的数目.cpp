/*
 * @lc app=leetcode.cn id=1448 lang=cpp
 *
 * [1448] 统计二叉树中好节点的数目
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
    int counts = 0;
    int goodNodes(TreeNode* root) {
        if(root == nullptr) return counts;
        traverse(root, root->val);
        return counts;
    }
    void traverse(TreeNode* root, int curMaxValue){
        if(root == nullptr) return;
        if(root->val >= curMaxValue){
            counts++;
            curMaxValue = root->val;
        }
        traverse(root->left, curMaxValue);
        traverse(root->right, curMaxValue);
    }
};
// @lc code=end

