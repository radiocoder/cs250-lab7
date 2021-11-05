#include <iostream>
#include <stdlib.h>
#include <time.h>

void rand_nums(int number)
{
    // print random numbers with range 1- 6
    srand(time(NULL));
    int i;
    for (i = 0; i < number; i++) {
        std::cout << rand() % 6 + 1 << " ";
    }
}


int main(int argc, char *argv[]) {
    int number = 0;
    std::cout << "Enter the number of dice rolls> ";
    std::cin >> number;
    rand_nums(number);
} 