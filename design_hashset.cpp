#include <vector>
#include <list>
#include <algorithm>

class MyHashSet {
    static const int SIZE = 10007;
    std::vector<std::list<int>> buckets;

    int hash(int key) {
        return key % SIZE;
    }

public:
    MyHashSet() {
        buckets.resize(SIZE);
    }

    void add(int key) {
        int idx = hash(key);
        auto& bucket = buckets[idx];
        if (std::find(bucket.begin(), bucket.end(), key) == bucket.end()) {
            bucket.push_back(key);
        }
    }

    void remove(int key) {
        int idx = hash(key);
        auto& bucket = buckets[idx];
        bucket.remove(key);
    }

    bool contains(int key) {
        int idx = hash(key);
        auto& bucket = buckets[idx];
        return std::find(bucket.begin(), bucket.end(), key) != bucket.end();
    }
};

