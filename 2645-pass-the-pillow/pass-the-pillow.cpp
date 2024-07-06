class Solution {
public:
    int passThePillow(int n, int time) {
        int cycle = 2 * (n - 1);
        int etime = time % cycle;
        if (etime < n) {
            return etime + 1;
        } else {
            return 2 * n - etime - 1;
        }
    }
};
