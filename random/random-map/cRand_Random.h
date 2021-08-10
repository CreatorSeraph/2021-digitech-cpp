#pragma once
#include <cstdlib>

class cRand_Random
{
public:
    cRand_Random(unsigned int _seed = 1)
    {
        srand(_seed);
    }

    //rand�Լ��� 0 ~ RAND_MAX������ ��ȯ�Ѵ�.
    int rand()
    {
        return std::rand();
    }

    //0�̻� 1�̸��� �Ǽ� ���� ��ȯ�ϰ� ���� �Լ�
    float float_rand()
    {
        return (float)rand() / RAND_MAX;
    }

    //min_val~max_val������ ���� ��ȯ�ϰ� ���� �Լ�
    int ranged_rand(int min_val, int max_val)
    {
        //3~8�� ��ȯ�ؾ� �ϸ� 0~5�� ��ȯ�ϴ� �Լ��� 3�� ���ϸ� �ȴ�
        //�ٵ� float_rand()�� 5�� ���ϸ� 0~4.9999999...(�Ҽ��� ©��)�� ���ͼ�
        //0~4�� ������ �ǹǷ� float_rand() * max_val - min_val + 1�� ����� �Ѵ�.
        return min_val + float_rand() * (max_val - min_val + 1);
    }
};

