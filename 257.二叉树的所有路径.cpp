/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    vector<string> res;
    vector<int> path;
    void transToString(){
        string temp = "";
        for(int i = 0; i < path.size() -1; i++){
            temp += to_string(path[i]);
            temp += "->";
        }
        temp += to_string(path[path.size()-1]);
        res.push_back(temp);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == nullptr) return res;
        traverse(root);
        return res;
    }
    void traverse(TreeNode* root){
        if(root == nullptr) return ;
        path.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr) transToString();
        traverse(root->left);
        traverse(root->right);
        path.pop_back();
    }
};
// @lc code=end

