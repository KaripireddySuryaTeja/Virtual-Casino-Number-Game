#include <iostream>
#include <ctime>
#include <string>

struct Number {
    int num1, num2, sum, extraCard;
};

void printCard1(int num1, int num2, int num3, int sum);
void printCard2(int num1, int num2, int sum);
bool playAgain(char x, int money);
int winnerFunction(int bankerCard, int playerCard);
int declareWinner(int winner, int decision, int bet);

int main() {
    system("Color 9F");
    srand(time(NULL));

    std::string name;
    int bet, decision, winner, prize;
    char play;
    bool logic = true;
    int money = 10000;

    std::cout << "==============================\n";
    std::cout << "To Start, please enter your card\n";
    std::cout << "Enter your name: ";
    getline(std::cin, name);

    std::cout << "\nGood evening, " << name << std::endl;
    std::cout << "==============================\n\n";
    std::cout << "WELCOME TO VIRTUAL CASINO TABLE\n";
    std::cout << "=================================\n";

    do {
        std::cout << "Current balance, PHP " << money << std::endl;
        std::cout << "1-BANKER \n2-PLAYER \n";
        std::cout << "Choose your bet ";

        while (!(std::cin >> decision) || (decision < 1 || decision > 2)) {
            std::cin.clear();
            std::cout << "\nChoose your bet ";
            std::cout << "\n1-BANKER \n2-PLAYER \n";
        }

        do {
            std::cout << "Place your bet, PHP: ";
            std::cin >> bet;
        } while (bet > money);

        std::cout << "\n==============================\n";
        std::cout << "      = BANKER'S CARD  =\n";
        std::cout << "==============================\n";

        struct Number banker;
        banker.num1 = rand() % 10 + 1;
        banker.num2 = rand() % 10 + 1;
        banker.sum = banker.num1 + banker.num2;
        banker.sum = banker.sum % 10;

        if (banker.sum != 9 && banker.sum != 8) {
            banker.extraCard = rand() % 10 + 1;
            banker.sum += banker.extraCard;
            banker.sum = banker.sum % 10;
            printCard1(banker.num1, banker.num2, banker.extraCard, banker.sum);
        } else {
            printCard2(banker.num1, banker.num2, banker.sum);
        }

        std::cout << "\n";
        std::cout << "==============================\n";
        std::cout << "      = PLAYER'S CARD  =\n";
        std::cout << "==============================\n";

        struct Number player;
        player.num1 = rand() % 10 + 1;
        player.num2 = rand() % 10 + 1;
        player.sum = player.num1 + player.num2;
        player.sum = player.sum % 10;

        if (player.sum != 9 && player.sum != 8) {
            player.extraCard = rand() % 10 + 1;
            player.sum += player.extraCard;
            player.sum = player.sum % 10;
            printCard1(player.num1, player.num2, player.extraCard, player.sum);
        } else {
            printCard2(player.num1, player.num2, player.sum);
        }

        winner = winnerFunction(banker.sum, player.sum);
        prize = declareWinner(winner, decision, bet);
        std::cout << "PHP " << prize << std::endl;
        money += prize;
        std::cout << "Current Money, PHP " << money << "\n\n";

        std::cout << "PLAY AGAIN? Y/N ";
        std::cin >> play;
        logic = playAgain(play, money);

    } while (logic != false);
}

void printCard1(int num1, int num2, int num3, int sum) {
    std::cout << "=======\n";
    std::cout << "|     |\n";
    std::cout << "|  " << sum << "  |\n";
    std::cout << "|     |\n";
    std::cout << "=======\n";

    std::cout << "First Card " << num1 << "\n";
    std::cout << "Second Card " << num2 << "\n";
    std::cout << "Extra Card " << num3;
}

void printCard2(int num1, int num2, int sum) {
    std::cout << "=======\n";
    std::cout << "|     |\n";
    std::cout << "|  " << sum << "  |\n";
    std::cout << "|     |\n";
    std::cout << "=======\n";

    std::cout << "This is a natural win 8/9 \n";
    std::cout << "First Card " << num1 << "\n";
    std::cout << "Second Card " << num2;
}

bool playAgain(char x, int money) {
    if (money > 0) {
        if (x == 'Y' || x == 'y') {
            return true;
        } else if (x == 'N' || x == 'n') {
            std::cout << "THANK YOU FOR PLAYING!";
            return false;
        }
    } else {
        std::cout << "Insufficient fund!";
        return false;
    }
}

int winnerFunction(int bankerCard, int playerCard) {
    std::cout << "\n==================================\n";
    if (bankerCard > playerCard) {
        std::cout << "\nBANKER WIN, ";
        return 1;
    } else if (bankerCard < playerCard) {
        std::cout << "\nPLAYER WIN, ";
        return 2;
    } else if (bankerCard == playerCard) {
        std::cout << "\nDRAW, ";
        return 3;
    }
}

int declareWinner(int winner, int decision, int bet) {
    if (winner == decision) {
        std::cout << "YOU WIN!\n";
        return bet;
    } if (winner == 3) {
        std::cout << "Tie Game!" << std::endl;
        return 0;
    } else {
        std::cout << "YOU LOSE!\n";
        bet *= -1;
        return bet;
    }
}
