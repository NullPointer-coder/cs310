// create a number of rectangles specified on the command line of
// random lengths and widths
// Jingbo Wang
// 2022-1-10

#include <chrono>
#include <iostream>
#include <random>
using namespace std;

 /**
  * compute the area of a rectangle
  * @param length the length of the rectangle
  * @param width the width of the rectangle
  * @return the area of a length X width rectangle 
  */
  unsigned get_rectangle_area(unsigned length, unsigned width);

  int main(int argc, char** argv)
  {
    const unsigned MAX_WIDTH = 75;
    const unsigned MAX_LENGTH = 500;

    if (argc != 2)
    {
      cerr << "Usage: " << argv[0] <<
        " n where n is the number of rectangles to generate" << endl;
      return 1;
    }

    // Set up two random number generators
    default_random_engine get_next_value
      (static_cast <unsigned>
       (chrono::system_clock::now().time_since_epoch().count()));

    uniform_int_distribution<unsigned> width_generator(1, MAX_WIDTH);
    uniform_int_distribution<unsigned> length_generator(1, MAX_LENGTH);

    unsigned number_of_rectangles = static_cast<unsigned>(stoul(argv[1]));

    for (unsigned rectangle = 0; rectangle < number_of_rectangles; rectangle++)
    {
      unsigned width = width_generator(get_next_value);
      unsigned length = length_generator(get_next_value);
      unsigned area = get_rectangle_area(length, width);

      cout << "The area of a " << width << " by " << length <<
        " rectangle is " << area << endl;
    }
    return 0;
  }

  unsigned get_rectangle_area(unsigned length, unsigned width)
  {
    return length * width;
  }
   