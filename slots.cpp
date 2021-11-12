// Quick Hands, a slots style gambling game.
#include <iostream>
#include <cstdlib> 
#include <Windows.h>
#include <conio.h> 
#include <string>
#include "termcolor.h"
using namespace std;
using namespace termcolor;

const int STARTING_CASH = 2000;

enum menuChoice {
    QUIT = 3,
    PLAY_SLOTS = 1,
    CREDITS = 2,
    NO_CHOICE = -1
};

//Array for storing staff names for reference in credits and for easy updating when staff changes are made.
string staffArray[6] =
{
    "Lincoln Hyde",
    "John Thomason",
    "Bernardo Wilson",
    "Julia Starfish",
    "Donald J Trump"
};

// constants representing win types for each draw result
enum WinMultiplier {
    NO_WIN = 0,
    PAIR = 3,
    THREE_OF_KIND = 5
};
//ensure's the player enters the correct bet
int getValidBet(int cashTotal)
{
    int bet = 0;
    string betError;
   
    
    //do
    do
        {
        //ask for player bet
        cout << cyan << "\n ||||||||||||| BETTING SCREEN ||||||||||||| \n" << termcolor::reset;
        cout << "\t" << yellow << "\n\nBET USING ONLY YOUR AVAILABLE FUNDS SHOWN BELOW " << termcolor::reset << "\n";
        cout << "\t" << yellow << "\n\n    ****AND ALWAYS GAMBLE RESPONSIBLY!**** \n" << termcolor::reset << "\n";
        cout << "     MAKE A BET BETWEEN $1 AND $ " << cashTotal << "\n";
        cout << "\n" << yellow << "   BET>" << termcolor::reset;
       
        // if they erred last time 
        if (betError != "")
        {
            cout << betError << "\n";
        }

        cin >> bet;
        
        //print the bet error
        if (bet < 1 || bet > cashTotal)
        {
            betError = "\nPlease check your bet amount, you can only bet your available funds...Thankyou \n";          
            
        }
        else
        {
            betError = "";
        }
        system("cls");

    } while (betError != "");

   

    return bet;
}

//function to check for winning bets
int checkForWins(int card1, int card2, int card3)
{
    //checks the card integer for compatible wins below
    //result stored and returned in multiplier
    int multiplier;

    if (card1 == card2 && card2 == card1 && card3 == card1)
    {
        cout << green << "\n   :-):-):-) THATS 3 OF A KIND BABY :-):-):-) " << termcolor::reset;
        multiplier = THREE_OF_KIND;
    }
    else if (card1 == card2 || card1 == card3 || card2 == card3)
    {
        cout << "\n:-):-):-) THATS A PAIR! NICE!! :-):-):-)";
        multiplier = PAIR;
    }
    else if (card1 != card2 || card3 && card2 != card3 || card1)
    {
        cout << "\n:-( :-(:-( BUMMER! NO PAIR OR 3 OF A KIND! :-( :-( :-( \n";
        cout << "\n :::::::::: Thats's a losing hand!!! :::::::::\n";
        cout << "\n :::::: HAVE ANOTHER GO OR MAKE A DEPOSIT! ::::: ";
        
        multiplier = NO_WIN;
    }

    return multiplier;
}

//displays available screens to choose from or quit
int displayMenu(int cashAmount)
{
    int choice;
    string inputError = "";

    do
    {
        cout << "\t" << magenta << "--------------------------------------------------\n" << termcolor::reset << "\n";
        cout << "\t" << green << "       ||||||| WELCOME TO QUICK HANDS ||||||| \n\n" << termcolor::reset << "";
        cout << "\t" << magenta << "--------------------------------------------------\n" << termcolor::reset << "\n";
        cout << "\n" << "\t" << cyan << "     ||||||| AN EXCITING GAME OF CHANCE!||||||| \n\n" << termcolor::reset << "";
        cout << "\n" << "\t" << cyan << "|| DRAW 3 CARDS AND WIN FROM A PAIR OR 3 OF A KIND || \n\n" << termcolor::reset << "";
        cout << "\t" << yellow << "\n                 YOUR AVAILABLE CASH IS: " << termcolor::reset << "" << cashAmount << "\n\n";
        cout << "\n             PLEASE MAKE YOUR SELECTION BELOW : \n";
        cout << "\t" << cyan << "\n                     1. PLAY \n                     2. SEE CREDITS \n                     3. QUIT\n" << termcolor::reset << "";
        cout << "                    >";
        
        
        if (inputError != "")
        {
            cout << inputError << "\n";
        }

        cin >> choice;

        if (choice < 1 || choice > 3)
        {
            inputError = "\nPlease check the menu choices and only enter 1,2 or 3...Thankyou \n";
        }
        else
        {
            inputError = "";
        }
        system("cls");
    } while (inputError != "");

    return choice;
}

