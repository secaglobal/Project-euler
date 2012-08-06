#include <iostream>
#include <cstring>
#include <cmath>

template <class T>
bool isPrime(T num)
{
  T limit = num / 2;
  for (T i = 2; i <= limit; ++i)
  {
    if (num % i == 0)
    {
      return false;
    }
  }

  return true;
}

void testIsPrimeSimple()
{
  struct Case {
    int value;
    bool expectation;
    Case(int val, bool exp = true) : value(val), expectation(exp) {}; 
  };

  Case cases[] = {Case(0), Case(1), Case(2), Case(4, false), Case(144, false), Case(17, true)};

  for (size_t i = 0; i < sizeof(cases) / sizeof(Case); ++i) {
    bool expectation = cases[i].expectation;
    bool result = isPrime(cases[i].value);    

    if (result != expectation) {
      std::cout << "Error in isPrime test. Value " << cases[i].value << " . Expectation: " << (expectation ? "True" : "False") << " Result: " << (result ? "True" : "False") << std::endl;
    } else {
      std::cout << "isPrime test case success. Value: " << cases[i].value << std::endl;
    }
  }
}

void test()
{
  typedef void (*testCaseFn)(void);
  testCaseFn cases[] = {
    &testIsPrimeSimple,
  };

  for (size_t i = 0; i < sizeof(cases) / sizeof(testCaseFn); ++i)
  {
    cases[i]();
  }
}


int main(int argc, const char** argv)
{
  if (argc > 1 && !std::strcmp(argv[1], "testMode")) {
    test();
  } else {
  }

  return 0;
}

