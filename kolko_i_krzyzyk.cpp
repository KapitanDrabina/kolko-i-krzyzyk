#include <iostream>

using namespace std;

void print(string board[])
{
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << "---+---+---" << endl;
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << "---+---+---" << endl;
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
}

char check(string board[]) 
{
    for (int i = 0; i < 3; i++) {
        if (board[i] == board[i+3]) {
            if (board[i+3] == board[i+6]) {
                if (board[i] == "X") {
                    return 'X';
                } else {
                    return 'O';
                }
            }
        }
    }

    for (int i = 0; i < 7; i = i + 3) {
        if (board[i] == board[i+1]) {
            if (board[i+1] == board[i+2]) {
                if (board[i] == "X") {
                    return 'X';
                } else {
                    return 'O';
                }
            }
        }
    }

    if ((board[0] == board[4] and board[4] == board[8]) or (board[2] == board[4] and board[4] == board[6])) {
        if (board[4] == "X") {
            return 'X';
        } else {
            return 'O';
        }
    }
}

int main() 
{
    char move = 'X';
    string board[] = {"1","2","3","4","5","6","7","8","9"};

    for(int i = 1; i<=9;i++) {
        print(board);

        cout << "\nPlayer " << move << "\n" << "\nEnter the number of the field to be marked: ";
        int zaznaczenie;
        cin >> zaznaczenie;

        board[zaznaczenie-1] = move;
        move = move == 'X' ? 'O' : 'X';

        if (check(board) == 'X') {
            cout << "X Won!";
            break;
        } else if (check(board) == 'O') { 
            cout << "O Won!";
            break;
        }
    }
    return 0;
}
