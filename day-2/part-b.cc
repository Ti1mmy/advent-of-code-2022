#include <bits/stdc++.h>
using namespace std;

int main() {
    int currentScore = 0;
    string in = "";
    string response = "";
    while (cin >> in >> response) {
        // pt b - need to figure out how to respond
        char initial_response = response[0];
        char response_play;
        if (initial_response == 'X') {
            // pick losing move
            if (in[0] == 'A') response_play = 'C'; // scissors lose to rock
            else if (in[0] == 'B') response_play = 'A'; // Rock loses to paper
            else response_play = 'B'; // Paper loses to Scissors
        } else if (initial_response == 'Y') {
            // pick tie move
            response_play = in[0];
        } else {
            // need to win
            if (in[0] == 'A') response_play = 'B'; // paper beats rock
            else if (in[0] == 'B') response_play = 'C'; // scissors beats paper
            else response_play = 'A'; // rock beats scissors
        }

        int shape = response_play - 'A' + 1; // X gives 1, then Y gives 2, etc.
        currentScore += shape;

        char response_char = response_play;
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
