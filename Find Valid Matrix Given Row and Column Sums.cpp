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
    vector<vector<int>> restoreMatrix(vector<int>& r, vector<int>& c) {
        // since solution exists, assign greedily.
        vvi ret;    
        f(i,0,sz(r)){
            vi go;
            f(j,0,sz(c)){
                int ass= min(r[i],c[j]);
                r[i]-=ass;c[j]-=ass;
                go.pb(ass);
            }   
            ret.pb(go);
        }


        return ret;
    }
};