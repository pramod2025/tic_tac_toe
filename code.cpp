#include <iostream>
using namespace std;

// Array for the board
char board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };

// Variable Declaration
int choice;
int row, column;
char turn = 'X';
bool draw = false;

// Function to show the current status of the gaming board
void display_board() {
    cout << "PLAYER - 1 [X]  PLAYER - 2 [O]\n\n";
    cout << "     |     |     \n";
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  \n";
    cout << "||_\n";
    cout << "     |     |     \n";
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  \n";
    cout << "||_\n";
    cout << "     |     |     \n";
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  \n";
    cout << "     |     |     \n";
}

// Function to get the player input and update the board
void player_turn() {
    cout << "\nPlayer - " << (turn == 'X' ? "1 [X]" : "2 [O]") << " turn : ";
    cin >> choice;

    // Determine row and column based on choice
    switch (choice) {
        case 1: row = 0; column = 0; break;
        case 2: row = 0; column = 1; break;
        case 3: row = 0; column = 2; break;
        case 4: row = 1; column = 0; break;
        case 5: row = 1; column = 1; break;
        case 6: row = 1; column = 2; break;
        case 7: row = 2; column = 0; break;
        case 8: row = 2; column = 1; break;
        case 9: row = 2; column = 2; break;
        default:
            cout << "Invalid Move! Please choose a number between 1 and 9.\n";
            player_turn();
            return;
    }

    if (board[row][column] != 'X' && board[row][column] != 'O') {
        board[row][column] = turn;
        turn = (turn == 'X') ? 'O' : 'X';
    } else {
        cout << "Box already filled! Please choose another.\n";
        player_turn();
    }
    display_board();
}

// Function to get the game status e.g. GAME WON, GAME DRAW GAME IN CONTINUE MODE
bool gameover() {
    // Check for winning condition
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) || // Check rows
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])) { // Check columns
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return true;
    }

    // Check for draw
    bool emptySpaces = false;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                emptySpaces = true;
                break;
            }
        }
    }

    if (!emptySpaces) {
        draw = true;
        return true;
    }

    return false;
}

// Main Method
int main() {
    cout << "\t\tT I C K -- T A C -- T O E -- G A M E\n";
    cout << "\t\tFOR 2 PLAYERS\n";

    while (!gameover()) {
        display_board();
        player_turn();
    }

    // Display result
    if (draw) {
        cout << "\nGAME DRAW!!!\n";
    } else {
        cout << "\nCongratulations! Player with '" << (turn == 'X' ? 'O' : 'X') << "' has won the game\n";
    }

    return 0;
}
