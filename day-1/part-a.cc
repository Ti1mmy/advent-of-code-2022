#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    string stringn;
    int N;
    int maxSum = 0;
    int currentSum = 0;
    while (getline(cin, stringn)) {
        if (stringn == "") {
            if (currentSum > maxSum) maxSum = currentSum;
            currentSum = 0;
        } else {
            istringstream(stringn) >> N;
            currentSum += N;
        }
    }
    cout << maxSum << endl;
    return 0;
}
