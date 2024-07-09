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
ll label[mx];
bool bfs(ll i)
{
    visit[i]=true;
    queue<ll>q;
    q.push(i);
    while(!q.empty())
    {
        ll recent=q.front();
        q.pop();
        for(ll child:gp[recent])
            if(!visit[child])
            {
                q.push(child);
                visit[child]=true;
                label[child]=label[recent]+1;
            }
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
    bfs(1);
    for(ll i=1; i<=n; i++)cout<<i<<" "<<label[i]<<endl;

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
