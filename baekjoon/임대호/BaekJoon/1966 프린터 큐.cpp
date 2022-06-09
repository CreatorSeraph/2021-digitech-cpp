//#include <iostream>
//#include <queue>
//using namespace std;
//int main()
//{
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	ios::sync_with_stdio(false);
//
//	int n, size, i, temp, result = 0, count = 1;
//	cin >> n;
//
//	for (int j = 0; j < n; j++)
//	{
//		cin >> size >> i;
//
//		priority_queue<int, vector<int>, less<int>> pq;
//		count = 1;
//
//		for (int k = 0; k < size; k++)
//		{
//			cin >> temp;
//			pq.push(temp);
//
//			if (k == i) result = temp;
//		}
//
//		while (!pq.empty())
//		{
//			temp = pq.top();
//			pq.pop();
//
//			if (result == temp) 
//			{
//				cout << count << '\n';
//				break;
//			}
//
//			count++;
//		}
//	}
//
//
//	return 0;
//}