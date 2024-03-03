class Solution {
public:
    int jump(vector<int>& a) {
        int n=a.size();
        int c=0,ans=0,l;
        for(int i=0;i<n-1;i++)
        {
           l=max(l,i+a[i]);
           if(l>=n-1){
               ++ans;
               break;
           }
           if(i==c)
           {
               ++ans;
               c=l;
           }
        }
        return ans;
    }
};
