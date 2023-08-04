// Day 2: I Was Told There Would Be No Math

#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <sstream>
#include <fstream>

using namespace std;

// Returns the side with the smallest surface area of the box
int findSmallestSurfaceArea(int l, int w, int h) {
  vector<int> surfaces = {l*w, w*h, h*l};
  return *min_element(surfaces.begin(), surfaces.end());
}

// Returns the surface area of the box
int calculateBoxSurfaceAera(int l, int w, int h) {
  return 2*l*w + 2*w*h + 2*h*l;
}

// Returns the box dimensions (l, w, h)
vector<string> getBoxDimensions(string line) {
  stringstream dimensions(line);
  string segment;
  vector<string> segDimensions;

  while(getline(dimensions, segment, 'x'))
    segDimensions.push_back(segment);

  return segDimensions;
}

// Returns the total number of square feet of wrapping paper to be ordered
int calculateRequiredWrappingPaper(string input) {
  int squareFeet = 0;
  ifstream elvesList(input);
  string line;

  while (elvesList >> line) {
    vector<string> dimensions = getBoxDimensions(line);
    int l = stoi(dimensions[0]);
    int w = stoi(dimensions[1]);
    int h = stoi(dimensions[2]);

    squareFeet += calculateBoxSurfaceAera(l, w, h) + findSmallestSurfaceArea(l, w, h);
  }

  return squareFeet;
}

// Main function
int main() {
  // Input
  string elvesList = "input.txt";

  // Result
  cout << calculateRequiredWrappingPaper(elvesList);
  return 0;
}
