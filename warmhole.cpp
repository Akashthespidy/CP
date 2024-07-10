#include<bits/stdc++.h>
using namespace std;
#define ll int
ll des[2],s[2],n;
ll hole[50][5];
ll ans;
bool visit[100]={false};
ll dis(ll x,ll y,ll x1,ll y1)
{
    return abs(x-x1)+abs(y-y1);
}
void solve(ll x,ll y,ll cost)
{
    ans=min(ans,cost+dis(x,y,des[0],des[1]));
    for(ll i=0;i<n;i++)
    {
        if(visit[i]==0)
        {
            visit[i]=1;
            solve(hole[i][2],hole[i][3],cost+(dis(x,y,hole[i][0],hole[i][1]))+hole[i][4]);
            solve(hole[i][0],hole[i][1],cost+(dis(x,y,hole[i][2],hole[i][3]))+hole[i][4]);
            visit[i]=0;
        }
    }

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {

        cin>>n;
        cin>>s[0]>>s[1]>>des[0]>>des[1];
        for(ll j=0;j<n;j++)
        {
            cin>>hole[j][0]>>hole[j][1]>>hole[j][2]>>hole[j][3]>>hole[j][4];
        }
        ans=INT_MAX;
        solve(s[0],s[1],0);
        cout<<ans<<endl;
    }
}
