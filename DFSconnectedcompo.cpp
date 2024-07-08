#include<bits/stdc++.h>
using namespace std;
#define ll    long long int
#define mod 1000000007
#define mx 3000010
#define endl "\n"
//pair<ll,ll>a[5001],b[5001];
ll b[mx];
ll a[mx];
vector<ll>gp[mx];
bool visit[mx];
void dfs(ll i)
{
    visit[i]=true;
    for(auto child:gp[i])
    {
        if(visit[child])continue;
        dfs(child);
    }
}
void solve()
{
    ll n,m;
    cin>>n>>m;

    for(ll i=0; i<m; i++)
    {
        ll  a,b;
        cin>>a>>b;
        gp[a].push_back(b);
        gp[b].push_back(a);

    }
    ll c=0;
    for(ll i=1; i<=n; i++)
    {
        if(visit[i])continue;
        c++;
        dfs(i);
    }

    cout<<c;
    cout<<endl;
}
/*Read the damn question carefully,show base case*/
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    //prime();
    //cin>>t;
    while(t--)
        solve();
    return 0;
}
