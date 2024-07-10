#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll a[15][5];
ll n,m,c=0;
int solve(ll x,ll y,bool f,ll ind)
{
    if(x<0||(a[x][y]==2&&ind>=5))return 0;
    ll ans=INT_MIN;
    ll d[3][2]={{-1,-1},{-1,0},{-1,1}};
    for(ll i=0;i<3;i++)
    {
        ll dx=x+d[i][0];
        ll dy=y+d[i][1];
        ll p=0;
        if(dx>=0&&dx<n&&dy>=0&&dy<5)
        {
            if(a[dx][dy]==1&&f==false)
            {
                p=1+solve(dx,dy,f,ind);
            }
            else if(a[dx][dy]==1&&f==true)
            {
                p=1+solve(dx,dy,f,ind+1);
            }
            else if(a[dx][dy]==2&&f==false)
            {
                p=solve(dx,dy,true,ind+1);
            }
            else if(a[dx][dy]==2&&f==true)
            {
                p=solve(dx,dy,true,ind+1);
            }
            else if(a[dx][dy]==0&&f==false)
            {
                p=solve(dx,dy,f,ind);

            }
            else if(a[dx][dy]==0&&f==true)
            {
                p=solve(dx,dy,true,ind+1);
            }
        }
        ans=max(ans,p);

    }
    return ans;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        m=5;
        for(ll i=0; i<n; i++)
            for(ll j=0; j<m; j++)cin>>a[i][j];
        cout<<"#"<<++c<<" "<<solve(n,2,false,0)<<endl;
    }
}
