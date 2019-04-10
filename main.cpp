#include "lib.h"
#include "spdlog/spdlog.h"

using namespace std;

int main()
{
  spdlog::info("build {}", version());
  spdlog::info("Hello, World!");
  return 0;
}
