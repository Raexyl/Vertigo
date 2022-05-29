#ifndef CORE_H
#define CORE_H

#include "App.h"
#include "Input.h"
#include "Logger.h"

App* GetApp(void);
/*!< \brief You must define this function.
 *
 *	This function needs to be defined by the library user. It must return your App derivative.
 *	Zippy uses this function to load and run your game.
 */

#endif