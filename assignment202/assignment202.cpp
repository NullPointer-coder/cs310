/**
 * @author Jingbo Wang
 * @brief  This program is
 * @date 2022-01-29
 */
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

/**
 * The purpose of foo here
 * @param array write stuff here
 */
void foo(vector<unsigned> &array);

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    cerr << "Usage: " << argv[0] <<
      " n where n is the number of values to use" << endl;
    return 1;
  }

  vector<unsigned>values;

  default_random_engine get_next_value
  (static_cast <unsigned>
    (chrono::system_clock::now().time_since_epoch().count()));

  uniform_int_distribution<unsigned> generator(0, 999999);

  unsigned number_of_values = static_cast<unsigned>(stoul(argv[1]));

  for (unsigned value = 0; value < number_of_values; value++)
  {
    values.push_back(generator(get_next_value));
  }

/*
  values.push_back(10);
  values.push_back(9);
  values.push_back(8);
  values.push_back(7);
  values.push_back(11);
  values.push_back(5);
  values.push_back(4);
  values.push_back(3);
  values.push_back(2);
  values.push_back(1);
  */
  foo(values);

  for (auto v : values)
  {
    cout << v << ' ';
  }
  cout << endl;
  return 0;
}

void foo(vector<unsigned>& array)
 {
  unsigned count = 0;
  size_t n = array.size();
  count++;   // argument n
  for (size_t start = 0; start < n - 1; start++)
  {
    count += 2;  // for loop header
    unsigned item = array.at(start);
    count++;   // argument item
    size_t position = start;
    count++;  // argument position

    for (size_t index = start + 1; index < n; index++)
    {
      count += 2;  // for loop header
      if (array.at(index) < item)
      {
        position++;
        count++;  // position++
      }
      count++; // if statement header
    }
    count += 2;  // last time for loop

    count++;  // if statement header
    if (position != start)
    {
      while (item == array.at(position))
      {
        count++;  //while statement header
        position++;
        count++;  // position++
      }
      count++;  // while statement header

      swap(array.at(position), item);
      count += 2;  // swap fuction

      while (position != start)
      {
        count++;  //while statement
        position = start;
        count++;  // count++ for position
        for (size_t index = start + 1; index < n; index++)
        {
          count+= 2;  // for loop
          if (array.at(index) < item)
          {
            position++;
            count++;  // position++
          }
          count++;  // if statement header
        }
        count += 2; // last timefor loop

        while (item == array.at(position))
        {
          count++;  // while statement header
          position++;
          count++;  // position++
        }
       count++; // while statement header

        swap(array.at(position), item);
        count +=2;  // swap fuction
      }
      count++; // while statement header
    }
  }
  count += 2;  // last tme for loop

  cerr <<  n  << " " << count << endl;
 }
