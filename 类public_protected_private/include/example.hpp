#ifndef EXAMPLE_HPP
#define EXAMPLE_HPP

/*
*
* public：所有均可访问
* protected：类自己以及子类访问，不能被类对象访问
* private：类自己的成员函数访问，不能被类对象访问
*
*
*/
class Value
{

public:
  Value(int value) : price(value){}

  int getPrice()
  {
    return price;
  }

protected:
  void setPrice(int val)
  {
    price = val;
  }
private:
  int price;
};

class Ring : public Value
{
public:
  Ring(int price=0):Value(price){}
  int getRingPrice()
  {
    return getPrice();
  }
  void setRingPrice(int val)
  {
    setPrice(val);
  }

};

#endif