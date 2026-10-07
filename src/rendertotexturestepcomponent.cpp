#include "rendertotexturestepcomponent.h"

#include <nap/core.h>
#include <entity.h>

RTTI_BEGIN_CLASS(nap::RenderToTextureStepComponent)
	RTTI_PROPERTY("RenderStep", &nap::RenderToTextureStepComponent::mRenderStep, nap::rtti::EPropertyMetaData::Required)
RTTI_END_CLASS

RTTI_BEGIN_CLASS_NO_DEFAULT_CONSTRUCTOR(nap::RenderToTextureStepComponentInstance)
	RTTI_CONSTRUCTOR(nap::EntityInstance&, nap::Component&)
RTTI_END_CLASS

namespace nap
{

	bool RenderToTextureStepComponentInstance::init(utility::ErrorState& errorState)
	{
		mRenderToTextureComponent = getEntityInstance()->findComponent<RenderToTextureComponentInstance>();
		if (mRenderToTextureComponent == nullptr)
		{
			errorState.fail("RenderToTextureStepComponent %s: no RenderToTextureComponent found", mID.c_str());
			return false;
		}

		mResource = getComponent<RenderToTextureStepComponent>();
		mResource->mRenderStep->registerComponent(*mRenderToTextureComponent);
		return true;
	}


	void RenderToTextureStepComponentInstance::onDestroy()
	{
		mResource->mRenderStep->unregisterComponent(*mRenderToTextureComponent);
	}

}
