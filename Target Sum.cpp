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
    vi fx(vi nums){
        vi ret; int n=sz(nums);
        f(i,0,(1<<n)){
            ll curr=0;
            f(j,0,n) if((i>>j)&1) curr+=nums[j]*1ll; else curr-=nums[j]*1ll;
            ret.pb(curr);
        }
        return ret;
    }
    int findTargetSumWays(vector<int>& nums, ll S) {
        int n=sz(nums);
        vi l,r; f(i,0,n) if(i<(n/2)) l.pb(nums[i]); else r.pb(nums[i]);
        l=fx(l); r=fx(r);
        sort(all(l)); sort(all(r));
        int ret=0;
        for(auto it : l){
            ll rem=S-it;
            auto ip=find(all(r),rem);
            if(ip!=r.end()){
                ret+=ub(all(r),rem)-lb(all(r),rem);
            }
        }
        return ret;
    }
};
