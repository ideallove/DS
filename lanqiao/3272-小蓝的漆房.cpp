#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t;      // t个测试
    cin >> t;
    while(t--){
        int n, k;   // 输入
        cin >> n >> k;

        vector<int> arr(n);
        unordered_set<int> s;

        for(int j = 0; j < n; j++) {
            cin >> arr[j];
            s.insert(arr[j]);       //一个集合防止重复
        }

        int ans = INT_MAX;
        // 枚举多次
        for(auto &x : s) {
            int count = 0;
            for(int j = 0; j < n; j++) {
                if(arr[j] == x){
                    continue;
                }
                count++;
                j += k - 1;
            }
            ans = min(ans, count);
        }

        cout << ans << endl; 
    }
}