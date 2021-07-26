#include <iostream>
#include <algorithm>
#include "cTimer.h"
#include "cMyVector.h"
#include <vector>

using namespace std;

constexpr int loop_count = 10;
constexpr int insert_count = 10000000;

int main()
{
    cTimer<double> timer;
    cMyVector<double> my_time_data(loop_count);
    double my_total_data = 0;

    for (int i = 0; i < loop_count; ++i)
    {
        timer.Play();
        cMyVector<int> cMyVec;
        for (int j = 0; j < insert_count; ++j)
            cMyVec.push_back(j);

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
            cStlVec.push_back(j);
    
        stl_time_data[i] = timer.Pause();
        stl_total_data += stl_time_data[i];
    }

    sort(stl_time_data.begin(), stl_time_data.end());
    cout << "STL ������ " << insert_count << "�� �߰��� �ɸ��� �ð�" << endl;
    cout << "��� �ҿ� �ð� : " << stl_total_data / loop_count << "��\t";
    cout << "�ּ� �ҿ� �ð� : " << stl_time_data[0] << "��\t";
    cout << "�ִ� �ҿ� �ð� : " << stl_time_data[loop_count - 1] << "��" << endl;


    return 0;
}