//Function that contains the Quick Hands game and returns the player cash balance
int playSlots(int playerCash)
{
    int bet = getValidBet(playerCash); 

    cout << yellow << "       ============  DRAW  ============\n\n" << termcolor::reset;
    cout << yellow << " ========== EVERYONE IS A WINNER!!==========\n" << termcolor::reset;
        
    cout << "\n !!!! HEY HIGH ROLLER YOUR BET IS $ " << bet << " !!!!\n";
    //Adjust balance of playerCash
    playerCash -= bet;
    
        int card1 = rand()%(7 - 1 + 1) + 1; 
        int card2 = rand()%(7 - 1 + 1) + 1;
        int card3 = rand()%(7 - 1 + 1) + 1;
    
    cout << "\n";
    cout << cyan << "|||||||||| YOUR CARD DRAW THIS ROUND |||||||||\n" << termcolor::reset;
    cout << "\n              " << "** " << card1 << " ** " << card2 << " ** " << card3 << " ** " << "\n"; 
    cout << cyan << "\n|||||||||| YOUR CARD DRAW THIS ROUND |||||||||\n" << termcolor::reset;

    int multiplier = checkForWins(card1, card2, card3);

    playerCash += bet * multiplier; 

   
    // such as displayWinLossOutcome(multiplier, cashTotal;
    if (multiplier == PAIR)
    {
        
    } 
        
    if (multiplier != NO_WIN)
    {
        cout << green << "\n\n#### YOU WON, ####" << termcolor::reset << yellow << " YOUR NEW BALANCE IS $ " << termcolor::reset << playerCash << "\n\n";
    }
    else
    {
        cout << red << "\n\n#### YOU lOST, #### " << termcolor::reset << yellow << " YOUR NEW BALANCE IS $ " << termcolor::reset << playerCash << "\n\n";
    }
    
     cout << "Press any key to return to the main menu \n";
    _getch();

    return(playerCash);
}
//Function that contains the developer team details
void displayCredits()
{
    cout << on_cyan << "                                                 \n" << termcolor::reset << "";
    cout << on_cyan << "                                                 \n" << termcolor::reset << "";
    cout << on_cyan << "                                                 \n" << termcolor::reset << "";
    cout << "          QUICK HANDS WAS DEVELOPED by:  \n\n         *****HYDE GLOBAL MEDIA!*****\n\n";
    cout << "       |||||| PRODUCTION SUPERVISOR ||||| \n\n                "    << staffArray[0] << endl;
    cout << "\n       |||||| TECHNICAL LEAD ||||| \n\n               "    << staffArray[1] << endl;
    cout << "\n       |||||| DESIGN TECHNICIAN ||||| \n\n               "    << staffArray[4] << endl;
    cout << "\n       |||||| COFFEE & GENERAL LACKY ||||| \n\n                "    << staffArray[0] << endl;
    cout << on_cyan << "                                                 \n" << termcolor::reset << "";
    cout << on_cyan << "                                                 \n" << termcolor::reset << "";
    cout << on_cyan << "                                                 \n" << termcolor::reset << "";
    cout << "\nIf you would like to donate to the project,\nPlease contact us at:\nlincoln@hydeglobalmedia.com \n";
    cout << "\n";
    cout << "\nHit any key to return to main menu ";
    


    _getch();

    return;
}

//Function that holds and displays the message to the player when they quit the game
void displayQuit(int finalCash)
{
    int winLoss = finalCash - STARTING_CASH;
    cout << cyan << "###################################################################" << termcolor::reset << "";
    cout << green << "\n\n          " << "      ##### YOUR PROFIT OR LOSS = $ " << winLoss << termcolor::reset << "\n" << endl;

    cout << cyan << "  ##### On behalf of the team at HYDE GLOBAL MEDIA ##### \n\n" << termcolor::reset << "";
    cout << cyan << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||| \n\n" << termcolor::reset << "";

    for (const auto& e : staffArray) //Using the total array output to show all staff members on the Quit screen
    {
        std::cout << "                        " << e << std::endl;
    }

    cout << cyan << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n" << termcolor::reset << "";

    cout << yellow << "\n\n                THANKS FOR PLAYING QUICK HANDS \n\n" << termcolor::reset << endl;

    cout << yellow << "Please come back and allow us to take your money again soon :-)\n\n" << termcolor::reset << "";
}


int main()
{
    int cashLeft = STARTING_CASH;
    int choice = NO_CHOICE;

    srand(time(0));
    bool playAgain = false;
    do
    {
        
        system("cls");
        choice = displayMenu(cashLeft);

        if (choice == CREDITS)
        {
            system("cls");  
            displayCredits();
        }
        else if (choice == PLAY_SLOTS)
        {
            system("cls"); 
            cashLeft = playSlots(cashLeft);
                       
        }

    } while (choice != QUIT); 

    

    system("cls"); 
    displayQuit(cashLeft);







}