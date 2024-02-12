#include <crtdbg.h>
#include <ecm/container/vector.hpp>

#pragma warning(disable : 4996)

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	ecm::container::vector<int> test_vec;
	test_vec.push_back(18975);
	test_vec.push_back(89321);
	test_vec.push_back(98432);

	for (const auto& val : test_vec)
	{
		char numberstring[(((sizeof(val) * CHAR_BIT) + 2) / 3 + 2)];
		sprintf(numberstring, "%d", val);
		printf(numberstring);
		printf("\n");
	}

	system("pause");
	return 0;
}
