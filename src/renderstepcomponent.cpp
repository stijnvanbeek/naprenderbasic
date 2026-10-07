#include "renderstepcomponent.h"

#include <nap/core.h>
#include <entity.h>

RTTI_BEGIN_CLASS(nap::RenderStepComponent)
	RTTI_PROPERTY("RenderStep", &nap::RenderStepComponent::mRenderStep, nap::rtti::EPropertyMetaData::Required)
RTTI_END_CLASS

RTTI_BEGIN_CLASS_NO_DEFAULT_CONSTRUCTOR(nap::RenderStepComponentInstance)
	RTTI_CONSTRUCTOR(nap::EntityInstance&, nap::Component&)
RTTI_END_CLASS

namespace nap
{

	bool RenderStepComponentInstance::init(utility::ErrorState& errorState)
	{
		mRenderableComponent = getEntityInstance()->findComponent<RenderableComponentInstance>();
		if (mRenderableComponent == nullptr)
		{
			errorState.fail("RenderStepComponent %s: no RenderableComponent found", mID.c_str());
			return false;
		}

		mResource = getComponent<RenderStepComponent>();
		mResource->mRenderStep->registerComponent(*mRenderableComponent);
		return true;
	}


	void RenderStepComponentInstance::onDestroy()
	{
		mResource->mRenderStep->unregisterComponent(*mRenderableComponent);
	}

}
