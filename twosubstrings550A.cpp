#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 200001

//pair<ll,ll>a[5001],b[5001];
//ll a[mx];
//ll b[mx];

//freopen ("input.txt","r",stdin);
//freopen ("output.txt","w",stdout);

void solve()
{
    string s;
   cin>>s;
   int a=s.find("AB");
   int  b=s.find("BA",a+2);
   int c=s.find("BA");
   int d=s.find("AB",c+2);
   if((a!=-1 && b!=-1) || (c!=-1 && d!=-1)) cout<<"YES"<<endl;
   else cout<<"NO"<<endl;
}
int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1;
   // cin>>t;

    for(int i=1; i<=t; i++)
        solve();
    return 0;
}
