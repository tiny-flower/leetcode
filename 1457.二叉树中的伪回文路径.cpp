/*
 * @lc app=leetcode.cn id=1457 lang=cpp
 *
 * [1457] 二叉树中的伪回文路径
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
    vector<int>cur_path {0,0,0,0,0,0,0,0,0,0};
    int pseudoPalindromicPaths (TreeNode* root) {
        if(root == nullptr) return 0;
        traverse(root);
        return res;
    }
    void traverse(TreeNode* root){
        if(root == nullptr) return;
        if(cur_path[root->val] == 0){
            cur_path[root->val] = root->val;
        }else {
            cur_path[root->val] ^= root->val;
        }
        if(root->left == nullptr && root->right == nullptr){
            int counts = 0;
            for (auto v : cur_path){
                if(v != 0){
                    counts++;
                }
            }
            if(counts == 1 || counts ==0 ) res++;
        }
        traverse(root->left);
        traverse(root->right);
        cur_path[root->val] ^= root->val;
    }
};
// @lc code=end

