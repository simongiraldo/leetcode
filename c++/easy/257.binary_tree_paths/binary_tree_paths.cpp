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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == nullptr) return {};

        vector<string> paths;

        findPaths(root, paths, "");

        return paths;
    }

    void findPaths(TreeNode* node, vector<string>& paths, string currentPath) {
        if(node == nullptr) return;

        if(!currentPath.empty()) currentPath += "->";
        currentPath += to_string(node->val);

        if(!node->left && !node->right) {
            paths.push_back(currentPath);
            return;
        }

        if(node->left) {
            findPaths(node->left, paths, currentPath);
        }

        if(node->right) {
            findPaths(node->right, paths, currentPath);
        }
    }
};