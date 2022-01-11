// Copyright (c) 2022 Ina Tolo All rights reserved.
//
// Created by: Ina Tolo
// Created on: Jan. 11 , 2021
// This program generates a random number
// and then uses a while true loop to ask
// the user until they guess correctly.
// It also uses a break statement to stop
// the program.

#include <iostream>
#include <random>

int main() {
  int randomNumber;
  int counter = 0;
  int userNumInt;
  std::string userNumString;

  std::random_device rseed;


  // mersenne_twister
  std::mt19937 rgen(rseed());

  // [0, 9]
  std::uniform_int_distribution<int> idist(0, 9);

  randomNumber = idist(rgen);

  while (true) {
     // get the user number as a string
     std::cout << "Enter a whole number between 0 and 9: ";
     std::cin >> userNumString;

     try {
          // convert the user's number to an int
          userNumInt = std::stoi(userNumString);

          if (userNumInt >= 0 && userNumInt <= 9) {
              // increments the counter
              counter++;
              if (userNumInt == randomNumber) {
                  std::cout << userNumInt << " is correct! Congratulations!.\n";
                  break;
              } else {
                  std::cout << userNumInt << " is incorrect.\n";
                  std::cout << std::endl;
                  std::cout << "Tracking ";
                  std::cout << counter << " times through the loop.\n";
                  std::cout << std::endl;
              }
          } else {
              std::cout << "This is not within the range!";
              std::cout << std::endl;
              std::cout << std::endl;
          }
     } catch (std::invalid_argument) {
       // The user did not enter a number.
       std::cout << userNumString << " is invalid.\n";
       std::cout << std::endl;
       }
  }
}
