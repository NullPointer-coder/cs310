/**
 * to count the number of collisions the algorithm produces when the words are hashed.
 * @author Jingbo Wang
 * @version 2022-3-4
 */

#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

/**
 * to get the hash number by hash function h(x) = key mod TABLE_SIZE
 * @param key an input string value which need to get hash number
 * @param table_size the size of hash table
 * @return size_t the hash number of input string value
 */
size_t hashx(const string& key, size_t table_size);

int main()
{
  const unsigned TABLE_SIZE = 102409;
  string word;
  size_t hash_num = 0;
  unsigned collisions_sum = 0;
  vector<unsigned> hash_array(TABLE_SIZE, 0);
  while (getline(cin, word))
  {
    hash_num = hashx(word, TABLE_SIZE);
    hash_array.at(hash_num)++;
    if(hash_array.at(hash_num) > 1)
    {
      collisions_sum++;
    }
  }
  cout << "The number of collisions: " << collisions_sum << endl;
  return 0;
}

size_t hashx(const string& key, size_t table_size)
{
  size_t hash_value = 1;
  for (auto character : key)
  {
    hash_value = 43 * hash_value + static_cast<size_t>(character);
  }
  return hash_value % table_size;
}
