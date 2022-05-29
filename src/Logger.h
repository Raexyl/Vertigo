#ifndef LOGGER_H
#define LOGGER_H

namespace Logger
{
	enum logLevel 
	{
		note, warning, error
	};
/*!< \brief Importance level of a logged line.
 *
 *	If the logLevel of a message is higher than the Logger's logLevel (set using Logger::SetLogLevel())
 *	it will be logged to the terminal. Otherwise it will be ignored.
 */

	void Log(const char* string, logLevel importance);
/*!< \brief Use to log an error, warning or note.
 *
 *	If the logLevel of the message is higher than the Logger's logLevel (set using Logger::SetLogLevel())
 *	it will be logged to the terminal. Otherwise it will be ignored.
 */

	void SetLogLevel(logLevel level);
/*!< \brief Set logger filter.
 *
 *	If the logLevel of a message is higher than the Logger's logLevel (set using Logger::SetLogLevel())
 *	it will be logged to the terminal. Otherwise it will be ignored.
 */
};

#endif