function nextGreaterElement(nums1: number[], nums2: number[]): number[] {
    const ans: number[] = [];
    const st: number[] = [];
    const nextGreaterMap = new Map<number, number>();

    for (let i = nums2.length - 1; i >= 0; i--) {
        while (st.length > 0 && st[st.length - 1] <= nums2[i]) {
            st.pop();
        }

        if (st.length === 0) {
            nextGreaterMap.set(nums2[i], -1);
        } else {
            nextGreaterMap.set(nums2[i], st[st.length - 1]);
        }
        st.push(nums2[i]);
    }
    for (let num of nums1) {
        ans.push(nextGreaterMap.get(num) ?? -1);
    }

    return ans;
}