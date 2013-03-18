#include "functorclass.h"
#include "toobig.h"
#include "iteratorsclass.h"

#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <iterator>
#include <cmath>
#include <functional>

double FunctorClass::operator()(double x)
{
  return y0 + slope * x;
}

void FunctorClass::FunctorFunc()
{
  TooBig<int> f100(100);
  int vals[10] = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
  std::list<int> yadayada(vals, vals + 10);
  std::list<int> etcetera(vals, vals + 10);
  
  std::cout << "Original list:\n\t\t";
  for_each(yadayada.begin(), yadayada.end(), IteratorsClass::outputint);
  std::cout << "\n\t\t";
  for_each(etcetera.begin(), etcetera.end(), IteratorsClass::outputint);
  std::cout << "\n";
  
  yadayada.remove_if(f100);
  etcetera.remove_if(TooBig<int>(200));
  
  std::cout << "Trimmed list:\n\t\t";
  for_each(yadayada.begin(), yadayada.end(), IteratorsClass::outputint);
  std::cout << "\n\t\t";
  for_each(etcetera.begin(), etcetera.end(), IteratorsClass::outputint);
  std::cout << "\n";
  
}

void FunctorClass::transform_func()
{
  
  const int LIM = 5;
  double arrl[LIM] = {36, 39, 42, 45, 48};
  double arr2[LIM] = {64, 61, 58, 55, 52};
  std::vector<double> m8(arr2, arr2 + LIM);
  std::vector<double> gr8(arrl, arrl + LIM);
  std::ostream_iterator<double, char> out(std::cout, "\t");
  std::cout << "simply container:\n\t";
  copy(gr8.begin(), gr8.end(), out);
  std::cout << "\n\t";
  copy(m8.begin(), m8.end(), out);
  std::cout << "\nsqrt:\n\t";
  transform(gr8.begin(), gr8.end(), out, sqrt);
  std::cout << "\naverage:\n\t";
  transform(gr8.begin(), gr8.end(), m8.begin(), out, average);
  std::cout << "\nstd::plus<double>()\n\t";
  transform(gr8.begin(), gr8.end(), m8.begin(), out, std::plus<double>());
  std::cout << "\nstd::minus<double>()\n\t";
  transform(gr8.begin(), gr8.end(), m8.begin(), out, std::minus<double>());
  std::cout << "\nstd::multiplies<double>()\n\t";
  transform(gr8.begin(), gr8.end(), m8.begin(), out, std::multiplies<double>()); // or times, for old realization
  std::cout << "\nstd::divides<double>()\n\t";
  transform(gr8.begin(), gr8.end(), m8.begin(), out, std::divides<double>());
  std::cout << "\nstd::greater<double>()\t(it means '>')\n\t";
  transform(gr8.begin(), gr8.end(), m8.begin(), out, std::greater<double>()); // it means '>'
  std::cout << "\nstd::less<double>()\t(it means '<')\n\t";
  transform(gr8.begin(), gr8.end(), m8.begin(), out, std::less<double>()); // it means '<'
/*
+	plus
-	minus
*	multiplies	// or times, for old realization
/	divides
%	modulus
-	negate
==	equal_to
!=	not_equal_to
>	greater
<	less
>=	greater_equal
<=	less_equal
&&	logical_and
||	logical_or
!	logical_not

*/
}

double FunctorClass::average(double first, double second)
{
  return (first + second)/2;
}

void FunctorClass::show(double v)
{
  std::cout.width(6);
  std::cout << v << ' ';
}

void FunctorClass::fundapcpp()
{
  double arrl[LIM] = {1, 2, 3, 4, 5, 6};
  double arr2[LIM] = {7, 8, 9, 1, 2, 3};
  std::vector<double> gr8(arrl, arrl + LIM);
  std::vector<double> m8(arr2, arr2 + LIM);
  std::cout.setf(std::ios_base::fixed);
  std::cout.precision(2); // number of numbers after dot
  std::cout << "gr8:\t";
  for_each(gr8.begin(), gr8.end(), show);
  std::cout << std::endl;
  std::cout << "m8: \t";
  for_each(m8.begin (), m8.end(), show);
  std::cout << std::endl;

  std::vector<double> sum(LIM);
  transform(gr8.begin (), gr8.end(), m8.begin(), sum.begin(), std::plus<double> ());
  std::cout << "sum:\t";
  for_each(sum.begin (), sum.end(), show);
  std::cout << std::endl;
  
  std::vector<double> prod(LIM);
  transform(gr8.begin (), gr8.end(), prod.begin(), bind1st(std::multiplies<double> (), 2.5));

  std::cout << "prod:\t";
  for_each(prod.begin (), prod.end(), show);
  std::cout << std::endl;

}

