/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    int findBottomLeftValue(TreeNode* root) {
        int res = root->val;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int sz = q.size();
            vector<int> leftVal;
            for(int i = 0; i < sz; i++){
                TreeNode* cur = q.front();
                q.pop();
                if(cur->left != nullptr) {
                    q.push(cur->left);
                    leftVal.push_back(cur->left->val);
                }
                if(cur->right != nullptr){
                    q.push(cur->right);
                    leftVal.push_back(cur->right->val);
                }
            }
            if(leftVal.size()>0) res = leftVal[0];
        }
        return res;

    }
};
// @lc code=end

