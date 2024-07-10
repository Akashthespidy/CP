#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
vector<set<ll>> gp(15);
ll n,m;
void solve()
{
    cin>>n>>m;
    vector<pair<ll,ll>>ed(m);
    for(ll i=0; i<m; i++)
    {
        ll a,b;
        cin>>a>>b;
        gp[a].insert(b);
        ed[i]= {a,b};
    }
    ll cd=LLONG_MAX;
    vector<ll>path;
    for(ll i=0; i<m; i++)
    {
        vector<ll>dis(n+1,LLONG_MAX);
        map<ll,ll>parent;
        queue<ll>q;
        ll u=ed[i].first,v=ed[i].second;
        gp[u].erase(v);
        dis[v]=v;
        parent[v]=v;
        q.push(v);
        while(!q.empty())
        {
            ll cur=q.front();
            q.pop();
            for(ll i1:gp[cur])
            {
                if(dis[cur]+1<dis[i1])
                {
                    dis[i1]=dis[cur]+1;
                    q.push(i1);
                    parent[i1]=cur;
                }
            }
        }
        if(dis[u]<cd)
        {
            cd=dis[u];
            path.clear();
            ll l=u;
            while(parent[l]!=l)
            {
                path.push_back(l);
                l=parent[l];
            }
            path.push_back(v);
        }
        gp[u].insert(v);

    }
    sort(path.begin(),path.end());
    for(auto u1:path)cout<<u1<<" ";
}

int main()
{
    ll t;
    t=1;
    //cin>>t;
    while(t--)solve();

}
