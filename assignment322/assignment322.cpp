#include <algorithm>
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include "avl.h"

using namespace std;

int main(int argc, char** argv)
{
  if (argc != 2)
  {
    cerr << "Usage: " << argv[0] <<
      " n where n is the number of values to insert" << endl;
    return 1;
  }

  size_t number_of_values = static_cast<size_t>(stoul(argv[1]));

  vector<unsigned> values(number_of_values);

  for (size_t index = 0; index < number_of_values; index++)
  {
    values.at(index) = static_cast<unsigned>(index);
  }
  unsigned seed =
    static_cast<unsigned>
      (chrono::system_clock::now().time_since_epoch().count());

  shuffle(values.begin(), values.end(), default_random_engine(seed));

  AVLTree<unsigned> avl;

  for (auto value : values)
  {
    avl.insert(value);
  }

  cerr << number_of_values << ' ' << avl.height() << endl;
  avl.print_tree();
  return 0;
}
