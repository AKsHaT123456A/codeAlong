function lengthOfLongestSubstring(s: string): number {
    let left = 0;
    let right = 0;
    let mpp = new Map();
    let len = 0;
    while (right < s.length) {
        if (mpp.has(s[right])) {
            left = Math.max(mpp.get(s[right])+1, left);
        }
        mpp.set(s[right], right);
        len = Math.max(len, right - left + 1);
        right++;
    }
    return len;
};