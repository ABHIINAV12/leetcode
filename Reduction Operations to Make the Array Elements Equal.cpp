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
    int reductionOperations(vector<int>& a) {
        int n=sz(a);
        mpi mp; f(i,0,n) mp[a[i]]++;
        vpii vt; for(auto it : mp) vt.pb({it.ff,it.ss});
        int pre=0,ret=0;
        for(int i=sz(vt)-1;i>=0;--i){
            ret+=pre;
            pre+=vt[i].ss;
        }
        return ret;
    }
};