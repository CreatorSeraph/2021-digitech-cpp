//#include <iostream>
//using namespace std;
//int main()
//{
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	ios::sync_with_stdio(false);
//
//	string s;
//	cin >> s;
//
//	int size = s.size();
//	int count = 0;
//	for (int i = 0; i < size; i++)
//	{
//		if (s[i] == 'X')
//			count++;
//		else if (count % 4 != 0 && count % 2 != 0)
//		{
//			cout << -1; return 0;
//		}
//
//		if (count == 4)
//		{
//			for (int j = i + 1 - count; j < i + 1; j++)
//				s[j] = 'A';
//
//			count = 0;
//		}
//		else if (s[i] == '.' && count == 2)
//		{
//			for (int j = i - count; j < i; j++)
//				s[j] = 'B';
//
//			count = 0;
//		}
//	}
//	if (count == 4)
//		for (int i = size - count; i < size; i++)
//			s[i] = 'A';
//	else if (count == 2)
//		for (int i = size - count; i < size; i++)
//			s[i] = 'B';
//	else if (count % 4 != 0 && count % 2 != 0)
//	{
//		cout << -1; return 0;
//	}
//
//	cout << s;
//
//	return 0;
//}