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
    int largestRectangleArea(vector<int>& h) {
        int ret=0,n=sz(h); if(n==0) return 0;
        vi left(n,0),right(n,0);
        stack<int> st;
        f(i,0,n){
            while(!st.empty() && h[st.top()]>=h[i]) st.pop();
            if(st.empty()) left[i]=-1;
            else left[i]=st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;--i) {
            while(!st.empty() && h[st.top()]>=h[i]) st.pop();
            if(st.empty()) right[i]=n;
            else right[i]=st.top();
            st.push(i);
        }
        f(i,0,n) ret=max(ret,h[i]*(right[i]-left[i]-1));
        return ret;
    }
};