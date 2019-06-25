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

        if (optionSys >= 1 && optionSys <= 33){  // Sys equal the rock
            if (optionUser == 2){
                pointUser++;
            } else if (){
                
            }
        } else if (optionSys >= 34 && optionSys <= 66){ // Sys equal the paper
            
        } else if (optionSys >= 67 && optionSys <= 100){  // Sys equal the scissors
            
        }




        round++;
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
