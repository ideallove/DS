#include <bits/stdc++.h>
using namespace std;

bool f(int x){
    while(x){
        int y = x % 10;
        if( y == 2 || y == 0 || y == 1 || y == 9 ){
            return true;
        }
        x /= 10;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;

    int ans = 0;

    for(int i = 1; i <= n; i++){
        if(f(i)){
            ans += i;
        }
    }

    cout << ans;

    return 0;
}