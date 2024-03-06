/*
 * @lc app=leetcode.cn id=1161 lang=cpp
 *
 * [1161] 最大层内元素和
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
    int maxLevelSum(TreeNode* root) {
        int maxDepth = 1;
        int curDepth = 1;
        int maxValue = INT_MIN;
        if(root == nullptr) return 0;
        queue<TreeNode*> q;
        q.push(root);
        if(root->val > maxValue){
            maxDepth = curDepth;
            maxValue = root->val;
        }
        while(!q.empty()){
            int sz = q.size();

            int curValue = 0;
            for(int i = 0; i < sz; i++){
                TreeNode* cur = q.front();
                q.pop();
                if(cur->left != nullptr){
                    q.push(cur->left);
                } 
                if(cur->right != nullptr){
                    q.push(cur->right);
                }
                curValue += cur->val;
            }
            if(curValue > maxValue){
                maxValue = curValue;
                maxDepth = curDepth;
            }
            curDepth++;
        }
        return maxDepth;
    }
};
// @lc code=end

