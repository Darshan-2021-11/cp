#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 50;
	int TC = 1, n;
	const char x[2] = { '#', '.' };
	char a[N][N];
	cin >> n;
	for (int i = 0; i <= n >> 1; ++i) {
		for (int j = i; j < n - i; ++j) {
			for (int k = i; k < n - i; ++k) {
				a[j][k] = x[i & 1];
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) cout << a[i][j];
		cout << '\n';
	}
}
