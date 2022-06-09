// 역겨운 문제 자식..

//#include <iostream>
//using namespace std;
//int main()
//{
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	ios::sync_with_stdio(false);
//
//	int n, x, y, count, cur_x;
//	cin >> n;
//
//	for (int i = 0; i < n; i++)
//	{
//		count = 0;
//
//		cin >> x >> y;
//		cur_x = x;
//
//		count++;
//		cur_x++;
//
//		while (true)
//		{
//			if (cur_x + 1 == y)
//			{
//				cur_x++;
//				count++;
//				break;
//			}
//			else if (cur_x + (count + 1) > y - 1)
//			{
//				cur_x = y - 1;
//				count++;
//			}
//			else
//			{
//				cur_x += count + 1;
//				count++;
//			}
//		}
//
//		cout << count << '\n';
//	}
//
//	return 0;
//}