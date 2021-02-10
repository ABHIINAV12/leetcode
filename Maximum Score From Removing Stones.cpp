class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int sum=a+b+c; sum/=2; 
        int mx=max({a,b,c}); mx*=-1; mx+=a+b+c;
        return min(mx,sum);
    }
};
