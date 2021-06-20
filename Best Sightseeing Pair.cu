
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


    int maxScoreSightseeingPair(vector<int>& a) {
        int n=a.size();
        priority_queue<int> here;
        here.push(a[0]);
        int ret=0;

        f(i,1,n){
            ret=max(ret,a[i]-i + here.top());
            here.push(a[i]+i);
        }

        return ret;
           
    }
};