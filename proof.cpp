// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    iota(v.begin(), v.end(), 1);

    int mx = 0;

    do {
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            auto vv = v;
            int j = i;
            int d = 1;
            while(0 <= j && j < n) {
                j += d;
                if(vv[j] > v[i]) {
                    cnt++;
                    d = -d;
                    vv[j]--;
                }
            }
        }
        if(cnt > mx) {
            mx = cnt;
        }
    } while(next_permutation(v.begin(), v.end()));

    do {
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            auto vv = v;
            int j = i;
            int d = 1;
            while(0 <= j && j < n) {
                j += d;
                if(vv[j] > v[i]) {
                    cnt++;
                    d = -d;
                    vv[j]--;
                }
            }
        }
        if(cnt == mx) {
            for(int i = 0; i < n; i++) cout << v[i] << " ";
            cout << "\n";
        }
    } while(next_permutation(v.begin(), v.end()));
    cout << mx;
}