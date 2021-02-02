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
    ll min(ll a,ll b,ll c){
        ll x[3]={a,b,c};
        sort(x,x+3); return x[0];
    }
    ll fx(ll a,ll b){
        if(a>b) return a;
        return b;
    }
    int nthUglyNumber(int n) {
        // the idea is the next number is formed by multiplying any of previous numbers byb 2,3,5.
        // for optimality we choose minimum
       if(n==1) return 1;
        ll dp[1700]; 
        ll a=2,b=3,c=5;
        int x=0,y=0,z=0;
        f(i,0,1700){
            int mn=min(a,b,c);
            dp[i]=mn;
            if(mn==a)
            a=dp[x++]*2ll;
            if(mn==b)
            b=dp[y++]*3ll;
            if(mn==c)
            c=dp[z++]*5ll;
        }
        --n;
        return int(dp[n-1]);
    }
};
