/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */
function maxDepth(root: TreeNode | null): number {
    if (root == null) return 0;
    let lh: number = maxDepth(root.left);
    let rh: number = maxDepth(root.right);
    return 1 + Math.max(lh, rh);
}
function isBalanced(root: TreeNode | null): boolean {
    if(root==null)return true;
    let left:number=maxDepth(root.left);
    let right:number=maxDepth(root.right);
    return Math.abs(left-right)<=1 && isBalanced(root.left) && isBalanced(root.right);
};