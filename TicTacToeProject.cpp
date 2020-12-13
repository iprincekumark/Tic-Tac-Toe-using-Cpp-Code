#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

char square[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int checkwin();
void board(string, string);

int main()
{
    int player = 1, i, choice;
    char mark;
    string player1, player2, playerfirst, name;
    cout << "Enter a name for the X player : ";
    getline(cin, player1);
    fflush(stdin);
    cout << "Enter a name for the O player : ";
    getline(cin, player2);
    fflush(stdin);
    cout << "\nWho will play first in the game -"
         << "\nEnter a name for the X player : " << player1 << "\nEnter a name for the O player : " << player2 << "\n";
    getline(cin, playerfirst);
    fflush(stdin);
    if ((playerfirst != player1) && (playerfirst != player2))
    {
        cout << "\nERROR : INVALID INPUT" << endl;
        return 0;
    }
    else
    {
        do
        {
            board(player1, player2);
            if (player1 == playerfirst)
            {
                board(player1, player2);
                player = (player % 2) ? 1 : 2;
                name = (player % 2) ? player1 : player2;
                cout << name << " enter a number :  ";
                cin >> choice;
                mark = (player == 1) ? 'X' : 'O';
            }
            else
            {
                board(player1, player2);
                player = (player % 2) ? 1 : 2;
                name = (player % 2) ? player2 : player1;
                cout << name << " enter a number :  ";
                cin >> choice;
                mark = (player == 2) ? 'X' : 'O';
            }
            if (choice == 1 && square[1] == '1')

                square[1] = mark;
            else if (choice == 2 && square[2] == '2')

                square[2] = mark;
            else if (choice == 3 && square[3] == '3')

                square[3] = mark;
            else if (choice == 4 && square[4] == '4')

                square[4] = mark;
            else if (choice == 5 && square[5] == '5')

                square[5] = mark;
            else if (choice == 6 && square[6] == '6')

                square[6] = mark;
            else if (choice == 7 && square[7] == '7')

                square[7] = mark;
            else if (choice == 8 && square[8] == '8')

                square[8] = mark;
            else if (choice == 9 && square[9] == '9')

                square[9] = mark;
            else
            {
                cout << "Invalid move ";

                player--;
                cin.ignore();
                cin.get();
            }
            i = checkwin();

            player++;
        } while (i == -1);
        board(player1, player2);
        if (i == 1)
            if (player1 == playerfirst)
                cout << "\aPlayer ==> " << player1 << " WINS ";
            else
                cout << "\aPlayer ==> " << player2 << " WINS ";
        else
            cout << "==>\aGame Draw<==";

        cin.ignore();
        cin.get();
        return 0;
    }
}

int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])

        return 1;
    else if (square[4] == square[5] && square[5] == square[6])

        return 1;
    else if (square[7] == square[8] && square[8] == square[9])

        return 1;
    else if (square[1] == square[4] && square[4] == square[7])

        return 1;
    else if (square[2] == square[5] && square[5] == square[8])

        return 1;
    else if (square[3] == square[6] && square[6] == square[9])

        return 1;
    else if (square[1] == square[5] && square[5] == square[9])

        return 1;
    else if (square[3] == square[5] && square[5] == square[7])

        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return -1;
}

void board(string player1, string player2)
{
    system("cls");
    cout << "\n\n\tTic Tac Toe by Prince Kumar Kanoujiya\n\n";

    cout << player1 << " (X)  -  " << player2 << " (O)" << endl
         << endl;
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

    cout << "     |     |     " << endl
         << endl;
}