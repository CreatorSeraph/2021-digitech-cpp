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

    //rand함수는 0 ~ RAND_MAX까지만 반환한다.
    int rand()
    {
        seed = seed * 1103515245 + 12345;
        return seed % MY_RAND_MAX;
    }

    //0이상 1미만의 실수 값을 반환하게 만든 함수
    float float_rand()
    {
        return (float)rand() / MY_RAND_MAX;
    }

    //min_val~max_val사이의 값을 반환하게 만든 함수
    int ranged_rand(int min_val, int max_val)
    {
        //3~8을 반환해야 하면 0~5를 반환하는 함수에 3을 더하면 된다
        //근데 float_rand()에 5를 곱하면 0~4.9999999...(소숫점 짤림)이 나와서
        //0~4가 나오게 되므로 float_rand() * max_val - min_val + 1을 해줘야 한다.
        return min_val + float_rand() * (max_val - min_val + 1);
    }
};

