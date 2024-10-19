function climb(n: number, dp:Array<number>): number {
    if (n === 1 || n === 0) return 1;
    if (dp[n] !== -1) return dp[n];
    let jumpOne: number = climb(n - 1, dp);
    let jumpTwo: number = 0;
    if (n >= 2) jumpTwo = climb(n - 2, dp);
    return dp[n] = jumpOne + jumpTwo;
}

function climbStairs(n: number): number {
    let dp = new Array(n + 1).fill(-1);
    return climb(n, dp);
}
