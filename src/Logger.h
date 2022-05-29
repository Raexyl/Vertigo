#ifndef LOGGER_H
#define LOGGER_H

namespace Logger
{
	enum logLevel 
	{
		note, warning, error
	};

	void Log(const char* string, logLevel importance);
	void SetLogLevel(logLevel level);
};

#endif