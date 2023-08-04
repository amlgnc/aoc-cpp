// Day 3: Perfectly Spherical Houses in a Vacuum

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
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
int getUniqueHousesVisited(string directions) {
  vector<vector<int>> visitedHouses = {{0,0}};
  vector<int> currentCoordinates = {0,0};

  for (string::size_type i = 0; i < directions.size(); i++) {
    vector<int> newCoordinates = travel(currentCoordinates, directions[i]);

    if (find(visitedHouses.begin(), visitedHouses.end(), newCoordinates) == visitedHouses.end()) {
      visitedHouses.push_back(newCoordinates);
    }

    currentCoordinates = newCoordinates;
  }

  return visitedHouses.size();
}

// Main function
int main() {
  ifstream input("input.txt");

  int uniqueVisitedHouses = 0;

  string text;
  while (input >> text) {
    uniqueVisitedHouses += getUniqueHousesVisited(text);
  }

  cout << to_string(uniqueVisitedHouses);
  return 0;
}
