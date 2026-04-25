#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Write C++ code here
    int n;
    string str;
    cout << "Enter the length of the array";
    cin >> n;
    int arr[n];
    cout << "Enter the elements";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]] += 1;
    }
    for (auto x : mp)
    {
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}