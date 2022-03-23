#include <iostream>
#include <math.h>

using namespace std;

struct Vector2
{
public:
	Vector2() {}
	Vector2(float x, float y)
		:x(x), y(y)
	{
	}

	float x;
	float y;

	Vector2 operator+(Vector2 a)
	{
		Vector2 b = Vector2(x + a.x, y + a.y);
		return b;
	}
	Vector2 operator-(Vector2 a)
	{
		Vector2 b = Vector2(x - a.x, y - a.y);
		return b;
	}

	Vector2 operator*(Vector2 a)
	{
		Vector2 b = Vector2(x * a.x, y * a.y);
		return b;
	}
	Vector2 operator*(float a)
	{
		Vector2 b = Vector2(x * a, y * a);
		return b;
	}
	Vector2 operator/(Vector2 a)
	{
		Vector2 b = Vector2(a.x != 0 ? x / a.x : x, a.y != 0 ? y / a.y : y);
		return b;
	}
	Vector2 operator/(float a)
	{
		Vector2 b = Vector2(a != 0 ? x / a : x, a != 0 ? y / a : y);
		return b;
	}

	bool operator==(Vector2 a)
	{
		bool value = x == a.x && y == a.y;
		return value;
	}
};

Vector2 Normalize(Vector2 a);
float Distance(Vector2 a, Vector2 b);
float DotProduct(Vector2 a, Vector2 b);
bool OBBCheck(Vector2 direction, float rects_distance);

Vector2 rect1[4];
Vector2 rect2[4];

Vector2 Normalize(Vector2 a)
{
	Vector2 Vec2 = a;

	return Vec2 / sqrt(a.x * a.x + a.y * a.y);
}

float Distance(Vector2 a, Vector2 b)
{
	Vector2 c = Vector2(a.x, b.y);

	float x = c.x > b.x ? c.x - b.x : b.x - c.x;
	float y = c.y > a.y ? c.y - a.y : a.y - c.y;

	return sqrt(x * x + y * y);
}

float DotProduct(Vector2 a, Vector2 b)
{
	return abs(a.x * b.x) + abs(a.y * b.y);
}

bool OBBCheck(Vector2 direction, float rects_distance)
{
	float sum = 0;

	Vector2 point = (rect1[1] - rect1[0]);
	Vector2 dir_vec = Normalize(rect1[1] - rect1[0]);
	float distance = Distance(rect1[1], rect1[0]) / 2;
	float value = DotProduct(dir_vec * distance, direction);
	sum += value;

	point = (rect1[2] - rect1[1]);
	dir_vec = Normalize(rect1[2] - rect1[1]);
	distance = Distance(rect1[2], rect1[1]) / 2;
	value = DotProduct(dir_vec * distance, direction);
	sum += value;

	point = (rect2[1] - rect2[0]);
	dir_vec = Normalize(rect2[1] - rect2[0]);
	distance = Distance(rect2[1], rect2[0]) / 2;
	value = DotProduct(dir_vec * distance, direction);
	sum += value;

	point = (rect2[2] - rect2[1]);
	dir_vec = Normalize(rect2[2] - rect2[1]);
	distance = Distance(rect2[2], rect2[1]) / 2;
	value = DotProduct(dir_vec * distance, direction);
	sum += value;

	if (fabsf(sum - rects_distance) <= FLT_EPSILON) return false;
	return sum > rects_distance;
}

int OBB_Object_Bounding_Box()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 4; i++)
	{
		cin >> rect1[i].x;
		cin >> rect1[i].y;
	}

	for (int i = 0; i < 4; i++)
	{
		cin >> rect2[i].x;
		cin >> rect2[i].y;
	}

	if (rect1[0] == rect1[1] || rect1[0] == rect1[2] || rect1[0] == rect1[3] || rect2[0] == rect2[1] || rect2[0] == rect2[2] || rect2[0] == rect2[3])
	{
		cout << 0;
		return 0;
	}

	Vector2 rect1_dir1 = Normalize(rect1[0] - rect1[1]);
	Vector2 rect1_dir2 = Normalize(rect1[1] - rect1[2]);
	Vector2 rect2_dir1 = Normalize(rect2[0] - rect2[1]);
	Vector2 rect2_dir2 = Normalize(rect2[1] - rect2[2]);
	Vector2 directions[4] = { rect1_dir1, rect1_dir2, rect2_dir1, rect2_dir2 };

	float line = Distance(rect1[0], rect1[2]);
	Vector2 dir = Normalize(rect1[2] - rect1[0]);
	Vector2 center1 = rect1[0] + dir * (line / 2);

	line = Distance(rect2[0], rect2[2]);
	dir = Normalize(rect2[2] - rect2[0]);
	Vector2 center2 = rect2[0] + dir * (line / 2);

	float rects_distance = Distance(center1, center2);

	for (int i = 0; i < 4; i++)
	{
		if (OBBCheck(directions[i], rects_distance))
		{
			cout << 1;
			return 0;
		}
	}

	cout << 0;

	return 0;
}