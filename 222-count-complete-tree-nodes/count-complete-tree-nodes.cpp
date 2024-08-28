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
    int bfs(TreeNode* root) {
        queue<TreeNode*> q;
        if(root==nullptr)return 0;
        q.push(root);
         int cnt=0;
        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            cnt++;
            if(front->left){
                q.push(front->left);
                }
            if(front->right){
                q.push(front->right);
                }

        }
        return cnt;
    }
    int countNodes(TreeNode* root) {
        return bfs(root);
    }
};