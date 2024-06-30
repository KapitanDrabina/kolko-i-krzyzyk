#include <iostream>
using namespace std;

void print(string board[]);
char check(string board[]);

int main(){
    char move = 'X';
    string board[] = {"1","2","3","4","5","6","7","8","9"};
    for(int i = 1; i<=9;i++){
        
        print(board);

        cout << "\nPlayer " << move << "\n" << "\nEnter the number of the field to be marked: ";
        int square;
        cin >> square;

        if(move == 'X'){
            board[square-1] = "X";
            move = 'O';
        }
        else{
            board[square-1] = "O";
            move = 'X';
        }
        if(check(board) == 'X'){
            print(board);
            cout << "\n" << "X Won!";
            return 0;
        }
        else if(check(board) == 'O'){
            print(board);
            cout << "\n" << "O Won!";
            return 0;
        }
    }
    print(board);
    cout << "\n" << "It's a draw!";
    return 0;
}

void print(string board[]){
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout <<"---+---+---" << endl;
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout <<"---+---+---" << endl;
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
    }

char check(string board[]){
    for(int i = 0; i < 3; i++){
        if(board[i] == board[i+3] and board[i+3] == board[i+6]){
            if(board[i] == "X"){
                return 'X';
            }
            else{
                return 'O';
            }
        }
    }

    for(int i = 0; i < 7; i = i + 3){
        if(board[i] == board[i+1] and board[i+1] == board[i+2]){
            if(board[i] == "X"){
                return 'X';
            }
            else{
                return 'O';
            }
        }
    }

    if(board[0] == board[4] and board[4] == board[8] or board[2] == board[4] and board[4] == board[6]){
        if(board[4] == "X"){
            return 'X';
        }
        else{
            return 'O';
        }
    }
}
