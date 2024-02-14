#include <crtdbg.h>
#include <ecm/container/vector.hpp>
#include <ecm/algorithm/random.h>
#include <ecm/ecm_version.h>

#pragma warning(disable : 4996)

class person
{
public:
	person() : _id{ (ecm::uint32)-1 } {}
	person(ecm::uint32 id) : _id{ id } {}
	~person() {}
private:
	ecm::uint32 _id;
};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	printf("%x", ecm::GetVersionNumber());
	printf("\n");
	printf("%x", ECM_VERSIONNUM(1, 2, 3));
	printf("\n");
	
	system("pause");
	return 0;
}
