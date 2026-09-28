class Twitter {
   public:
    unordered_map<int, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>> post;
    unordered_map<int, set<int>> followers;
    int time = 0;
    Twitter() { time = 0; }

    void postTweet(int userId, int tweetId) {
        post[userId].push({time, tweetId});
        if (post[userId].size() > 10) post[userId].pop();
        time++;
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> copy = post[userId];
        priority_queue<pair<int, int>> feed;
        while (!copy.empty()) {
            auto it = copy.top();
            copy.pop();
            feed.push(it);
        }
        for (auto user : followers[userId]) {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> copy = post[user];
            while (!copy.empty()) {
                auto it = copy.top();
                copy.pop();
                feed.push(it);
            }
        }
        int total = 10;
        vector<int> ans;
        while (total-- and !feed.empty()) {
            int it = feed.top().second;
            feed.pop();
            ans.push_back(it);
        }
        return ans;
    }

    void follow(int followerId, int followeeId) { followers[followerId].insert(followeeId); }

    void unfollow(int followerId, int followeeId) { followers[followerId].erase(followeeId); }
};
