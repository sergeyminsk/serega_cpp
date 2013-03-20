#ifndef MAINCLASS_H
#define MAINCLASS_H

#include "iteratorsclass.h"
#include "listclass.h"
#include "setcontainerclass.h"
#include "multimapclass.h"
#include "functorclass.h"
#include "toobig.h"
#include "patternclass.h"

static short constructorDefault;
static short destructorDefault;

class MainClass: public IteratorsClass, public SetContainerClass, public FunctorClass
{
public:
  int inches;
  MainClass();
  MainClass(double f, double s) : FunctorClass(f,s){} // send paramerers to FunctorClass constructor
  ~MainClass();
  char *getValOfChar();
  void use_ptr() const;
  typedef enum
  {
    eFirst,
    eSecond,
    eThird,
 } eNumFirst;
//  void toBinary(int);
};

#endif // MAINCLASS_H
