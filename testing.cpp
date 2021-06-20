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
    ll max(ll a,ll b){
        if(a>b) return a;
        return b;
    }
public:
    int trap(vector<int>& h) {
        ll l=INT_MIN; ll n=sz(h);
        if(n==0) return 0;
        ll a[n]; f(i,0,n) {
            a[i]=l; l=max(l,h[i]);
        }
        l=INT_MIN; ll b[n]; for(int i=n-1;i>=0;--i){
            b[i]=l; l=max(l,h[i]);
        }
        ll ret=0;
        f(i,0,n){
            ll er=min(a[i],b[i]);
            ret+=max(er-h[i],0);
        }
        int xp=ret;
        return xp;
    }
};
