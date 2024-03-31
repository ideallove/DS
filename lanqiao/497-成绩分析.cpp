#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 +10;
int a[N];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    cout << *max_element(a + 1, a + 1 + n) << '\n';
    cout << *min_element(a + 1, a + 1 + n) << '\n';
    long long sum = 0;
    for(int i = 1; i<=n; i++){
        sum += a[i];
    }

    cout << fixed << setprecision(2) << 1.0 * sum / n << '\n';

    return 0;
}
