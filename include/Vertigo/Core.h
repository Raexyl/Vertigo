#ifndef CORE_H
#define CORE_H

#include "App.h"

App* GetApp(void);
/*!< \brief You must define this function.
 *
 *	This function needs to be defined by the library user. It must return your App derivative.
 *	Vertigo uses this function to load and run your game.
 */

#endif