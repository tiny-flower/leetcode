/*
 * @lc app=leetcode.cn id=993 lang=cpp
 *
 * [993] 二叉树的堂兄弟节点
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
    TreeNode *leftParent, *rightParent;
    int leftDepth, rightDepth;
    int leftTarget, rightTarget;
    bool isCousins(TreeNode* root, int x, int y) {
        leftTarget = x, rightTarget = y;
        if(root == nullptr) return false;
        traverse(root, 0, nullptr);
        if(leftDepth == rightDepth && rightParent != leftParent){
            return true;
        } else return false;
    }
    void traverse(TreeNode* root, int depth, TreeNode* parent){
        if(root == nullptr) return;
        if(root->val == leftTarget){
            leftParent = parent;
            leftDepth = depth;
        }
        if(root->val == rightTarget){
            rightParent = parent;
            rightDepth = depth;
        }
        traverse(root->left, depth+1, root);
        traverse(root->right, depth+1, root);
    }
};
// @lc code=end

