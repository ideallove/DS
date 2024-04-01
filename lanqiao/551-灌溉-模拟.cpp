#include <bits/stdc++.h>
using namespace std;

const int N = 120;
int mp[N][N];
bool a[N][N], b[N][N];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;

    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;
    }
    int k;
    cin >> k;
    while(k--){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(a[i][j]){
                    b[i][j] = b[i-1][j] = b[i+1][j] = b[i][j-1] = b[i][j+1] = 1;
                }
            }
        }
        // 将b复制回a
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                a[i][j] = b[i][j];
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j]){
                ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
