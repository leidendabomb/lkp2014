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

const unsigned int SIEVE_MAX = 100000;
bool sieve[SIEVE_MAX];
set<unsigned int> primes;

void factorize(unsigned int num, map<unsigned int, unsigned int>& factorization) {
	factorization.clear();

	for (unsigned int prime : primes) {
		while (num % prime == 0) {
			factorization[prime]++;
			num /= prime;
		}
	}
	if (num != 1) {
		factorization[num] = 1;
	}

}

int main()
{

	memset(sieve, true, SIEVE_MAX);

	sieve[0] = false;
	sieve[1] = false;

	for (unsigned int i = 2; i < (unsigned int) ceil(sqrt(SIEVE_MAX)); i++) {
		if (!sieve[i]) {
			continue;
		}
		for (unsigned int j = i * i; j < SIEVE_MAX; j += i) {
			sieve[j] = false;
		}
	}

	for (unsigned int i = 0; i < SIEVE_MAX; i++) {
		if (sieve[i]) {
			primes.insert(i);
		}
	}

	int numEntries = 0;
	cin >> numEntries;
	cin.ignore();

	map<unsigned int, unsigned int> dieFactorization; // prime to occurrences
	map<unsigned int, unsigned int> iceFactorization;
	while (numEntries--)
	{
		unsigned int n, k;
		cin >> n >> k;

		factorize(n, iceFactorization);
		factorize(k, dieFactorization);
		unsigned int minThrows = 0;
		bool possible = true;
		for (auto prime : iceFactorization) {
			if (prime.second > 0 && dieFactorization[prime.first] == 0) {
				possible = false;
				break;
			} else {
				unsigned int needed = prime.second / dieFactorization[prime.first];
				if (prime.second % dieFactorization[prime.first]) {
					needed++;
				}
				minThrows = max(needed, minThrows);
			}
		}

		if (!possible) {
			cout << "unbounded" << endl;
		} else {
			cout << minThrows << endl;
		}
	}
	return 0;
}
