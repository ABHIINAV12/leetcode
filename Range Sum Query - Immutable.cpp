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

class NumArray {
public:
    vector<int> pre;
    NumArray(vector<int>& nums) {
        if(sz(nums)!=0){
            pre.pb(nums[0]);
            f(i,1,sz(nums)) pre.pb(pre[i-1]+nums[i]);
        }       
        for(auto it : pre) cout<<it<<" ";
    }
    
    int sumRange(int i, int j) {
        if(sz(pre)==0) return 0;
        return pre[j]-(i==0 ? 0 : pre[i-1]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
