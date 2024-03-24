#include <iostream>
#include <vector>

#define ull unsigned long long

using namespace std;

int zeroCount = 0;
ull Factorial_Zigun(int n1) {
    if (n1 <= 1)
        return 1;

    int factorial = 24;
    for (int i = 4; i < n1; i++) {
        factorial *= i + 1;

        while (factorial % 10 == 0) {
            zeroCount++;
            factorial /= 10;
        }

        factorial %= 1000;
    }

    return factorial;
}

int 팩토리얼0의갯수() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

    int n;

    cin >> n;

    Factorial_Zigun(n);
    cout << zeroCount;

	return 0;
}