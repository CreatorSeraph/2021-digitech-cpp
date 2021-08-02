#include "pch.h"
#include "cMapDijk.h"
#include "cKeyManager.h"
#include <string>

using std::wstring;

cMapDijk::cMapDijk()
    : cell_table(WINSIZEY / CELL_SIZE, vector<cCellDijk>(WINSIZEX / CELL_SIZE))
    , wall_brush(nullptr)
    , select_brush(nullptr)
    , target_brush(nullptr)
    , find_start(empty_pos)
    , find_end(empty_pos)
    , is_find_start(false)
    , remain_loop_count(0)
{
}

cMapDijk::~cMapDijk()
{
}

void cMapDijk::Init()
{
    //�� ������ ������
    wall_brush = CreateSolidBrush(RGB(0, 0, 0));
    select_brush = CreateSolidBrush(RGB(255, 0, 255));
    target_brush = CreateSolidBrush(RGB(0, 0, 255));
    now_dijk_brush = CreateSolidBrush(RGB(255, 255, 255));
    height_brushes.resize(6);
    visited_height_brushes.resize(6);
    //i�� ������ �ʷϻ�, ������ ��Ȳ���� ��� ������ �����.
    for (int i = 0; i < 6; ++i)
    {
        height_brushes[i] = CreateSolidBrush(RGB(50 * i, 0x99, 0));
        visited_height_brushes[i] = CreateSolidBrush(RGB(127 + 25 * i, 204, 0x7f));
    }
}

void cMapDijk::Release()
{
    DeleteObject(wall_brush);
    for (auto iter : height_brushes)
        DeleteObject(iter);
}

void cMapDijk::Update()
{
    if (is_find_start)
        Update_Find();
    else
        Update_Input();
}

void cMapDijk::Update_Find()
{
    while (remain_loop_count != 0)
    {
        --remain_loop_count;
        
        if (dijk_open.empty())
            break;

        //������� �鷯�����߿�, ���� �ڽ�Ʈ�� ���Ҵ� ���� ã�ƺ���.
        auto [min_distance, pos] = dijk_open.top();
        dijk_open.pop();

        if (cell_table[pos.first][pos.second].is_visit)
        {
            ++remain_loop_count;
            continue;
        }
        
        //���ͽ�Ʈ�� �˰��򿡼� �ѹ� �鸥���� ������ �ִܰ�θ� ã�� ��Ȳ�̴�.
        //�̷þ��� ����ص���.
        cell_table[pos.first][pos.second].is_visit = true;
        
        int now_height = cell_table[pos.first][pos.second].height;

        //�����¿�� �� �� �ִ� ���� ��� üũ�غ���.
        AddOpenList(pos, min_distance, now_height, pos.first - 1, pos.second);
        AddOpenList(pos, min_distance, now_height, pos.first + 1, pos.second);
        AddOpenList(pos, min_distance, now_height, pos.first, pos.second - 1);
        AddOpenList(pos, min_distance, now_height, pos.first, pos.second + 1);
    }

    if (KEYMANAGER.IsOnceKeyDown('1'))
        remain_loop_count = 1;
    if (KEYMANAGER.IsOnceKeyDown(VK_RETURN))
    {
        if (dijk_open.empty())
            is_find_start = false;
        else
            remain_loop_count = -1;
    }
}

void cMapDijk::AddOpenList(position_type now_pos, int now_distance, int now_height, int y, int x)
{
    //��ȿ���� ���� y, x�������� ��� �ٷ� return
    if (IsVaildCursorIdx(std::make_pair(y, x)) == false)
        return;
    //���̸� �翬�� �ѱ��
    if (cell_table[y][x].is_wall)
        return;
    //�̹� üũ�� ���� ��ġ�� �װ͵� �ѱ��
    if (cell_table[y][x].is_visit)
        return;

    int next_distance = now_distance + abs(cell_table[y][x].height - now_height) + 1;
    if (next_distance < cell_table[y][x].min_distance)
    {
        //�� ª�� ��θ� �߰��������� �������ش�.
        cell_table[y][x].min_distance = next_distance;
        cell_table[y][x].last_cell = now_pos;
        dijk_open.push(dijk_queue(next_distance, std::make_pair(y, x)));
    }
}

