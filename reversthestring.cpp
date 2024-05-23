class Solution {
public:
    string reverseWords(string s) {
        int i=0,j=0;
        int n=s.size();
        while(i<n)
        {
            while(s[i]==' '&&i<n)++i;
            if(i<n)
            {
                if(j!=0)
                {
                    s[j]=' ',++j;
                }
                int k=i;
                while(k<n&&s[k]!=' ')
                {
                    s[j]=s[k],++j,++k;
                }
                reverse(s.begin()+j-(k-i),s.begin()+j);
                i=k;
            }
        }
            s.erase(s.begin()+j,s.end());
            reverse(s.begin(),s.end());
            return s;

    }
};
