#include "renderbasicservice.h"

#include <nap/core.h>

RTTI_BEGIN_CLASS_NO_DEFAULT_CONSTRUCTOR(nap::RenderBasicService)
	RTTI_CONSTRUCTOR(nap::ServiceConfiguration*)
RTTI_END_CLASS

namespace nap
{

	bool RenderBasicService::init(utility::ErrorState &error)
	{
		mRenderService = getCore().getService<RenderService>();
		return true;
	}


	void RenderBasicService::render()
	{
	}

}
