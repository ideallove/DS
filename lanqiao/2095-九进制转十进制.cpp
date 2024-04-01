#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 10;
int a[N];

int main()
{  
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n = 4;
    string s = "2022";
    for(int i = 1; i<=4; i++){
        a[i] = s[i-1] - '0';
    }
    ll x = 0;
    for(int i = 1; i<=n; ++i){
        x = x * 9 + a[i];
    }
    cout << x << '\n';

    return 0;
}