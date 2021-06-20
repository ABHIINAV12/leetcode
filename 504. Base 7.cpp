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
    string convertToBase7(int num) {
        if(num==0) return "0";
        string ret="";
        string here="";
        bool neg=0;
        if(num<0) {neg=1; num*=-1;}
        while(num!=0){
            here+='0'+num%7;
            num/=7;
        }
        reverse(all(here));
        if(neg) ret+='-';
        ret+=here;
        return ret;
    }
};