#include <unordered_map>
#include <list>

class LFUCache {
    int capacity;
    int minFreq;
    std::unordered_map<int, std::pair<int, int>> keyValue;
    std::unordered_map<int, int> keyFreq;
    std::unordered_map<int, std::list<int>> freqList;
    std::unordered_map<int, std::list<int>::iterator> keyIter;

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (keyValue.find(key) == keyValue.end()) {
            return -1;
        }

        int freq = keyFreq[key];
        freqList[freq].erase(keyIter[key]);
        if (freqList[freq].empty() && freq == minFreq) {
            minFreq++;
        }

        keyFreq[key]++;
        freqList[keyFreq[key]].push_back(key);
        keyIter[key] = --freqList[keyFreq[key]].end();

        return keyValue[key].first;
    }

    void put(int key, int value) {
        if (capacity <= 0) return;

        if (keyValue.find(key) != keyValue.end()) {
            keyValue[key].first = value;
            get(key);
            return;
        }

        if (keyValue.size() >= capacity) {
            int evictKey = freqList[minFreq].front();
            freqList[minFreq].pop_front();
            keyValue.erase(evictKey);
            keyFreq.erase(evictKey);
            keyIter.erase(evictKey);
        }

        keyValue[key] = {value, 1};
        keyFreq[key] = 1;
        freqList[1].push_back(key);
        keyIter[key] = --freqList[1].end();
        minFreq = 1;
    }
};

