
#pragma once

#include "Engine/Scripting/Script.h"
#include <Engine/Core/Log.h>
#include <Engine/Engine/Screen.h>

#include "RmlRenderInterface.h"
#include "RmlSystemInterface.h"

#include <RmlUI/include/Core.h>
#include <RmlUI/include/Debugger.h>

API_CLASS() class GAME_API RmlSceneActor : public Script
{
DECLARE_SCRIPTING_TYPE(RmlSceneActor);
    
    RmlRenderInterface renderInterface;
    RmlSystemInterface systemInterface;

    Rml::Core::Context* Context;
    Rml::Core::ElementDocument* Document;

    bool IsInitialized = false;

    // [Script]
    void OnEnable() override;
    void OnDisable() override;
    void OnStart() override;
    void OnUpdate() override;
    void OnDestroy() override;

    API_FUNCTION() void InitializeRML();
    API_FUNCTION() void OnDrawRML();
    API_FUNCTION() void DestroyRML();
};
