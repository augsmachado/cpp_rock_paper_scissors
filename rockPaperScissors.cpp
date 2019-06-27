# include <iostream>
# include <cstdlib>
# include <ctime>
using namespace std;

void menuOption ();
void inputOptionUser (int *optionUser);
void randomOptionSys (int *optionSys);
int match ();


int main () {
    char newMatch;
    int winner;
    int winUserMatch = 0, winSysMatch = 0;
    
    std::cout << "Press y to start game" << endl;
    std::cin >> newMatch;
    
    while (newMatch == 'y') {
        
        winner = match();
        
        // Stores who won the match
        if (winner == true) {
            winSysMatch++;
        } else {
            winUserMatch++;
        }
        
        cout << "Want to play again? Yes [y] or no [n]?" << endl;
        cin >> newMatch; 
    }
    
    // Print the final scores of matches
    cout << "System: " << winSysMatch <<" vs. You: " << winUserMatch << endl;
    
    return 0;
}


int match () {
    int optionUser, optionSys;
    int pointUser = 0, pointSys = 0;
    int round = 1;
    srand(time(0));

    // The match lasts three rounds
    while (round <= 3) {
        optionUser = 0;
        
        menuOption();
        inputOptionUser(&optionUser);
        randomOptionSys(&optionSys);

        /*
         * Decide who won the round
         * In this case, systemys equal the rock
         */
        if (optionSys >= 1 && optionSys <= 33) {
            
            // If system equal the rock, lose to 2-paper, win 3 scissor
            if (optionUser == 2) {
                std::cout << "Rock loses for paper" << endl;
                std::cout << "You won" << endl;
                pointUser++;
                
            } else if (optionUser == 3) {
                std::cout << "Rock wins scissors" << endl;
                std::cout << "You lost" << endl;
                pointSys++;
                
            } else {
                std::cout << "Gave a tie" << endl;
            }
            
        // In this case, systemys equal the paper
        } else if (optionSys >= 34 && optionSys <= 66) {
            
            // If system equal the paper, lose to 3-scissors, win 1-rock
            if (optionUser == 3) {
                std::cout << "Paper loses for scissors" << endl;
                std::cout << "You won" << endl;
                pointUser++;
                
            } else if (optionUser == 1) {
                std::cout << "Paper wins rock" << endl;
                std::cout << "You lost" << endl;
                pointSys++;
                
            } else {
                std::cout << "Gave a tie" << endl;
            }
            
        // In this case, systemys equal the scissors
        } else if (optionSys >= 67 && optionSys <= 100) {
        
            // If system equal the scissors, lose to 1-rock, win 2-paper
            if (optionUser == 1) {
                std::cout << "Scissors loses for rock" << endl;
                std::cout << "You won" << endl;
                pointUser++;
                
            } else if (optionUser == 2) {
                std::cout << "Scissors wins paper" << endl;
                std::cout << "You lost" << endl;
                pointSys++;
                
            } else {
                std::cout << "Gave a tie" << endl;
            }
        }
        round++;
    }
    
    // Prints who won the rounds in the end of match
    if (pointSys > pointUser) {
        std::cout << "Sorry, but the system won" << std::endl;
        return true;
    } else {
        std::cout << "Congratulations, you won!" << std::endl;
        return false;
    }
}

// Print the options menu
void menuOption () {
    std::cout << std::endl << "Choose an option:" << std::endl;
    std::cout << "1 - Rock" << std::endl;
    std::cout << "2 - Paper" << std::endl;
    std::cout << "3 - Scissors" << std::endl;
}

// Input of user option
void inputOptionUser (int *optionUser) {
    
    // While the user not write a number between one and three, repeat
    while (*optionUser < 1 || *optionUser > 3) {
        std::cin >> *optionUser;
    }
}

// Use the computer clock to create a true random function
void randomOptionSys (int *optionSys) {

    // A random function return a number between zero and one hundred
    *optionSys = (1 + (rand() % 100));
}
