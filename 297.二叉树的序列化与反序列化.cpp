/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string SEP = ",";
    string NULL_STR = "#";

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr){
            return string(NULL_STR) + SEP;
        }

        string res = to_string(root->val) + SEP;
        res += serialize(root->left);
        res += serialize(root->right);

        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        LinkedList<string> nodes;
        string cur = "";
        for(char &c: data){
            if(c == SEP){
                nodes.push_back(cur);
                cur = "";
            }else{
                cur += c;
            }
        }
        return deserialize(nodes);
    }

    TreeNode* deserialize(LinkedList<string> &nodes){
        if(nodes.empty()) return nullptr;
        string first = nodes.front(); nodes.pop_front();
        if(first == NULL_STR) return nullptr;
        TreeNodes* root = new TreeNode(stoi(first));

        root->left = deserialize(nodes);
        root->right = deserialize(nodes);

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

