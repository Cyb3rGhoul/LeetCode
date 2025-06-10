class Twitter {
    int time;
    unordered_map<int,unordered_set<int>> fmp; // ye yaha kyu use kiya hai kyuki yahi requirement thi qusetion ki
    // humesha socho ki konsa data sturcture use hoga, kesse hoga and kyu hoga 
    unordered_map<int,vector<pair<int,int>>> tmp; //similarli yahi requirement thi iske liye kyuki latest 10 nikalne the to yahi karna pada

public:
    Twitter() : time(0) {}
    
    void postTweet(int userId, int tweetId) {
        tmp[userId].push_back({time++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int,int>> feed = tmp[userId];
        for(int followeeId: fmp[userId]){
            feed.insert(feed.end(),tmp[followeeId].begin(),tmp[followeeId].end());
        }
        sort(feed.begin(),feed.end(), [](auto &a, auto &b){
            return a.first > b.first;
        });
        vector<int> res;
        for(int i = 0; i<min(10,(int)feed.size()); i++){
            res.push_back(feed[i].second);
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) { // follower add hua
        if(followerId != followeeId){
            fmp[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) { // follower remove hua
        fmp[followerId].erase(followeeId);
    }
};
