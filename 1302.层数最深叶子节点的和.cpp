/*
 * @lc app=leetcode.cn id=1302 lang=cpp
 *
 * [1302] 层数最深叶子节点的和
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
    int deepestLeavesSum(TreeNode* root) {
        int res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            int levelValue = 0;
            for(int i = 0; i < sz; i++){
                TreeNode* cur = q.front();
                q.pop();
                if(cur->left != nullptr){
                    q.push(cur->left);
                }
                if(cur->right != nullptr){
                    q.push(cur->right);
                }
                levelValue += cur->val;
            }
            res = levelValue;
        }
        return res;
    }
};
// @lc code=end

