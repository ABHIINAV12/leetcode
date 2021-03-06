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
    int longestSubsequence(vector<int>& a, int d) {
        int n=sz(a); mpi mp; 
        int ret=1; f(i,0,n){
            int here=1+mp[a[i]-d];
            ret=max(ret,here); mp[a[i]]=here;
        }
        return ret;
    }
};
