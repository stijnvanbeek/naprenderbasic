#pragma once

#include <nap/resource.h>
#include <renderablemeshcomponent.h>
#include <rendertotexturecomponent.h>
#include <rendertarget.h>
#include <nap/core.h>

namespace nap {

	class RenderBasicService;


	class RenderStepBase : public Resource
	{
		RTTI_ENABLE(Resource)

	public:
		RenderStepBase() = default;
		virtual void perform() = 0;
	};


	class NAPAPI RenderStep : public RenderStepBase
	{
		RTTI_ENABLE(RenderStepBase)

	public:
		RenderStep() = default;
		bool init(utility::ErrorState &errorState) override;
		void perform() override;

		ResourcePtr<RenderTarget> mRenderTarget; ///< Property: 'RenderTarget'

		void registerComponent(RenderableComponentInstance& component);
		void unregisterComponent(RenderableComponentInstance& component);

		void setCamera(CameraComponentInstance& camera) { mCamera = &camera; }
		void unregisterCamera(CameraComponentInstance& camera) { if (mCamera == &camera) mCamera = nullptr; }

	private:
		RenderService* mRenderService = nullptr;
		std::vector<RenderableComponentInstance*> mComponents;
		CameraComponentInstance* mCamera = nullptr;
	};


	class NAPAPI RenderToTextureStep : public RenderStepBase
	{
		RTTI_ENABLE(RenderStepBase)

	public:
		void perform() override { mRenderToTextureComponent->draw(); }

		void registerComponent(RenderToTextureComponentInstance& component) { mRenderToTextureComponent = &component; }
		void unregisterComponent(RenderToTextureComponentInstance& component) { if (&component == mRenderToTextureComponent) mRenderToTextureComponent = nullptr; }

	private:
		RenderToTextureComponentInstance* mRenderToTextureComponent = nullptr;
	};


	class NAPAPI RenderPipeline : public Resource
	{
		RTTI_ENABLE(Resource)

	public:
		RenderPipeline(Core& core) : mCore(&core) {}
		bool init(utility::ErrorState& error) override;
		void onDestroy() override;

		std::vector<ResourcePtr<RenderStepBase>> mRenderSteps; ///< Property: 'RenderSteps'

		void perform();

	private:
		Core* mCore = nullptr;
		RenderBasicService* mService = nullptr;
	};

}
