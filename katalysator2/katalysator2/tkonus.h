/***************************************************************************
                          tkonus.h  -  description
                             -------------------
    begin                : Thu Feb 22 2001
    copyright            : (C) 2001 by Holger Stock
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

#ifndef TKONUS_H
#define TKONUS_H

#include <tkegelschnitt.h>
#include <twerkstoff.h>

/**
  *@author Holger Stock
  */

class Tkonus : public Tkegelschnitt, public twerkstoff  {
public:
	Tkonus(treal l=0, treal d=0, treal w=0, treal h=0, treal d2=0, treal r=0, treal c=0, treal lam=0, treal p=0,
		QString n="Konus", int x_=0, int y_=0);
	virtual ~Tkonus();
	virtual treal volumen(void);
	virtual treal masse(void);
	virtual treal preis(void);
	virtual treal WKap(void);
	
};

#endif
