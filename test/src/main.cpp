#include <bandit/bandit.h>
#include <filesystem>

using namespace snowhouse;
using namespace bandit;


int main(int argc, char* argv[]) {
  // Run the tests.
  return bandit::run(argc,argv);
}
