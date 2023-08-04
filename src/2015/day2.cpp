// Day 2: I Was Told There Would Be No Math

#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <sstream>
#include <fstream>

using namespace std;

// Return the cubic volume of the box
int cubicVolume(int l, int w, int h) {
  return l*w*h;
}

// Return the smallest perimeter of the box
int findSmallestPerimeter(int l, int w, int h) {
  vector<int> perimeters = {2*(l+w), 2*(w+h), 2*(h+l)};
  return *min_element(perimeters.begin(), perimeters.end());
}

// Return the total ribbon paper for one box
int calculateRequiredRibbon(int l, int w, int h) {
  return findSmallestPerimeter(l, w, h) + cubicVolume(l, w, h);
}

// Return the side with the smallest surface area of the box
int findSmallestSurfaceArea(int l, int w, int h) {
  vector<int> surfaces = {l*w, w*h, h*l};
  return *min_element(surfaces.begin(), surfaces.end());
}

// Return the surface area of the box
int calculateBoxSurfaceAera(int l, int w, int h) {
  return 2*l*w + 2*w*h + 2*h*l;
}

// Return the total wrapping paper for one box
int calculateRequiredWrappingPaper(int l, int w, int h) {
  return calculateBoxSurfaceAera(l, w, h) + findSmallestSurfaceArea(l, w, h);
}

// Return the box dimensions (l, w, h)
vector<string> getBoxDimensions(string line) {
  stringstream dimensions(line);
  string segment;
  vector<string> segDimensions;

  while(getline(dimensions, segment, 'x'))
    segDimensions.push_back(segment);

  return segDimensions;
}

// Return the total wrapping paper and ribbon to be ordered
string readElvesList(string input) {
  int wrappingPaper = 0;
  int ribbon = 0;
  ifstream elvesList(input);
  string line;

  while (elvesList >> line) {
    vector<string> dimensions = getBoxDimensions(line);
    int l = stoi(dimensions[0]);
    int w = stoi(dimensions[1]);
    int h = stoi(dimensions[2]);

    wrappingPaper += calculateRequiredWrappingPaper(l, w, h);
    ribbon += calculateRequiredRibbon(l, w, h);
  }

  return "Wrapping paper : " + to_string(wrappingPaper) + "\nRibbon : " + to_string(ribbon);
}

// Main function
int main() {
  // Input
  string elvesList = "input.txt";

  // Result
  cout << readElvesList(elvesList);
  return 0;
}
