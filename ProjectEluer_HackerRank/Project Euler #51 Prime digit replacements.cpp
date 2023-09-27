#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;

unsigned int maxDigits = 7;
unsigned int replace   = 3;
unsigned int siblings  = 7;

map<string, vector<unsigned int>> matches;

unsigned int smallestPrime = 99999999;

void match(unsigned int number, string& regex, unsigned int digit, unsigned int howOften, unsigned int startPos = 0){
  char asciiDigit = digit + '0';

  for (unsigned int i = startPos; i < maxDigits; i++) {
    if (regex[i] != asciiDigit)
      continue;

    if (i == 0 && asciiDigit == '0')
      continue;

    regex[i] = '.';

    if (howOften == 1)  {
      auto& addTo = matches[regex];
      addTo.push_back(number);
      if (addTo.size() >= siblings && addTo.front() < smallestPrime)
        smallestPrime = addTo.front();
    }
    else  {
      match(number, regex, digit, howOften - 1, i + 1);
    }

    regex[i] = asciiDigit;
  }
}


int main(){
  cin >> maxDigits >> replace >> siblings;

  unsigned int minNumber = 1;
  for (unsigned int i = 1; i < maxDigits; i++)
    minNumber *= 10;
  unsigned int maxNumber = minNumber * 10 - 1;

 
vector<bool> primes(maxNumber, true);
  primes[0] = primes[1] = false;
  for (unsigned int i = 2; i*i <= maxNumber; i++)
    if (primes[i])
      for (unsigned j = 2*i; j <= maxNumber; j += i)
        primes[j] = false;
        
  for (unsigned int i = minNumber; i <= maxNumber; i++)
    if (primes[i])  {
      auto strNum = std::to_string(i);

      for (unsigned int digit = 0; digit <= 9; digit++)
        match(i, strNum, digit, replace);

      if (maxDigits == 7)   {
        if (replace == 1 && i > 2000000)
          break;
        if (replace == 2 && i > 3000000)
          break;
      }
    }
string minimum;
  for (auto m : matches){
    if (m.second.size()  < siblings)
      continue;
    if (m.second.front() != smallestPrime)
      continue;
   string s;
    for (unsigned i = 0; i < siblings; i++)
      s += to_string(m.second[i]) + " ";

  
    if (minimum > s || minimum.empty())
      minimum = s;
  }

  cout << minimum << endl;
}