#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Write C++ code here
    int n;
    string str;
    cout << "Enter the length of the string";
    cin >> n;
    cout << "Enter the string";
    cin >> str;
    map<int, int> mp; // normal maps
    // unordered_map<int, int> mp; // unordered maps
    for (int i = 0; i < n; i++)
    {
        mp[str[i] - 'a'] += 1;
    }

    int q;
    cout << "Enter the query length";
    cin >> q;
    int hashArr[q];
    for (int j = 0; j < q; j++)
    {
        char ch;
        cin >> ch;
        hashArr[j] = mp[ch - 'a'];
    }

    for (int k = 0; k < q; k++)
    {
        cout << hashArr[k] << "\n";
    }
    return 0;
}