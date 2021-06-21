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
    vector<vector<int>> groupThePeople(vector<int>& g) {
        map<int,vi> mp;
        f(i,0,sz(g)) mp[g[i]].pb(i);
        vvi here;
        for(auto it : mp){
            int go=it.ff;
            stack<int> st;
            for(auto p : it.ss){
                st.push(p);
                if(sz(st)==go){
                    vi tmp;
                    while(!st.empty()){
                        tmp.pb(st.top());
                        st.pop();
                    }
                    here.pb(tmp);
                }
            }
        }
        return here;      
    }
};