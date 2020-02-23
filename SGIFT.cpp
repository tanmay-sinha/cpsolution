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

int main()
{
    ll n,q,i,a,b;
    cin>>n;
    ll arr[n];
    for(i=0;i<n;i++)
    cin>>arr[i];
    sort(arr,arr+n);
    ll pre[n+1];
    pre[0]=0;
    for(i=0;i<n;i++)
        pre[i+1]=pre[i]+arr[i];
    cin>>q;
    while(q--)
    {
        cin>>a>>b;
        ll low = lower_bound(arr,arr+n,a)-arr;
        ll up = upper_bound(arr,arr+n,b)-arr;
        //deb1(low,up);
        cout<<pre[up]-pre[low]<<"\n";
    }
    
}
