#include <iostream>
#include <map>

int main(){
  std::map<int, int> m;
  m.insert({1, 2});
  m.insert({2, 4});
  m.insert({2, 5});
  m.insert({2, 11});
  m.insert({2, 12});
  m.insert({4, 5});
  m.insert({5, 5});
  // auto it = m.begin();
  std::cout << m.size() << std::endl;
}
