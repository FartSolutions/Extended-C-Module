#include <crtdbg.h>
#include <ecm/container/vector.hpp>
#include <ecm/algorithm/random.h>

#pragma warning(disable : 4996)

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	ecm::algorithm::linear_congruential rand{};

	ecm::container::vector<int> test_vec;
	test_vec.push_back(static_cast<int>(rand.next()));
	test_vec.push_back(static_cast<int>(rand.next()));
	test_vec.push_back(static_cast<int>(rand.next()));
	test_vec.push_back(static_cast<int>(rand.next()));
	test_vec.push_back(static_cast<int>(rand.next()));

	for (const auto& val : test_vec)
	{
		char numberstring[(((sizeof(val) * CHAR_BIT) + 2) / 3 + 2)];
		sprintf(numberstring, "%d", val);
		printf(numberstring);
		printf("\n");
	}

	for (int i{ 0 }; i < 5000; i++)
	{
		rand.set_seed(i);
		int val = static_cast<int>(rand.next());
		char buf[(((sizeof(val) * CHAR_BIT) + 2) / 3 + 2)];
		sprintf(buf, "%d", val);
		printf(buf);
		printf("\n");
	}

	ecm::container::free_vector<int> free_test;
	free_test.add(rand.next());
	free_test.add(rand.next());
	free_test.add(rand.next());
	free_test.add(rand.next());
	free_test.add(rand.next());
	free_test.add(rand.next());
	free_test.add(rand.next());
	free_test.add(rand.next());
	free_test.add(rand.next());
	free_test.add(rand.next());

	free_test.remove(4);

	system("pause");
	return 0;
}
