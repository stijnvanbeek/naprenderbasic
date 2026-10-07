#pragma once

#include <renderservice.h>
#include <nap/service.h>

namespace nap
{

	class NAPAPI RenderBasicService : public Service
	{
		RTTI_ENABLE(Service)

	public:
		RenderBasicService(ServiceConfiguration* configuration) : Service(configuration) { }

		bool init(utility::ErrorState& error);
		void render();

	private:
		void getDependentServices(std::vector<rtti::TypeInfo> &dependencies) override { dependencies.emplace_back(RTTI_OF(RenderService)); }

		RenderService* mRenderService = nullptr;
	};

}