//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//vector<string> v;
//vector<string> _v;
//vector<string> __v;
//vector<string> ___v;
//
//void Mer_____ge(int start, int mid, int end);
//void Merge_____Sort(int start, int end);
//
//int 도비의난독증테스트()
//{
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	ios::sync_with_stdio(false);
//
//	int n;
//	string s;
//
//	while (true)
//	{
//		cin >> n;
//		if (n == 0) break;
//
//		v.resize(n);
//		_v.resize(n);
//		__v.resize(n);
//		___v.resize(n);
//
//		for (int i = 0; i < n; i++)
//		{
//			cin >> v[i];
//			__v[i] = v[i];
//
//			for (int j = 0; j < v[i].size(); j++)
//			{
//				if ((v[i][j]) > 96)
//				{
//					v[i][j] = v[i][j] - 32;
//				}
//			}
//
//		}
//		Merge_____Sort(0, n - 1);
//
//		cout << __v[0] << '\n';
//	}
//
//	return 0;
//}
//
//void Mer_____ge(int start, int mid, int end)
//{
//	int index = start;
//	int left = start;
//	int right = mid + 1;
//
//	while (left <= mid && right <= end)
//	{
//		if (v[left] < v[right])
//		{
//			_v[index] = v[left];
//			___v[index] = __v[left++];
//		}
//		else
//		{
//			_v[index] = v[right];
//			___v[index] = __v[right++];
//		}
//
//		index++;
//	}
//
//	if (left > mid)
//		while (right <= end)
//		{
//			_v[index] = v[right];
//			___v[index++] = __v[right++];
//		}
//
//	else if (right > end)
//		while (left <= mid)
//		{
//			_v[index] = v[left];
//			___v[index++] = __v[left++];
//		}
//
//	for (int i = start; i <= end; i++)
//	{
//		v[i] = _v[i];
//		__v[i] = ___v[i];
//	}
//}
//
//void Merge_____Sort(int start, int end)
//{
//	if (start >= end)return;
//
//	int mid = (start + end) / 2;
//
//	Merge_____Sort(start, mid);
//	Merge_____Sort(mid + 1, end);
//	Mer_____ge(start, mid, end);
//}