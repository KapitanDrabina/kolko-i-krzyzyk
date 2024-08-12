#include <iostream>

using namespace std;

class Gra{
    private:
        array<string, 9> board;
        char move;

    public:
        Gra() : board({"1", "2", "3", "4", "5", "6", "7", "8", "9"})
        {
            move = 'X';
        }

        array<string, 9> getBoard()
        {
            return this->board;
        }

        void setBoard(int position, char value)
        {
            this->board[position] = value;
        }

        char getMove()
        {
            return this->move;
        }

        void setMove(char move)
        {
            this->move = move;
        }

        void print() {
            cout << " " << this->board[0] << " | " << this->board[1] << " | " << this->board[2] << endl;
            cout <<"---+---+---" << endl;
            cout << " " << this->board[3] << " | " << this->board[4] << " | " << this->board[5] << endl;
            cout <<"---+---+---" << endl;
            cout << " " << this->board[6] << " | " << this->board[7] << " | " << this->board[8] << endl;
        }

        bool is_in_list(int square){
            return to_string(square) == this->board[square-1];
        }

        string check(){
            for(int i = 0; i < 3; i++){
                if(this->board[i] == this->board[i+3] and this->board[i+3] == this->board[i+6]){
                    return this->board[i];
                }
            }

            for(int i = 0; i < 7; i = i + 3){
                if(this->board[i] == this->board[i+1] and this->board[i+1] == this->board[i+2]){
                    return this->board[i];
                }
            }

            if((this->board[0] == this->board[4] and this->board[4] == this->board[8]) or (this->board[2] == this->board[4] and this->board[4] == this->board[6])){
                return this->board[4];
            }

            return "N";
        }
};

int main(){
    Gra runda = Gra();

    for(int i = 1; i <= 9; i++){
        int square;
        bool is_correct = false;

        while(!is_correct){
            runda.print();
            
            cout << endl << "Player " << runda.getMove() << "\n\nEnter the number of a field to be marked: ";
            cin >> square;
            cout << endl;

            if (runda.is_in_list(square)) {
                is_correct = true;
            } else {
                cout << "!!!This square is already marked!!!\n\n";
            }
        }

        runda.setBoard(square-1, runda.getMove());
        runda.setMove(runda.getMove() == 'X' ? 'O' : 'X');

        if (runda.check() != "N") {
            runda.print();
            cout << "\n" << runda.check() << " Won!";
            return 0;
        } 
    }
    runda.print();
    cout << "\n" << "It's a draw!";

    return 0;
}
