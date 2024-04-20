#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll rangeAnd(ll x, ll y) {
	if (y < x) {
		return -1;
	}
	for (int i = 0; i < (int)log2(y) + 1; i++) {
		if (y <= x) {
			return y;
		}
		if (y & (1LL << i)) {
			y &= ~(1LL << i);
		}
	}
	return y;
}

void test_case(int& tc) {
	ll n, x;
	cin >> n >> x;
	ll low = n, high = (1LL << 61);
	ll ans = (1LL << 61);
	while (low <= high) {
		ll mid = low + (high - low) / 2;
		ll res = rangeAnd(n, mid);
		if (res <= x) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
		if (res == x) {
			ans = min(ans, mid);
		}
	}
	cout << (ans != (1LL << 61) ? ans : -1) << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T = 1;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		test_case(tc);
	}
}
