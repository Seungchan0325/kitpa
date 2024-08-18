#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
    cin >> n;
    int lsum, rsum;
    lsum = rsum = 0;
    vector<int> l, r;

    for(int i = n; i >= 1; i--) {
        if(lsum >= rsum) {
            r.push_back(i);
            rsum += i;
        } else {
            l.push_back(i);
            lsum += i;
        }
    }

    for(auto i : l) cout << i << " ";
    reverse(r.begin(), r.end());
    for(auto i : r) cout << i << " ";
}