#include <bits/stdc++.h>
using namespace std;

int S(int x){
    if(x==0) return 1;
    if(x%2==0){
        return S(x/2);
    }else{
        return S(x-1)+1;
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int x;
    cin >> x;

    cout << S(x);

    return 0;
}