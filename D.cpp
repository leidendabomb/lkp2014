// LESSONS LEARNED:
// - Off-by-one errors are off-by-one
//
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
static unsigned int angerBelow[1501];
static unsigned int angerAbove[1501];

int main()
{
	int numEntries = 0;
	cin >> numEntries;
	cin.ignore();
	
	while (numEntries--)
	{
		memset(anger, 0, sizeof(anger));
		memset(angerBelow, 0, sizeof(angerBelow));

		unsigned int numStudents = 0;
		int floors;

		cin >> floors;
		for (int i = 1; i <= floors; i++)
		{
			cin >> students[i];
			numStudents += students[i];
		}

		angerAbove[0] = numStudents;
		angerBelow[floors] = students[floors]*floors;

		for (int i = floors-1; i >= 0; i--)
			angerBelow[i] = angerBelow[i+1] + students[i]*i;

		for (int i = 1; i <= floors; i++)
		{
			anger[i] = 0xFFFFFFFF;
			angerAbove[i] = angerAbove[i-1] - students[i];

			unsigned int angerBellow = 0;
			for (int j = i-1; j >= 0; j--)
			{
				unsigned int ang = anger[j] + angerAbove[i] + angerBellow;
				/*ang += i*(angerAbove[j]-angerAbove[i]);
				ang -= angerBelow[j]-angerBelow[i];*/
				angerBellow += (i-j)*students[j];

				if (ang < anger[i])
				{
					anger[i] = ang;
				}
			}
		}

		cout << anger[floors] << endl;
	}
	return 0;
}
