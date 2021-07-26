#pragma once
#include <chrono>

template<typename T>
class cTimer
{
private:
    bool is_start;
    std::chrono::system_clock::time_point start_point;
    T total_time;

public:
    cTimer(bool _start = false)
        :is_start(_start), total_time()
    {
        if (is_start)
            start_point = std::chrono::system_clock::now();
    }

    /**
    * @brief    �����ð��� 0���� �ʱ�ȭ �ϸ鼭 ����
    * @return   �̹� �������� Ÿ�̸��ϰ�� false, ���� ���࿡ ���������� true
    */
    bool Play()
    {
        if (is_start)
            return false;
        is_start = true;
        total_time = 0;
        start_point = std::chrono::system_clock::now();
        return true;
    }

    /**
    * @brief    �����ð��� �ʱ�ȭ���� �ʰ� ����
    * @return   �̹� �������� Ÿ�̸��ϰ�� false, ���� ���࿡ ���������� true
    */
    bool Resume()
    {
        if (is_start)
            return false;
        is_start = true;
        start_point = std::chrono::system_clock::now();
        return true;
    }

    /**
    * @brief    Ÿ�̸Ӹ� �Ͻ����� ��Ŵ
    * @return   Ÿ�̸��� ���� �ð�
    */
    T Pause()
    {
        if (is_start)
        {
            std::chrono::duration<T> result = std::chrono::system_clock::now() - start_point;
            total_time = result.count();
            is_start = false;
        }
        return total_time;
    }

    operator T()
    {
        std::chrono::duration<T> result = std::chrono::system_clock::now() - start_point;
        return result.count() + total_time;
    }
};

