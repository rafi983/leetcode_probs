#include <iostream>
#include <vector>

using namespace std;

class LockingTree {
    vector<int> parent;
    vector<vector<int>> children;
    vector<int> locked; // Stores user id, 0 if unlocked

public:
    LockingTree(vector<int>& parent) {
        this->parent = parent;
        int n = parent.size();
        children.resize(n);
        locked.assign(n, 0); // 0 means unlocked

        for (int i = 1; i < n; ++i) {
            if (parent[i] != -1) {
                children[parent[i]].push_back(i);
            }
        }
    }

    bool lock(int num, int user) {
        if (locked[num] != 0) return false;
        locked[num] = user;
        return true;
    }

    bool unlock(int num, int user) {
        if (locked[num] != user) return false;
        locked[num] = 0;
        return true;
    }

    bool upgrade(int num, int user) {
        if (locked[num] != 0) return false;

        int curr = parent[num];
        while (curr != -1) {
            if (locked[curr] != 0) return false;
            curr = parent[curr];
        }

        vector<int> lockedDescendants;
        collectLockedDescendants(num, lockedDescendants);

        if (lockedDescendants.empty()) return false;

        for (int descendant : lockedDescendants) {
            locked[descendant] = 0;
        }
        locked[num] = user;

        return true;
    }

private:
    void collectLockedDescendants(int node, vector<int>& result) {
        for (int child : children[node]) {
            if (locked[child] != 0) {
                result.push_back(child);
            }
            collectLockedDescendants(child, result);
        }
    }
};
