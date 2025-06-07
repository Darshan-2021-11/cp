#include <bits/stdc++.h>
using namespace std;

std::random_device rd;
std::mt19937 g(rd());

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'001;
	int64_t TC = 1, n, a[N << 1], sum;
	cin >> TC;
	while (TC--) {
		sum = 0;
		cin >> n;
		for (int i = 0; i < n << 1; ++i) cin >> a[i];
		sort(a, a + (n << 1));
		for (int i = (n << 1) - 1; i >= n - 1; --i) sum += a[i];
		for (int i = n - 2; i >= 0; --i) sum -= a[i];
		cout << a[(n << 1) - 1] << ' ' << sum << ' ' << a[(n - 1) << 1];
		for (int i = 0; i < n - 1; ++i) {
			cout << ' ' << a[i] << ' ' << a[n - 1 + i];
		}
		cout << '\n';
	}
}
