#include<bits/stdc++.h>
using namespace std;
#define ll    long long int
#define mod 1000000007
#define mx 1000005
#define endl "\n"
//pair<ll,ll>a[5001],b[5001];
ll b[mx];
ll a[mx];
ll a1[mx];
ll c1=0;
ll o1=1;
ll dp[mx];
vector<ll>p,seg,sg;
map<ll,ll>mp1;
//freopen ("input.txt","r",stdin);
//freopen ("output.txt","w",stdout);
ll fix_mod(ll x, ll y)
{
    return (y + x % y) % y;
}
int bmod(int a,int b,int m)
{
    if(b==0)
        return 1;
    int x=bmod(a,b/2,m);
    x=(x*x)%m;
    if(b%2==1)
        x=(x*a)%m;
    return x;
}
void prime()
{

    for(ll i=2; i<1e5; i++)
    {
        if(a1[i]==0)
            p.push_back(i),mp1[i]=1;
        for(ll j=i; j<mx; j+=i)
            a1[j]=1;
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
int sumofdiv(int m)
{
    ll l=p.size();
    ll c=0,r=1,s;
    for(ll i=0; i<l&&p[i]<=sqrt(m); i++)
    {
        ll l1=p[i];
        if(m%p[i]==0)
        {
            while(m%p[i]==0)
            {
                ++c;
                m/=p[i];
                if(m==1||m==0)
                    break;
            }
            r=r*(pow((double)l1,c+1.0)-1)/(l1-1);
        }
    }
    if(m!=1)
    {
        r=r*(pow((double)m,2)-1)/(m-1);
    }
    //cout<<r;
    return r;
}
int divisor(int m)
{
    ll l=p.size();
    ll c=0,r=1,s;
    for(ll i=0; i<l&&p[i]<=sqrt(m); i++)
    {
        if(m%p[i]==0)
        {
            while(m%p[i]==0)
            {
                ++c;
                m/=p[i];
                if(m==1||m==0)
                    break;
            }

            s=c+1;
            r*=s;
        }
    }
    if(m!=1)
    {
        r*=2;
    }
    //cout<<r;
    return r;
}
bool cmp(pair<ll,ll>x,pair<ll,ll>y)
{
    if(x.first==y.first)
    {
        return (x.second>y.second);
    }
    return (x.first>y.first);
}
bool myComp(string &a, string &b)
{
    return a.size() < b.size();
}
ll yes(ll f)
{
    return 1;
}

void solve()
{


}
/*Read the damn question carefully,show base case*/
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    prime();
    //cin>>t;
    while(t--)
        solve();
    return 0;
}

