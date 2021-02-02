#include<bits/stdc++.h>
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define f(i,x,n) for(int i=x;i<(int)n;++i)
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define pq priority_queue<int>
#define pqs priority_queue<int,vi,greater<int>>
#define vpii vector<pair<int,int>>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define mpi map<int,int>
#define ll long long 

class Solution {
public:
    vector<bool> dp,vis;
    bool rec(int curr,int mx,string s,vector<string> &w){
        if(curr==mx) return 1;
        bool xp=0; if(vis[curr]) return dp[curr];
        vis[curr]=1;
        f(i,curr,mx)
            if(find(all(w),s.substr(curr,i-curr+1))!=w.end()) xp|=rec(i+1,mx,s,w);
        return dp[curr]=xp;
    }
    bool wordBreak(string s, vector<string>& w) {
        sort(all(w)); f(i,0,sz(s)){dp.pb(0); vis.pb(0);}
        return rec(0,sz(s),s,w);
    }
};
