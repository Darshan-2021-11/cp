#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1, h, w, l;
	cin >> TC;
	while (TC--) {
		cin >> h >> w >> l;
		cout << 1000 / ((h * w + w * l + l * h) << 1);
	}
}
