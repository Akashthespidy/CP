#include<bits/stdc++.h>
using namespace std;
#define ll    long long int
#define mod 1000000007
#define mx 3000010
#define endl "\n"
//pair<ll,ll>a[5001],b[5001];
ll b[mx];
ll a[mx];
bool visit[mx];
ll g[12][12];
ll n,ans=INT_MAX;
void tsp(ll i,ll c,ll dis)
{
    if(c==n-1)
    {
        ans=min(ans,g[i][0]+dis);
        return;
    }
    visit[i]=true;
    for(ll i1=0;i1<n;i1++)
    {
        if(!visit[i1])
        {
            tsp(i1,c+1,dis+g[i][i1]);
        }
    }
    visit[i]=false;

}
void solve()
{
    cin>>n;
    for(ll i=0;i<n;i++)
        for(ll j=0;j<n;j++)cin>>g[i][j];
    tsp(0,0,0);
    cout<<ans<<endl;
    ans=INT_MAX;
}
int main()
{
    ll t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
