#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <string>

using namespace std;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ll,ii>
#define iiii pair<ii,ii>
#define pb push_back 
#define fi first 
#define se second 
#define log(a,b) ln(b)/ln(a)
#define deb(x) cout << #x << " = " << x << '\n'
const ll MOD = 1e9+7;
const ll inf = 1e9+7;
const ll N = 2e5+5;
const ll BASE = 31;


ll n;
ll a[N],b[N];

void solve(){
    cin >> n;
    for (int i = 1;i <= n;++i){
        cin >> a[i];
        b[i] = a[i];
    }
    for (int i = 1;i < n;++i){
        if (a[i] > a[i+1]){
            ll tmp = a[i]-a[i+1];
            a[i] -= tmp;
            a[i+1] += (tmp+tmp%2);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t = 1;
    // cin >> t;
    for (int i = 1;i <= t;++i){
        solve();
    }
    return 0;
}
