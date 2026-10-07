#include "renderstepcameracomponent.h"

#include <nap/core.h>
#include <entity.h>

RTTI_BEGIN_CLASS(nap::RenderStepCameraComponent)
	RTTI_PROPERTY("RenderStep", &nap::RenderStepCameraComponent::mRenderStep, nap::rtti::EPropertyMetaData::Required)
RTTI_END_CLASS

RTTI_BEGIN_CLASS_NO_DEFAULT_CONSTRUCTOR(nap::RenderStepCameraComponentInstance)
	RTTI_CONSTRUCTOR(nap::EntityInstance&, nap::Component&)
RTTI_END_CLASS

namespace nap
{

	bool RenderStepCameraComponentInstance::init(utility::ErrorState& errorState)
	{
		mCameraComponent = getEntityInstance()->findComponent<CameraComponentInstance>();
		mResource = getComponent<RenderStepCameraComponent>();
		mResource->mRenderStep->setCamera(*mCameraComponent);
		return true;
	}


	void RenderStepCameraComponentInstance::onDestroy()
	{
		mResource->mRenderStep->unregisterCamera(*mCameraComponent);
	}

}
