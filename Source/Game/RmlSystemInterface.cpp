#include "RmlSystemInterface.h"


double RmlSystemInterface::GetElapsedTime()
{
	return Time::Update.DeltaTime.GetTotalSeconds();
}

bool RmlSystemInterface::LogMessage(Rml::Core::Log::Type type, const Rml::Core::String& message)
{
	
	if (type == Rml::Core::Log::LT_WARNING)
		LOG_STR(Warning, String(message.c_str()));
	else if (type == Rml::Core::Log::LT_ERROR)
		LOG_STR(Error, String(message.c_str()));
	else
		LOG_STR(Info, String(message.c_str()));

	return true;
}
