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
    int longestMountain(vector<int>& arr) {
        int n = sz(arr);
        int left[11000]={0}; int right[11000]={0};
        for(int i=n-2;i>=0;--i){
            if(arr[i]>arr[i+1]) {
                right[i]=right[i+1]+1;
            }
        }
        f(i,1,n) if(arr[i]>arr[i-1]) left[i]=left[i-1]+1;
        int ret=0;

        f(i,0,n){
            int here=left[i]+right[i]+1;
            if(here>=3 && left[i]!=0 && right[i]!=0) ret=max(ret,here);
        }

        return ret;
        
    }
};