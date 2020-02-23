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
const ll INF = 1e18l+10,N = 1e5,MAX = 5000000;
#define sq(X) ((X)*(X))
ll n;
ll bit[32][N+5];
ll arr[N+5];
void update(ll j,ll old,ll ne)
{
    ll val = 1,k = j;
    for(ll i=0;i<32;i++)
    {
        //deb1((( 1 << i ) & ne));
        if(((( 1 << i ) & old)==0)&&((( 1 << i ) & ne )!=0))
        val = 1;
        else if(((( 1 << i ) & old) !=0) &&((( 1 << i ) & ne )==0))
        val=-1;
        else continue;
        //deb1(i,val);
        while(j<=n)
        {
            bit[i][j]+=val;
            j+= j & (-j);
        }
        j = k;
    }
}
ll query(ll j,ll i)
{
    ll s = 0;
    while(j>0)
    {
        s+=bit[i][j];
        j -= j & (-j);
    }
    //deb1(s);
    return s;
}
int main()
{
    SPEED
    ll q,i,j,k,x;
    
    cin>>n>>q;
    for(i=1;i<=n;i++)
    {
        cin>>arr[i];
        update(i,0,arr[i]);
    }
    while(q--)
    {
        ll t;
        cin>>t;
        if(t==1)
        {
            cin>>x>>i;
            update(i,arr[i],x);
            arr[i] = x;
        }
        else {
            string s;
            ll sum = 0;
            cin>>s>>x>>i;
            for(j =0;j<32;j++)
            {
                ll o = query(i,j)-query(x-1,j);
                //deb1(o);
                ll N = i - x+1;
                ll z = N-o;
                if(s[0]=='A')
                sum+= ((o*(o-1))/2)*(1 << j);
                else if(s[0]=='X')
                sum+= (o*(N-o))*(1 << j);
                else sum+= (N*(N-1)/2 - z*(z-1)/2)*(1 << j);
            }
            cout<<sum<<"\n";
        }
    }
}