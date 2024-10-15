function longestOnes(nums: number[], k: number): number {
    let left: number = 0;
    let right: number = 0;
    let zerosCount: number = 0;
    let len: number = 0;

    while (right < nums.length) {
        if (nums[right] === 0) {
            zerosCount++;
        }
        while (zerosCount > k) {
            if (nums[left] === 0) {
                zerosCount--;
            }
            left++; 
        }
        len = Math.max(len, right - left + 1);
        right++;
    }

    return len;
}
