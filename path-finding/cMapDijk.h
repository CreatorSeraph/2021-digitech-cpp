#pragma once
#include <vector>

using std::vector;

//CELL�� ���̴� 0~10���� ����
struct cCellDijk
{
    bool is_wall;
    int height;

    cCellDijk()
        :is_wall(false), height(5)
    {
    }
};

class cMapDijk
{
public:
    static constexpr int CELL_SIZE = 50;

    HBRUSH wall_brush;
    vector<HBRUSH> height_brushes;

    vector<vector<cCellDijk>> cell_table;
public:
    cMapDijk();
    ~cMapDijk();

    void Init();
    void Release();
    //���콺 �Է��� �޾Ƽ� ���̸� ���̰ų�, ���� �����.
    void Update();
    void Render(HDC hdc);
};

