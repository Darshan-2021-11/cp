#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int solve()
{
	int m, n;
	string s, t;
	cin >> n >> m;
	cin >> s >> t;

	bool isSok = true, isTok = true;
	if(n != 1) {
		for(int i = 0; i < n - 1; ++i) {
			if(s[i] == s[i + 1]) {
				isSok = false;
				break;
			}
		}
	}
	if(isSok) {
		cout << "YES\n";
		return 0;
	}

	if(m != 1) {
		if(!(m & 1)) {
			isTok = false;
		}
		else {
			for(int i = 0; i < m - 1; ++i) {
				if(t[i] == t[i + 1]) {
					isTok = false;
					break;
				}
			}
		}
	}

	if(!isTok) {
		cout << "NO\n";
		return 0;
	}

	bool tmpIsSok = true;
	for(int i = 0; i < n - 1; ++i)
	{
		if(s[i] == s[i + 1]) {
			if(s[i] != t[0])
				continue;
			else {
				tmpIsSok = false;
			}
		}
	}

	if(tmpIsSok) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
	return 0;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
