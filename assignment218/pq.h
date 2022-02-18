/**
 * Provide a priority queue based on an unsorted vector.
 * This implementation also provides a field for counting basic operations.
 * @author Jingbo Wang
 * @version  18 Feb
 */

#ifndef MY_PQ
#define MY_PQ

#include <cassert>
#include <cstdint>
#include <climits>
#include <vector>

class PriorityQueue
{
 public:
  /**
   * Construct an empty priority queue
   */
  PriorityQueue() : op_count{0} {}

  /**
   * Insert a priority into the PQ
   * @param priority the priority of the inserted job
   */
  void push(unsigned priority)
  {
    array.push_back(priority);
    op_count++; // one operation for push_back

    bubble_up(size() - 1);
    op_count++; // bubble_up function call
  }

  /**
   * Remove and return the maximum-priority job in the queue.
   * @return the priority of the removed job
   */
  unsigned pop()
  {
    unsigned max_value = array.at(0);
    op_count += 2;  // an element assignment

    array.at(0) = array.at(size() - 1);
    op_count += 3; // an element assignment

    array.pop_back();
    op_count++; //pop_back function call

    percolate_down(0);
    op_count ++; // percolate_down function call
    return max_value;
  }

  /**
   * Report if the queue is empty
   * @return true if empty, false otherwise
   */
  bool is_empty() const
  {
    return array.empty();
  }

  /**
   * Report the number of elements in the queue
   * @return the number of elements
   */
  size_t size() const
  {
    return array.size();
  }

  /**
   * Return the number of basic operations counted so far
   * @return the count of basic operations
   */
  uint64_t get_op_count() const
  {
    return op_count;
  }

 private:
  std::vector<unsigned> array;
  uint64_t op_count;

  /**
   * Bubble up the last place value in the vecter to right place
   * @param position the position of value in the vector needs
   * to be bubbled up
   */
  void bubble_up(size_t position)
  {
    if (position > 0)
    {
      if (array.at(position) > array.at((position - 1 ) / 2))
     {
        std::swap(array.at(position), array.at((position - 1) / 2));
        op_count += 2; //swap function call
      }
      op_count += 4; // if statement header

      size_t parent = (position - 1)  /  2;
      op_count += 3; // an element assignment
      bubble_up(parent);
    }
    op_count++;  // if statement header
  }

/**
 * percolate_down the first place value in the heep tree
 * to right place
 * @param parent the position of value in the heep tree
 */
  void percolate_down(size_t parent)
  {
    if ( (parent * 2 + 2) < size() && !is_finish(parent))
    {
      size_t position = array.at(parent * 2 + 1)
                                 >= array.at(parent * 2 + 2)?
                                     (parent * 2 + 1) : (parent * 2 + 2);
      op_count += 8; // an element assignment
      if (position == (parent * 2 + 1))
      {
        std::swap(array.at(parent), array.at( parent * 2 + 1));
        op_count += 2; //swap function call
        parent =  parent * 2 + 1;
        op_count += 3; // an element assignment
      }
      else
      {
        std::swap(array.at(parent), array.at( parent * 2 + 2));
        op_count += 2; //swap function call
        parent =  parent * 2 + 2;
        op_count += 3; // an element assignment
      }
      op_count += 3; // if statement header
      percolate_down(parent);
    }
    op_count += 5; // if statement header
    if ((parent * 2 + 2) == size()
          && array.at(parent) < array.at(parent * 2 + 1))
    {
        std::swap(array.at(parent), array.at( parent * 2 + 1));
        op_count++; // swap function call
    }
    op_count += 8; // if statement function call
  }

/**
 * to boolean procalate_down function finished or not
 * @param position the position of value in the heep tree
 * @return if true the procalate_down function finished,
 * othewise is false
 */
  bool is_finish(size_t position)
  {
    bool done = array.at(position) > array.at(position * 2 + 1)
                        &&  array.at(position)> array.at(position * 2 + 2)?
                      true : false;
    op_count += 12;  // an element assignment
    return done;
  }
};
#endif
