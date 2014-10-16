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

static unsigned int anger[1501];
static unsigned int students[1501];

int main()
{
	int numEntries = 0;
	cin >> numEntries;
	cin.ignore();
	
	while (numEntries--)
	{
		memset(anger, 0, sizeof(anger));

		int floors;
		unsigned int angBelowSum = 0;
		unsigned int angAboveSum = 0;

		cin >> floors;
		for (int i = 0; i < floors; i++)
		{
			cin >> students[i];
			angAboveSum += students[i];
		}

		for (int i = 1; i <= floors; i++)
		{
			anger[i] = 0xFFFFFFFF;
			angBelowSum += anger[i-1];
			angAboveSum -= anger[i];

			for (int j = 0; j < i; j++)
			{
				unsigned int ang = anger[j] + angBelowSum + angAboveSum;

				if (ang < anger[i])
					anger[i] = ang;
			}
		}

		cout << anger[floors] << endl;
	}
	return 0;
}
