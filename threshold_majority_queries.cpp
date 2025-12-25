#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <iostream>

using namespace std;

struct Query {
    int l, r, threshold, id;
};

class Solution {
public:
    vector<int> subarrayMajority(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();

        if (n == 0) return {};
        if (q == 0) return {};

        // Coordinate Compression
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        sorted_nums.erase(unique(sorted_nums.begin(), sorted_nums.end()), sorted_nums.end());

        vector<int> compressed_nums(n);
        for(int i=0; i<n; ++i) {
            compressed_nums[i] = lower_bound(sorted_nums.begin(), sorted_nums.end(), nums[i]) - sorted_nums.begin();
        }

        // Prepare Queries
        vector<Query> qs(q);
        for(int i=0; i<q; ++i) {
            qs[i] = {queries[i][0], queries[i][1], queries[i][2], i};
        }

        // Set Block Size
        int blockSize = 1;
        if (q > 0)
            blockSize = max(1, (int)(n / sqrt(q)));

        sort(qs.begin(), qs.end(), [blockSize](const Query& a, const Query& b) {
            int block_a = a.l / blockSize;
            int block_b = b.l / blockSize;
            if (block_a != block_b)
                return block_a < block_b;
            return (block_a % 2 == 0) ? (a.r < b.r) : (a.r > b.r);
        });

        // Data structures for Mo's algorithm
        // cnt[val] stores the frequency of compressed value 'val'
        vector<int> cnt(sorted_nums.size(), 0);

        // freq_sets[f] stores the set of compressed values that have frequency 'f'
        // Max frequency can be n
        vector<set<int>> freq_sets(n + 1);

        int max_freq = 0;
        int curr_l = 0;
        int curr_r = -1;

        auto add = [&](int idx) {
            int val = compressed_nums[idx];
            int old_f = cnt[val];
            if (old_f > 0) {
                freq_sets[old_f].erase(val);
            }

            int new_f = old_f + 1;
            cnt[val] = new_f;
            freq_sets[new_f].insert(val);

            if (new_f > max_freq) {
                max_freq = new_f;
            }
        };

        auto remove = [&](int idx) {
            int val = compressed_nums[idx];
            int old_f = cnt[val];
            freq_sets[old_f].erase(val);

            int new_f = old_f - 1;
            cnt[val] = new_f;
            if (new_f > 0) {
                freq_sets[new_f].insert(val);
            }

            if (old_f == max_freq) {
                if (freq_sets[old_f].empty()) {
                    max_freq--;
                }
            }
        };

        vector<int> ans(q);

        for(const auto& query : qs) {
            while (curr_l > query.l) {
                curr_l--;
                add(curr_l);
            }
            while (curr_r < query.r) {
                curr_r++;
                add(curr_r);
            }
            while (curr_l < query.l) {
                remove(curr_l);
                curr_l++;
            }
            while (curr_r > query.r) {
                remove(curr_r);
                curr_r--;
            }

            if (max_freq < query.threshold) {
                ans[query.id] = -1;
            } else {
                int best_val_compressed = *freq_sets[max_freq].begin();
                ans[query.id] = sorted_nums[best_val_compressed];
            }
        }

        return ans;
    }
};

