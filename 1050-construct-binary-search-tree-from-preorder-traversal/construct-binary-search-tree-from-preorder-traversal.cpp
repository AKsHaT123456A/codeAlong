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
    TreeNode* bstFromPreorderHelper(vector<int>& preorder, int& i, int upper_bound) {
        if (i == preorder.size() || preorder[i] > upper_bound) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = bstFromPreorderHelper(preorder, i, root->val);
        root->right = bstFromPreorderHelper(preorder, i, upper_bound);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return bstFromPreorderHelper(preorder, i, INT_MAX);
    }
};