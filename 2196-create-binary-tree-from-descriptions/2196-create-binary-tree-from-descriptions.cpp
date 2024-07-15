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
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        unordered_map <int, TreeNode*> map;
        unordered_map <int, int> parentCount;
        unordered_map <int, int> childCount;

        for(int i = 0; i < d.size(); i++){
            if(map.find(d[i][0]) == map.end()){
                TreeNode* createNode = new TreeNode(d[i][0]);
                map[d[i][0]] = createNode;
            }
            if(map.find(d[i][1]) == map.end()){
                TreeNode* createNode = new TreeNode(d[i][1]);
                map[d[i][1]] = createNode;
            }
            if(d[i][2]) map[d[i][0]]->left = map[d[i][1]];
            else map[d[i][0]]->right = map[d[i][1]];

            parentCount[d[i][0]]++;
            childCount[d[i][1]]++;
        }

        TreeNode* answer;
        for(auto &it : map){
            if(parentCount.find(it.first) != parentCount.end() && childCount.find(it.first) == childCount.end()){
                // means return parent node which has no parent...
                answer = it.second;
                break;
            }
        }
        return answer;
    }
};