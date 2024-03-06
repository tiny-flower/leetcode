/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            int levelMax = INT_MIN;
            for(int i = 0; i < sz; i++){
                TreeNode* cur = q.front();
                q.pop();
                levelMax = max(cur->val, levelMax);
                if(cur->left != nullptr){
                    q.push(cur->left);
                }
                if(cur->right != nullptr){
                    q.push(cur->right);
                }
            }
            res.push_back(levelMax);
        }
        return res;
    }
};
// @lc code=end

