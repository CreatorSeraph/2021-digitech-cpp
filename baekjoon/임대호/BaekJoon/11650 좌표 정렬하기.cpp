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
//void _Merge(int start, int mid, int end);
//void _MergeSorting(int start, int end);
//
//vector<Vector2> v;
//vector<Vector2> _vec;
//
//int 좌표정렬하기()
//{
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	ios::sync_with_stdio(false);
//
//	int n, x, y;
//	Vector2 vec2;
//	cin >> n;
//
//	v.resize(n);
//	_vec.resize(n);
//
//	for (int i = 0; i < n; i++)
//	{
//		cin >> x >> y;
//
//		vec2.x = x;
//		vec2.y = y;
//
//		v[i] = vec2;
//	}
//
//	_MergeSorting(0, n - 1);
//
//	for (int i = 0; i < n; i++)
//	{
//		cout << v[i].x << ' ' << v[i].y << '\n';
//	}
//
//	return 0;
//}
//
//void _Merge(int start, int mid, int end)
//{
//	int left = start;
//	int right = mid + 1;
//	int index = start;
//
//	while (left <= mid && right <= end)
//	{
//		if (v[left].x < v[right].x)
//		{
//			_vec[index] = v[left++];
//		}
//		else
//		{
//			if (v[left].x == v[right].x)
//			{
//				if (v[left].y < v[right].y) _vec[index] = v[left++];
//				else _vec[index] = v[right++];
//			}
//			else
//			{
//				_vec[index] = v[right++];
//			}
//		}
//
//		index++;
//	}
//
//	if (right > end)
//		while (left <= mid)
//			_vec[index++] = v[left++];
//
//	else if (left > mid)
//		while (right <= end)
//			_vec[index++] = v[right++];
//
//	for (int i = start; i <= end; i++)
//		v[i] = _vec[i];
//}
//
//void _MergeSorting(int start, int end)
//{
//	if (start >= end) return;
//
//	int mid = (end + start) / 2;
//
//	_MergeSorting(start, mid);
//	_MergeSorting(mid + 1, end);
//	_Merge(start, mid, end);
//}