#include <iostream>
#include <cfloat>
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
bool OBBCheck(Vector2 direction, Vector2 center1, Vector2 center2);

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

bool OBBCheck(Vector2 direction, Vector2 center1, Vector2 center2)
{
	float sum = 0;
	Vector2 rects_dir = Normalize(center2 - center1);
	float rects_distance = Distance(center1, center2);
	float r_value = DotProduct(rects_dir * rects_distance, direction);

	Vector2 dir_vec_1 = Normalize(rect1[1] - rect1[0]);
	float distance_1 = Distance(rect1[1], rect1[0]) / 2;
	float value_1 = DotProduct(dir_vec_1 * distance_1, direction);

	Vector2 dir_vec_2 = Normalize(rect1[2] - rect1[1]);
	float distance_2 = Distance(rect1[2], rect1[1]) / 2;
	float value_2 = DotProduct(dir_vec_2 * distance_2, direction);

	Vector2 dir_vec_3 = Normalize(rect2[1] - rect2[0]);
	float distance_3 = Distance(rect2[1], rect2[0]) / 2;
	float value_3 = DotProduct(dir_vec_3 * distance_3, direction);

	Vector2 dir_vec_4 = Normalize(rect2[2] - rect2[1]);
	float distance_4 = Distance(rect2[2], rect2[1]) / 2;
	float value_4 = DotProduct(dir_vec_4 * distance_4, direction);

	sum = value_1 + value_2 + value_3 + value_4;

	float result = fabsf(r_value - sum);
	// if (result < FLT_EPSILON)
	// 	cout << "¤·¤±È£¸Ï¤Å¤½ÃÊ¼¤±¤¤";

	return r_value > sum && result >= FLT_EPSILON;
}

int main()
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

	Vector2 rect1_dir1 = Normalize(rect1[3] - rect1[0]);
	Vector2 rect1_dir2 = Normalize(rect1[0] - rect1[1]);
	Vector2 rect2_dir1 = Normalize(rect2[3] - rect2[0]);
	Vector2 rect2_dir2 = Normalize(rect2[0] - rect2[1]);
	Vector2 directions[4] = { rect1_dir1, rect1_dir2, rect2_dir1, rect2_dir2 };

	float line = Distance(rect1[0], rect1[2]);
	Vector2 dir = Normalize(rect1[2] - rect1[0]);
	Vector2 center1 = rect1[0] + dir * (line / 2);

	line = Distance(rect2[0], rect2[2]);
	dir = Normalize(rect2[2] - rect2[0]);
	Vector2 center2 = rect2[0] + dir * (line / 2);

	for (int i = 0; i < 4; i++)
	{
		if (OBBCheck(directions[i], center1, center2))
		{
			cout << 0;
			return 0;
		}
	}

	cout << 1;

	return 0;
}