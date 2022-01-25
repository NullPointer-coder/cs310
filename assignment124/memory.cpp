/**
 * @file memory.cpp
 * @author Jingbo Wang
 * @brief  This program to declare variables and allocates memory to 
 *         initially match the diagram of memory above.
 * @date 2022-01-19
 */

#include <iostream>
using namespace std;

uint16_t foo(uint16_t a, uint16_t& b);
void bar(uint16_t& x, uint16_t& y);

int main()
{
  uint16_t i = 10;
  uint16_t& j = i;
  uint16_t k;
  k = foo(10, i);
  cout << "i: " << i << endl;
  cout << "j: " << j << endl;
  cout << "k: " << k << endl;
  return 0;
}

uint16_t foo(uint16_t a, uint16_t& b)
{
  a /= 2;
  b += 1;
  uint16_t c = 20;
  bar(b, c);
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  cout << "c: " << c << endl;
  return a + b + c;
}

void bar(uint16_t& x, uint16_t& y)
{
  x *= 2;
  y += 3;
  cout << "x: " << x << endl;
  cout << "y: " << y << endl;
}
