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

static struct person
{
	int velocity;
	bool toRight;
	bool annoyed;
} grid[3001][3001];

int main()
{
	int numEntries = 0;
	cin >> numEntries;
	cin.ignore();
	
	while (numEntries--)
	{
		memset(grid, 0, sizeof(grid));

		int width, height, numPeople;
		cin >> width >> height >> numPeople;

		for (int i = 0; i < numPeople; ++i)
		{
			int x, y, s;
			char dir;
			cin >> x >> y >> s;
			cin.ignore();
			cin >> dir;
			grid[x-1][y-1].velocity = s;
			grid[x-1][y-1].toRight = (dir == 'R');
		}

		uint64_t ticks = 0;
		bool didAnythingAtAllWhatsoever = true;
		while (didAnythingAtAllWhatsoever)
		{
			didAnythingAtAllWhatsoever = false;

			// First step, people moving to the right
			for (int x = width - 1; x >= 0; x--)
				for (int y = 0; y < height; y++)
				{
					if (!grid[x][y].velocity || !grid[x][y].toRight)
						continue;
					didAnythingAtAllWhatsoever = true;

					int targetx;
					for (targetx = x; targetx < x+grid[x][y].velocity && targetx < width; targetx++)
						if (grid[targetx+1][y].velocity)
							break;

					if (targetx >= width)
					{
						grid[x][y].velocity = 0;
					}
					else
					{
						grid[targetx][y] = grid[x][y];
						grid[x][y].velocity = 0;

						if (targetx-x < (grid[targetx][y].velocity+1)/2)
							grid[targetx][y].annoyed = true;
					}
				}

			// Second step, people moving to the left
			for (int x = 0; x < width; x++)
				for (int y = 0; y < height; y++)
				{
					if (!grid[x][y].velocity || grid[x][y].toRight)
						continue;
					didAnythingAtAllWhatsoever = true;

					int targetx;
					for (targetx = x; targetx > x-grid[x][y].velocity && targetx > 0; targetx--)
						if (grid[targetx-1][y].velocity)
							break;

					if (targetx < 0)
					{
						grid[x][y].velocity = 0;
					}
					else
					{
						grid[targetx][y] = grid[x][y];
						grid[x][y].velocity = 0;

						if (x-targetx < (grid[targetx][y].velocity+1)/2)
							grid[targetx][y].annoyed = true;
					}
				}

			// Third step, annoyed right-moving people try to go up
			for (int x = width - 1; x >= 0; x--)
				for (int y = 1; y < height; y++)
				{
					if(!grid[x][y].velocity || !grid[x][y].annoyed || !grid[x][y].toRight)
						continue;

					if (!grid[x][y-1].velocity)
					{
						grid[x][y-1] = grid[x][y];
						grid[x][y-1].annoyed = (grid[x][y].velocity = 0);
					}
				}

			// Fourth step, annoyed, left-moving people try to go down
			for (int x = 0; x < width; x++)
				for (int y = height - 2; y >= 0; y--)
				{
					if(!grid[x][y].velocity || !grid[x][y].annoyed || grid[x][y].toRight)
						continue;

					if (!grid[x][y+1].velocity)
					{
						grid[x][y+1] = grid[x][y];
						grid[x][y+1].annoyed = (grid[x][y].velocity = 0);
					}
				}

			// Fifth step, annoyed, right-moving people try to go down
			for (int x = width - 1; x >= 0; x--)
				for (int y = 0; y < height - 1; y++)
				{
					if(!grid[x][y].velocity || !grid[x][y].annoyed || !grid[x][y].toRight)
						continue;

					if (!grid[x][y+1].velocity)
					{
						grid[x][y+1] = grid[x][y];
						grid[x][y+1].annoyed = (grid[x][y].velocity = 0);
					}
				}

			// Sixth step, annoyed, left-moving people try to go up
			for (int x = 0; x < width; x++)
				for (int y = height - 1; y >= 1; y--)
				{
					if(!grid[x][y].velocity || !grid[x][y].annoyed || grid[x][y].toRight)
						continue;

					if (!grid[x][y-1].velocity)
					{
						grid[x][y-1] = grid[x][y];
						grid[x][y-1].annoyed = (grid[x][y].velocity = 0);
					}
				}

			ticks++;
		}

		cout << ticks << endl;
	}
	return 0;
}
