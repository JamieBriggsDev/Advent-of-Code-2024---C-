//
// Created by Jamie Briggs on 11/12/2024.
//

#include "PebbleRow.h"

#include <iostream>
#include <sstream>
#include <string>

namespace solutions {
  PebbleRow::PebbleRow(std::string rawInput) {

    std::istringstream stream(rawInput);
    std::string token;
    while (std::getline(stream, token, ' ')) {
      // Attempt to convert each token to a long and add to pebbleList
      try {
        pebbleList.push_back(std::stoll(token));
      } catch (const std::invalid_argument &e) {
        // Ignore invalid tokens that cannot be converted to a number
      }
    }
  }
  long long PebbleRow::getPebbleAtIndex(int index) {
    auto front = this->pebbleList.begin();
    std::advance(front, index);
    return *front;
  }

  bool PebbleRow::upgradeZeroEngraving(std::list<long long>::iterator &idx) {
    if (*idx == 0) {
      *idx = 1;
      return true;
    }
    return false;
  }
  bool PebbleRow::splitPebbleIfEven(std::list<long long>::iterator &idx) {
    long long currentValue = *idx;
    std::string currentValueStr = std::to_string(currentValue);
    if(currentValueStr.length() % 2 == 0) {
      size_t halfSize = currentValueStr.size() / 2;

      // Handle if number has odd number of digits
      std::string firstHalf = currentValueStr.substr(0, halfSize);
      std::string secondHalf = currentValueStr.substr(halfSize);

      long long one = std::stoll(firstHalf);
      long long two = std::stoll(secondHalf);

      this->pebbleList.insert(idx, one);
      this->pebbleList.insert(idx, two);

      // Remove index, and update reference to iterator
      idx = this->pebbleList.erase(idx);
      // Move iterator to new last number inserted
      --idx;
      return true;
    }
    return false;
  }
  bool PebbleRow::multiplyPebbleByYear(std::list<long long>::iterator &idx) {
    long long currentValue = *idx;
    std::string currentValueStr = std::to_string(currentValue);
    if (currentValue > 0 && currentValueStr.length() % 2 != 0) {
      *idx *= 2024;
      return true;
    }
    return false;
  }
  void PebbleRow::printToConsole() {
    for (auto it = this->getStoneList().begin(); it != this->getStoneList().end(); ++it) {
      std::cout << *it << " ";
    }
    std::cout << "" << std::endl << std::endl;
  }
  int PebbleRow::getTotalStones() {
    return this->getStoneList().size();
  }

} // namespace solutions
