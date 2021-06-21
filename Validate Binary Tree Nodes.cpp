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
    vi here;

    int get(int a){
        if(here[a]==a) return a;
        return here[a]=get(here[a]);
    }

    void un(int a,int b){
        here[a]=b;
    }

    bool validateBinaryTreeNodes(int n, vector<int>& l, vector<int>& r) {
        // indgree is 0 for 1 node only, for rest is 1;
        // outdegree is >=0 && <=2
        // one connected component. -- dsu. -- or indegree part covers this.
        // no self loops. -- dsu.
        here.resize(n);  f(i,0,n) here[i]=i;
        vi in(n,0), out(n,0);
        int i=-1;
        for(auto it : l){
             ++i;
            if(it==-1) continue; // check array bounds
            in[it]++;
            ++out[i];
            int a=get(i),b=get(it);
            if(a==b) {return 0;} // self loop
            un(a,b);
        }
        i=-1;
        for(auto it : r){
             ++i;
            if(it==-1) continue;
            in[it]++;
            ++out[i];
            int a=get(i),b=get(it);
            if(a==b){ return 0;} // self loop
            un(a,b); 
        }

        int zero=0;
        f(i,0,n) if(in[i]==0) ++zero; else if(in[i]>1) {return 0;}
        if(zero!=1) return 0;

        f(i,0,n) if(!(out[i]>=0 && out[i]<=2)) {return 0;}

        return 1;
    }
};