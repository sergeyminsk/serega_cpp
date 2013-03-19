#ifndef ALGORITHMCLASS_H
#define ALGORITHMCLASS_H

class AlgorithmClass
{
public:
  void algorithm();
  /* copy() function */
  template<class Inputlterator, class Outputlterator> 
  Outputlterator copy(Inputlterator first, Inputlterator last, Outputlterator result);
};

#endif // ALGORITHMCLASS_H

