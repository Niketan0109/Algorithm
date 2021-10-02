///////////////////////////////////////////////////////////////////////////////////////////////////////
/*
HACKED BY NINAD KALANKE
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

// Macros startted
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ld double
#define endl cout<<'\n';
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define mod (ll)1e9+7
#define inf (ll)1e18
#define vec vector
#define pi pair
#define ff first
#define ss second
#define pb push_back
#define pob pop_back()
#define all(n) n.begin(),n.end()
#define mp make_pair
#define gcd(a,b) __gcd(a,b)
#define sortd(n) sort(all(n),greater<>())
#define sorta(n) sort(all(n))
#define lower(s) transform(s.begin(),s.end(),s.begin(), ::tolower)
#define upper(s) transform(s.begin(),s.end(),s.begin(), ::toupper)
// Macros ended

// Debug strated
void debug(ll n) {cout<<n; endl}
void debug(ld n) {cout<<n; endl}
void debug(string n) {cout<<n; endl}
void debug(char n) {cout<<n; endl}
void debug(vec<ll> a) {for(ll i=0;i<a.size();i++){ cout<<a[i]<<" ";}endl}
void debug(vec<ld> a) {for(ll i=0;i<a.size();i++){ cout<<a[i]<<" ";}endl}
void debug(vec<string> a) {for(ll i=0;i<a.size();i++){ cout<<a[i]<<" ";}endl}
void debug(vec<pi<ll,ll>> a) {for(ll i=0;i<a.size();i++){cout<<a[i].ff<<" "<<a[i].ss;endl}}
void debug(vec<pi<ld,ld>> a) {for(ll i=0;i<a.size();i++){cout<<a[i].ff<<" "<<a[i].ss;endl}}
void debug(vec<pi<string,string>> a) {for(ll i=0;i<a.size();i++){cout<<a[i].ff<<" "<<a[i].ss;endl}}
void debug(vec<vec<ll>> a) {for(ll i=0;i<a.size();i++){for(ll j=0;j<a[i].size();j++) cout<<a[i][j]<<" ";endl}}
void debug(vec<vec<ld>> a) {for(ll i=0;i<a.size();i++){for(ll j=0;j<a[i].size();j++) cout<<a[i][j]<<" ";endl}}
void debug(vec<vec<string>> a) {for(ll i=0;i<a.size();i++){for(ll j=0;j<a[i].size();j++) cout<<a[i][j]<<" ";endl}}
void debug(vec<vec<char>> a) {for(ll i=0;i<a.size();i++){for(ll j=0;j<a[i].size();j++) cout<<a[i][j]<<" ";endl}}
void debug(unordered_map<ll,ll> a) {for(auto e : a){cout<<e.ff<<" "<<e.ss;endl}}
void debug(unordered_map<ld,ld> a) {for(auto e : a){cout<<e.ff<<" "<<e.ss;endl}}
// End of debug

// Some Many times used functions
template<typename T>
bool isprime(T n)
{
    for(ll i=2;i<=(T)sqrt(n);i++)
    {
        if(n%i==0)
        return 0;
    }
    return 1;
}
template<typename T1,typename T2>
bool fs(pi<T1,T2> &a,pi<T1,T2> &b)
{
    if(a.ff<b.ff)
    return 1;
    if(a.ff>b.ff)
    return 0;
    return a.ss<b.ss;
}
template<typename T1,typename T2>
bool sf(pi<T1,T2> &a,pi<T1,T2> &b)
{
    if(a.ss<b.ss)
    return 1;
    if(a.ss>b.ss)
    return 0;
    return a.ff<b.ff;
}
// End of functions

int main(){
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    fast
    ll t=1;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;

        deque<ll> b;

        vec<ll> a(n);

        for(ll i=0;i<n;i++)
        cin>>a[i];

        for(ll i=0;i<n;i++)
        {
            if(i==0)
            {
                b.push_front(a[i]);
            }
            else if(b.front()>a[i])
            b.push_front(a[i]);
            else
            b.push_back(a[i]);
        }

        while(!b.empty())
        {
            cout<<b.front()<<' ';
            b.pop_front();
        }

        endl;
    }
    return 0;
}
