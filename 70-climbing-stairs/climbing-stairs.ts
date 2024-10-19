function climb(n: number, dp: Array<number>): number {
    if (n === 1 || n === 0) return 1;
    if (dp[n] !== -1) return dp[n];
    let jumpOne: number = climb(n - 1, dp);
    let jumpTwo: number = 0;
    if (n >= 2) jumpTwo = climb(n - 2, dp);
    return dp[n] = jumpOne + jumpTwo;
}

function climbStairs(n: number): number {
    let dp = new Array(n + 1).fill(-1);
    dp[1] = 1;
    dp[0] = 1;
    for (let i = 1; i <= n; i++) {
        let jumpOne: number = dp[i-1];
        let jumpTwo: number = 0;
        if (i >= 2) jumpTwo = dp[i-2];
        dp[i] = jumpOne + jumpTwo;
    }
    return dp[n];
}
