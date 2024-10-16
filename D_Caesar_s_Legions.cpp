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
#define FORU(i,a,b) for (int i = a;i <= b;++i)
const ll MOD = 100000000;
const ll inf = 1e9+7;
const ll N = 2e5+5;
const ll BASE = 31;

ll dp[105][105][15][15] = {};

int n1,n2,k1,k2;
ll C(int f,int h,int kf,int kh){
    //cout << f << ' ' << h << ' ' << kf << ' ' << kh << '\n';
    if (dp[f][h][kf][kh] != -1) return dp[f][h][kf][kh]; 
    if (f + h == 0) return 1;
    else{
        ll ans = 0;
        if (f > 0 && kf > 0) ans = (ans+C(f-1,h,kf-1,k2))%MOD;
        if (h > 0 && kh > 0) ans = (ans+C(f,h-1,k1,kh-1))%MOD;
        dp[f][h][kf][kh] = ans;
    }
    return dp[f][h][kf][kh];
}


void solve(){
    cin >> n1 >> n2 >> k1 >> k2;
    FORU(i,0,n1){
        FORU(j,0,n2){
            FORU(p,0,k1){
                FORU(q,0,k2){
                    if (i + j == 0) dp[i][j][p][q] = 1;
                    else{
                        ll ans = 0;
                        if (i>0&&p>0) ans = (ans+dp[i-1][j][p-1][k2])%MOD;
                        if (j>0&&q>0) ans = (ans + dp[i][j-1][k1][q-1])%MOD;
                        dp[i][j][p][q] = ans;
                    }
                }
            }
        }
    }
    cout << dp[n1][n2][k1][k2] << '\n';
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
