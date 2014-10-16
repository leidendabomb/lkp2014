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
#include <string>

using namespace std;

// Why have a double array of characters when you can have a double array of strings?
string board[20];
bool whiteJoker[20];
bool blackJoker[20];

int main()
{
	int numEntries = 0;
	cin >> numEntries;
	cin.ignore();
	
	while (numEntries--)
	{
		int n,m;
		cin >> n >> m;
		cin.ignore();
		for (int y = 0; y < n; y++) {
			cin >> board[y];
		}

		memset(blackJoker, false, sizeof(blackJoker));
		memset(whiteJoker, false, sizeof(whiteJoker));

		int numMoves = 0;
		// Determine number of moves
		int doubleJokers = 0;
		int whiteJokers = 0;
		int blackJokers = 0;
		for (int x = 0; x < m; x++) {
			int blackPos = -1;
			int whitePos = n;
			for (int y = 0; y < n; y++) {
				if (board[y][x] == 'B') blackPos = y;
				if (board[y][x] == 'W') whitePos = y;
			}
			if (blackPos == 0 && whitePos == n - 1 && n > 3) {
				doubleJokers++;
			} else {
				if (blackPos == 0 && whitePos > 2) {
					blackJokers += whitePos - blackPos - 2;
				}
				if (whitePos == n - 1 && blackPos < n - 3) {
					whiteJokers += whitePos - blackPos - 2;
				}
				numMoves += whitePos - blackPos - 1;
			}
		}

		bool winner = (n == 4 && doubleJokers % 2 == 1) ||
		                    whiteJokers > blackJokers ||
		                    (whiteJokers >= blackJokers - 1 && numMoves % 2 == 1);
		if (winner) {
			cout << "White wins" << endl;
		} else {
			cout << "Black wins" << endl;
		}
	}
	return 0;
}
