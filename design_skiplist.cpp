#include <vector>
#include <cstdlib>
#include <ctime>

class Skiplist {
    struct Node {
        int val;
        std::vector<Node*> next;
        Node(int v, int level) : val(v), next(level, nullptr) {}
    };

    static const int MAX_LEVEL = 16;
    Node* head;
    int level;

    int randomLevel() {
        int lvl = 1;
        while (lvl < MAX_LEVEL && (rand() & 1)) {
            lvl++;
        }
        return lvl;
    }

public:
    Skiplist() {
        srand(time(0));
        head = new Node(-1, MAX_LEVEL);
        level = 1;
    }

    bool search(int target) {
        Node* curr = head;
        for (int i = level - 1; i >= 0; i--) {
            while (curr->next[i] && curr->next[i]->val < target) {
                curr = curr->next[i];
            }
        }
        curr = curr->next[0];
        return curr && curr->val == target;
    }

    void add(int num) {
        std::vector<Node*> update(MAX_LEVEL, nullptr);
        Node* curr = head;

        for (int i = level - 1; i >= 0; i--) {
            while (curr->next[i] && curr->next[i]->val < num) {
                curr = curr->next[i];
            }
            update[i] = curr;
        }

        int newLevel = randomLevel();
        if (newLevel > level) {
            for (int i = level; i < newLevel; i++) {
                update[i] = head;
            }
            level = newLevel;
        }

        Node* newNode = new Node(num, newLevel);
        for (int i = 0; i < newLevel; i++) {
            newNode->next[i] = update[i]->next[i];
            update[i]->next[i] = newNode;
        }
    }

    bool erase(int num) {
        std::vector<Node*> update(MAX_LEVEL, nullptr);
        Node* curr = head;

        for (int i = level - 1; i >= 0; i--) {
            while (curr->next[i] && curr->next[i]->val < num) {
                curr = curr->next[i];
            }
            update[i] = curr;
        }

        curr = curr->next[0];
        if (!curr || curr->val != num) {
            return false;
        }

        for (int i = 0; i < level; i++) {
            if (update[i]->next[i] != curr) {
                break;
            }
            update[i]->next[i] = curr->next[i];
        }

        delete curr;

        while (level > 1 && !head->next[level - 1]) {
            level--;
        }

        return true;
    }
};

