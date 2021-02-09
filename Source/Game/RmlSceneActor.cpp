
#include "RmlSceneActor.h"

RmlSceneActor::RmlSceneActor(const SpawnParams& params)
    : Script(params)
{
    // Enable ticking OnUpdate function
    _tickUpdate = true;
}

void RmlSceneActor::OnEnable()
{
    // Here you can add code that needs to be called when script is enabled (eg. register for events)
}

void RmlSceneActor::OnDisable()
{
    // Here you can add code that needs to be called when script is disabled (eg. unregister from events)
}

void RmlSceneActor::OnStart()
{
	

}

void RmlSceneActor::OnUpdate()
{
    // Here you can add code that needs to be called every frame
}

void RmlSceneActor::OnDestroy()
{
	
}

void RmlSceneActor::InitializeRML()
{
	if (IsInitialized)
		return;

	LOG(Info, "<RmlUI>Starting to Initialize things");

	Rml::Core::SetRenderInterface(&renderInterface);
	Rml::Core::SetSystemInterface(&systemInterface);
	//
	if (!Rml::Core::Initialise())
		LOG(Error, "<RmlUI> Failed to initialize");

	Rml::Core::LoadFontFace("C:\\Users\\again\\Documents\\repos\\FlaxEngine\\Binaries\\Editor\\Win64\\Development\\assets\\Delicious-Bold.otf");
	Rml::Core::LoadFontFace("C:\\Users\\again\\Documents\\repos\\FlaxEngine\\Binaries\\Editor\\Win64\\Development\\assets\\Delicious-BoldItalic.otf");
	Rml::Core::LoadFontFace("C:\\Users\\again\\Documents\\repos\\FlaxEngine\\Binaries\\Editor\\Win64\\Development\\assets\\Delicious-Italic.otf");
	Rml::Core::LoadFontFace("C:\\Users\\again\\Documents\\repos\\FlaxEngine\\Binaries\\Editor\\Win64\\Development\\assets\\Delicious-Roman.otf");

	Context = Rml::Core::CreateContext("default",
		Rml::Core::Vector2i(Screen::GetSize().X, Screen::GetSize().Y));

	Rml::Debugger::Initialise(Context);

	if (Context)
	{
		LOG(Info, "<RmlUI> Context loaded");
	}
	else
	{
		LOG(Error, "<RmlUI >Context is null");
	}

	Document = Context->LoadDocument("C:\\Users\\again\\Documents\\repos\\FlaxEngine\\Binaries\\Editor\\Win64\\Development\\assets\\demo.rml");


	/*renderInterface.Init();*/

	if (Document)
	{
		Document->Show();
		LOG(Info, "<RmlUI> Document  loaded");

		
	}
	else
	{
		LOG(Error, "<RmlUI> Document is null");
	}
	IsInitialized = true;

}

void RmlSceneActor::OnDrawRML()
{
	if (!IsInitialized)
		return;

	Context->Render();

	Context->Update();
}

API_FUNCTION() void RmlSceneActor::DestroyRML()
{
	if (IsInitialized) {
		Rml::Core::Shutdown();
	}

	return API_FUNCTION() void();
}
