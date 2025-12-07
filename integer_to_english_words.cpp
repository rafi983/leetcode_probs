class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";

        vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                               "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        vector<string> thousands = {"", "Thousand", "Million", "Billion"};

        string result;
        int i = 0;

        while (num > 0) {
            if (num % 1000 != 0) {
                string chunk = helper(num % 1000, ones, tens);
                if (!thousands[i].empty() && !chunk.empty()) {
                    chunk += " " + thousands[i];
                }
                if (result.empty()) {
                    result = chunk;
                } else {
                    result = chunk + " " + result;
                }
            }
            num /= 1000;
            i++;
        }

        return result;
    }

private:
    string helper(int num, vector<string>& ones, vector<string>& tens) {
        if (num == 0) return "";

        string result;

        if (num >= 100) {
            result = ones[num / 100] + " Hundred";
            num %= 100;
            if (num > 0) result += " ";
        }

        if (num >= 20) {
            result += tens[num / 10];
            num %= 10;
            if (num > 0) result += " ";
        }

        if (num > 0) {
            result += ones[num];
        }

        return result;
    }
};

