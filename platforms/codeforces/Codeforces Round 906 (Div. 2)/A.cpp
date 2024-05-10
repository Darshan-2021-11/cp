#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int solve()
{
	int n, tmp;
	cin >> n;

	map<int, int> count;

	for(int i = 0; i < n; ++i)
	{
		cin >> tmp;
		++count[tmp];
	}

	if(count.size() == 1) {
		cout << "YES\n";
	}
	else if(count.size() == 2) {
		auto it = count.begin();
		int count1, count2;
		count1 = it->second;
		++it;
		count2 = it->second;

		if(count1 == count2)
			cout << "YES\n";
		else if((count1 == count2 + 1) || (count2 == count1 + 1))
			cout << "YES\n";
		else
			cout << "NO\n";
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
