//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//struct Vector2
//{
//public:
//	Vector2(float x, float y) : x(x), y(y) {}
//	Vector2() { x = 0; y = 0; }
//
//	float x = 0;
//	float y = 0;
//	float distance_with_center;
//
//	void operator+=(Vector2 vec)
//	{
//		x += vec.x;
//		y += vec.y;
//	}
//
//	void operator/=(float f)
//	{
//		x /= f;
//		y /= f;
//	}
//};
//
//float Distance(Vector2 a, Vector2 b);
//void Merge(int start, int mid, int end);
//void MergeSort(int start, int end);
//
//vector<Vector2> v;
//vector<Vector2> _v;
//int main()
//{
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	ios::sync_with_stdio(false);
//
//	int n;
//	cin >> n;
//
//	v.resize(n);
//	_v.resize(n);
//
//	Vector2 center = Vector2(0, 0);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> v[i].x;
//		cin >> v[i].y;
//
//		center += v[i];
//	}
//
//	center /= (float)n;
//
//	for (int i = 0; i < n; i++)
//	{
//		v[i].distance_with_center = Distance(v[i], center);
//	}
//
//	MergeSort(0, n - 1);
//
//	return 0;
//}
//
//float Distance(Vector2 a, Vector2 b)
//{
//	float dis_x = fabsf(a.x - b.x);
//	float dis_y = fabsf(a.y - b.y);
//
//	float distance = sqrt(dis_x * dis_x + dis_y * dis_y);
//	return distance;
//}
//
//void Merge(int start, int mid, int end)
//{
//	int index = start;
//	int left = start;
//	int right = mid + 1;
//
//	while (left <= mid && right <= end)
//	{
//		if (v[left].distance_with_center > v[right].distance_with_center)
//			_v[index] = v[left++];
//		else
//			_v[index] = v[right++];
//
//		index++;
//	}
//
//	if (left > mid) while (right <= end)	_v[index++] = v[right++];
//	else while (left <= mid) _v[index++] = v[left++];
//
//	for (int i = start; i <= end; i++)
//		v[i] = _v[i];
//}
//
//void MergeSort(int start, int end)
//{
//	if (start >= end) return;
//
//	int mid = (start + end) / 2;
//
//	MergeSort(start, mid);
//	MergeSort(mid + 1, end);
//	Merge(start, mid, end);
//}