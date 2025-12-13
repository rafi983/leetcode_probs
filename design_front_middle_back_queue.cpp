#include <vector>

class FrontMiddleBackQueue {
    std::vector<int> q;
public:
    FrontMiddleBackQueue() {
    }

    void pushFront(int val) {
        q.insert(q.begin(), val);
    }

    void pushMiddle(int val) {
        int mid = q.size() / 2;
        q.insert(q.begin() + mid, val);
    }

    void pushBack(int val) {
        q.push_back(val);
    }

    int popFront() {
        if (q.empty()) return -1;
        int val = q.front();
        q.erase(q.begin());
        return val;
    }

    int popMiddle() {
        if (q.empty()) return -1;
        int mid = (q.size() - 1) / 2;
        int val = q[mid];
        q.erase(q.begin() + mid);
        return val;
    }

    int popBack() {
        if (q.empty()) return -1;
        int val = q.back();
        q.pop_back();
        return val;
    }
};

