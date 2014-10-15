#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <map>
#include <list>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
	int numEntries = 0;
	cin >> numEntries;
	cin.ignore();
	
	while (numEntries--)
	{
		int n, k;
		cin >> n >> k;
		uint64_t boe = k;
		if (n == 1)
		{
			cout << 0 << endl;
			n = -1;
		}

		for (int t = 1; t < 35; ++t, boe = (boe * k) % n)
			if (boe%n == 0)
			{
				cout << t << endl;
				n = -1;
				break;
			}

		if (n >= 0)
			cout << "unbounded" << endl;
	}
	return 0;
}
