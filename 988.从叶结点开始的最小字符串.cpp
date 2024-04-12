/*
 * @lc app=leetcode.cn id=988 lang=cpp
 *
 * [988] 从叶结点开始的最小字符串
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
    string path;
    string res = "";
    string smallestFromLeaf(TreeNode* root) {
        traverse(root);
        return res;
    }
    void traverse(TreeNode* root){
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr){
            path += (char)('a'+root->val);
            reverse(path.begin(), path.end());
            string s = path;
            if(res.empty() || res.compare(s) > 0){
                res = s;
            }
            reverse(path.begin(), path.end());
            path.pop_back();
            return;
        }
        path+=(char)('a' + root->val);
        traverse(root->left);
        traverse(root->right);
        path.pop_back();
    }
};
// @lc code=end

