#pragma once
#include <vector>

using std::vector;

//CELL�� ���̴� 0~10���� ����
struct cCell
{
    bool is_wall;
    int height;

    cCell()
        :is_wall(false), height(5)
    {
    }
};

class cMap
{
public:
    static constexpr int CELL_SIZE = 50;

    HBRUSH wall_brush;
    vector<HBRUSH> height_brushes;

    vector<vector<cCell>> cell_table;
public:
    cMap();
    ~cMap();

    void Init();
    void Release();
    //���콺 �Է��� �޾Ƽ� ���̸� ���̰ų�, ���� �����.
    void Update();
    void Render(HDC hdc);
};

