/*#include <iostream>
#include <cmath>

using namespace std;
int main() {
    int k, n;
    cin >> k >> n;

    auto* arr = new long long[k];
    long long max = 0;
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
        if (arr[i] > max)
            max = arr[i];
    }


    long long left = 0;
    long long right = max;
    long long val = round((left + right) / 2.0l);
    long long maxVal = 0;
    long long sum = 0;
    while (val != 0) {
        for (int i = 0; i < k; i++) {
            sum += arr[i] / val;
        }
        
        if (sum >= n) {
            left = val;

            if (val > maxVal) {
                maxVal = val;

                sum = 0;
                for (int i = 0; i < k; i++) {
                    sum += arr[i] / (maxVal + 1);
                }

                if (sum < n)
                    break;
            }
            
            val = round((val + right) / 2.0l);
            
            sum = 0;
            continue;
        }
        
        if (sum < n) {
            right = val;
            val = round((left + val) / 2.0l);
        }
        else {
            left = val;
            val = round((val + right) / 2.0l);
        }
        sum = 0;
    }

    cout << maxVal;

    return 0;
}*/