// Leetcode 355. Design Twitter
// https://leetcode.com/problems/design-twitter/

class Twitter
{
    // follower -> followee
    unordered_map<int, unordered_set<int>> followTable;
    
    // tweet list, user -> feed <timestamp, tweet_id>
    unordered_map<int, vector<pair<int,int>>> tweetList;
    int timestamp;
    
    // priority queue comparator
    struct Comp
    {
        bool operator()(pair<int,int> x, pair<int,int> y)
        {
            return x.first > y.first;
        }
    };
    
public:
    Twitter() 
    {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId)
    {
        tweetList[userId].push_back(make_pair(timestamp, tweetId));
        timestamp++;
    }
    
    vector<int> getNewsFeed(int userId)
    {
        vector<int> newsFeed;
        unordered_set<int>& followee = followTable[userId];
        priority_queue<pair<int,int>, vector<pair<int,int>>, Comp> q;
        for (auto it = followee.begin(); it != followee.end(); it++)
        {
            vector<pair<int, int>>& tl = tweetList[*it];
            for (pair<int, int> t : tl)
            {
                q.push(t);
            }
        }
        
        // also need to get tweet list of userId
        for (pair<int, int> t : tweetList[userId])
        {
            q.push(t);
        }
        
        while (q.size() > 10)
        {
            q.pop();
        }
        
        while (!q.empty())
        {
            newsFeed.push_back(q.top().second);
            q.pop();
        }
        
        reverse(newsFeed.begin(), newsFeed.end());
        
        return newsFeed;
    }
    
    void follow(int followerId, int followeeId)
    {
        followTable[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId)
    {
        followTable[followerId].erase(followeeId);
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
