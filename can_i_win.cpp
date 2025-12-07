class Solution {
public:
    unordered_map<int, bool> memo;

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int sum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
        if (desiredTotal <= 0) return true;
        if (sum < desiredTotal) return false;

        return canWin(maxChoosableInteger, desiredTotal, 0);
    }

    bool canWin(int maxNum, int total, int used) {
        if (memo.count(used)) return memo[used];

        for (int i = 1; i <= maxNum; i++) {
            int mask = 1 << i;
            if (used & mask) continue;

            if (i >= total || !canWin(maxNum, total - i, used | mask)) {
                memo[used] = true;
                return true;
            }
        }

        memo[used] = false;
        return false;
    }
};

