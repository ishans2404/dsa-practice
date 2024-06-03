/*
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

static const bool Booster = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return true;
}();


void parse_input_and_solve(std::ofstream& out, std::string& s) {
    vector<string> res;
    istringstream iss(s);
    string word;
    while(getline(iss, word, ',')) res.push_back(word);
    out << log2(res.size()+1) << endl;
}

bool Solve = [](){
    std::ofstream out("user.out");
    for (std::string s; std::getline(std::cin, s);) {
        parse_input_and_solve(out, s);
    }
    out.flush();
    exit(0);
    return true;
}();

*/

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
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> nodes;
        int height = 0;
        int count = 0;
        TreeNode* current;
        if(!root) return 0;
        nodes.push(root);
        while(!nodes.empty()) {
            height++;
            count = nodes.size();
            while(count--) {
                current = nodes.front();
                if(current->left) nodes.push(current->left);
                if(current->right) nodes.push(current->right);
                nodes.pop();
            }
        }
        return height;
    }
};