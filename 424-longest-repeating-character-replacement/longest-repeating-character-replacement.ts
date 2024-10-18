function characterReplacement(s: string, k: number): number {
    let right = 0;
    let left = 0;
    let len = 0;
    let maxFreq = 0;
    let n = s.length;
    let mp = new Map<string, number>();
    while (right < n) {
        let char = s[right];
        mp.set(char, (mp.get(char) || 0) + 1);
        maxFreq = Math.max(maxFreq, mp.get(char));
        if ((right - left + 1) - maxFreq > k) {
            const leftChar = s[left];
            mp.set(leftChar, mp.get(leftChar)! - 1);
            left++;
        }
        len = Math.max(len, right - left + 1);
        right++;

    }
    return len;
};