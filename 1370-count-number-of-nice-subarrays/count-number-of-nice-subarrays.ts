function numberOfSubarrays(nums: number[], k: number): number {
    let right = 0;
    let left = 0;
    let oddCount = 0;
    let ans = 0;
    let prefix = 0;  

    while (right < nums.length) {
        if (nums[right] % 2 !== 0) {
            oddCount++;
            prefix = 0;
        }

        while (oddCount === k) {
            if (nums[left] % 2 !== 0) oddCount--;
            left++;
            prefix++;
        }

        ans += prefix;
        right++;
    }

    return ans;
}
