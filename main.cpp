#include <iostream>
#include "spdlog/spdlog.h"

using namespace std;

int main()
{
//  spdlog::info("Hello world");
// cout << "Hello World" << endl;
  auto logger = spdlog::stdout_logger_mt("console");
  logger->info("version {} was started", version());

  return 0; 
}
