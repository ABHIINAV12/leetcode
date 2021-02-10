class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;++i){
            bool xp=1;
            for(int j=1;j<n;++j){
                if(!(nums[(j+i)%n]>=nums[(j+i-1)%n])) xp=0;
            }
            if(xp) return 1;
        }
        return 0;
    }
};
