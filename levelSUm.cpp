#include<bits/stdc++.h>
using namespace std;
#define ll int
void solve()
{
    ll k;
    cin >> k;
    string s;
    cin >> s;
    ll sum=0,c=-1;
    for(ll i=0;i<s.size();)
    {
        if(s[i]=='(')++c,++i;
        else if(s[i]==')')--c,++i;
        else

        {
            string t=" ";
            while(s[i]!='('&&s[i]!=')')
            {
                t+=s[i];
                ++i;
            }
            if(c==k)sum+=(stoll(t));
        }
    }


    cout << sum;
}

int main()
{
    solve();
}
