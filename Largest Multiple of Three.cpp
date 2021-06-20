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
    string largestMultipleOfThree(vector<int>& a) {
        int n=sz(a);
        string ret="";
        if(n==0) return "0";
        int sum=0; f(i,0,n) sum+=a[i];
        
        int fre[10]={0}; for(int t : a) fre[t]++;
        if(sum%3==0){
            bool ok=0; 
            for(int i=9;i>=0;--i){
                if(i!=0 && fre[i]!=0) ok=1;
                if(i!=0) while(fre[i]--) ret+='0'+i;
                if(i==0) if(!ok) ret+='0'; else while(fre[i]--) ret+='0';
            }
        }else if(sum%3==1){
            bool ok=0;
            if(fre[1]) {
                fre[1]--;
                ok=1;
            }else if (fre[4]) {
                fre[4]--;
                ok=1;
            }else if (fre[7]) {
                fre[7]--;
                ok=1;
            }
            if(!ok){
                int get=2;
                int have=0;
                have=min(get,fre[2]);
                fre[2]-=have;
                get-=have;
                have=min(get,fre[5]);
                fre[5]-=have;
                get-=have;
                have=min(get,fre[8]);
                fre[8]-=have;
                get-=have;
            }
            ok=0; 
            for(int i=9;i>=0;--i){
                if(i!=0 && fre[i]!=0) ok=1;
                if(i!=0) while(fre[i]--) ret+='0'+i;
                if(i==0) if(!ok & fre[0]!=0) ret+='0'; else while(fre[i]--) ret+='0';
            }
        }else{
            bool ok=0;
            if(fre[2]) {
                fre[2]--;
                ok=1;
            }else if (fre[5]) {
                fre[5]--;
                ok=1;
            }else if (fre[8]) {
                fre[8]--;
                ok=1;
            }
            if(!ok){
                int get=2;
                int have=0;
                have=min(get,fre[1]);
                fre[1]-=have;
                get-=have;
                have=min(get,fre[4]);
                fre[4]-=have;
                get-=have;
                have=min(get,fre[7]);
                fre[7]-=have;
                get-=have;
            }
            ok=0; 
            for(int i=9;i>=0;--i){
                if(i!=0 && fre[i]!=0) ok=1;
                if(i!=0) while(fre[i]--) ret+='0'+i;
                if(i==0) if(!ok & fre[0]!=0) ret+='0'; else while(fre[i]--) ret+='0';
            }
        }
        return ret;
    }
};