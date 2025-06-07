#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int n;
	cin >> n;
	int na = 0;
	/*
	char a[12];
	while (n >= 1000) {
		n -= 1000;
		a[na++] = 'M';
	}
	if (n >= 900) {
		n -= 900;
		a[na++] = 'C';
		a[na++] = 'M';
	} else if (n >= 500) {
		n -= 500;
		a[na++] = 'D';
	} else if (n >= 400) {
		n -= 400;
		a[na++] = 'C';
		a[na++] = 'D';
	}
	while (n >= 100) {
		n -= 100;
		a[na++] = 'C';
	}

	if (n >= 90) {
		n -= 90;
		a[na++] = 'X';
		a[na++] = 'C';
	} else if (n >= 50) {
		n -= 50;
		a[na++] = 'L';
	} else if (n >= 40) {
		n -= 40;
		a[na++] = 'X';
		a[na++] = 'L';
	}
	while (n >= 10) {
		n -= 10;
		a[na++] = 'X';
	}

	if (n >= 9) {
		n -= 9;
		a[na++] = 'I';
		a[na++] = 'X';
	} else if (n >= 5) {
		n -= 5;
		a[na++] = 'V';
	} else if (n >= 4) {
		n -= 4;
		a[na++] = 'I';
		a[na++] = 'V';
	}
	while (n) {
		n -= 1;
		a[na++] = 'I';
	}
	*/
	string a;
	while (n >= 1000) {
		n -= 1000;
		a += 'M';
	}
	if (n >= 900) {
		n -= 900;
		a += 'C';
		a += 'M';
	} else if (n >= 500) {
		n -= 500;
		a += 'D';
	} else if (n >= 400) {
		n -= 400;
		a += 'C';
		a += 'D';
	}
	while (n >= 100) {
		n -= 100;
		a += 'C';
	}

	if (n >= 90) {
		n -= 90;
		a += 'X';
		a += 'C';
	} else if (n >= 50) {
		n -= 50;
		a += 'L';
	} else if (n >= 40) {
		n -= 40;
		a += 'X';
		a += 'L';
	}
	while (n >= 10) {
		n -= 10;
		a += 'X';
	}

	if (n >= 9) {
		n -= 9;
		a += 'I';
		a += 'X';
	} else if (n >= 5) {
		n -= 5;
		a += 'V';
	} else if (n >= 4) {
		n -= 4;
		a += 'I';
		a += 'V';
	}
	while (n) {
		n -= 1;
		a += 'I';
	}

	for (int i = 0; i < na; ++i) cout << a[i];
}
