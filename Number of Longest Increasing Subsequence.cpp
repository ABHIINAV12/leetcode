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
    int findNumberOfLIS(vector<int>& nums) {
     int n=sz(nums); if(!n) return 0;
        int dp[n],num[n];
        int ret=0;
        f(i,0,n){
            int mx=1;
            f(j,0,i) if(nums[j]<nums[i]) mx=max(mx,dp[j]+1);
            dp[i]=mx; int look=mx-1; int how=0;
            f(j,0,i) if(nums[j]<nums[i]) if(dp[j]==look) how+=num[j]; if(how==0) how=1;
            num[i]=how;
            ret=max(ret,mx);
        }
        f(i,0,n) cout<<num[i]<<" "; cout<<"\n";
        f(i,0,n) cout<<dp[i]<<" "; cout<<"\n";
        int rip=0;
        f(i,0,n)
          if(dp[i]==ret) rip+=num[i];
        return rip;
    }
};
