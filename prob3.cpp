#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MAXN = 200005;

ll N, M, K, X, Y;
ll ssum;
ll A[MAXN], B[MAXN];
bool isin[MAXN];

ll calc(ll lo, ll hi, ll inrange)
{
    ll ret = 0;
    ret += (hi - lo + 1) * K;
    ret += Y * (ssum - inrange) + X * inrange;
    return ret;
}

ll solve(ll l, ll r)
{
    if(l == r) return calc(l, l, B[A[l]]);

    ll mid = (l + r) >> 1;
    ll ret = min(solve(l, mid), solve(mid+1, r));

    // memset(isin, 0, sizeof(isin));

    ll cand = 0;

    cand += B[A[mid]];
    isin[A[mid]] = true;
    if(A[mid] != A[mid+1]) {
        cand += B[A[mid+1]];
        isin[A[mid+1]] = true;
    }

    ret = min(calc(mid, mid+1, cand), ret);

    ll lo = mid, hi = mid+1;
    while(l < lo || hi < r) {
        if(hi == r || (l < lo && (isin[A[hi+1]] || (B[A[lo-1]] > B[hi+1])))) {
            lo--;
            if(!isin[A[lo]]) cand += B[A[lo]];
            isin[A[lo]] = true;
        } else {
            hi++;
            if(!isin[A[hi]]) cand += B[A[hi]];
            isin[A[hi]] = true;
        }
        ret = min(calc(lo, hi, cand), ret);
    }

    for(int i = l; i <= r; i++) {
        isin[A[i]] = false;
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M >> K >> X >> Y;
    for(ll i = 1; i <= M; i++) {
        cin >> A[i];
    }
    for(ll i = 1; i <= N; i++) {
        cin >> B[i];
        ssum += B[i];
    }

    ll result = min(solve(1, M), Y * ssum);
    cout << result;
}