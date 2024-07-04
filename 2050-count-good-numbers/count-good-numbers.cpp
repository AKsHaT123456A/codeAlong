class Solution {
private:
    long long mod = 1e9+7;

    long long modExp(long long base, long long exp, long long mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

public:
    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2; 
        long long oddCount = n / 2;    

        long long result = (modExp(5, evenCount, mod) * modExp(4, oddCount, mod)) % mod;
        return result;
    }
};
