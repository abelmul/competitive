#include <cstdio>
#include <iostream>
#include <set>
#include <string>
#include <tuple>
#include <utility>

int main() {
  std::string line;

  std::set<std::pair<int, int>> houses;
  int x_santa = 0, y_santa = 0;
  int x_robosanta = 0, y_robosanta = 0;
  bool isSanta = true;

  houses.insert(std::pair<int, int>(0, 0));

  std::getline(std::cin, line);

  for (auto c : line) {
    int *x = isSanta ? &x_santa : &x_robosanta;
    int *y = isSanta ? &y_santa : &y_robosanta;

    switch (c) {
    case '^':
      ++(*y);
      break;
    case 'v':
      --(*y);
      break;
    case '>':
      ++(*x);
      break;
    case '<':
      --(*x);
      break;
    }

    houses.insert(std::pair<int, int>(*x, *y));

    isSanta = !isSanta;
  }

  std::printf("%lu houses get gifts.\n", houses.size());

  return 0;
}
