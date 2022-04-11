#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <stack>

using namespace std;

#define async_with_stdio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
constexpr auto nl = '\n';
constexpr auto sp = ' ';
constexpr auto tab = '\t';

//5y3y8ny-4ny1y7y4nny2y-5nny6

inline int INF = 1000000;

int main()
{
	async_with_stdio;

	int V;
	cout << "������ ����" << nl;
	cin >> V;

	char cmd;
	int dis;

	vector<vector<int>> w(V, vector<int>(V, INF));

	vector<vector<int>> pi(V, vector<int>(V, 0));

	for (size_t origin = 0; origin < V; origin++)
	{
		for (size_t other = 0; other < V; other++)
		{
			// ���� ��ġ�� �ƴҶ�
			if (origin != other)
			{
				if (w[other][origin] != INF) continue;
				cout << origin + 1 << " ---> " << other + 1 << "�� ���ϴ� ���� �ֽ��ϱ�? ( y / n )" << nl;
				cin >> cmd;

				switch (cmd)
				{
				case 'y':
				case 'Y':

					cout << origin + 1 << "�� " << other + 1 << "������ �Ÿ��� �󸶳� �˴ϱ�?" << nl;
					cin >> dis;
					w[origin][other] = dis;
					pi[origin][other] = origin + 1;

					break;
				}
			}
			else
			{
				// ��ġ�� ���⿡ 0�� ����
				w[origin][other] = 0;
			}
		}
	}

	cout << nl << nl;

	for (size_t i = 0; i < V; i++)
	{
		for (size_t j = 0; j < V; j++)
		{
			cout.width(3);
			cout.fill(' ');
			if (w[i][j] == INF) cout << "INF ";
			else cout << w[i][j] << " ";
		}
		cout << nl;
	}

	cout << nl << nl;

	for (size_t i = 0; i < V; i++)
	{
		for (size_t j = 0; j < V; j++)
		{
			cout.width(3);
			cout.fill(' ');
			cout << pi[i][j] << " ";
		}
		cout << nl;
	}

	vector<vector<int>> d(w);

	for (size_t k = 0; k < V; k++)
	{
		for (size_t i = 0; i < V; i++)
		{
			for (size_t j = 0; j < V; j++)
			{
				if (d[i][j] > d[i][k] + d[k][j])
				{
					d[i][j] = d[i][k] + d[k][j];
					pi[i][j] = pi[k][j];
				}
			}
		}
	}

	cout << nl << nl;

	for (size_t i = 0; i < V; i++)
	{
		for (size_t j = 0; j < V; j++)
		{
			cout.width(3);
			cout.fill(' ');
			if (d[i][j] == INF) cout << "INF ";
			else cout << d[i][j] << " ";
		}
		cout << nl;
	}

	cout << nl << nl;

	for (size_t i = 0; i < V; i++)
	{
		for (size_t j = 0; j < V; j++)
		{
			cout.width(3);
			cout.fill(' ');
			cout << pi[i][j] << " ";
		}
		cout << nl;
	}

	cout << nl;
	while (true)
	{
		cout << "������� �������� �Է��ϼ��� ( �Ѵ� 0 �Է½� ���� )" << nl;
		int origin, to;
		cin >> origin >> to;
		if (origin == to && origin == 0) break;
		origin--;
		to--;

		stack<int> path;
		path.push(to);
		while (pi[origin][to] != (origin + 1))
		{
			to = pi[origin][to] - 1;
			path.push(to);
		}
		path.push(origin);

		cout << path.top() + 1;
		path.pop();

		while (!path.empty())
		{
			cout << " -> " << path.top() + 1;
			path.pop();
		}
		cout << nl;
	}

	return 0;
}