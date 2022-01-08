#include <iostream>
#include <stdlib.h> 

void PrintIntroduction(int BiggestNumber, int Sum, int Product) {
    std::cout << "->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->";
    std::cout << "\n* Logical test";
    std::cout << "\n* You must find the 3 numbers in range of 1 and " << BiggestNumber << " that:";
    std::cout << "\n- When they are added the result is " << Sum; 
    std::cout << "\n- Whe they are multiplied the result is " << Product << "\n";
    std::cout << "->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->\n";
}

bool VerifyTheAnswer(int Sum, int Product, int GuessFirst, int GuessSecond, int GuessThirdy) {
    return Sum == ( GuessFirst + GuessSecond + GuessThirdy ) && Product == ( GuessFirst * GuessSecond * GuessThirdy );
}

bool PlayGame(int Dificult) {

    int BiggestNumber = (Dificult + 2);
    int First = rand() % BiggestNumber + 1;
    int Second = rand() % BiggestNumber + 1;
    int Thirdy = rand() % BiggestNumber + 1;
    int Sum = First + Second + Thirdy;
    int Product = First * Second * Thirdy;
    int GuessFirst, GuessSecond, GuessThirdy;

    PrintIntroduction(BiggestNumber, Sum, Product);
    std::cin >> GuessFirst >> GuessSecond >> GuessThirdy;

    if( VerifyTheAnswer(Sum, Product, GuessFirst, GuessSecond, GuessThirdy) ){
        if( Dificult == 7 ){
            std::cout << "End game, you win!";
        } else {
            std::cout << "You are correct, next level...";
        }
       return true;
    } else {
        std::cout << "You are wrong, trying again...";
         return false;
    }

}

int main () {

    int Dificult = 1;
    int MaxDificult = 7;

    while(Dificult > MaxDificult){
        if( PlayGame(Dificult) ){
            Dificult++;
        }
        std::cin.clear();
        std::cin.ignore();
    }

    return 0;
} 