/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
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
    int curDep = 0;
    int maxDep = 0;
    int maxDepth(Node* root) {
        traverse(root);
        return maxDep;
    }
    void traverse(Node* root){
        if(root == nullptr) return;
        curDep++;
        maxDep = max(maxDep, curDep);
        for(int i = 0; i < root->children.size(); i++){
            traverse(root->children[i]);
        }
        curDep--;
    }
};
// @lc code=end

