#include<bits/stdc++.h>
using namespace std;
#define ll int
ll people[3],gate[3];
ll ans=INT_MAX,n,sum=0;
int dis(ll x)
{
    if(x>0)return x;
    else return -x;
}
void solve(ll index,ll val,ll c)
{
    if(sum==c)
    {
        ans=min(ans,val);
        return;
    }
    if(index==n+1)return;
    for(ll i=0; i<3; i++)
    {
        if(people[i]>0)
        {
            people[i]--;
            solve(index+1,val+dis(gate[i]-index)+1,c+1);
            people[i]++;
        }
    }
    solve(index+1,val,c);
}
int main()
{
    cin>>n;
    for(ll i=0; i<3; i++)cin>>gate[i];
    for(ll i=0; i<3; i++)cin>>people[i],sum+=people[i];
    solve(1,0,0);
    cout<<ans;

}
