#include <ecm/window/context.hpp>

namespace ecm
{
	namespace
	{
		static ContextBase* currentContext = nullptr;
	} // anonymous namespace

	void SetCurrentContext(ContextBase* context)
	{
		currentContext = context;
	}

	ContextBase* GetCurrentContext()
	{
		return currentContext;
	}
} // namespace ecm
