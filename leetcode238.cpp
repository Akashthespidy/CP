class Solution {
public:
    vector<int> productExceptSelf(vector<int>& v) {
        int n=v.size();
        vector<int>p(n);
        p[0]=1;
        for(int i=1;i<n;i++)p[i]=p[i-1]*v[i-1];
        int s=1;
        for(int i=n-1;i>=0;i--)
        {
            p[i]=s*p[i];
            s*=v[i];
        }
       return p;

    }
};
