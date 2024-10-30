#include <iostream>
#include <string>

using namespace std;

bool all9(string str);

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    string s = to_string(n);

    bool t1 = all9(s);
    if (t1) {
        s = to_string(++n);
    }

    bool same = true;
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - i - 1]) {
            same = false;
            break;
        }
    }

    int center = s[s.size() / 2] - 48;
    if (t1 && same) {
        cout << n;
    } else if (same && s.size() % 2 == 1 && center != 9) {
        s[s.size() / 2] = ++center + 48;
        cout << stoi(s);
    } else {
        string before = s.substr(0, s.size() / 2);
        string after = s.substr(s.size() / 2, s.size() / 2);

        if (stoi(before) <= stoi(after) && s.size() % 2 == 1) {
            before = s.substr(0, s.size() / 2 + 1);
            after = s.substr(s.size() / 2, s.size() / 2 + 1);
        }

        string tempBefore = before;
        string tempAfter = after;

        if (!all9(before)) {
            string realTempBefore = to_string(stoi(before) + 1);
            int i = 0;
            for (; i < realTempBefore.size(); i++) {
                tempBefore[tempBefore.size() - i - 1] = realTempBefore[realTempBefore.size() - i - 1];
            }
            for (; i < tempBefore.size(); i++)
                tempBefore[tempBefore.size() - i - 1] = '0';
        }

        if (!all9(after)) {
            string realTempAfter = to_string(stoi(after) + 1);
            int i = 0;
            for (; i < realTempAfter.size(); i++) {
                tempAfter[tempAfter.size() - i - 1] = realTempAfter[realTempAfter.size() - i - 1];
            }
            for (; i < tempAfter.size(); i++)
                tempAfter[tempAfter.size() - i - 1] = '0';
        }

        string tempStr1 = s;
        string tempStr2 = s;

        for (int i = 0 ; i < tempBefore.size(); i++) {
            tempStr1[i] = tempBefore[i];
            tempStr1[tempStr1.size() - i - 1] = tempBefore[i];
        }
        for (int i = 0; i < tempAfter.size(); i++) {
            tempStr2[i] = tempAfter[tempAfter.size() - i - 1];
            tempStr2[tempStr2.size() - i - 1] = tempAfter[tempAfter.size() - i - 1];
        }

        int tempA = stoi(tempStr1);
        int tempB = stoi(tempStr2);

        if (tempA < tempB || tempB == 0 || tempB < n)
            cout << tempA;
        else
            cout << tempB;
    }

    return 0;
}

bool all9(string str) {
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != '9')
            return false;
    }

    return true;
}