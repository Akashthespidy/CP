class Solution {
public:
    int hIndex(vector<int>&v) {
        int c=0;
        int n=v.size();
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
        {
            if(v[i]>=n-i)c=max(c,n-i);
        }
        return c;
    }
};
