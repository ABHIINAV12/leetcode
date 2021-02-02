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
    bool canPartition(vector<int>& nums) {
        bitset<11000> bt; bt[0]=1; for(auto it : nums) bt=bt|(bt<<it);
        int ts=0; for(auto it : nums) ts+=it; if(ts&1) return 0;
        ts/=2; return (bt[ts]==1);
    }
};
