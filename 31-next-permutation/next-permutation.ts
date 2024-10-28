/**
 Do not return anything, modify nums in-place instead.
 */
function nextPermutation(nums: number[]): void {
    let n = nums.length;
    let index = -1;

    // Step 1: Find the first decreasing element from the end
    for (let i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            index = i;
            break;
        }
    }

    if (index === -1) {
        // If no next permutation is possible, reverse the entire array
        nums.reverse();
        return;
    }

    // Step 2: Find the element just larger than nums[index] and swap
    for (let i = n - 1; i > index; i--) {
        if (nums[i] > nums[index]) {
            [nums[i], nums[index]] = [nums[index], nums[i]]; // Swap elements
            break;
        }
    }

    // Step 3: Reverse the remaining elements after the index
    let left = index + 1;
    let right = n - 1;
    while (left < right) {
        [nums[left], nums[right]] = [nums[right], nums[left]];
        left++;
        right--;
    }
}
