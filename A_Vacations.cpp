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

int a[N];
int dp[N][2] = {};
int n;

void solve(){
    cin >> n;
    for (int i=1;i<=n;++i)  cin >> a[i];
    for (int i=1;i<=n;++i){
        if (a[i] == 1){
            dp[i][1] = dp[i-1][0] + 1;
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
        }
        else if(a[i] == 2){
            dp[i][0] = dp[i-1][1] +1;
            dp[i][1] = max(dp[i-1][0],dp[i-1][1]);
        }
        else if(a[i] == 3){
            dp[i][1] = dp[i-1][0] + 1;
            dp[i][0] = dp[i-1][1] + 1;
        }
        else{
            dp[i][1] = dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
        }
        //cout << dp[i][0] << ' ' << dp[i][1] << '\n';
    }
    cout << n - max(dp[n][0],dp[n][1]) << '\n';
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
