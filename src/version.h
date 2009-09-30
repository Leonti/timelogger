/*************************************************************************************
*  Time Logger - writes time in and time out into database                           *
*  Copyright (C) 2009  Leonti Bielski                                                *
*                                                                                    *
*  This program is free software; you can redistribute it and/or modify              *
*  it under the terms of the GNU General Public License as published by              *
*  the Free Software Foundation; either version 2 of the License, or                 *
*  (at your option) any later version.                                               *
*                                                                                    *
*  This program is distributed in the hope that it will be useful,                   *
*  but WITHOUT ANY WARRANTY; without even the implied warranty of                    *
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                     *
*  GNU General Public License for more details.                                      *
*                                                                                    *
*  You should have received a copy of the GNU General Public License                 *
*  along with this program; if not, write to the Free Software                       *
*  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA    *
*************************************************************************************/
#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{

	//Date Version Types
	static const char DATE[] = "24";
	static const char MONTH[] = "09";
	static const char YEAR[] = "2009";
	static const double UBUNTU_VERSION_STYLE = 9.09;

	//Software Status
	static const char STATUS[] = "Alpha";
	static const char STATUS_SHORT[] = "a";

	//Standard Version Type
	static const long MAJOR = 0;
	static const long MINOR = 7;
	static const long BUILD = 0;
	static const long REVISION = 0;

	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 42;
	#define RC_FILEVERSION 0,7,0,0
	#define RC_FILEVERSION_STRING "0, 7, 0, 0\0"
	static const char FULLVERSION_STRING[] = "0.7.0.0";

	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 0;


}
#endif //VERSION_H