void cMapDijk::Update_Input()
{
    if (KEYMANAGER.IsOnceKeyDown(VK_LBUTTON))
    {
        position_type mouse_idx = GetCursorIdx();

        if (IsVaildCursorIdx(mouse_idx))
            cell_table[mouse_idx.first][mouse_idx.second].is_wall = !cell_table[mouse_idx.first][mouse_idx.second].is_wall;
    }

    if (KEYMANAGER.IsOnceKeyDown(VK_RBUTTON))
    {
        position_type mouse_idx = GetCursorIdx();

        if (IsVaildCursorIdx(mouse_idx))
        {
            if (++cell_table[mouse_idx.first][mouse_idx.second].height == 6)
                cell_table[mouse_idx.first][mouse_idx.second].height = 0;
        }
    }

    if (KEYMANAGER.IsOnceKeyDown(VK_SPACE))
    {
        position_type mouse_idx = GetCursorIdx();

        if (IsVaildCursorIdx(mouse_idx))
        {
            if (cell_table[mouse_idx.first][mouse_idx.second].is_wall);
            else if (find_start == mouse_idx)
                find_start = empty_pos;
            else if (find_end == mouse_idx)
                find_end = empty_pos;
            else if (find_start == empty_pos)
                find_start = mouse_idx;
            else
                find_end = mouse_idx;
        }
    }

    if (KEYMANAGER.IsOnceKeyDown(VK_RETURN))
    {
        if (find_start != empty_pos && find_end != empty_pos)
        {
            //Ž�� ������ ����
            for (auto& iter : cell_table)
                for (auto& iter2 : iter)
                    iter2.Reset_Dijk_Value();

            //Ž�� ����
            is_find_start = true;
            cell_table[find_start.first][find_start.second].min_distance = 0;
            dijk_open.push(dijk_queue(0, find_start));
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
            if (std::make_pair(i, j) == find_start)
                SelectObject(hdc, select_brush);
            else if(std::make_pair(i, j) == find_end)
                SelectObject(hdc, target_brush);
            else if (target_cell.is_wall)
                SelectObject(hdc, wall_brush);
            else if(is_find_start && !dijk_open.empty() && std::make_pair(i, j) == dijk_open.top().target)
                SelectObject(hdc, now_dijk_brush);
            else if(is_find_start && target_cell.is_visit)
                SelectObject(hdc, visited_height_brushes[target_cell.height]);
            else
                SelectObject(hdc, height_brushes[target_cell.height]);

            Rectangle(hdc, j * CELL_SIZE, i * CELL_SIZE, (j + 1) * CELL_SIZE, (i + 1) * CELL_SIZE);
            if(is_find_start && target_cell.min_distance != 0x7fffffff)
                TextOut(hdc, j * CELL_SIZE, i * CELL_SIZE, std::to_wstring(target_cell.min_distance).c_str(), std::to_wstring(target_cell.min_distance).size());
        }
    }
}

position_type cMapDijk::GetCursorIdx()
{
    POINT mouse_pos;
    GetCursorPos(&mouse_pos);
    ScreenToClient(hWnd, &mouse_pos);

    int y_idx = mouse_pos.y / CELL_SIZE;
    int x_idx = mouse_pos.x / CELL_SIZE;

    return std::make_pair(y_idx, x_idx);
}

bool cMapDijk::IsVaildCursorIdx(const position_type& pt)
{
    if (pt.first < 0 || pt.second < 0)
        return false;
    if (pt.first < cell_table.size() && pt.second < cell_table[0].size())
        return true;
    return false;
}