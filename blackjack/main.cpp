#include "./src/player.hpp" 
#include <conio.h>

void playerTurn(Player &player, Deck d) {
    std::cout << "Your hand: ";
    player.print();
    std::cout << '\n';
    std::cout << "Your hand's Value: " << player.value() << "\n";

    std::cout << "Would you like to hit or stand? (h/s) ";
    char ans;
    std::cin >> ans;

    while (ans != 'h' && ans != 's') {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Would you like to hit or stand? (h/s) ";
        std::cin >> ans;
    }

    if(ans == 'h') {
        player.draw(d);
    } else {
        player.m_notStand = false;
    }
    
}

void dealerTurn(Player &dealer, Deck d) {
    std::cout << "Dealer's hand: ";
    dealer.print();
    std::cout << '\n';
    std::cout << "Dealer's hand's Value: " << dealer.value() << "+\n";
    dealer.unHideCard();
    if(dealer.value() < 17) {
        dealer.draw(d);
    }
    dealer.hideCard();
}

int main() {
    std::cout << ".------..------..------..------..------..------..------..------..------.\n"<<
                 "|B.--. ||L.--. ||A.--. ||C.--. ||K.--. ||J.--. ||A.--. ||C.--. ||K.--. |\n"<<
                 "| :(): || :/\\: || (\\/) || :/\\: || :/\\: || :(): || (\\/) || :/\\: || :/\\: |\n"<<
                 "| ()() || (__) || :\\/: || :\\/: || :\\/: || ()() || :\\/: || :\\/: || :\\/: |\n"<<
                 "| '--'B|| '--'L|| '--'A|| '--'C|| '--'K|| '--'J|| '--'A|| '--'C|| '--'K|\n"<<
                 "`------'`------'`------'`------'`------'`------'`------'`------'`------'\n"<<
                 "                     --Press any key to start--\n";
    getch();
    while(true) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        Deck deck{};
        Player player{};
        Player dealer{};
        deck.shuffle();


        dealer.draw(deck);
        dealer.hideCard();
        dealer.draw(deck);

        player.draw(deck);
        player.draw(deck);

        while (!player.m_isBust && !dealer.m_isBust && player.m_notStand) {
            dealerTurn(dealer, deck);
            playerTurn(player, deck);
            std::cout << '\n';
        }

        dealer.unHideCard();
        std::cout << "Dealer's hand: ";
        dealer.print();
        std::cout << '\n';
        std::cout << "Dealer's hand's Value: " << dealer.value() << "\n";

        std::cout << "Your hand: ";
        player.print();
        std::cout << '\n';
        std::cout << "Your hand's Value: " << player.value() << "\n\n";

        if(
            (!player.m_isBust && dealer.m_isBust) 
            || ((!player.m_isBust && !dealer.m_isBust) && (player.value() > dealer.value()))) {
            std::cout << "You Win!";
        } else if ((player.m_isBust && !dealer.m_isBust) 
            || ((!player.m_isBust && !dealer.m_isBust) && (player.value() < dealer.value()))) {
            std::cout << "You Lose";
        } else {
            std::cout << "You Tie";
        }

        std::cout << "\n\nWould you like to play again? (y/n) ";

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        char ans;
        std::cin >> ans;

        while (ans != 'y' && ans != 'n') {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Would you like to play again? (y/n) ";
            std::cin >> ans;
        }

        if (ans == 'n') {
            break;
        }

        std::cout << '\n';
    }

    return 0;
}