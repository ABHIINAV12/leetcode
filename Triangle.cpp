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
    vvi ret;
    int rec(int r,int c,int mx,vector<vector<int>>& t){
        if(r>=mx) return 0;
        if(ret[r][c]!=-1) return ret[r][c];
        return ret[r][c]=t[r][c] + min(rec(r+1,c,mx,t),rec(r+1,c+1,mx,t));
    }
    int minimumTotal(vector<vector<int>>& t) {
        int mx=sz(t); vi vp; f(i,0,mx) vp.pb(-1);
        f(i,0,mx) ret.pb(vp);
        return rec(0,0,mx,t);
    }
};
