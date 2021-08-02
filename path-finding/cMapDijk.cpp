#include "pch.h"
#include "cMapDijk.h"
#include "cKeyManager.h"

cMapDijk::cMapDijk()
    :cell_table(WINSIZEY / CELL_SIZE, vector<cCellDijk>(WINSIZEX / CELL_SIZE)), wall_brush(nullptr)
{
}

cMapDijk::~cMapDijk()
{
}

void cMapDijk::Init()
{
    //�� ������ ������
    wall_brush = CreateSolidBrush(RGB(0, 0, 0));
    height_brushes.resize(11);
    //i�� ������ �ʷϻ�, ������ ��Ȳ���� ��� ������ �����.
    for (int i = 0; i < 11; ++i)
        height_brushes[i] = CreateSolidBrush(RGB(25 * i, 0x99, 0));
}

void cMapDijk::Release()
{
    DeleteObject(wall_brush);
    for (auto iter : height_brushes)
        DeleteObject(iter);
}

void cMapDijk::Update()
{
    if (KEYMANAGER.IsOnceKeyDown(VK_LBUTTON))
    {
        POINT mouse_pos;
        GetCursorPos(&mouse_pos);
        ScreenToClient(hWnd, &mouse_pos);

        int y_idx = mouse_pos.y / CELL_SIZE;
        int x_idx = mouse_pos.x / CELL_SIZE;

        if(y_idx >= 0 && y_idx < cell_table.size() && x_idx >= 0 && x_idx < cell_table[0].size())
            cell_table[y_idx][x_idx].is_wall = !cell_table[y_idx][x_idx].is_wall;
    }

    if (KEYMANAGER.IsOnceKeyDown(VK_RBUTTON))
    {
        POINT mouse_pos;
        GetCursorPos(&mouse_pos);
        ScreenToClient(hWnd, &mouse_pos);

        int y_idx = mouse_pos.y / CELL_SIZE;
        int x_idx = mouse_pos.x / CELL_SIZE;

        if (y_idx >= 0 && y_idx < cell_table.size() && x_idx >= 0 && x_idx < cell_table[0].size())
        {
            if (++cell_table[y_idx][x_idx].height == 11)
                cell_table[y_idx][x_idx].height = 0;
        }
    }
}

void cMapDijk::Render(HDC hdc)
{
    for (int i = 0; i < cell_table.size(); ++i)
    {
        for (int j = 0; j < cell_table[0].size(); ++j)
        {
            auto& target_cell = cell_table[i][j];
            if (target_cell.is_wall)
                SelectObject(hdc, wall_brush);
            else
                SelectObject(hdc, height_brushes[target_cell.height]);

            Rectangle(hdc, j * CELL_SIZE, i * CELL_SIZE, (j + 1) * CELL_SIZE, (i + 1) * CELL_SIZE);
        }
    }
}