/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
//     int minDepth(TreeNode* root) {
//         if(root == nullptr) return 0;
//         int leftMin = minDepth(root->left);
//         int rightMin = minDepth(root->right);
//         //需要判断左子树完全为空，或右子树完全为空
//         // return 1 + (min(leftMin, rightMin)?min(leftMin, rightMin): max(leftMin, rightMin));
//         if(leftMin != 0 && rightMin !=0)
//             return 1 + min(leftMin, rightMin);
//         else if (rightMin == 0)
//             return 1 + leftMin;
//         else if(leftMin == 0)
//             return 1 + rightMin;
//         else return 1;

//     }
    int depth = 0;
    int res = 1000000;
    int minDepth(TreeNode* root){
        if(root == nullptr) return 0;
        traverse(root);
        return res;
    }
    void traverse(TreeNode* root){
        if(root == nullptr) return;
        depth++;
        if(root->left == nullptr and root->right == nullptr)
            res = min(res, depth);
        traverse(root->left);
        traverse(root->right);
        depth--;
    }
};
// @lc code=end

