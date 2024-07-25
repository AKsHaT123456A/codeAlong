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
    void inOrderTraversal(TreeNode* &root, int &k, int &cnt, int& ans) {
        if (!root || cnt >= k)
            return;

        inOrderTraversal(root->left, k, cnt, ans);
        cnt++;
        if (cnt == k) {
            ans = root->val;
            return;
        }
        inOrderTraversal(root->right, k, cnt, ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        int cnt=0;
        inOrderTraversal(root, k, cnt, ans);
        return ans;
    }
};
