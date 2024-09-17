#include<bits/stdc++.h>
using namespace std;
#define ll    long long int
#define endl "\n"

// Graph representation and visited map
map<string, vector<string>> g;
map<string, bool> visit;

void dfs(string s)
{
    visit[s] = true;
    for(auto u : g[s])
    {
        if(!visit[u]) dfs(u);
    }
}

void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<string>vol(n);
    map<string,ll>m1;
    for(ll i=0; i<n; i++)
    {
        cin>>vol[i];
        m1[vol[i]]=i;
    }
    bool inv[100][100]= {false};
    for(ll i=0; i<m; i++)
    {
        string s,s1;
        cin>>s>>s1;
        ll u=m1[s],v=m1[s1];
        inv[u][v]=true;
        inv[v][u]=true;
    }
    ll best_m=0,best_t=0;
    for(ll mask=0; mask<(1<<n); mask++)
    {
        vector<ll>v;
        bool f=true;
        for(ll i=0; i<n; i++)
        {
            if(mask&(1<<i))
            {
                for(ll j:v)
                {
                    if(inv[i][j])
                    {
                        f=false;
                        break;
                    }
                }
                if(f)v.push_back(i);
                else break;
            }
        }
        if(v.size()>best_t&&f)
        {
            best_m=mask;
            best_t=v.size();
        }
    }
    vector<string>ans;
    for(ll i=0; i<n; i++)
    {
        if(best_m&(1<<i))
        {
            ans.push_back(vol[i]);
        }
    }
    cout<<ans.size()<<endl;
    sort(ans.begin(),ans.end());
    for(auto u:ans)cout<<u<<endl;
    //cout<<endl;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
