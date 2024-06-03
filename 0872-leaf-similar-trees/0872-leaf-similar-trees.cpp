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
    void leafNodes(TreeNode* root, string& str) {
        if(!root) return;
        if(!root->left && !root->right) {
            str += to_string(root->val) + " ";
            return;
        }
        if(root->left) leafNodes(root->left, str);
        if(root->right) leafNodes(root->right, str);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string s1 = "", s2 = "";
        leafNodes(root1, s1);
        leafNodes(root2, s2);
        return (s1 == s2);
    }
};