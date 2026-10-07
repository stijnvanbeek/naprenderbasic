#pragma once

#include <component.h>
#include <rendertotexturecomponent.h>
#include <renderpipeline.h>

namespace nap
{

	class RenderToTextureStepComponentInstance;


	class NAPAPI RenderToTextureStepComponent : public Component
	{
		RTTI_ENABLE(Component)
		DECLARE_COMPONENT(RenderToTextureStepComponent, RenderToTextureStepComponentInstance)

	public:
		RenderToTextureStepComponent() { }

		ResourcePtr<RenderToTextureStep> mRenderStep; ///< Property: 'RenderStep'

		void getDependentComponents(std::vector<rtti::TypeInfo>& components) const override { components.emplace_back(RTTI_OF(RenderToTextureComponent)); }
	};


	class NAPAPI RenderToTextureStepComponentInstance : public ComponentInstance
	{
		RTTI_ENABLE(ComponentInstance)

	public:
		RenderToTextureStepComponentInstance(EntityInstance& entity, Component& resource) : ComponentInstance(entity, resource) { }

		bool init(utility::ErrorState& errorState) override;
		void onDestroy() override;
		void update(double deltaTime) override { }

	private:
		RenderToTextureStepComponent* mResource = nullptr;
		RenderToTextureComponentInstance* mRenderToTextureComponent = nullptr;
	};

}
