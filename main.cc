#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> split(const std::string &str, char d) {
  std::vector<std::string> r;

  std::string::size_type start = 0;
  std::string::size_type stop = str.find_first_of(d);
  while (stop != std::string::npos) {
    r.push_back(str.substr(start, stop - start));

    start = stop + 1;
    stop = str.find_first_of(d, start);
  }

  r.push_back(str.substr(start));

  return r;
}

std::vector<int> parseIp(const std::string &str) {
  std::vector<int> r;
  auto delim{'.'};

  std::string::size_type start = 0;
  std::string::size_type stop = str.find_first_of(delim);
  while (stop != std::string::npos) {
    r.push_back(std::stoi(str.substr(start, stop - start)));

    start = stop + 1;
    stop = str.find_first_of(delim, start);
  }

  r.push_back(std::stoi(str.substr(start)));

  return r;
}

/*
 * Напечатать IP-адрес в формате: XXX.XXX.XXX.XXX
 */
std::ostream &operator<<(std::ostream &out, const std::vector<int> &ip) {
  for (auto it = ip.begin(); it != ip.end(); ++it) {
    if (it != ip.begin()) {
      out << ".";
    }
    out << *it;
  }

  return out;
}

int main(int argc, char *argv[]) {
  try {
    std::vector<std::vector<int>> ip_pool;

    for (std::string line; std::getline(std::cin, line);) {
      std::vector<std::string> v = split(line, '\t');

      ip_pool.push_back(parseIp(v.at(0)));
    }

    std::sort(ip_pool.begin(), ip_pool.end(),
              [](const std::vector<int> &a, const std::vector<int> &b) {
                auto its = std::mismatch(a.begin(), a.end(), b.begin());
                return not(*its.first < *its.second);
              });

    for (auto &ip : ip_pool) {
      std::cout << ip << std::endl;
    }

    for_each(ip_pool.begin(), ip_pool.end(), [](const std::vector<int> &ip) {
      if (ip.at(0) == 1) {
        std::cout << ip << std::endl;
      }
    });

    for_each(ip_pool.begin(), ip_pool.end(), [](const std::vector<int> &ip) {
      if (ip.at(0) == 46 and ip.at(1) == 70) {
        std::cout << ip << std::endl;
      }
    });

    for_each(ip_pool.begin(), ip_pool.end(), [](const std::vector<int> &ip) {
      if (std::any_of(ip.begin(), ip.end(),
                      [](int part) { return part == 46; })) {
        std::cout << ip << std::endl;
      }
    });
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
