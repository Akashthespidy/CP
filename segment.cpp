#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 600005
#define endl "\n"

//pair<ll,ll>a[5001],b[5001];
ll a[mx];
ll b[mx];
ll a1[mx];
vector<ll>p,seg,sg;
//freopen ("input.txt","r",stdin);
//freopen ("output.txt","w",stdout);
ll fix_mod(ll x, ll y)
{
    return (y + x % y) % y;
}
void prime()
{
    for(ll i=2; i<mx; i++)
    {
        if(a1[i]==0)
            p.push_back(i);
        for(ll j=i; j<mx; j+=i)
            a1[i]=1;
    }
}
void segment(ll l,ll r)
{
    sg.clear();
    ll root=sqrt(r)+1;
    for(ll i=l; i<=r; i++)
        sg.push_back(i);
    if(l==0)
        sg[1]=0;
    else if(l==1)
        sg[0]=0;
    for(ll i=0; i<root; i++)
    {
        ll sq=p[i];
        ll start=p[i]*p[i];
        if(start<l)
        {
            start=((l+sq-1)/sq)*sq;
        }
        for(ll j=start; j<=r; j+=sq)
            sg[j-l]=0;
    }
}
void solve()
{
    ll l,r;
    prime();
    cin>>l>>r;
    segment(l,r);
    for(ll i=l; i<=r; i++)
    {
        if(sg[i-l])
            cout<<i<<" ";
    }
    cout<<endl;
}
/*Read the damn question carefully,show base case*/
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;

    cin>>t;
    while(t--)
        solve();
    return 0;
}

