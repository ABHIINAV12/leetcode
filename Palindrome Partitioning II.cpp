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
    int dp[2200][2200];
    int ans[2200];
    int rec(int curr,int mx){
        if(curr==mx) return 0;
        if(ans[curr]!=-1) return ans[curr];
        int here=INT_MAX;
        f(i,curr,mx)
            if(dp[curr][i])
                here=min(here,1*(i!=(mx-1)) + rec(i+1,mx));
        ans[curr]=here;
        return ans[curr];
    }
public:
    int minCut(string s) {
        int n=sz(s); if(n==0) return 0;
        f(i,0,n) dp[i][i]=1; f(i,0,n) ans[i]=-1;
        f(i,0,n-1) if(s[i]==s[i+1]) dp[i][i+1]=1;
        f(len,3,n+1) {
            f(i,0,n){
                int nx=i+len-1; if(nx>=n) break;
                if(dp[i+1][nx-1] && s[i]==s[nx]) dp[i][nx]=1;
            }
        }
        return rec(0,sz(s));
    }
};
