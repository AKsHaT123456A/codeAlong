/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool dfs(TreeNode* root, vector<TreeNode*>& path, int data) {
        if (root == NULL)
            return false;
        path.push_back(root);
        if (root->val == data)
            return true;
        if (dfs(root->left, path, data) || dfs(root->right, path, data))
            return true;
        path.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;
        dfs(root, path1, p->val);
        dfs(root, path2, q->val);

        int n1 = path1.size();
        int n2 = path2.size();

        TreeNode* matched = NULL;
        int len = min(n1, n2);
        for (int i = 0; i < len; i++) {
            if (path1[i] == path2[i]) {
                matched = path1[i];
            } else {
                break;
            }
        }

        return matched;
    }
};