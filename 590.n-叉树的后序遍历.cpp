/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N 叉树的后序遍历
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
    vector<int> res;
    vector<int> postorder(Node* root) {
        traverse(root);
        return res;
    }
    void traverse(Node* root){
        if(root == nullptr) return;
        for(int i = 0; i < root->children.size(); i++){
            traverse(root->children[i]);
        }
        res.push_back(root->val);
    }
};
// @lc code=end

