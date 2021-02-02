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
    int numSquares(int n) {
        vi vt; int curr=1; while(1){
            if((curr*curr)>n) break;
            vt.pb(curr*curr);
            ++curr;
        }
        int dp[n+1]; f(i,0,n+1) dp[i]=INT_MAX; dp[0]=0;
        for(auto it : vt) f(i,0,n+1) if(it<=i) dp[i]=min(dp[i],1+dp[i-it]);
        return dp[n];
    }
};
