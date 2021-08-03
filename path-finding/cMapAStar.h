#pragma once
#include <vector>

using std::vector;

//CELL�� ���̴� 0~10���� ����
struct cCellAStar
{
    bool is_wall;
    int height;

    cCellAStar()
        :is_wall(false), height(5)
    {
    }
};

class cMapAStar
{
public:
    static constexpr int CELL_SIZE = 50;

    HBRUSH wall_brush;
    vector<HBRUSH> height_brushes;

    vector<vector<cCellAStar>> cell_table;
public:
    cMapAStar();
    ~cMapAStar();

    void Init();
    void Release();
    //���콺 �Է��� �޾Ƽ� ���̸� ���̰ų�, ���� �����.
    void Update();
    void Render(HDC hdc);
};

