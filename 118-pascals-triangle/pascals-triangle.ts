function generate(numRows: number): number[][] {
    let ans: number[][] = [];
    for (let row = 0; row < numRows; row++) {
        ans[row] = new Array(row + 1).fill(0);
        ans[row][0] = 1;
        ans[row][row] = 1;
        for (let col = 1; col < row; col++) {
            ans[row][col] = ans[row - 1][col - 1] + ans[row - 1][col];
        }
    }
    return ans;
}
