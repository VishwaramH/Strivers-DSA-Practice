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
    int maxFreq = 0, minFreq = n;
    int maxEle = 0, minEle = 0;
    for (auto x : mp)
    {
        cout << x.first << " " << x.second << endl;
        int ele = x.first;
        int count = x.second;
        if (count > maxFreq)
        {
            maxFreq = count;
            maxEle = ele;
        }
        if (count < minFreq)
        {
            minFreq = count;
            minEle = ele;
        }
    }
    cout << "Highest frequency element: " << maxEle << " Frequency: " << maxFreq << endl;
    cout << "Lowest frequency element: " << minEle << " Frequency: " << minFreq << endl;
    return 0;
}