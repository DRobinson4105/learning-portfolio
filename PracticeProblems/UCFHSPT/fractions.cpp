#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
  int numTests;
  cin >> numTests;

  for(int i = 0; i < numTests; i++)
  {
   int numba;
   cin >> numba;

    vector<int> vec(numba);
    for(auto& e : vec){
      cin >> e;
    }

    bool ans = false;
    for(const auto& e : vec)
    {
      for(const auto& f : vec)
        ans = ans || (f > e) * f % e;
    }
    
    cout << "Array #" << (i + 1) << ": " << (ans ? "Go away" : "This array is bae") << "!\n";
	}

  return 0;
}