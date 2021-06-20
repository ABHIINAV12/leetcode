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
    int bestTeamScore(vector<int>& s, vector<int>& a) {
        int n=sz(s);
        vpii vt; f(i,0,n) 
            vt.pb({a[i],s[i]});
        sort(all(vt));
        vi dp(n,0); 
        f(i,0,n){
            dp[i]=vt[i].ss;
            for(int j=i-1;j>=0;--j){
                if(vt[j].ss<=vt[i].ss)
                dp[i]=max(dp[i],dp[j]+vt[i].ss);
            }
        }
        return *max_element(all(dp));
    }
};