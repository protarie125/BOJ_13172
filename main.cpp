#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;

constexpr auto mod = ll{ 1'000'000'007 };

int m;
vl ns;
vl ss;
int ans;

ll mpow(ll x, ll y) {
	if (0 == y) {
		return 1;
	}

	if (0 == y % 2) {
		const auto& q = mpow(x, y / 2);
		return (q * q) % mod;
	}

	const auto& q = mpow(x, y - 1);
	return (x * q) % mod;
}

ll mdiv(ll a, ll b) {
	const auto& x = mpow(b, mod - 2);

	return (a * x) % mod;
}

void solve() {
	ans = 0;

	for (auto i = 0; i < m; ++i) {
		const auto& n = ns[i];
		const auto& s = ss[i];

		ans += mdiv(s, n);
		ans %= mod;
	}
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> m;
	ns = vl(m);
	ss = vl(m);

	for (auto i = 0; i < m; ++i) {
		cin >> ns[i] >> ss[i];
	}

	solve();

	cout << ans;

	return 0;
}