#include <iostream>
#include <string>
#define var auto;

using namespace std;
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int sum = 0;
	for (int i = 666; ; i++) {
		if (std::to_string(i).find("666") != std::string::npos) {
			sum++;
			if (sum == n) {
				cout << i;
				break;
			}
		}
	}
	
	return 0;
}
