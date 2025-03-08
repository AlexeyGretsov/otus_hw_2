#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {
  std::vector<std::string> ips = {"111.2.3.4", "111.3.1.1", "111.2.2.1",
                                  "111.2.3.3", "127.0.0.1", "11.3.4.5"};

  std::sort(ips.begin(), ips.end(),
            [](const std::string &a, const std::string &b) -> bool {
              return std::lexicographical_compare(a.begin(), a.end(), b.begin(),
                                                  b.end());
            });

  std::cout << "Sorted IP-addressses" << std::endl;
  for (auto &ip : ips) {
    std::cout << "IP: " << ip << std::endl;
  }

  return 0;
}
