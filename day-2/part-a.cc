#include <bits/stdc++.h>
using namespace std;

int main() {
    int currentScore = 0;
    string in = "";
    string response = "";
    while (cin >> in >> response) {
        int shape = response[0] - 'X' + 1; // X gives 1, then Y gives 2, etc.
        currentScore += shape;

        // A B C
        // X Y Z
        // -----
        // response - in + 'A'?

        // vvvvvvv // let's convert to same standard
        // A B C [in]
        // A B C [response]
        
        // we want response - X + 'A'
        char response_char = response[0] + 'A' - 'X';
        if (response_char == in[0]) {
            currentScore += 3; // for tie
            continue;
        }

        if (response_char == 'A') {
            if (in == "B") currentScore += 0;
            else if (in == "C") currentScore += 6;
        } else if (response_char == 'B') {
            if (in == "A") currentScore += 6;
            else if (in == "C") currentScore += 0;
        } else {
            // scissors
            if (in == "A") currentScore += 0;
            else if (in == "B") currentScore += 6;
        }
    }
    cout << currentScore << endl;
    return 0;
}
