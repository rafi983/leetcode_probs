#include <vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;

        for (int b : bills) {
            if (b == 5) {
                ++five;
            } else if (b == 10) {
                if (five == 0) {
                    return false;
                }
                --five;
                ++ten;
            } else {
                if (ten > 0 && five > 0) {
                    --ten;
                    --five;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};

#ifdef LEMONADE_CHANGE_TEST
#include <iostream>

int main() {
    Solution sol;
    vector<int> a{5, 5, 5, 10, 20};
    vector<int> b{5, 5, 10, 10, 20};

    cout << boolalpha << sol.lemonadeChange(a) << "\n";
    cout << boolalpha << sol.lemonadeChange(b) << "\n";

    return 0;
}
#endif
