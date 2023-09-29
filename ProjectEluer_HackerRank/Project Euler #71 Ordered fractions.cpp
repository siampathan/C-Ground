#include <iostream>


template <typename T>
void multiply(T a, T b, T& result_high, T& result_low){
  const T Shift = 4 * sizeof(a);
  const T Mask  = T(~0) >> Shift;

  auto a_high = a >> Shift;
  auto a_low  = a &  Mask;
  auto b_high = b >> Shift;
  auto b_low  = b &  Mask;

  auto c_0  = a_low  * b_low;
  auto c_1a = a_high * b_low;
  auto c_1b = a_low  * b_high;
  auto c_2  = a_high * b_high;

  auto carry = ((c_0 >> Shift) + (c_1a & Mask) + (c_1b & Mask)) >> Shift;

  result_high = c_2 + (c_1a >> Shift) + (c_1b >> Shift) + carry;
  result_low  = c_0 + (c_1a << Shift) + (c_1b << Shift);
}

bool isLess(unsigned long long a, unsigned long long b, unsigned long long c, unsigned long long d){
 

  unsigned long long r1_high, r1_low;
  unsigned long long r2_high, r2_low;
  multiply(a, d, r1_high, r1_low);
  multiply(c, b, r2_high, r2_low);

  if (r1_high < r2_high)
    return true;
  if (r1_high > r2_high)
    return false;

  return (r1_low < r2_low);
}

int main(){
  unsigned int tests = 1;
  std::cin >> tests;
  while (tests--) {
    unsigned int a = 3;
    unsigned int b = 7;
    unsigned long long limit = 1000000;
    std::cin >> a >> b >> limit;

   
    unsigned long long leftN  = 0;
    unsigned long long leftD  = 1;
    unsigned long long rightN = 1;
    unsigned long long rightD = 1;
    while (leftD + rightD <= limit){
      auto mediantN = leftN + rightN;
      auto mediantD = leftD + rightD;

      if (isLess(mediantN, mediantD, a, b)){
        leftN = mediantN;
        leftD = mediantD;
      }
      else {
        rightN = mediantN;
        rightD = mediantD;
        if (rightN == a && rightD == b)
          break;
      }
    }

    if (limit >= leftD + rightD){
      auto difference = limit - (leftD + rightD);
      auto repeat = 1 + difference / rightD;
      leftN += repeat * rightN;
      leftD += repeat * rightD;
    }

    std::cout << leftN << " " << leftD << std::endl;
  }
}