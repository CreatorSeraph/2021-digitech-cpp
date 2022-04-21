#include <iostream>
#include <list>

using namespace std;

class Queue
{
public:
	void Push(int n)
	{
		data.push_back(n);
	}

	void Pop()
	{
		if (data.size() == 0) { cout << -1 << '\n'; return; }

		cout << data.front() << '\n';
		data.pop_front();
	}

	void Size()
	{
		cout << data.size() << '\n';
	}

	void Empty()
	{
		cout << (data.empty() ? 1 : 0) << '\n';
	}

	void Front()
	{
		if (data.size() == 0) { cout << -1 << '\n'; return; }
		cout << data.front() << '\n';
	}

	void Back()
	{
		if (data.size() == 0) { cout << -1 << '\n'; return; }
		cout << data.back() << '\n';
	}

private:
	list<int> data;

};

int ť2()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, v;
	cin >> n;

	string s;

	Queue q;

	for (int i = 0; i < n; i++)
	{
		cin >> s;

		if (s == "push")
		{
			cin >> v;
			q.Push(v);
		}
		else if (s == "pop")
		{
			q.Pop();
		}
		else if (s == "size")
		{
			q.Size();
		}
		else if (s == "empty")
		{
			q.Empty();
		}
		else if (s == "front")
		{
			q.Front();
		}
		else
		{
			q.Back();
		}
	}

	return 0;
}