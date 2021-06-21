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
    vector<int> rearrangeBarcodes(vector<int>& a) {
        int n=sz(a);
        mpi mp; for(auto it : a) ++mp[it];
        vpii vt; for(auto it : mp) vt.pb({it.ss,it.ff});
        sort(all(vt)); reverse(all(vt));
        int x=0;
        for(auto it : vt){
            int num=it.ss;
            int fre=it.ff;
            while(fre--) a[x++]=num;
        }
        vi ret(n,0);
        int curr=0;
        for(auto it : a){
            if(curr>=n) curr=1;
            ret[curr]=it;
            curr+=2;
        }
        return ret;
    }
};