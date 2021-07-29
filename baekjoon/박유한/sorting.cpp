#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
#include "../../data-structure/cTimer.h"

using namespace std;

//set�� �̿��� ���� ���
void solve_by_set(int n)
{
    //�ð� ���⵵ : O(n log n)
    //���� ���⵵ : O(n)
    //1 1 2 3 4 (1/2/3/4)
    //����Ž��Ʈ�� (red-black tree�� �̿��� ���� ����̴�)
    set<int> s;

    for (int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        s.insert(temp);
    }

    for (auto iter : s)
        cout << iter << "\n";
}

//multiset�� �̿��� ���� ���
void solve_by_multiset(int n)
{
    //multiset�� ���� �ߺ��� ����Ѵ�.
    //�׷��� 1,5,3,1,4,3 ���� ���� ���� ������ �־ ������ �����ϴ�.
    multiset<int> s;

    for (int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        s.insert(temp);
    }

    for (auto iter : s)
        cout << iter << "\n";
}

//priority queue (�켱���� ť)�� �̿��� ���� ���
void solve_by_priority_queue(int n)
{
    //�Ʒ� ����Ʈ���� priority_queue�� ���� ������ �ľ��Ҽ� �ִ�.
    //C++������ priority_queue�� ���ο� vector�� ������ �ֱ� ������
    //�̸� �Ҵ��ص� vector�� �����, ������ vector�� Ȯ��Ǵ°��� ���´�.
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    //�⺻������ priority_queue�� ū ������ ��ȯ�ϱ� ������
    //�������� ���� ��ȯ�ؾ��ϴ� ������ ��Ȳ������
    //�⺻���� ����Ǿ��ִ� less<int>��� greater<int>�� ����Ѵ�.
    priority_queue<int, vector<int>, greater<int>> q(greater<int>(), v);

    while (!q.empty())
    {
        cout << q.top() << "\n";
        q.pop();
    }
}

//counting sort (ī���� ��Ʈ)�� �̿��� ���� ���
void solve_by_counting_sort(int n)
{
    //�ٸ� ���Ĺ����� �޸� �ణ ��Ư�ϴ�.
    //���� �� �ִ� ������ ũ�Ⱑ ũ�� �ʰų�, ������ ������ �������� ���
    //��� ���� ������ ���� ������, ���� ���ں��� ����ϴ� ����̴�.

    //��Ȳ�� ���� �޸𸮿� �ӵ��� ��� ������ �ִ� ���� ����̱⵵ �ϴ�.
    //��� string�� ���� �ڷ����̳� float����, �������� �ε����� ǥ���Ҽ� ���� ��쿡��
    //counting_sort�� ����� �� ����.

    //�̿� ����� ���̵��� ������� �ڷᱸ���� hash_table�̶� �����غ� ���� �ִ�.
    constexpr int count_n = 10000;
    vector<int> count(count_n + 1);

    for (int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        ++count[temp];
    }

    for (int i = 1; i <= count_n; ++i)
    {
        //count[i]�� ����� ������ŭ i�� ���
        for (int j = 0; j < count[i]; ++j)
            cout << i << "\n";
    }
}

//bubble sort(��������)�� �����ϱ�
void solve_by_bubble_sort(int n)
{
    //�ð����⵵ : O(n ^ 2)
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    for (int i = n - 1; i > 0; --i)
    {
        //���������� ���� ū ���ڰ� �ڷ� ���� �����ϴ� ����̴�.
        //��ġ ���ӿ� �ִ� ������ ���� ���������� ū ���ڰ� ���� �ö�´� �ؼ� ���� �̸��̴�.

        //�ڵ� ������ ���� �����ϰ� �������̶� ���� ���������� �� ������ ���� ����
        for (int j = 0; j < i; ++j)
        {
            if (v[j] > v[j + 1])
                swap(v[j], v[j + 1]);
        }

        for (auto iter : v)
            cout << iter << " ";
        cout << "\n";
    }

}

