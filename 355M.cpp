class Twitter {
public:
    /** Initialize your data structure here. */
    unordered_map<int,set<int> >following;
    unordered_map<int,vector<pair<int,int> > >user_tweets;
    int time;
    Twitter() {
        time=0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        time++;
        user_tweets[userId].push_back({time,tweetId});
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<pair<int,int>,int> >pq;
        vector<int>newsFeed;
        for(auto x:user_tweets)
        {
            if(x.first==userId || ( following[userId].find(x.first)!=following[userId].end()))
            {
                if(!x.second.empty())
                {
                    pq.push({x.second.back(),x.first});
                    user_tweets[x.first].pop_back();
                }
            }
        }
        int cnt=0;
        while(!pq.empty() && cnt<10)
        {
            int twId=pq.top().first.second;
            int user_id=pq.top().second;
            pq.pop();
            if(!user_tweets[user_id].empty())
            {
                pq.push({user_tweets[user_id].back(),user_id});
                user_tweets[user_id].pop_back();
            }
            newsFeed.push_back(twId);
            cnt++;
        }
        return newsFeed;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(following[followerId].find(followeeId)==following[followerId].end())
            following[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(following[followerId].find(followeeId)!=following[followerId].end())
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