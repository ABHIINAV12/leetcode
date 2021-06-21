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
    int maxProduct(vector<int>& nums) {
        long long ret=INT_MIN,max_here=INT_MIN,min_here=INT_MAX;
        for(auto it : nums){
            if(it<0) swap(max_here,min_here);
            max_here=max(max_here*it,it*1ll);
            min_here=min(min_here*it,it*1ll);
            ret=max(ret,max_here);
        }      
        return (int)ret;
    }
};