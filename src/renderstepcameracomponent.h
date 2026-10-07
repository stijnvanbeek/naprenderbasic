#pragma once

#include <component.h>
#include <cameracomponent.h>
#include <renderpipeline.h>

namespace nap
{

	class RenderStepCameraComponentInstance;


	class NAPAPI RenderStepCameraComponent : public Component
	{
		RTTI_ENABLE(Component)
		DECLARE_COMPONENT(RenderStepCameraComponent, RenderStepCameraComponentInstance)

	public:
		RenderStepCameraComponent() { }

		ResourcePtr<RenderStep> mRenderStep; ///< Property: 'RenderStep'

		void getDependentComponents(std::vector<rtti::TypeInfo>& components) const override { components.emplace_back(RTTI_OF(CameraComponent)); }
	};


	class NAPAPI RenderStepCameraComponentInstance : public ComponentInstance
	{
		RTTI_ENABLE(ComponentInstance)

	public:
		RenderStepCameraComponentInstance(EntityInstance& entity, Component& resource) : ComponentInstance(entity, resource) { }

		bool init(utility::ErrorState& errorState) override;
		void onDestroy() override;
		void update(double deltaTime) override { }

	private:
		RenderStepCameraComponent* mResource = nullptr;
		CameraComponentInstance* mCameraComponent = nullptr;
	};

}
