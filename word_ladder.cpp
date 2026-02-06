#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());

        if (dict.find(endWord) == dict.end()) {
            return 0;
        }

        dict.erase(beginWord);

        queue<string> q;
        q.push(beginWord);

        int level = 1;

        while (!q.empty()) {
            int levelSize = q.size();

            // Process all nodes at the current level
            while (levelSize--) {
                string currentWord = q.front();
                q.pop();

                if (currentWord == endWord) {
                    return level;
                }

                // Try changing each character of the current word
                for (int j = 0; j < currentWord.length(); ++j) {
                    char originalChar = currentWord[j];

                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == originalChar) continue;

                        currentWord[j] = c;

                        // If the transformed word is in the dictionary
                        if (dict.find(currentWord) != dict.end()) {
                            q.push(currentWord);
                            dict.erase(currentWord); // Mark as visited by removing from set
                        }
                    }

                    // Restore the original character for the next iteration (next char position)
                    currentWord[j] = originalChar;
                }
            }
            // Increment level after finishing the current level
            level++;
        }

        return 0;
    }
};
