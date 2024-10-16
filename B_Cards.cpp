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

int n;
string s;
int r[300] ={};

void solve(){
    cin >> n >> s;
    for (int i = 0;i < n;++i)   r[s[i]]++;
    ll a = r['B'];
    ll b = r['G'];
    ll c = r['R'];
    if ((a>=1&&b>=1&&c>=1) || (a>=2&&b>=2) || (b>=2&&c>=2) || (c>=2&&a>=2)){
        cout << "BGR";
        return;
    }
    if ((a>=1&&b==0&&c==0)){
        cout << "B";
        return;
    }
    if ((a==0&&b>=1&&c==0)){
        cout << "G";
        return;
    }
    if ((a==0&&b==0&&c>=1)){
        cout << "R";
        return;
    }
    if (a == 0){
        if (b>=2&&c==1) cout << "BR";
        else if(c>=2&&b==1) cout <<"BG";
        else if (b==1&&c==1) cout << "B";
        return;
    }
    else if (b == 0){
        if (a>=2&&c==1) cout << "GR";
        else if (c>=2&&a==1) cout << "BG";
        else cout << "G";
    }// BGR
    else if (c==0){
        if (a>=2&&b==1) cout << "GR";
        else if (b>=2&&a==1) cout << "BR";
        else cout << "R";
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

