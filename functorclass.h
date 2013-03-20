#ifndef FUNCTORCLASS_H
#define FUNCTORCLASS_H

const int LIM = 6;

class FunctorClass
{
private:
  double slope;
  double y0;
  static void show(double);
public:
  FunctorClass(double sl_ = 1, double y_ = 0) : slope(sl_), y0(y_) {}
  double operator()(double);
  void FunctorFunc();
  void transform_func();
  static double average(double, double);

  void fundapcpp();
};

#endif // FUNCTORCLASS_H
