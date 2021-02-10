class Solution {
public:
    vector<int> a,b;
    void fx(vector<int> &A){
        vector<int> ret;
        int n=A.size(); for(int i=0;i<(1<<n);++i){
            int sum=0; for(int j=0;j<n;++j) if((i>>j)&1) sum+=A[j];
            ret.push_back(sum);
        }
        A=ret;
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        sort(nums.begin(),nums.end());
        int n=nums.size(); for(int i=0;i<n;++i){
            if(i<(n/2)) a.push_back(nums[i]);
            else b.push_back(nums[i]);
        }
        fx(a); fx(b);
        sort(a.begin(),a.end()); sort(b.begin(),b.end());
        int ret=INT_MAX; for(int i=0;i<(int)b.size();++i) ret=min(ret,abs(goal-b[i]));
        for(int i=0;i<(int)a.size();++i){
            ret=min(ret,abs(goal-a[i]));
            int ano=goal-a[i];
            int l=0,h=(int)b.size()-1,poss=-1;
            while(l<=h){
                int mid=l+h; mid/=2;
                if(b[mid]>=ano){
                    poss=mid;
                    h=mid-1;
                }else l=mid+1;
            }
            if(poss!=-1) ret=min(ret,abs(a[i]+b[poss]-goal));
            l=0; h=(int)b.size()-1; poss=-1;
            while(l<=h){
                int mid=l+h; mid/=2;
                if(b[mid]<=ano){
                    poss=mid;
                    l=mid+1;
                }else h=mid-1;
            }
            if(poss!=-1) ret=min(ret,abs(a[i]+b[poss]-goal));
        } 
        return ret;
    }
};
