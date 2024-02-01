#include "ecm/ecm_version.h"

namespace ecm
{
	Version GetVersion(void)
	{
		Version v{};
		ECM_VERSION(v);
		return v;
	}

	int32 GetVersionNumber(void)
	{
		Version v{};
		ECM_VERSION(v);
		return ECM_VERSIONNUMV(v);
	}
} // namespace ecm
