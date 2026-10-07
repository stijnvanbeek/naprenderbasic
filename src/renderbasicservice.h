#pragma once

#include <renderservice.h>
#include <nap/service.h>

namespace nap
{

	class RenderPipeline;


	class NAPAPI RenderBasicService : public Service
	{
		RTTI_ENABLE(Service)

	public:
		RenderBasicService(ServiceConfiguration* configuration) : Service(configuration) { }

		bool init(utility::ErrorState& error);
		void render();

		void registerPipeline(RenderPipeline& pipeline) { mPipelines.emplace(&pipeline); }
		void unregisterPipeline(RenderPipeline& pipeline) { mPipelines.erase(&pipeline); }

	private:
		void getDependentServices(std::vector<rtti::TypeInfo> &dependencies) override { dependencies.emplace_back(RTTI_OF(RenderService)); }

		std::set<RenderPipeline*> mPipelines;

		RenderService* mRenderService = nullptr;
	};

}
