#ifndef ITERATORSCLASS_H
#define ITERATORSCLASS_H

#include <string>

typedef double * iterator;

struct Node
{
  double item;
  Node *p_next;
};

class IteratorsClass
{
public:
  void ostream_iterator_func();
  void back_insert_iterator_func();
  static void output(const std::string&);
  static void outputchar(const char&);
  static void outputint(const int&);
  iterator find_ar(double*,int, const double&);
  void insert_iterator_func();
  void fill_of_queue();
  void input_by_cin();
};

#endif // ITERATORSCLASS_H
