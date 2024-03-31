#include <bits/stdc++.h>
using namespace std;

int a,b,c;

bool f(int x){
    return x % a != 0 && x % b != 0 && x % c !=0;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;

    cin >> a >> b >> c;

    int ans = 0;

    for(int i = 1; i <= n; i++){
        if(f(i)){
            ans += 1;
        }
    }

    cout << ans;

    return 0;
}