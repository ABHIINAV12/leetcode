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
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(sz(nums)<2) return 0;
        if(k==0) {
            f(i,1,sz(nums)) if(nums[i]==nums[i-1] && nums[i]==0) return 1;
            return 0;
        }
        for(auto &it : nums) it%=k;
        mpi mp;
        int here=nums[0];
        int add=0,add1=nums[0];
        here=add+add1; here%=k;
        f(i,1,sz(nums)){
            ++mp[add];
            here+=nums[i]; here%=k;
            if(mp[here]!=0) return 1;
            add=add1;
            add1=here;
        }
        return 0;
    }
};
