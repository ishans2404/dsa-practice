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
    void inorder(TreeNode* node, vector<TreeNode*>& values) {
        if (node == nullptr) return;
        inorder(node->left, values);
        values.push_back(node);
        inorder(node->right, values);
    }

    TreeNode* buildBalancedBST(vector<TreeNode*>& values, int left, int right) {
        if (left > right) return nullptr;
        
        int mid = left + (right - left) / 2;
        TreeNode* root = values[mid];
        root->left = buildBalancedBST(values, left, mid - 1);
        root->right = buildBalancedBST(values, mid + 1, right);
        
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        vector<TreeNode*> values;
        inorder(root, values);
        return buildBalancedBST(values, 0, values.size() - 1);
    }
};