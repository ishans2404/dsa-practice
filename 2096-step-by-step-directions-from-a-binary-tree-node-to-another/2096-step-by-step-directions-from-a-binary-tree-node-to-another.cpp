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
    bool findPath(TreeNode* root, int target, string& path) {
        if(!root) return false;
        if(root->val == target) return true;

        path += "L"; // left subtree
        if(findPath(root->left, target, path)) return true;
        path.pop_back();

        path += "R"; // right subtree
        if(findPath(root->right, target, path)) return true;
        path.pop_back();

        return false;        
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        string startPath, destPath;

        findPath(root, startValue, startPath);
        findPath(root, destValue, destPath);

        string dirs;
        int commonLen = 0;

        while(commonLen < startPath.length() && commonLen < destPath.length() && startPath[commonLen] == destPath[commonLen]) commonLen++; // common path length

        for(int i=0; i < startPath.length() - commonLen; i++) dirs += "U";  // add u for start to common ancestor
        for(int i=commonLen; i < destPath.length(); i++) dirs += destPath[i];  // add dirs form common ancestor to dest

        return dirs;
    }
};