// Day 3: Perfectly Spherical Houses in a Vacuum

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Returns the new coordinates
vector<int> travel(vector<int> c, char direction) {
  vector<int> newCoordinates;

  switch (direction) {
    case '>':
      newCoordinates = {c[0]+1, c[1]};
      break;
    case '<':
      newCoordinates = {c[0]-1, c[1]};
      break;
    case '^':
      newCoordinates = {c[0], c[1]-1};
      break;
    case 'v':
      newCoordinates = {c[0], c[1]+1};
      break;
    default:
      newCoordinates = {c[0], c[1]};
      break;
  }

  return newCoordinates;
}

// Returns the number of houses that received at least one gift
int getUniqueHousesVisited(string directions, bool roboSanta) {
  vector<vector<int>> visitedHouses = {{0,0}};
  vector<int> currentSantaCoordinates = {0,0};
  vector<int> currentRoboCoordinates = {0,0};
  bool roboTurn = false;

  for (string::size_type i = 0; i < directions.size(); i++) {
    vector<int> newCoordinates;

    if (roboSanta && roboTurn) {
      newCoordinates = travel(currentRoboCoordinates, directions[i]);
      currentRoboCoordinates = newCoordinates;
    }
    else {
      newCoordinates = travel(currentSantaCoordinates, directions[i]);
      currentSantaCoordinates = newCoordinates;
    }

    if (find(visitedHouses.begin(), visitedHouses.end(), newCoordinates) == visitedHouses.end())
      visitedHouses.push_back(newCoordinates);

    roboTurn = !roboTurn;
  }

  return visitedHouses.size();
}

// Main function
int main() {
  ifstream input("input.txt");

  int uniqueVisitedHouses = 0;
  bool roboSanta = true;

  string text;
  while (input >> text)
    uniqueVisitedHouses += getUniqueHousesVisited(text, roboSanta);

  cout << to_string(uniqueVisitedHouses);
  return 0;
}
