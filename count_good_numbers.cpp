class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long power(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1)
                result = (result * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2;
        long long oddCount = n / 2;

        long long evenWays = power(5, evenCount, MOD);
        long long oddWays = power(4, oddCount, MOD);

        return (evenWays * oddWays) % MOD;
    }
};

