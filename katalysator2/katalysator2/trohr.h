/***************************************************************************
                          trohr.h  -  description
                             -------------------
    begin                : Tue Feb 20 2001
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

#ifndef TROHR_H
#define TROHR_H

#include <tkatbasis.h>
#include "twerkstoff.h"
/**
  *@author Holger Stock
  */



class Trohr : public Tkatbasis, public twerkstoff  {
	
public: 
	Trohr(treal l=0, treal d=0, treal w=0, treal r=0, treal c=0, treal lam=0, treal p=0,
		QString n="Rohr", int x_=0, int y_=0);
	virtual ~Trohr();
	
	treal Innendurchmesser(void) {return getdurchmesser()-2*getwandstaerke();}
	//virtuelle Funktionen
	virtual  treal preis(void);
	virtual treal masse(void);
	virtual treal WKap(void);
};

#endif
