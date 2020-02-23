/*
    AUTHOR : TANMAY SINHA
    INFORMATION TECHNOLOGY
    BIT MESRA ,RANCHI
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ld long double
#define ull unsigned long long int
#define ll long long int
#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define rep(i,L,R) for(i=L;i<R;i++)
#define DEBUG
#ifdef DEBUG
#define deb2(args...) {dbg,args; cerr<<endl;}
#else
#define deb2(args...)
#endif
struct debb{template<typename T> debb& operator,(const T &v){cerr<<v<<" ";return *this;}}dbg;
#define deb1(args...) do {cerr << #args << " : "; dbg,args; cerr << "\n";} while(0)
#define printa(a,L,R) rep(i,L,R) cout << a[i] <<' ';cout<<"\n";
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
template<typename T>T gcd(T a,T b){if(b==0)return a;else return gcd(b,a%b);}
template<typename T>T lcm(T a,T b){return a/gcd(a,b)*b;}
ll power(ll x,ll y,ll p){ll res=1;x=x%p;while(y>0){if(y&1)res=((res%p)*(x%p))%p;y=y>>1;x=(x*x)%p;}return res;}
ll pow1(ll x,ll y){ll res=1;while(y>0){if(y&1)res=(res*x);y=y>>1;x=x*x;}return res;}
const ll INF = 1e18l+10,N = 105,MAX = 5000000;
#define sq(X) ((X)*(X))
 
ll bit[N][N][N];
ll n;
void update(ll x,ll y,ll z,ll val)
{
    for(ll i = x;i<=n;i=i|(i+1))
    for(ll j = y;j<=n;j=j|(j+1))
    for(ll k = z;k<=n;k=k|(k+1))
    bit[i][j][k]+=val;
}
ll sum(ll x,ll y,ll z)
{
    ll s =0;
    for(ll i=x;i>=0;i =(i & (i+1))-1)
    for(ll j = y;j>=0;j=(j & (j+1))-1)
    for(ll k = z;k>=0;k=(k & (k+1))-1)
    s+=bit[i][j][k];
    return s;
}
int main()
{
    ll q,tot=0;
    cin>>n>>q;
    while(q--)
    {
        ll t,x,y,z,X,Y,Z,val;
        cin>>t>>x>>y>>z;
        if(t==1)
        {
            cin>>val;
            tot+=val;
            update(x,y,z,val);
        }
        else {
            cin>>X>>Y>>Z;
            ll s = sum(X,Y,Z);
            s-=sum(x-1,Y,Z)+sum(X,y-1,Z)+sum(X,Y,z-1);
            s+=sum(x-1,y-1,Z)+sum(x-1,Y,z-1)+sum(X,y-1,z-1);
            s-=sum(x-1,y-1,z-1);
            cout<<tot -s<<"\n";
        }
    }
}
