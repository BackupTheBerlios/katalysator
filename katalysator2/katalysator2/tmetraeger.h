/***************************************************************************
                          tmetraeger.h  -  description
                             -------------------
    begin                : Sun Feb 3 2002
    copyright            : (C) 2002 by Holger Stock
    email                : hstock@users.berlios.de
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef TMETRAEGER_H
#define TMETRAEGER_H

#include <trohr.h>
#include <tmatrix.h>

/**Describing all relevant data for a metal substrate
  *@author Holger Stock
  */

class TMeTraeger : public Trohr , public Tmatrix {
public: 
	TMeTraeger(treal l, treal d, treal w, QString n, int x_, int w_);
	~TMeTraeger();
};

#endif
