#include "../headers/map_cpp.h"

TEST(Map_test, init) {
  Map<int, int> map;
  EXPECT_EQ(map.size(), 0);
}

TEST(Map_test, insert1) {
  Map<int, int> map;
  map.insert({1, 2});
  EXPECT_EQ(map.size(), 1);
}

TEST(Map_test, insert2) {
  Map<int, int> map;
  map.insert({4, 5});
  map.insert({2, 3});
  map.insert({3, 1});
  map.insert({3, 5});
  EXPECT_EQ(map.size(), 4);
}

TEST(Map_test, iterator) {
  Map<int, int> map;
  map.insert({4, 5});
  map.insert({2, 3});
  map.insert({3, 1});
  map.insert({5, 7});

  auto it = map.begin();
  EXPECT_EQ(it->first, 4);
  EXPECT_EQ(it->second, 5);
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
