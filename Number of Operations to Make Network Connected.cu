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
    vi dsu;
    int get(int x){
        if(dsu[x]==x) return x;
        return dsu[x]=get(dsu[x]);
    }       
    void unon(int x,int y){
        dsu[x]=y;
    }
    int makeConnected(int n, vector<vector<int>>& c) {
       int m=c.size();
       if(m>=(n-1)){
           dsu.resize(n);
           f(i,0,n) dsu[i]=i;
           for(auto it : c){
               it[0]=get(it[0]);
               it[1]=get(it[1]);
               unon(it[0],it[1]);
           }
           set<int> st; 
           f(i,0,n) st.insert(get(i));
           return sz(st)-1;
       }else return -1;
    }
};