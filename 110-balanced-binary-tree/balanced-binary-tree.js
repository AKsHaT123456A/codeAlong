/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
function maxDepth(root){
    if (root == null) return 0;
    let lh= maxDepth(root.left);
    let rh = maxDepth(root.right);
    return 1 + Math.max(lh, rh);
}
function isBalanced(root) {
    if(root==null)return true;
    let left=maxDepth(root.left);
    let right=maxDepth(root.right);
    return Math.abs(left-right)<=1 && isBalanced(root.left) && isBalanced(root.right);
};