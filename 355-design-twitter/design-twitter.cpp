class Twitter {
public:
    Twitter() {
        this->time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        if(graph.find(userId) == graph.end() || graph[userId].find(userId) == graph[userId].end()){
            graph[userId].insert(userId);
        }
        tweet_times[userId].push_back(make_pair(time,tweetId));
        ++time;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> top_ten_tweets;

        for(auto follower : graph[userId]){
            for(auto tweet : tweet_times[follower]){
                top_ten_tweets.push(tweet);

                if(top_ten_tweets.size() > 10) top_ten_tweets.pop();
            }
        }

        while(!top_ten_tweets.empty()){
            ans.push_back(top_ten_tweets.top().second);
            top_ten_tweets.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        graph[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        graph[followerId].erase(followeeId);
    }
    
    private:
    unordered_map<int,unordered_set<int>> graph;
    unordered_map<int,vector<pair<int,int>>> tweet_times;
    int time;
};