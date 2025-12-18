#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long countBinaryPalindromes(long long n) {
        if (n == 0) return 1;

        // Get bit length of n
        int L = 0;
        long long temp = n;
        while (temp > 0) {
            temp >>= 1;
            L++;
        }

        long long count = 1; // Count 0

        // Count palindromes of length < L
        for (int len = 1; len < L; ++len) {
            int half_len = (len + 1) / 2;
            count += (1LL << (half_len - 1));
        }

        // Count palindromes of length L <= n
        int half_len = (L + 1) / 2;
        long long p_start = 1LL << (half_len - 1);
        long long p_limit = n >> (L - half_len);

        count += (p_limit - p_start);

        // Check if palindrome formed by p_limit is <= n
        long long palindrome = createPalindrome(p_limit, L);
        if (palindrome <= n) {
            count++;
        }

        return count;
    }

private:
    long long createPalindrome(long long prefix, int length) {
        long long palindrome = prefix;
        long long suffix = prefix;

        if (length % 2 != 0) {
            suffix >>= 1; // Remove middle bit for odd length
        }

        // Reverse suffix
        long long reversed_suffix = 0;
        int suffix_len = length / 2;
        for (int i = 0; i < suffix_len; ++i) {
            reversed_suffix = (reversed_suffix << 1) | (suffix & 1);
            suffix >>= 1;
        }

        palindrome = (palindrome << suffix_len) | reversed_suffix;
        return palindrome;
    }
};


