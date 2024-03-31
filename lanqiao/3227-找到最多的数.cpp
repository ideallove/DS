#include <bits/stdc++.h>
using namespace std;

map<int, int> mp;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    // 用map<int, int>存放数字出现次数

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n * m; i++){
        int x;
        cin >> x;
        mp[x]++;
    }

    for(const auto &[x, y] : mp){
        if( 2 * y > n * m ){
            cout << x << endl;
        }
    }

    return 0;
}