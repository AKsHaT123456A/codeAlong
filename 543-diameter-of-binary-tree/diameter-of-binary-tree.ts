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
interface IResult {
    getDiaAndHeight(input: IResultInput): number;
}
interface IResultInput {
    root: TreeNode | null;
}
class DiameterAndHeight implements IResult {
    maxDiameter: number;
    constructor() {
        this.maxDiameter = 0;
    }
    private calculateHeight(node: TreeNode | null): number {
        if (node === null) {
            return 0;
        }
        const leftHeight = this.calculateHeight(node.left);
        const rightHeight = this.calculateHeight(node.right);
        this.maxDiameter = Math.max(this.maxDiameter, leftHeight + rightHeight);
        return 1 + Math.max(leftHeight, rightHeight);
    }

    getDiaAndHeight(input: IResultInput): number {
        this.maxDiameter = 0;
        this.calculateHeight(input.root);
        return this.maxDiameter;
    }
}
function diameterOfBinaryTree(root: TreeNode | null): number {
    const diameterCalc = new DiameterAndHeight();
    return diameterCalc.getDiaAndHeight({ root });
};