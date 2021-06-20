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
    int constrainedSubsetSum(vector<int>& a, int k) {
        int n=sz(a);
        vi dp(n);
        stack<pii> h,hh;
        f(i,0,n){
            dp[i]=a[i];
            while(!hh.empty() && (i-hh.top().ff)>k) hh.pop();
            if(hh.empty())
                while(!h.empty())
                    hh.push({h.top().ff, max(hh.empty() ? 0 : hh.top().ss , dp[h.top().ff])}), h.pop();
            dp[i]+=max({0,h.empty() ? 0 : h.top().ss ,hh.empty() ? 0 : hh.top().ss });
            if(h.empty())
                h.push({i,dp[i]});
            else h.push({i,max(dp[i],h.top().ss)});
        }
        return *max_element(all(dp));
    }
};