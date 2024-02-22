#include <crtdbg.h>
#include <ecm/container/vector.hpp>
#include <ecm/algorithm/random.h>
#include <ecm/ecm_version.h>
#include <ecm/ecm_console.h>
#include <ecm/ecm_types.hpp>

namespace ec = ecm::console;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	ec::Write("Hello world!");
	ec::SetForeground(ec::ConsoleColor::LIGHTMAGENTA);
	ec::WriteLine(" This is so coooool!");
	ec::SetForeground(ec::ConsoleColor::LIGHTGRAY);

	ec::Write("\nTippe mal ne Taste an: ");
	ecm::int8 key = ec::ReadKey();
	ec::Write("\nSchreib mal nen Satz: ");
	ecm::string line = ec::ReadLine();

	ec::WriteLine(line + " " + std::to_string(key));

	ecm::Color test1{};
	ecm::Color test2{};
	test1 = test1 += test2;

	system("pause");
	return 0;
}
