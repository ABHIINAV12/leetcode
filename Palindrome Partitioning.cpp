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
    vector<string> tem;
    bool pallin(string s){
        string t=s;
        reverse(all(s));
        return s==t;
    }
    vector<vector<string>> ret;
    void rec(int curr,int mx,string &s){
        if(curr==mx){
            ret.pb(tem);
            return ;
        }
        f(i,curr,mx){
            string left=s.substr(curr,i-curr+1);
            if(pallin(left)){
                tem.pb(left);
                rec(i+1,mx,s);
                tem.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        rec(0,sz(s),s);
        return ret;
    }
};
