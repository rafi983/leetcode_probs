#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <map>
#include <unordered_set>

using namespace std;


class Solution {
private:
    unordered_map<Node*, Node*> visited;

public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }

        // If the node was already visited, return the cloned node from the map
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }

        // Create a clone for the given node
        Node* cloneNode = new Node(node->val);
        visited[node] = cloneNode;

        // Iterate through the neighbors to generate their clones
        for (Node* neighbor : node->neighbors) {
            cloneNode->neighbors.push_back(cloneGraph(neighbor));
        }

        return cloneNode;
    }
};
