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
function FindMax(root: TreeNode | null, maxi: { value: number }): number {
    if (root == null) return 0;
    let lh: number = Math.max(0, FindMax(root.left, maxi))
    let rh: number = Math.max(0, FindMax(root.right, maxi))
    maxi.value = Math.max(maxi.value, lh + rh + root.val)
    return Math.max(lh, rh) + root.val;
}

function maxPathSum(root: TreeNode | null): number {
    let maxi = { value: Number.MIN_SAFE_INTEGER };
    FindMax(root, maxi);
    return maxi.value;
};