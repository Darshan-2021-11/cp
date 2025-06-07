#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int n, x;
	cin >> n;
	x = n / 3;
	if (abs(n - x * 3) < abs(n - (x + 1) * 3)) cout << x * 3 << '\n';
	else cout << (x + 1) * 3 << '\n';
}
