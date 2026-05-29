class Twitter {
private:
    int time = 0;
    unordered_map<int, unordered_set<int>> followers;
    unordered_map<int, vector<pair<int, int>>> tweets;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({tweetId, time});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        auto com = [](pair<int, int>& a, pair<int, int>& b){
            if(a.second > b.second) return true;
            else return false;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(com)> pq(com);
        for(auto& p : tweets[userId]){
            pq.push(p);
            if(pq.size() == 11){
                pq.pop();
            } 
        }
        for(int id : followers[userId]){
                for(auto& p : tweets[id]){
                    pq.push(p);
                    if(pq.size() == 11){
                        pq.pop();
                    } 
                }
        }
        vector<int> res;
        while(!pq.empty()){
            if(res.empty()) res.push_back(pq.top().first);
            if(pq.top().first != res.back()) res.push_back(pq.top().first);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        
        followers[followerId].erase(followeeId);
        
       
    }
};
