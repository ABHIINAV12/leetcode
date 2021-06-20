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
    int maximumSum(vector<int>& a) {
        int n=sz(a);
        bool pos=0; f(i,0,n) if(a[i]>=0) pos=1;
        if(!pos)
            return *max_element(all(a));
        int mx=0,curr=0; f(i,0,n){
            curr+=a[i];
            if(curr<0) curr=0;
            mx=max(mx,curr);
        }
        vi left(n,0); curr=0;
        f(i,0,n) {
            curr+=a[i];
            curr=max(curr,0);
            left[i]=curr;
        }
        vi right(n,0); curr=0;
        for(int i=n-1;i>=0;--i){
            curr+=a[i];
            curr=max(curr,0);
            right[i]=curr;
        }
        f(i,1,n-1)
            if(a[i]<0)
                mx=max(mx,left[i-1]+right[i+1]);
            
        return mx;
    }
};