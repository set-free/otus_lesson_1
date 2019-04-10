#include "lib.h"
#include "spdlog/spdlog.h"

using namespace std;

int main()
{
  spdlog::set_pattern("%v");
  spdlog::info("build {}", version());
  spdlog::info("Hello, World!");
  return 0;
}
