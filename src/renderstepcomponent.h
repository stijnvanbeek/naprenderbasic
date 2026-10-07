#pragma once

#include <component.h>
#include <renderablemeshcomponent.h>
#include <renderpipeline.h>

namespace nap
{

	class RenderStepComponentInstance;


	class NAPAPI RenderStepComponent : public Component
	{
		RTTI_ENABLE(Component)
		DECLARE_COMPONENT(RenderStepComponent, RenderStepComponentInstance)

	public:
		RenderStepComponent() { }

		ResourcePtr<RenderStep> mRenderStep; ///< Property: 'RenderStep'

		void getDependentComponents(std::vector<rtti::TypeInfo>& components) const override { components.emplace_back(RTTI_OF(RenderableComponent)); }
	};


	class NAPAPI RenderStepComponentInstance : public ComponentInstance
	{
		RTTI_ENABLE(ComponentInstance)

	public:
		RenderStepComponentInstance(EntityInstance& entity, Component& resource) : ComponentInstance(entity, resource) { }

		bool init(utility::ErrorState& errorState) override;
		void onDestroy() override;
		void update(double deltaTime) override { }

	private:
		RenderStepComponent* mResource = nullptr;
		RenderableComponentInstance* mRenderableComponent = nullptr;
	};

}
