/*
	Name: Rock, Paper or Scissors
	Copyright: 2019 Augusto Machado Ramos
	Author: Augusto Machado Ramos
	Date: 06/16/2019 02:35 pm
	Comment language: en
	Description: 
		The goal was to develop a simple game of "Rock, paper or scissors
            using a text user interface.
		In addition to developing the notion of programming in general,
			know the fundamentals of software programming, Software Engineering concepts,
			in addition to developing basic knowledge in C++.
*/

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
    
    std::cout << "Press y to start game" << std::endl;
    std::cin >> newMatch;
    
    while (newMatch == 'y') {
        
        winner = match();
        
        // Stores who won the match
        if (winner == true) {
            winSysMatch++;
        } else {
            winUserMatch++;
        }
        
        std::cout << "Want to play again? Yes [y] or no [n]?" << std::endl;
        std::cin >> newMatch; 
    }
    
    // Print the final scores of matches
    std::cout << "System: " << winSysMatch <<" vs. You: " << winUserMatch << std::endl;
    
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
                std::cout << "Rock loses for paper" << std::endl;
                std::cout << "You won" << std::endl;
                pointUser++;
                
            } else if (optionUser == 3) {
                std::cout << "Rock wins scissors" << std::endl;
                std::cout << "You lost" << std::endl;
                pointSys++;
                
            } else {
                std::cout << "Gave a tie" << std::endl;
            }
            
        // In this case, systemys equal the paper
        } else if (optionSys >= 34 && optionSys <= 66) {
            
            // If system equal the paper, lose to 3-scissors, win 1-rock
            if (optionUser == 3) {
                std::cout << "Paper loses for scissors" << std::endl;
                std::cout << "You won" << std::endl;
                pointUser++;
                
            } else if (optionUser == 1) {
                std::cout << "Paper wins rock" << std::endl;
                std::cout << "You lost" << std::endl;
                pointSys++;
                
            } else {
                std::cout << "Gave a tie" << std::endl;
            }
            
        // In this case, systemys equal the scissors
        } else if (optionSys >= 67 && optionSys <= 100) {
        
            // If system equal the scissors, lose to 1-rock, win 2-paper
            if (optionUser == 1) {
                std::cout << "Scissors loses for rock" << std::endl;
                std::cout << "You won" << std::endl;
                pointUser++;
                
            } else if (optionUser == 2) {
                std::cout << "Scissors wins paper" << std::endl;
                std::cout << "You lost" << std::endl;
                pointSys++;
                
            } else {
                std::cout << "Gave a tie" << std::endl;
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
