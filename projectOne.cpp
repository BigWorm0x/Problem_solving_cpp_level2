#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

enum enGameChoice { Stone = 1, Paper = 2, Scissors = 3 };
enum enWinner { Player = 1, Computer = 2, Draw = 3 };

string GetChoiceName(enGameChoice choice) {
    string names[] = { "Stone", "Paper", "Scissors" };
    return names[choice - 1];
}

string GetWinnerName(enWinner winner) {
    switch (winner) {
    case Player: return "\033[1;32mPlayer\033[0m";  // Green
    case Computer: return "\033[1;31mComputer\033[0m";  // Red
    default: return "\033[1;33mDraw\033[0m";  // Yellow
    }
}

enGameChoice GetComputerChoice() {
    return (enGameChoice)(rand() % 3 + 1);
}

enGameChoice GetPlayerChoice() {
    int choice;
    do {
        cout << "\nChoose your move:\n[1] Stone\n[2] Paper\n[3] Scissors\n> ";
        cin >> choice;
    } while (choice < 1 || choice > 3);
    return (enGameChoice)choice;
}

enWinner DetermineWinner(enGameChoice player, enGameChoice computer) {
    if (player == computer) return Draw;
    if ((player == Stone && computer == Scissors) ||
        (player == Paper && computer == Stone) ||
        (player == Scissors && computer == Paper))
        return Player;
    return Computer;
}

void PrintRoundResult(int round, enGameChoice player, enGameChoice computer, enWinner winner) {
    cout << "\n\033[1;34mRound " << round << "\033[0m\n";
    cout << "Player chose: " << GetChoiceName(player) << endl;
    cout << "Computer chose: " << GetChoiceName(computer) << endl;
    cout << "Winner: " << GetWinnerName(winner) << endl;
}

void PlayGame(int totalRounds) {
    int playerScore = 0, computerScore = 0;
    for (int round = 1; round <= totalRounds; ++round) {
        enGameChoice player = GetPlayerChoice();
        enGameChoice computer = GetComputerChoice();
        enWinner winner = DetermineWinner(player, computer);

        if (winner == Player) playerScore++;
        else if (winner == Computer) computerScore++;

        PrintRoundResult(round, player, computer, winner);
        cout << "\nCurrent Score -> Player: " << playerScore << " | Computer: " << computerScore << "\n\n";
    }

    cout << "\033[1;36mFinal Result:\033[0m\n";
    if (playerScore > computerScore)
        cout << "\033[1;32mYou Win the Game!\033[0m\n";
    else if (computerScore > playerScore)
        cout << "\033[1;31mComputer Wins the Game!\033[0m\n";
    else
        cout << "\033[1;33mIt's a Draw!\033[0m\n";
}

int main() {
    srand((unsigned)time(NULL));
    int rounds;
    cout << "\033[1;36mWelcome to Rock, Paper, Scissors Game!\033[0m\n";
    cout << "How many rounds would you like to play? ";
    cin >> rounds;
    PlayGame(rounds);
    return 0;
}
