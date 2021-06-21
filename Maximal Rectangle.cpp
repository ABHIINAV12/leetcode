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
    int maximalRectangle(vector<vector<char>>& a) {
        int m=sz(a); if(m==0) return 0;
        int n=sz(a[0]); if(n==0) return 0;
        int ret=0; vi h(n,0) ,left(n,0), right(n,0);
        stack<int> st;
        f(i,0,m){
            f(j,0,n) if(a[i][j]=='0') h[j]=0; else h[j]++;
      //      f(j,0,n) cout<<h[j]<<" "; cout<<"------height\n";
            while(!st.empty()) st.pop();
            f(j,0,n){
                while(!st.empty() && h[st.top()]>=h[j]) st.pop();
                if(st.empty()) left[j]=-1;
                else left[j]=st.top();
                st.push(j);
            }
    //        f(j,0,n) cout<<left[j]<<" "; cout<<"-------------left\n";
            while(!st.empty()) st.pop();
            for(int j=n-1;j>=0;--j){
                while(!st.empty() && h[st.top()]>=h[j]) st.pop();
                if(st.empty()) right[j]=n;
                else right[j]=st.top();
                st.push(j);
            }
  //          f(j,0,n) cout<<right[j]<<" "; cout<<"---------right\n";
            f(j,0,n) ret=max(ret,h[j]*(right[j]-left[j]-1));
        }

        return ret;
    }
};