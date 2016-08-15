
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n % 2 == 0)
    {
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < n; i++)
    {
        if(i) cout << ' ';
        cout << i;
    }
    cout << endl;
    for(int i = 0; i < n; i++)
    {
        if(i) cout << ' ';
        cout << i;
    }
    cout << endl;
    for(int i = 0; i < n; i++)
    {
        if(i) cout << ' ';
        cout << (i + i) % n;
    }
    cout << endl;
    return 0;
}
