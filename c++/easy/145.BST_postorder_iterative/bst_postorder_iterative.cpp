#include <vector>
#include <stack>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if (root == NULL) return postorder;

        stack<long int> st;
        long int memoryPtrInt;
        TreeNode* ptr = root;

        while (ptr != NULL || !st.empty()) {
            if (ptr) {
                memoryPtrInt = reinterpret_cast<long int>(ptr);
                st.push(memoryPtrInt);
                ptr = ptr->left;
            } else {
                memoryPtrInt = st.top();
                st.pop();
                if (memoryPtrInt > 0) {
                    st.push(-memoryPtrInt);
                    ptr= reinterpret_cast<TreeNode*>(memoryPtrInt);
                    ptr = ptr->right;
                } else {
                    ptr = reinterpret_cast<TreeNode*>(-memoryPtrInt);
                    postorder.push_back(ptr->val);
                    ptr = NULL;
                }
            }
        }

        return postorder;
    }
};