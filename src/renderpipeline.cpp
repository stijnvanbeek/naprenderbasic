#include "renderpipeline.h"

#include <renderservice.h>
#include <nap/core.h>

RTTI_BEGIN_CLASS_NO_DEFAULT_CONSTRUCTOR(nap::RenderStepBase)
RTTI_END_CLASS

RTTI_BEGIN_CLASS(nap::RenderStep)
	RTTI_PROPERTY("RenderTarget", &nap::RenderStep::mRenderTarget, nap::rtti::EPropertyMetaData::Required)
RTTI_END_CLASS

RTTI_BEGIN_CLASS_NO_DEFAULT_CONSTRUCTOR(nap::RenderPipeline)
	RTTI_CONSTRUCTOR(nap::Core&)
	RTTI_PROPERTY("RenderSteps", &nap::RenderPipeline::mRenderSteps, nap::rtti::EPropertyMetaData::Embedded)
RTTI_END_CLASS

namespace nap
{


	bool RenderStep::init(utility::ErrorState &errorState)
	{
		return true;
	}


	void RenderStep::perform()
	{
		mRenderTarget->beginRendering();
		mRenderService->renderObjects(*mRenderTarget, *mCamera, mComponents);
		mRenderTarget->endRendering();
	}


	void RenderStep::registerComponent(RenderableComponentInstance &component)
	{
		mComponents.push_back(&component);
	}


	void RenderStep::unregisterComponent(RenderableComponentInstance &component)
	{
		auto it = std::find(mComponents.begin(), mComponents.end(), &component);
		if (it != mComponents.end())
			mComponents.erase(it);
	}


	bool RenderPipeline::init(utility::ErrorState& error)
	{
		mRenderService = mCore->getService<RenderService>();
		return true;
	}


	void RenderPipeline::perform()
	{
		for (auto& step : mRenderSteps)
			step->perform();
	}

}
