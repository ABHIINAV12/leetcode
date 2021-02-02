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
#define ub upper_bound
#define lb lower_bound

class Solution {
public:
    ll lcm(ll a,ll b){
        ll c=__gcd(a,b);
        a/=c; a*=b;
        return a;
    }
    ll lcm1(ll a,ll b ,ll c){
        return lcm(a,lcm(b,c));
    }
    ll min(ll a,ll b ,ll c){
        ll x[3];
        x[0]=a; x[1]=b; x[2]=c;
        sort(x,x+3);
        return x[0];
    }
    int dis(vi a ,vi b){
        return abs(a[0]-b[0]) + abs(a[1]-b[1]);
    }
    vector<array<int,3>> vp;
    int com[1100000];
    int gt(int i){
        if(com[i]==i) return i; com[i]=gt(com[i]);
        return com[i];
    }
    int minCostConnectPoints(vector<vector<int>>& p) {
        int n=sz(p); if(n<=1) return 0;
        f(i,0,n) 
            f(j,i+1,n) vp.pb({dis(p[i],p[j]),i,j});
        sort(all(vp));
        int ret=0;f(i,0,n) com[i]=i;
        int here=0;
        for(auto it : vp){
            if(gt(it[1])!=gt(it[2])) {
                ret+=it[0];
                com[gt(it[1])]=gt(it[2]);
                ++here;
                if(here==(n-1)) break;
            }
        }
        return ret;
    }
};
