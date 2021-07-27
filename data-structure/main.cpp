#include <iostream>
#include <algorithm>
#include "cTimer.h"

using namespace std;

constexpr int loop_count = 10;
constexpr int insert_count = 100000;

#include <vector>
#include "cMyVector.h"
void vector_test()
{
    cTimer<double> timer;
    cMyVector<double> my_time_data(loop_count);
    double my_total_data = 0;

    for (int i = 0; i < loop_count; ++i)
    {
        timer.Play();
        cMyVector<int> cMyVec;
        for (int j = 0; j < insert_count; ++j)
            cMyVec.insert(0,j);

        my_time_data[i] = timer.Pause();
        my_total_data += my_time_data[i];
    }

    sort(my_time_data.begin(), my_time_data.end());
    cout << "���� ���� ������ " << insert_count << "�� �߰��� �ɸ��� �ð�" << endl;
    cout << "��� �ҿ� �ð� : " << my_total_data / loop_count << "��\t";
    cout << "�ּ� �ҿ� �ð� : " << my_time_data[0] << "��\t";
    cout << "�ִ� �ҿ� �ð� : " << my_time_data[loop_count - 1] << "��" << endl;

    vector<double> stl_time_data(loop_count);
    double stl_total_data = 0;

    for (int i = 0; i < loop_count; ++i)
    {
        timer.Play();
        vector<int> cStlVec;
        for (int j = 0; j < insert_count; ++j)
            cStlVec.insert(cStlVec.begin(), j);

        stl_time_data[i] = timer.Pause();
        stl_total_data += stl_time_data[i];
    }

    sort(stl_time_data.begin(), stl_time_data.end());
    cout << "STL ������ " << insert_count << "�� �߰��� �ɸ��� �ð�" << endl;
    cout << "��� �ҿ� �ð� : " << stl_total_data / loop_count << "��\t";
    cout << "�ּ� �ҿ� �ð� : " << stl_time_data[0] << "��\t";
    cout << "�ִ� �ҿ� �ð� : " << stl_time_data[loop_count - 1] << "��" << endl;
}

#include <list>
#include "cMyList.h"
void list_test()
{
    cTimer<double> timer;
    cMyVector<double> my_time_data(loop_count);
    double my_total_data = 0;

    for (int i = 0; i < loop_count; ++i)
    {
        timer.Play();
        cMyList<int> cMyList;
        for (int j = 0; j < insert_count; ++j)
            cMyList.push_front(j);

        my_time_data[i] = timer.Pause();
        my_total_data += my_time_data[i];
    }

    sort(my_time_data.begin(), my_time_data.end());
    cout << "���� ���� ����Ʈ�� " << insert_count << "�� �߰��� �ɸ��� �ð�" << endl;
    cout << "��� �ҿ� �ð� : " << my_total_data / loop_count << "��\t";
    cout << "�ּ� �ҿ� �ð� : " << my_time_data[0] << "��\t";
    cout << "�ִ� �ҿ� �ð� : " << my_time_data[loop_count - 1] << "��" << endl;

    vector<double> stl_time_data(loop_count);
    double stl_total_data = 0;

    for (int i = 0; i < loop_count; ++i)
    {
        timer.Play();
        list<int> cStlList;
        for (int j = 0; j < insert_count; ++j)
            cStlList.push_front(j);

        stl_time_data[i] = timer.Pause();
        stl_total_data += stl_time_data[i];
    }

    sort(stl_time_data.begin(), stl_time_data.end());
    cout << "STL ����Ʈ�� " << insert_count << "�� �߰��� �ɸ��� �ð�" << endl;
    cout << "��� �ҿ� �ð� : " << stl_total_data / loop_count << "��\t";
    cout << "�ּ� �ҿ� �ð� : " << stl_time_data[0] << "��\t";
    cout << "�ִ� �ҿ� �ð� : " << stl_time_data[loop_count - 1] << "��" << endl;
}

#include <set>
#include <unordered_set>
#include <algorithm>

//AVL Tree(���س� ������ ������ ������ �ƽ��� �ڷᱸ��)
//red-black Tree

//�ڰ����� ����Ʈ����
//1234
//1
//  2
//      3
//          4

//AVL Tree (Ž���ӵ��� Ȯ���ѵ�... �ְ��� �ӵ��� �� ���� �ƽ���)
// �ӵ��� �ƽ����� �Ⱦ�
// 1 2 3 4 5 6 7 8 9 10
//
//         4
//     2        8
//  1    3    6    9
//          5   7      10
//
//
// ���� ���� ������ ���� ���� ������ 2�̻� ���̳��� ���ϰ�

//red-black
// �� �� �� �� �� �� �� �� (8)
// �� �� �� �� (4)
// �� �� �� �� �� �� (6)
//
// ���� ���� ������ ���� ���� ������ 2���̻� ���̳��� ���ϰ�
// ���? ������ 2�������� �������� �����

void compare_data_structure()
{
    set<int> s;
}

int main()
{
    unordered_set<int> data;
    int arr[997] = {0};

    for (auto iter : { 312332, 7777, 79374, 14141, 818 })
    {
        arr[iter % 997] = iter;
    }

    cout << arr[773 % 997] << endl;

    return 0;
}