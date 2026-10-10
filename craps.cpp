// Plays the game of craps.
#include <iostream>
#include <cstdlib>
#include <ctime>

// function prototype / declarations
int roll_2d6();		
int do_game(int, int);

int main()
{
  /*
    Normally, we would seed with time(NULL), however autograding
    is hard to do with random results. So, we are going to 
    enter a seed value to allow for autograding.
  */
  int seed;
  std::cin >> seed;
  if (std::cin.eof())
	  return 0;
  if (std::cin.fail())
  {
	std::cin.clear();
	std::cin.ignore(10000, '\n');
	seed = 0;
  }
  srand(seed); // Seed the random number generator
  int wallet = 1000;
  bool gameOver = false;

  while (!gameOver)
  {
	std::cout << "Enter amount to bet. You have $" << wallet << std::endl;
	int bet;
	std::cin >> bet;
	if (std::cin.eof())
		break;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		bet = -1;
	}
	if (bet <= 0)
		std::cout << "Bet must be positive." << std::endl;
	else if (bet > wallet)
		std::cout << "You don't have that much money." << std::endl;
	else
        wallet = do_game(bet,wallet);
	if (wallet == 0)
	{
		std::cout << "You are penniless. Thanks for playing." << std::endl;
		gameOver = true;
	}
	else
	{
		std::cout << "Play again? (y/n)" << std::endl;
		char c;
		std::cin >> c;
		if (std::cin.eof())
			break;
		if (c=='n')
			gameOver = true;
	}
  }
  std::cout << "You ended the game with $" << wallet << "." << std::endl;
}

// roll 1 6-sided die and return the result
int roll_1d6() {
  // rand() % 6 will give a value of 0 to 5
  // adding 1 will give a value of 1 to 6
  return rand() % 6 + 1;
}

// Simulate rolling two dice.
int roll_2d6() { return roll_1d6() + roll_1d6(); }

int do_game(int bet, int wallet) {
    // Make initial roll
    int roll = roll_2d6();
    std::cout << "You rolled " << roll << std::endl;
    // Check for a win or loss or the point
    switch (roll)
    {
        case 7:
        case 11:
            std::cout << "You win!" << std::endl;
            wallet += bet;
            break;
        case 2:
        case 3:
        case 12:
            std::cout << "You lose." << std::endl;
            wallet -= bet;
            break;
        default:
            // Continue rolling until we roll the point
            // or 7
            int point = roll;
            std::cout << "The point is " << point << std::endl;
            do
            {
                roll = roll_2d6();
                std::cout << "You rolled " << roll << std::endl;
                if (roll == 7)
                {
                  std::cout << "You lose." << std::endl;
                  wallet -= bet;
                }
                else if (roll == point)
                {
                  std::cout << "That matches the point!" <<
                    " You win!" << std::endl;
                  wallet += bet;
                }
            } while ((roll != 7) && (roll != point));
    }
    return wallet;
}
   