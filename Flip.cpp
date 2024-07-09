#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n,m,k;
ll a[20][20];
ll c=0,res=INT_MIN;
void count_c(ll index)
{
    for(ll j=0;j<n;j++)a[j][index]=!(a[j][index]);
}
ll count_r()
{
    ll c1=0;
    for(ll i=0; i<n; i++)
    {
        ll f=1;
        for(ll j=0; j<m; j++)
        {
            if(a[i][j]!=1)
            {
                f=0;
                break;
            }
        }
        if(f)++c1;
    }
    return c1;
}
void flip(ll index,ll k)
{
    if(k<=0)
    {
        ll temp=count_r();
        if(res<temp)res=temp;
        return;
    }
    if(index>m)return;
    for(ll i=0;i<=k;i++)
    {
        for(ll j=0;j<i;j++)
        {
            count_c(index);
        }
        flip(index+1,k-i);
        for(ll j=0;j<i;j++)count_c(index);
    }
}

int main()
{
    cin>>n>>m>>k;
    for(ll i=0; i<n; i++)
        for(ll j=0; j<m; j++)cin>>a[i][j];
    res=0;
    flip(0,k);
    cout<<res<<endl;
}
