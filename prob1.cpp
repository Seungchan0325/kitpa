#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

int N, M, T;
bool is_in[MAXN];
vector<int> fre[MAXN];
vector<tuple<int, int, int>> enter;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M >> T;
    enter.resize(N);
    int _i = 0;
    for(auto& [a, b, i] : enter) {
        cin >> a >> b; i = ++_i;
    }
    for(int i = 0; i < M; i++) {
        int c, d;
        cin >> c >> d;
        fre[c].push_back(d);
        fre[d].push_back(c);
    }

    sort(enter.begin(), enter.end());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    int idx = 0;
    int pairs = 0;
    for(int t = 0; t < T; t++) {
        while(!pq.empty() && pq.top().first <= t) {
            auto [a, b] = pq.top(); pq.pop();
            is_in[b] = false;
            for(auto other : fre[b]) {
                if(is_in[other]) pairs--;
            }
        }
        while(idx < N && get<0>(enter[idx]) <= t) {
            auto [a, b, i] = enter[idx];
            pq.emplace(b, i);
            for(auto other : fre[i]) {
                if(is_in[other]) pairs++;
            }
            is_in[i] = true;
            idx++;
        }
        cout << pairs << "\n";
    }
}