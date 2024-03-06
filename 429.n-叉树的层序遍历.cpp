/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(root == nullptr) return res;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            vector<int> level;
            for(int i = 0; i < sz; i++){
                Node* cur = q.front();
                q.pop();
                level.push_back(cur->val);
                for(auto child : cur->children){
                    q.push(child);
                }
            }
            res.push_back(level);
        }
        return res;
    }
};
// @lc code=end

