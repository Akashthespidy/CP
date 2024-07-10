#include<bits/stdc++.h>
using namespace std;
#define ll int
ll a[50][50];
ll n,m,ans=INT_MAX;
int visit[50][50];
void solve(ll x,ll y,ll diff)
{
    if(x<0||y<0||x>=n||y>=m)return;
    if(a[x][y]==3)
    {
        ans=min(ans,diff);
        return;
    }
    visit[x][y]=1;
    ll up=x-1;
    while(up>=0&&a[up][y]==0)up--;
    if(up>=0&&visit[up][y]==0)solve(up,y,max(diff,x-up));
    ll down=x+1;
    while(down<n&&a[down][y]==0)down++;
    if(down<n&&visit[down][y]==0)solve(down,y,max(diff,down-x));
    if(y+1<m&&!visit[x][y+1]&&a[x][y+1])solve(x,y+1,diff);
    if(y-1>=0&&!visit[x][y-1]&&a[x][y-1])solve(x,y-1,diff);

    visit[x][y]=0;
    return;

}
int main()
{
    cin>>n>>m;
    for(ll i=0; i<n; i++)
        for(ll j=0; j<m; j++)cin>>a[i][j];
    solve(n-1,0,0);
    cout<<ans;
}
