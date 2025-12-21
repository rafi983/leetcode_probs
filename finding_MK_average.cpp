#include <vector>
#include <deque>
#include <iostream>

using namespace std;

class MKAverage {
private:
    int m, k;
    deque<int> stream;
    vector<int> count_bit;
    vector<long long> sum_bit;
    const int MAX_VAL = 100005;

    void add(int num, int delta) {
        for (int i = num; i < MAX_VAL; i += i & -i) {
            count_bit[i] += delta;
            sum_bit[i] += (long long)num * delta;
        }
    }

    long long get_sum(int num) {
        long long res = 0;
        for (int i = num; i > 0; i -= i & -i) {
            res += sum_bit[i];
        }
        return res;
    }

    int get_count(int num) {
        int res = 0;
        for (int i = num; i > 0; i -= i & -i) {
            res += count_bit[i];
        }
        return res;
    }

    int find_kth(int k) {
        int idx = 0;
        int current_count = 0;
        for (int i = 1 << 17; i > 0; i >>= 1) {
            if (idx + i < MAX_VAL && current_count + count_bit[idx + i] < k) {
                idx += i;
                current_count += count_bit[idx];
            }
        }
        return idx + 1;
    }

    long long get_sum_k(int k) {
        int num = find_kth(k);
        long long sum = get_sum(num - 1);
        int count = get_count(num - 1);
        sum += (long long)(k - count) * num;
        return sum;
    }

public:
    MKAverage(int m, int k) : m(m), k(k) {
        count_bit.resize(MAX_VAL, 0);
        sum_bit.resize(MAX_VAL, 0);
    }

    void addElement(int num) {
        stream.push_back(num);
        add(num, 1);
        if (stream.size() > m) {
            int old = stream.front();
            stream.pop_front();
            add(old, -1);
        }
    }

    int calculateMKAverage() {
        if (stream.size() < m) return -1;
        long long sum_k = get_sum_k(k);
        long long sum_m_k = get_sum_k(m - k);
        return (sum_m_k - sum_k) / (m - 2 * k);
    }
};
