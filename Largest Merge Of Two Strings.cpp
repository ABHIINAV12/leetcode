class Solution {
public:
    string largestMerge(string a, string b) {
        int n=a.size(), m=b.size(); string ret="";
        int i=0,j=0; while(i<n && j<m){
            if(a.substr(i)>b.substr(j))
                ret+=a[i++]; 
            else
                ret+=b[j++];
        }while(i<n) ret+=a[i++];
        while(j<m) ret+=b[j++];
        return ret;
    }
};
