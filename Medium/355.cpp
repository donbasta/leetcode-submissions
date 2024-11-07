class Twitter {
public:
    map<int, set<int>> following;
    map<int, set<pair<int, int>>> tweets;
    int timestamp;
    
    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].insert(make_pair(timestamp, tweetId));
        timestamp--;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int, int>> buf;
        for (auto f : following[userId]) {
            for (auto t : tweets[f]) {
                buf.push_back(t);
            }
        }
        for (auto t : tweets[userId]) {
            buf.push_back(t);
        }
        sort(buf.begin(), buf.end());
        vector<int> res;
        for (int i = 0; i < min(10, (int) buf.size()); i++) {
            res.push_back(buf[i].second);
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */