function twoSum(nums: number[], target: number): number[] {
    for (let i = 0; i < nums.length; i++) {
        let a = nums[i];
        let b = target - a;
        let j = nums.indexOf(b);
        if (j !== -1 && j !== i) {
            return [i, j];
        }
    }
    return []; 
}
