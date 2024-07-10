#include<bits/stdc++.h>
using namespace std;
#define ll  int
ll a[20],b[20],n,ans;
ll  abs(ll x)
{
    if(x>0)return x;
    else return -x;
}
ll dis(ll p,ll r)
{
    return(abs(a[p]-a[r])+abs(b[p]-b[r]));
}
void solve(ll ri,bool visit[],ll val,ll pi)
{
    if(pi==n)
    {
        ans=min(ans,val+dis(ri,n+1));
        return;
    }
    for(ll i=1;i<=n;i++)
    {
        if(!visit[i])
        {
            visit[i]=true;
            solve(i,visit,val+dis(ri,i),pi+1);
            visit[i]=false;
        }
    }
}
int main()
{
    ll t=10,c=0;
    while(t--)
    {
        cin>>n;
        cin>>a[0]>>b[0]>>a[n+1]>>b[n+1];
        for(ll i=1;i<=n;i++)cin>>a[i]>>b[i];
        ans=INT_MAX;
        bool visit[n+2]={false};
        solve(0,visit,0,0);
        cout<<"# "<<++c<<" "<<ans<<endl;
    }
}
