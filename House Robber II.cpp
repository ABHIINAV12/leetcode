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
     int rob1(vector<int>& nums) {
        int n=sz(nums); if(n==0) return 0;
        int ret=0; int val[n];
        f(i,0,n){
            int here=nums[i];
            int bk=0; f(j,0,i-1) bk=max(bk,val[j]);
            here+=bk;
            val[i]=here;
            ret=max(ret,val[i]);
        }
        return ret;
    }
    int rob(vector<int>& nums) {
        int n=sz(nums); if(n==0) return 0; if(n==1) return nums[0];
        vi a,b; f(i,0,n-1) a.pb(nums[i]); f(i,1,n) b.pb(nums[i]);
        return max(rob1(a),rob1(b));
    }
};
