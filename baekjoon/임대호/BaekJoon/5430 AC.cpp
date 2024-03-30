#include <iostream>
#include <list>
#include <sstream>
#include <algorithm>

using namespace std;

list<int> splitString(const std::string& str, char delimiter) {
    list<int> tokens;
    string token;
    istringstream tokenStream(str);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(stoi(token));
    }

    return tokens;
}

struct RemoveIfChar {
    bool operator()(char c) const {
        return c == '[' || c == ']';
    }
};

int AC() {
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, n;
    string str, arr, ret;
    bool reversed = false;

    cin >> t;

    list<int> lst;

    for (int i = 0; i < t; i++) {
        lst.clear();
        reversed = false;

        cin >> str;
        cin >> n;
        cin >> arr;


        if (n > 0) {
            arr.erase(remove_if(arr.begin(), arr.end(), RemoveIfChar()), arr.end());

            lst = splitString(arr, ',');
        }

        for (int j = 0; j < str.size(); j++) {
            if (str[j] == 'R') {
                reversed = !reversed;
            } else if (str[j] == 'D') {
                if (lst.empty()) {
                    cout << "error" << '\n';
                    goto EXIT;
                }
                if (reversed) {
                    lst.pop_back();
                } else {
                    lst.pop_front();
                }
            }
        }

        ret = "[";
        if (reversed) {
            for (auto iter = lst.rbegin(); iter != lst.rend(); ++iter) {
                ret.append(to_string((*iter)));
                if (iter != --lst.rend())
                    ret.append(",");
            }
        } else {
            for (auto iter = lst.begin(); iter != lst.end(); ++iter) {
                ret.append(to_string((*iter)));
                if (iter != --lst.end())
                    ret.append(",");
            }
        }

        ret.append("]");

        cout << ret << '\n';

        EXIT:;
    }


    return 0;
}
