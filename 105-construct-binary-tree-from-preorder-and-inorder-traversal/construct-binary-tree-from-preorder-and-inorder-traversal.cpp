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
  TreeNode*f(int &i,int l,int h,vector<int>&pre,unordered_map<int,int>&mp)
{
    if(l>h) return NULL;
    int id=mp[pre[i]];
    if(id<l || id>h) return NULL;
    TreeNode*root=new TreeNode(pre[i]);
    i++;
    root->left=f(i,l,id-1,pre,mp);
    root->right=f(i,id+1,h,pre,mp);
    return root;
}
TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
    int n=pre.size();
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++) mp[in[i]]=i;
    int i=0;
    return f(i,0,n-1,pre,mp);
}
};