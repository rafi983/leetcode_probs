#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        int result = 0;
        long long num = 0; // Using long long to prevent overflow during digit accumulation
        int sign = 1;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '+') {
                result += sign * num;
                num = 0;
                sign = 1;
            } else if (c == '-') {
                result += sign * num;
                num = 0;
                sign = -1;
            } else if (c == '(') {
                // Push current result and sign onto stack to handle the sub-expression
                nums.push(result);
                nums.push(sign);
                // Reset result and sign for the new sub-expression
                result = 0;
                sign = 1;
            } else if (c == ')') {
                result += sign * num;
                num = 0;
                // Combine current sub-expression result with the one from the stack
                int prevSign = nums.top(); nums.pop();
                int prevResult = nums.top(); nums.pop();
                result = prevResult + prevSign * result;
            }
        }
        result += sign * num;
        return result;
    }
};
