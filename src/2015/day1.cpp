// Day 1: Not Quite Lisp

#include <iostream>
#include <string>

using namespace std;

// Returns the current new floor where Santa is
int changeFloor(char instruction, int currentFloor) {
  if (instruction == '(')
    // Santa goes up one floor
    return currentFloor + 1;
  else
    // Santa goes down one floor
    return currentFloor - 1;
}

// Returns the position of the first character that causes Santa to enter the basement
int findFirstBasementPositionCharacter(int currentFloor, int i) {
  // Basement = floor-1
  if (currentFloor == -1)
    // First character position = 1
    return i + 1;
  else
    return 0;
}

// Returns Santa's position information according to the instructions
string readInstructions(string instructions, int currentFloor) {
  int firstBasementPositionCharacter = 0;
  
  for (string::size_type i = 0; i < instructions.size(); i++) {
    currentFloor = changeFloor(instructions[i], currentFloor);
    
    if (firstBasementPositionCharacter == 0)
      firstBasementPositionCharacter = findFirstBasementPositionCharacter(currentFloor, i);
  }
  
  return "Current floor : " + to_string(currentFloor) + " ; First basement position character : " + to_string(firstBasementPositionCharacter);
}

// Main function
int main() {
  string puzzleInput = "";
  int currentFloor = 0;
  
  // Result
  cout << readInstructions(puzzleInput, currentFloor);
  return 0;
}