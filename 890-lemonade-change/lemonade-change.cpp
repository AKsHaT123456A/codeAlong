class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveDollarCount = 0;
        int tenDollarCount = 0;
        
        for (int bill : bills) {
            if (bill == 5) {
                fiveDollarCount++;
            } else if (bill == 10) {
                if (fiveDollarCount == 0) {
                    return false;
                }
                fiveDollarCount--;
                tenDollarCount++;
            } else if (bill == 20) {
                if (tenDollarCount > 0 && fiveDollarCount > 0) {
                    tenDollarCount--;
                    fiveDollarCount--;
                } else if (fiveDollarCount >= 3) {
                    fiveDollarCount -= 3;
                } else {
                    return false;
                }
            }
        }
        
        return true;
    }
};