//selection sort(��������)�� �����ϱ�
void solve_by_selection_sort(int n)
{
    //�ð����⵵ : O(n ^ 2)
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    for (int i = 0; i < n - 1; ++i)
    {
        //���������� �տ��� ���� �������
        //�̹� ���ĵ� ���ڸ� ������ �� �߿���
        //���� ���� ���ڰ� ���� �ε����� ���� �ϴ� ���� ����̴�.
        int min_val = v[i];
        int min_idx = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (min_val > v[j])
            {
                min_val = v[j];
                min_idx = j;
            }
        }
        swap(v[i], v[min_idx]);

        for (auto iter : v)
            cout << iter << " ";
        cout << "\n";
    }

}

//insertion sort(��������)�� �����ϱ�
void solve_by_insertion_sort(int n)
{
    //���ĵ� ���¿����� �ð����⵵ : O(n)
    //���� ���ĵ� ���¿����� ������ ������.
    //�ð����⵵ : O(n ^ 2)
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    for (int i = 0; i < n; ++i)
    {
        //���� ������ ���� ���� �����Ͱ� �տ� ���� ����� ���� ����̴�.
        //���ĵ��� ���� �ε����� �������� �ڷ� �˻��ذ��鼭, ���κ��� ���� �����Ͱ� ������ ������ �ű��.
        int target = v[i];
        int j = i - 1; //j�� �ۿ� �ִ� ������ v[i]�� �� ��ġ�� �����صα� ����

        //v[i]�� ������ ��ġ�� ã�´�
        for (; j >= 0 && v[j] > target; --j)
            v[j + 1] = v[j];

        v[j + 1] = target;

        for (auto iter : v)
            cout << iter << " ";
        cout << "\n";
    }
}

void quick_sort(vector<int>& v, int s, int e)
{
    if (s + 6 > e)
        return;

    int target = v[s];
    int l = s + 1;
    int r = e;

    do
    {
        //l�� target���� ū �������� �ݺ�
        while (l <= r && v[l] < target)
            ++l;
        //r�� target���� ���� �������� �ݺ�
        while (r >= l && v[r] > target)
            --r;
        //l < r�� �ƴ� ��Ȳ�̸�, �ݺ����� Ż���� ���� �Ǿ��� ������ Ż�� ���Ѿ� ��
        if(l < r)
            swap(v[l], v[r]);
    } while (l < r);

    swap(v[s], v[r]);
    quick_sort(v, s, r - 1);
    quick_sort(v, r + 1, e);
}

void solve_by_quick_sort(int n)
{
    //�ð����⵵ O(n^2)
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    quick_sort(v, 0, n - 1);

    for (auto iter : v)
        cout << iter << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    solve_by_counting_sort(n);
}

//bubble_sort
// O(n ^ 2)
// 1024 + 1023 + 1022 + 1021 ---
// 524800

//merge_sort
//O(n log n)
//8 6 3 4 5 7 9 1
//(((8 6)(3 4))((5 7)(9 1)))
//1024���� �����͸� 10�� �˻� = 10240
//(6 8 3 4)((5 7) (1 9))
//(3 4 6 8)(1 5 7 9)
//(1 3 4 5 6 7 8 9)

//quick_sort
//O(n ^ 2) : �־��� ��Ȳ
//O(n log n) : ������� ��Ȳ
//8 6 3 4 5 7 9 1
//(3 1) 4 (8 6 5 7 9)
//1 3 4 ((6 5) 7 (8 9)
//1 3 4 5 6 7 8 9

//8 4a 5 4b 3
//3 4b 4a 5 8

//heap_sort
//O(n log n)
//8 6 3 4 5 7 9 1
//       8
//     6   7
//   4  5 3  1

//[ 6 8 4 5 3 7 ]
// 9

//[2 2 2 1 2 0 1]
//5 2 3 1 4 2 3 5 1 7

//1 1 2 2 3 3 4 5 5 7