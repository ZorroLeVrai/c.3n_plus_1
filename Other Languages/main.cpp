#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef unsigned int uint;

int transform(uint previous)
{
  if (previous & 1)
    // if previous is an odd number
    return 3 * previous + 1;

  // divide previous by 2
  return previous >> 1;
}

vector<uint> getSeries(uint number)
{
  vector<uint> result;
  result.push_back(number);
  while (number != 1)
  {
    number = transform(number);
    result.push_back(number);
  }

  return result;
}

string seriesToString(vector<uint> numbers)
{
  string result = "[";
  auto separatorNeeded = false;

  for (auto number : numbers)
  {
    if (separatorNeeded)
      result.append(", ");
    else
      separatorNeeded = true;

    result.append(to_string(number));
  }

  result.append("]");
  return result;
}

int main()
{
  auto numbers = getSeries(1025);
  auto stringResult = seriesToString(numbers);

  cout << stringResult << endl;
}