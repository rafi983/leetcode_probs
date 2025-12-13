#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>

class Twitter {
    struct Tweet {
        int tweetId;
        int timestamp;
        Tweet(int id, int time) : tweetId(id), timestamp(time) {}
    };

    int globalTime;
    std::unordered_map<int, std::vector<Tweet>> userTweets;
    std::unordered_map<int, std::unordered_set<int>> followers;

public:
    Twitter() {
        globalTime = 0;
    }

    void postTweet(int userId, int tweetId) {
        userTweets[userId].push_back(Tweet(tweetId, globalTime++));
    }

    std::vector<int> getNewsFeed(int userId) {
        std::vector<Tweet> allTweets;

        if (userTweets.count(userId)) {
            for (const auto& tweet : userTweets[userId]) {
                allTweets.push_back(tweet);
            }
        }

        if (followers.count(userId)) {
            for (int followeeId : followers[userId]) {
                if (userTweets.count(followeeId)) {
                    for (const auto& tweet : userTweets[followeeId]) {
                        allTweets.push_back(tweet);
                    }
                }
            }
        }

        std::sort(allTweets.begin(), allTweets.end(), [](const Tweet& a, const Tweet& b) {
            return a.timestamp > b.timestamp;
        });

        std::vector<int> feed;
        for (int i = 0; i < std::min(10, (int)allTweets.size()); i++) {
            feed.push_back(allTweets[i].tweetId);
        }

        return feed;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followers[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        if (followers.count(followerId)) {
            followers[followerId].erase(followeeId);
        }
    }
};

