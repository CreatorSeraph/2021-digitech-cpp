//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//struct Vector2
//{
//public:
//	int x;
//	int y;
//};
//
//void __Merge(int start, int mid, int end);
//void __MergeSorting(int start, int end);
//
//vector<Vector2> _v;
//vector<Vector2> __vec;
//
//int 좌표정렬하기2()
//{
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	ios::sync_with_stdio(false);
//
//	int n, x, y;
//	Vector2 vec2;
//	cin >> n;
//
//	_v.resize(n);
//	__vec.resize(n);
//
//	for (int i = 0; i < n; i++)
//	{
//		cin >> x >> y;
//
//		vec2.x = x;
//		vec2.y = y;
//
//		_v[i] = vec2;
//	}
//
//	__MergeSorting(0, n - 1);
//
//	for (int i = 0; i < n; i++)
//	{
//		cout << _v[i].x << ' ' << _v[i].y << '\n';
//	}
//
//	return 0;
//}
//
//void __Merge(int start, int mid, int end)
//{
//	int left = start;
//	int right = mid + 1;
//	int index = start;
//
//	while (left <= mid && right <= end)
//	{
//		if (_v[left].y < _v[right].y)
//		{
//			__vec[index] = _v[left++];
//		}
//		else
//		{
//			if (_v[left].y == _v[right].y)
//			{
//				if (_v[left].x < _v[right].x) __vec[index] = _v[left++];
//				else __vec[index] = _v[right++];
//			}
//			else
//			{
//				__vec[index] = _v[right++];
//			}
//		}
//
//		index++;
//	}
//
//	if (right > end)
//		while (left <= mid)
//			__vec[index++] = _v[left++];
//
//	else if (left > mid)
//		while (right <= end)
//			__vec[index++] = _v[right++];
//
//	for (int i = start; i <= end; i++)
//		_v[i] = __vec[i];
//}
//
//void __MergeSorting(int start, int end)
//{
//	if (start >= end) return;
//
//	int mid = (end + start) / 2;
//
//	__MergeSorting(start, mid);
//	__MergeSorting(mid + 1, end);
//	__Merge(start, mid, end);
//}