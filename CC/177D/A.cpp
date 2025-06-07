#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int x, y, z;
	cin >> x >> y >> z;
	cout << (x + y > z && y + z > x && x + z > y ? "YES" : "NO");
}
