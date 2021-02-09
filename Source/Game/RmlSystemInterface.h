#pragma once

#include <RmlUI/include/Core.h>

#include <Engine/Core/Log.h>
#include <Engine/Engine/Time.h>

class RmlSystemInterface : public Rml::Core::SystemInterface
{
public:
	double GetElapsedTime() override;
	bool LogMessage(Rml::Core::Log::Type type, const Rml::Core::String& message) override;
};
