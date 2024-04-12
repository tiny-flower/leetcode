/*
 * @lc app=leetcode.cn id=987 lang=cpp
 *
 * [987] 二叉树的垂序遍历
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
    struct Triple{
        int row, col;
        TreeNode* node;
        Triple(TreeNode* node, int row, int col){
            this->node = node;
            this->row = row;
            this->col = col;
        }
    };
    vector<Triple> nodes;
    vector<vector<int>> verticalTraversal(TreeNode* root) { 
        vector<vector<int>> res;
        if (root == nullptr) return res;
        traverse(root, 0, 0);
        sort(nodes.begin(), nodes.end(), [](Triple a, Triple b){
            if(a.col == b.col && a.row == b.row){
                return a.node->val < b.node->val;
            }
            if(a.col == b.col){
                return a.row < b.row;
            }
            return a.col < b.col;
        });
        int preCol = INT_MIN;
        for(int i = 0; i < nodes.size(); i++){
            Triple cur = nodes[i];
            if(cur.col != preCol){
                res.push_back(vector<int>());
                preCol = cur.col;
            }
            res.back().push_back(cur.node->val);
        }
        return res;
    }
    void traverse(TreeNode* root, int row, int col){
        if(root == nullptr) return;
        nodes.emplace_back(root, row, col);
        traverse(root->left, row+1, col-1);
        traverse(root->right, row+1, col+1);
    }
};
// @lc code=end

