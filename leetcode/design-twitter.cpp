// Design Twitter
// https://leetcode.com/problems/design-twitter/
// Accepted 2026-07-04 | Runtime 10 ms | Memory 55.9 MB


class Twitter {
public:
    unordered_map<int,unordered_set<int>> following;
    unordered_map<int,vector<pair<int,int>>> tweets;
    int timer = 0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        following[userId].insert(userId);

        priority_queue<vector<int>> pq;

        for(int user : following[userId]){
            if(!tweets[user].empty()){
                int idx = tweets[user].size() - 1;

                pq.push({tweets[user][idx].first, tweets[user][idx].second, user, idx});
            }
        }
        vector<int> ans;

        while(!pq.empty() && ans.size()<10){
            int tweetId = pq.top()[1];
            int userId = pq.top()[2];
            int idx = pq.top()[3];

            pq.pop();

            ans.push_back(tweetId);
            idx--;

            if(idx>=0){
                pq.push({tweets[userId][idx].first, tweets[userId][idx].second, userId, idx});
            }
        }
        
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId)
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