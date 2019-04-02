#include <iostream>
#include "lib.h"
#include "version.h"

int version()
{
  std::cout << "PROJECT_VERSION_PATCH: " << PROJECT_VERSION_PATCH;
  return PROJECT_VERSION_PATCH;
}
