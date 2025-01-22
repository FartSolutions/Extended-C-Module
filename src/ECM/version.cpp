#include <ECM/ecm_version.h>

namespace ecm
{
	version GetVersion(void)
	{
		version v{};
		ECM_VERSION(&v);
		return v;
	}

	int32 GetVersionNumber(void)
	{
		version v{};
		ECM_VERSION(&v);
		return ECM_VERSIONNUMV(v);
	}
} // namespace ecm
