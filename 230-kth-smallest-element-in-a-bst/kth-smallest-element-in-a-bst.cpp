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
    void inOrderTraversal(TreeNode* root, int k, vector<int>& arr) {
        if (!root || arr.size() >= k) 
            return;

        inOrderTraversal(root->left, k, arr);
        if (arr.size() < k) 
            arr.push_back(root->val);
        inOrderTraversal(root->right, k, arr);
    }
    
    int kthSmallest(TreeNode* root, int k) { 
        vector<int> arr;
        inOrderTraversal(root, k, arr);
        return arr[k - 1];
    }
};
