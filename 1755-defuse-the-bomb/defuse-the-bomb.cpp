class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            int j = k;
            if (j == 0) {
                return ans;
            } else if (j > 0) {
                int sum = 0;
                while (j) {
                    int index = (i + j + n) % n;
                    sum += code[index];
                    j--;
                }
                ans[i] = sum;
            } else if (j < 0) {
                int sum = 0;
                while (j) {
                    int index = (i + j + n) % n;
                    sum += code[index];
                    j++;
                }
                ans[i] = sum;
            }
        }
        return ans;
    }
};