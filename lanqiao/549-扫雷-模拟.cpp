#include <bits/stdc++.h>
using namespace std;

const int N = 150;
int mp[N][N], ans[N][N];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i<= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> mp[i][j];
        }
    }

    for(int i = 1; i<= n; i++){
        for(int j = 1; j <= m; j++){
            if(mp[i][j]==1){
                ans[i][j]=9;
                continue;
            }
            // 扫描九宫格
            for(int _i = max(1, i - 1); _i <= min(n, i + 1); ++_i){
                for(int _j = max(1, j - 1); _j <= min(m, j + 1); ++_j){
                    if(mp[_i][_j]){
                        ans[i][j]++;
                    }
                }
            }
        }
    }

    for(int i = 1; i<= n; i++){
        for(int j = 1; j <= m; j++){
            cout << ans[i][j] << ' ';
        }
        cout << "\n";
    }

    return 0;
}
