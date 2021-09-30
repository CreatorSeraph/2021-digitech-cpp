#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stack>

using namespace std;

int main()
{
	string target;
	string buffer;
	vector<string> splits;

	while (buffer != ".")
	{
		getline(cin, buffer);
		target += buffer;
	}

	istringstream ss(target);
	while (getline(ss, buffer, '.')) splits.push_back(buffer);

	for (auto&& iter : splits)
	{
		if (iter == "") break;

		stack<int> open;

		int count = 0;
		for (int i = 0; i < iter.size(); ++i)
		{
			switch (iter[i])
			{
			case '(':
				open.push(1); ++count;
				break;
			case ')':
				++count;
				if (open.empty()) open.push(10);
				else if (open.top() == 1) open.pop();
				else open.push(10);
				break;
			case '{':
				open.push(2); ++count;
				break;
			case '}':
				++count;
				if (open.empty()) open.push(20);
				else if (open.top() == 2) open.pop();
				else open.push(20);
				break;
			case '[':
				open.push(3); ++count;
				break;
			case ']':
				++count;
				if (open.empty()) open.push(30);
				else if (open.top() == 3) open.pop();
				else open.push(30);
				break;
			}
		}
		if (count == 0) cout << "yes\n";
		else if (!open.empty()) cout << "no\n";
		else cout << "yes\n";
	}

	return 0;
}