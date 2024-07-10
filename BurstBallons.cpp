#include<bits/stdc++.h>
using namespace std;
#define ll int
ll solve(ll i,ll j,vector<ll>&v,ll dp[12][12])
{
    if(i>j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    ll ans=INT_MIN;
    for(ll l=i;l<=j;l++)
    {
        ll c,n=v.size();
        if((i-1==0)&&(j+1==n-1))c=v[l]+solve(i,l-1,v,dp)+solve(l+1,j,v,dp);
        else c=(v[i-1]*v[j+1])+solve(i,l-1,v,dp)+solve(l+1,j,v,dp);
        ans=max(ans,c);
    }
    return dp[i][j]=ans;
}
int main()
{
    ll n;
    cin>>n;
    vector<ll>v;
    v.push_back(1);
    ll dp[12][12];
    memset(dp,-1,sizeof(dp));
    for(ll i=0;i<n;i++){
        ll l;
        cin>>l;
        v.push_back(l);
    }
    v.push_back(1);
    n=v.size();
    cout<<solve(1,n-2,v,dp);
    return 0;

}
