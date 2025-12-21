#include <vector>
#include <deque>
#include <set>
#include <unordered_map>
#include <tuple>
#include <algorithm>
#include <iostream>

using namespace std;

class Router {
    struct Packet {
        int source;
        int destination;
        int timestamp;
    };

    int memoryLimit;
    deque<Packet> queue;
    set<tuple<int, int, int>> lookup;
    unordered_map<int, deque<int>> dest_timestamps;

public:
    Router(int memoryLimit) : memoryLimit(memoryLimit) {}

    bool addPacket(int source, int destination, int timestamp) {
        if (lookup.count({source, destination, timestamp})) {
            return false;
        }

        if (queue.size() == memoryLimit) {
            Packet oldest = queue.front();
            queue.pop_front();
            lookup.erase({oldest.source, oldest.destination, oldest.timestamp});

            auto& dt = dest_timestamps[oldest.destination];
            if (!dt.empty()) {
                dt.pop_front();
            }
        }

        queue.push_back({source, destination, timestamp});
        lookup.insert({source, destination, timestamp});
        dest_timestamps[destination].push_back(timestamp);
        return true;
    }

    vector<int> forwardPacket() {
        if (queue.empty()) {
            return {};
        }

        Packet p = queue.front();
        queue.pop_front();
        lookup.erase({p.source, p.destination, p.timestamp});

        auto& dt = dest_timestamps[p.destination];
        if (!dt.empty()) {
            dt.pop_front();
        }

        return {p.source, p.destination, p.timestamp};
    }

    int getCount(int destination, int startTime, int endTime) {
        if (dest_timestamps.find(destination) == dest_timestamps.end()) {
            return 0;
        }
        const auto& dt = dest_timestamps[destination];
        auto it1 = lower_bound(dt.begin(), dt.end(), startTime);
        auto it2 = upper_bound(dt.begin(), dt.end(), endTime);
        return distance(it1, it2);
    }
};
