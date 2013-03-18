#ifndef PATTERN_H_
#define PATTERN_H_



template <class T1, class T2, class T3> 
class PatternClass
{
public:
  T3 divine(T1, T2);
  double argDivine(short, short);
  template <class T> void swap(T &a, T &b) { T temp;    temp = a;    a = b;    b = temp;   }
};


template <class T1, class T2, class T3> T3 PatternClass<T1,T2,T3>::divine(T1 firstVar, T2 secondVal)
{
  return (T3)firstVar/secondVal;
}

template <class T1, class T2, class T3> double PatternClass<T1,T2,T3>::argDivine(short aValue, short bValue)
{
  PatternClass<short,short,float>w;
  return w.divine(aValue, bValue);
}



#endif