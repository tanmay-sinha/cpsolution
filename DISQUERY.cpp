#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ld long double
#define ull unsigned long long int
#define ll long long int
#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007ll
#define rep(i,L,R) for(ll i=L;i<R;i++)
#define f(n) rep(i,0,n)
#define DEBUG
#ifdef DEBUG
#define deb2(args...) {dbg,args; cerr<<endl;}
#else
#define deb2(args...)
#endif
struct debb{template<typename T> debb& operator,(const T &v){cerr<<v<<" ";return *this;}}dbg;
#define deb1(args...) do {cerr << #args << " : "; dbg,args; cerr << "\n";} while(0)
#define printa(a,L,R) rep(i,L,R) cout << a[i] <<' ';cout<<"\n";
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
template<typename T>T gcd(T a,T b){if(b==0)return a;else return gcd(b,a%b);}
template<typename T>T lcm(T a,T b){return a/gcd(a,b)*b;}
ll power(ll x,ll y,ll p){ll res=1;x=x%p;while(y>0){if(y&1)res=((res%p)*(x%p))%p;y=y>>1;x=(x*x)%p;}return res;}
ll pow1(ll x,ll y){ll res=1;while(y>0){if(y&1)res=(res*x);y=y>>1;x=x*x;}return res;}
#define sq(X) ((X)*(X))
#define PI 3.141592653589
const ll INF = 1e18l+10,N = 1e5+10,MAX = 5000000;
vector<pair<ll,ll> > adj[N];
vector<vector<ll>> par,m1,m2;
vector<ll> lev;
ll s;

void dfs(ll n,ll p,ll e) {
    lev[n] = lev[p] + 1;
    par[n][0] = p;
    
    m1[n][0] = m2[n][0] = e;

    for(int i = 1;i<=s;i++)
    if(par[n][i-1]!=-1){
    par[n][i] = par[par[n][i-1]][i-1];
    m1[n][i] = max(m1[n][i-1],m1[par[n][i-1]][i-1]);
    m2[n][i] = min(m2[n][i-1],m2[par[n][i-1]][i-1]);
    }

    for(auto i : adj[n])
    if(i.first != p)
    dfs(i.first,n,i.second);
}

pair<ll,ll> lca(ll u,ll v){
    if(lev[u]<lev[v])
    swap(u,v);
    ll a1 = INT_MAX,a2 =-1;
    ll d = lev[u] - lev[v];

    for(ll i = 0;i<s;i++)
    if((d>>i) & 1)
    {
    a1= min(a1,m2[u][i]);
    a2 = max(a2,m1[u][i]);
    u = par[u][i];
    }

    if(u==v) return {a1, a2};

    for(ll i = s-1;i>=0;i--)
    if(par[u][i]!=par[v][i])
    {
    a1 = min({a1, m2[v][i], m2[u][i]});
    a2 = max({a2, m1[v][i], m1[u][i]});
    u = par[u][i], v = par[v][i];
    }
    a1 = min({a1, m2[v][0], m2[u][0]});
    a2 = max({a2, m1[v][0], m1[u][0]});

    return {a1, a2};
}

int main()
{
    SPEED
    ll t,i,m,n,j,q,u,v;
    // cin>>t;
    // while(t--)
    {
        cin>>n;
        // f(n+1) adj[i].clear();
        rep(i,0,n-1){
            ll a,b,w;
            cin>>a>>b>>w;
            adj[a].push_back({b,w}),adj[b].push_back({a,w});
        }
        cin>>q;
        s = (ll)ceill(log2(n));
        par.assign(n+1, vector<ll>(s+1, -1));
        m1.assign(n+1, vector<ll>(s+1, -1));
        m2.assign(n+1, vector<ll>(s+1, INT_MAX));
        lev.assign(n+1,0);
        dfs(1,0,0);
        // cout<<"Case "<<c++<<":\n";
        while(q--)
        {
            cin>>u>>v;
            auto p = lca(u,v);
            cout<<p.first<<" "<<p.second<<"\n";
        }
    }
}
