#ifndef TOOBIG_H
#define TOOBIG_H

#include "patternclass.h"
#include "functorclass.h"
#include <iostream>

template<class T>
class TooBig
{
private:
  T cutoff;
public:
  TooBig(const T &t) : cutoff(t) {}
  bool operator()(const T &v) { return v > cutoff; }
  void FunctorFunc();
  bool tooBig(const T &, const T &);
};

template<class T>
class TooBig2
{
private:
  T cutoff;
public:
  TooBig2(const T & t) : cutoff(t) {}
  bool operator()(const T & v) { return TooBig<T>::toobig(v, cutoff); }
};


/* 
 *  implementing "void FunctorFunc();"
 * 
 */
template <class T>void TooBig<T>::FunctorFunc()
{
  FunctorClass f1;
  double y1 = f1(12.5);
  
  FunctorClass f2(2.5, 10.0);
  double y2 = f2(12.5);
  
  std::cout << "f1(12.5)\t" 	<< f1(12.5) 
	    << "\nf2(12.5)\t" 	<< f2(12.5) << "\n";
}


template<class T>bool TooBig<T>::tooBig(const T & val, const T & lim)
{
  return val > lim;
}







#endif // TOOBIG_H
