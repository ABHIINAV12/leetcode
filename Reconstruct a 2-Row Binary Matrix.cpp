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
    vector<vector<int>> reconstructMatrix(int u, int l, vector<int>& c) {
        int sum=0,n=sz(c); for(auto it : c) sum+=it;
        vvi ret;
        if(sum!=(u+l)) return ret;
        for(auto it : c) if(it<0 || it>2) return ret;
        vi up(n,0),down(n,0); 
        f(i,0,n) if(c[i]==2 && u!=0) {
            up[i]++; --u; c[i]=1;
        }
        f(i,0,n) if(c[i]==2 && l!=0){
            --l; ++down[i]; c[i]=1;
        }
        f(i,0,n) if(c[i]==1){
            if(up[i]==0){
                if(u!=0){
                    --u; up[i]=1; --c[i];
                }else{
                    if(l!=0){
                        if(down[i]==0){
                            down[i]=1; --l;  --c[i];
                        }else return ret;
                    }else return ret;
                }
            }else{
                if(l!=0){
                    if(down[i]!=1){
                        down[i]=1; --c[i]; --l;
                    }else return ret;
                }else return ret;
            }
        }
        ret.pb(up); ret.pb(down);
        return ret;
    }
};