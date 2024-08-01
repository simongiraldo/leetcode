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
    TreeNode* bstToGst(TreeNode* root) {
        if(root == NULL) return NULL;

        greaterSum(root);

        return root;
    }

    TreeNode* greaterSum(TreeNode* root) {
        if(root == NULL) return NULL;

        TreeNode* rightSum = greaterSum(root->right);
        if(rightSum) {
            root->val += rightSum->val;
        }

        if(root->left) {
            TreeNode* some = root->left;
            while(some->right) {
                some = some->right;
            }
            some->val += root->val;
            
            return greaterSum(root->left);
        }

        return root;
    }
};