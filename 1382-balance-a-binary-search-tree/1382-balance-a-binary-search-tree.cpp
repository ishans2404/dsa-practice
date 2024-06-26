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
    vector<int> v;
    void inorder(TreeNode* node) {
        if(!node) return;
        inorder(node->left);
        v.push_back(node->val);
        inorder(node->right);
    }

    TreeNode* balance(int l, int r) {
        if(l > r) return nullptr;
        int m = l + (r-l) / 2;
        TreeNode* left = balance(l, m-1);
        TreeNode* right = balance(m+1, r);
        return new TreeNode(v[m], left, right);
    }

    TreeNode* balanceBST(TreeNode* root) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        inorder(root);
        int n = v.size();
        return balance(0, n-1);
    }
};