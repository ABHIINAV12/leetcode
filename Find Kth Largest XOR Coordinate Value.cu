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
    int kthLargestValue(vector<vector<int>>& a, int k) {
        int m=a.size(),n=a[0].size();

        int col[1100]={0};
        int ans[m+1][n+1];
        f(i,0,m+1) f(j,0,n+1) ans[i][j]=0;
        f(i,0,m) {
            int x=0;
            f(j,0,n){
                ans[i+1][j+1]=ans[i][j]^col[j]^x^a[i][j];
                x^=a[i][j];
            }
            f(j,0,n) col[j]^=a[i][j];
        }

        vi ri; 
        
        
        f(i,1,m+1) f(j,1,n+1) ri.pb(ans[i][j]);
        sort(all(ri));
        reverse(all(ri));

        return ri[k-1];
    
    }
};