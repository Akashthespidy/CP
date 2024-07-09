#include<bits/stdc++.h>
using namespace std;
#define ll long long int
map<ll,string>mp;
bool check(char c,string &s)
{
    for(ll i=0; i<s.size(); i++)
    {
        if(c==s[i])return true;
    }
    return false;
}
void solve()
{
    ll n,m,x1,y1,l1;
    cin>>n>>m>>x1>>y1>>l1;
    ll a[n+1][m+1];
    for(ll i=0; i<n; i++)
        for(ll j=0; j<m; j++)cin>>a[i][j];
    map<ll,map<ll,ll>>vis;
    queue<vector<ll>>q;
    q.push({x1,y1,l1-1});
    vis[x1][y1]=1;
    ll ans=1;
    while(!q.empty())
    {
        ll x=q.front()[0];
        ll y=q.front()[1];
        ll l=q.front()[2];
        q.pop();
        if(l==0)continue;
        if(x>0&&vis[x-1][y]==0&&check('u',mp[a[x][y]])&&check('d',mp[a[x-1][y]]))
        {
            vis[x-1][y]=1;
            q.push({x-1,y,l-1});
            ++ans;
        }
        if(x+1<n&&vis[x+1][y]==0&&check('d',mp[a[x][y]])&&check('u',mp[a[x+1][y]]))
        {
            vis[x+1][y]=1;
            q.push({x+1,y,l-1});
            ++ans;
        }
        if(y>0&&vis[x][y-1]==0&&check('l',mp[a[x][y]])&&check('r',mp[a[x][y-1]]))
        {
            vis[x][y-1]=1;
            q.push({x,y-1,l-1});
            ++ans;
        }
        if(y+1<m&&vis[x][y+1]==0&&check('r',mp[a[x][y]])&&check('l',mp[a[x][y+1]]))
        {
            vis[x][y+1]=1;
            q.push({x,y+1,l-1});
            ++ans;
        }

    }
    cout<<ans<<endl;
}
int main()
{
    ll t;
    cin>>t;
    mp[1]="urdl";
    mp[2]="ud";
    mp[3]="lr";
    mp[4]="ur";
    mp[5]="rd";
    mp[6]="dl";
    mp[7]="ul";
    while(t--)solve();
}
