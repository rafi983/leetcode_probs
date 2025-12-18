#include <queue>
#include <vector>
#include <functional>

using namespace std;

class SeatManager {
    // Min-heap to store unreserved seats that are smaller than next_seat
    priority_queue<int, vector<int>, greater<int>> available_seats;
    // The next seat number to be reserved if the heap is empty
    int next_seat;

public:
    SeatManager(int n) {
        next_seat = 1;
    }

    int reserve() {
        if (!available_seats.empty()) {
            int seat = available_seats.top();
            available_seats.pop();
            return seat;
        }
        int seat = next_seat;
        next_seat++;
        return seat;
    }

    void unreserve(int seatNumber) {
        available_seats.push(seatNumber);
    }
};
