#pragma once

class cLCG_Random
{
private:
    unsigned int seed;
    static constexpr int MY_RAND_MAX = 0x7fff;
public:
    cLCG_Random(unsigned int _seed = 1)
        :seed(_seed)
    {
    }

    void srand(unsigned int _seed)
    {
        seed = _seed;
    }

    //rand�Լ��� 0 ~ RAND_MAX������ ��ȯ�Ѵ�.
    int rand()
    {
        seed = seed * 1103515245 + 12345;
        return seed % MY_RAND_MAX;
    }

    //0�̻� 1�̸��� �Ǽ� ���� ��ȯ�ϰ� ���� �Լ�
    float float_rand()
    {
        return (float)rand() / MY_RAND_MAX;
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

