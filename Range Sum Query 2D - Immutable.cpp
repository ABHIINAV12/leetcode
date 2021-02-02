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

class NumMatrix {
public:
    vector<vector<int>> pre;
    NumMatrix(vector<vector<int>>& mat) {
        int r=sz(mat); if(r!=0){
            int c=sz(mat[0]);
            if(c!=0){
                vi vt; f(i,0,c+1) vt.pb(0); pre.pb(vt);
                f(i,0,r){
                    vt.clear(); vt.pb(0);
                    f(j,0,c) vt.pb(vt[j]+mat[i][j]);
                    pre.pb(vt);
                }
                f(i,1,r+1)
                    f(j,0,c+1) pre[i][j]+=pre[i-1][j];   
            }
        }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        if(sz(pre)==0) return 0;
        return pre[r2+1][c2+1]+pre[r1][c1]-pre[r1][c2+1]-pre[r2+1][c1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
