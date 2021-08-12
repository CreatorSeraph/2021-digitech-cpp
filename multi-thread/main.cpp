#include <thread>
#include <iostream>
#include <mutex>

using namespace std;

//지금 할일
//운영체제는 놀고있는 코어를 찾아서 필요한 일을 시킨다

//필요한 프로세스를 불렀더니
//나 1초동안 자는 상태임 ㅃㅃ

int temp = 0;
bool func1_end = false;
bool func2_end = false;

mutex m;

void func_test()
{
    lock_guard<mutex> lock(m);
    int t = temp;
    t += 5;
    t /= 3;
    if (t == 0)
    {
        return;
    }
}

void func1()
{
    func1_end = false;
    for (int i = 0; i < 10000; ++i)
    {
        lock_guard<mutex> lock(m);
        int t = temp;
        t += 2;
        temp = t;
    }

    func1_end = true;
}

void func2()
{
    //3 * 10000;
    func2_end = false;
    for (int i = 0; i < 10000; ++i)
    {
        lock_guard<mutex> lock(m);
        int t = temp;
        t += 3;
        temp = t;
    }

    func2_end = true;
}

string make_strange_char(int c)
{
    //switch문을 쓰면?
    switch (c)
    {
    case 0:
        return "hi";
    case 1:
        return "my";
    case 2:
        return "name";
    case 3:
        return "is";
    }
    //이렇게 바꿔준다
    return "hi\0\0\0my\0\0\0name\0is\0\0\0" + c * 5;
}

string make_str()
{
    return "make_str_func";
}

int main()
{
    cout << make_str() << endl;

    thread t1(func1);
    thread t2(func2);
    
    //필요한 프로세스를 불렀더니
    //나 1초동안 자는 상태임 ㅃㅃ
    //Sleep(1000);
    
    while (!func1_end || !func2_end);
    
    //2 * 10000 + 3 * 10000 = 50000
    cout << temp << endl;
    
    t1.detach();
    t2.detach();

    return 0;
}