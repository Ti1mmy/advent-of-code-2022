#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string stringn;
    int N;
    int currentSum = 0;
    vector<int> v;
    while (getline(cin, stringn)) {
        if (stringn == "") {
            v.emplace_back(currentSum);
            currentSum = 0;
        } else {
            istringstream(stringn) >> N;
            currentSum += N;
        }
    }
    sort(v.begin(), v.end());
    int topThree = 0;
    for (int i = 0; i < 3; ++i) {
        topThree += v.back();
        v.pop_back();
    }
    cout << topThree << endl;
    return 0;
}
