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
    int maximumScore(vector<int>& a, int k) {
        // the idea being that min is decreasing function so we can choose greedily th direction.
        int ret=a[k],i=k,j=k,len=1,mn=ret,n=sz(a);
        while(i>=1 && j<(n-1)){
            if(a[i-1]>=a[j+1]) --i;
            else ++j;
            mn=min({mn,a[i],a[j]});
            ++len;
            ret=max(ret,len*mn);
          //  cout<<i<<" "<<j<<" "<<ret<<" "<<len*mn<<"\n";
        }
        while(i>=1){
            --i;
            mn=min(mn,a[i]);
            ++len;
            ret=max(ret,len*mn);
            //cout<<i<<" "<<j<<" "<<ret<<" "<<len*mn<<"\n";
        }
        while(j<(n-1)){
            ++j;
            mn=min(mn,a[j]);
            ++len;
            ret=max(ret,len*mn);
           // cout<<i<<" "<<j<<" "<<ret<<" "<<len*mn<<"\n";
        }
        return ret;
    }
};