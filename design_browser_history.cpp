#include <string>
#include <vector>

class BrowserHistory {
    std::vector<std::string> history;
    int current;

public:
    BrowserHistory(std::string homepage) {
        history.push_back(homepage);
        current = 0;
    }

    void visit(std::string url) {
        history.erase(history.begin() + current + 1, history.end());
        history.push_back(url);
        current++;
    }

    std::string back(int steps) {
        current = std::max(0, current - steps);
        return history[current];
    }

    std::string forward(int steps) {
        current = std::min((int)history.size() - 1, current + steps);
        return history[current];
    }
};

