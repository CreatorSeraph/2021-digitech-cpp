#include <iostream>
#include <vector>
#include <numeric>
#include <iostream>
#include <string>
#include <chrono>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <list>

using namespace std;

#define async_with_stdio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
constexpr auto nl = '\n';
constexpr auto sp = ' ';
constexpr auto tab = '\t';

// 체스판의 크기
const int LINE = 8;
const int CROSS = LINE * 2 - 1;

//Q = 퀸
bool columns[LINE]; // 직선상 존재하는 Q의 위치정보를 담는 배열
bool c_rt[CROSS]; // 오른쪽 상단을 향하는 대각선상 Q의 위치정보를 담는 배열
bool c_lt[CROSS]; // 왼쪽 상단을 향하는 대각선상 Q의 위치정보를 담는 배열
int pos[LINE]; // 열에대한 Q의 위치정보를 담는 배열

void Print()
{
	for (int j = 0; j < LINE; j++) // 행 (가로줄)
	{
		for (int i = 0; i < LINE; i++) // 열 (세로줄)
		{
			if (pos[i] == j)
				cout << "■";
			else
				cout << "□";
		}
		cout << "\n";
	}
	cout << "\n" << "\n";
}

void Set(int i) // i는 열(세로줄)
{
	for (int j = 0; j < LINE; j++) // j는 행(가로줄)
	{
		// columns는 직선상에 다른 Q를 확인
		// c_rt는 오른쪽 상단을 향하는 대각선상에 다른 Q확인
		// c_lt는 왼쪽 상단을 향하는 대각선상에 다른 Q확인
		// true : 있음, false : 없음
		if (!columns[j] && !c_rt[i + j] && !c_lt[i - j + (LINE - 1)])
		{
			// 전부 없다면 pos[i]에 Q의 위치 정보를 담음
			pos[i] = j;
			if (i == (LINE - 1)) // i가 최대값일 경우 Print를 호출하고 return
			{
				Print(); return;
			}
			else // i가 최대값이 아닐 경우 지금 Q의 정보를 저장하고 다음 열(i + 1)에 대한 Q의 정보를 찾기위해 Set(i + 1) 호출
			{
				columns[j] = c_rt[i + j] = c_lt[i - j + (LINE - 1)] = true;
				Set(i + 1);
				// Set함수가 return되었다면 다시 차례대로 반환하면서 i열에 대한 Q의 위치정보 초기화
				columns[j] = c_rt[i + j] = c_lt[i - j + (LINE - 1)] = false;
			}
		}
	}
}

int main()
{
	Set(0);

	return 0;
}