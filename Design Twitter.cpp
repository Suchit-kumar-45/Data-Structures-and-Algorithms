#include <bits/stdc++.h>
using namespace std;

class Twitter {
    struct Tweet { int time; int id; };
    unordered_map<int, unordered_set<int>> follows;
    unordered_map<int, vector<Tweet>> tweets;
    int timer = 0;
public:
    Twitter() { }
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({++timer, tweetId});
    }
    vector<int> getNewsFeed(int userId) {
        struct Node { int time; int id; int uid; int idx; };
        struct Cmp { bool operator()(Node const& a, Node const& b) const { return a.time < b.time; } };
        priority_queue<Node, vector<Node>, Cmp> pq;
        auto push_latest = [&](int uid){
            auto &v = tweets[uid];
            if(!v.empty()){
                int i = (int)v.size() - 1;
                pq.push({v[i].time, v[i].id, uid, i});
            }
        };
        push_latest(userId);
        for(int f : follows[userId]) push_latest(f);
        vector<int> res;
        while(!pq.empty() && (int)res.size() < 10){
            auto cur = pq.top(); pq.pop();
            res.push_back(cur.id);
            if(cur.idx - 1 >= 0){
                auto &v = tweets[cur.uid];
                int ni = cur.idx - 1;
                pq.push({v[ni].time, v[ni].id, cur.uid, ni});
            }
        }
        return res;
    }
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        follows[followerId].insert(followeeId);
    }
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};
DEsign_t
