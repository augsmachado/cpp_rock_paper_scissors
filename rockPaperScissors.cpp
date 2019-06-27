# include <iostream>
# include <cstdlib>
# include <ctime>
using namespace std;

void menuOption ();
void inputOptionUser( int *optionUser);
void randomOptionSys (int *optionSys);


int main () {
    int optionUser, optionSys;
    int pointUser = 0, pointSys = 0;
    int round = 1;
    srand(time(0));

    while (round <= 3){
        optionUser = 0;
        
        menuOption();
        inputOptionUser(&optionUser);
        randomOptionSys(&optionSys);

		/*
		* Options to user:
    	* 1 - Rock
    	* 2 - Paper
    	* 3 - Scissors
		*/


        if (optionSys >= 1 && optionSys <= 33){  // Sys equal the rock
            
            if (optionUser == 2){
                std::cout << "Rock loses for paper" << endl;
                pointUser++;

            }
			
			if (optionUser == 3){
                std::cout << "Rock wins scissors" << endl;
                pointSys++;
            }
            
            
        } else if (optionSys >= 34 && optionSys <= 66){ // Sys equal the paper
            
            if (optionUser == 3){
                std::cout << "Paper loses for scissors" << endl;
                pointUser++;
            
            }
			
			if (optionUser == 1){
                std::cout << "Paper wins rock" << endl;
                pointSys++;
            }
            
            
        } else if (optionSys >= 67 && optionSys <= 100){  // Sys equal the scissors
            
            if (optionUser == 3){
                std::cout << "Scissors loses for rock" << endl;
                pointUser++;
            
            }
			
			if (optionUser == 3){
                std::cout << "Scissors wins paper" << endl;
                pointSys++;
            }
        }

        round++;
    }
    
    if(pointSys > pointUser){
        std::cout << "Sorry, but the system won" << std::endl;
    } else {
        std::cout << "Congratulations, you won!" << std::endl;
    }
    
    return 0;
}


void menuOption (){
    std::cout << std::endl << "Choose an option:" << std::endl;
    std::cout << "1 - Rock" << std::endl;
    std::cout << "2 - Paper" << std::endl;
    std::cout << "3 - Scissors" << std::endl;
}

void inputOptionUser( int *optionUser){
    while (*optionUser < 1 || *optionUser > 3){
        std::cin >> *optionUser;
    }
}

void randomOptionSys (int *optionSys){
    *optionSys = (1 + (rand() % 100));
}
