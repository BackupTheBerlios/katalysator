/***************************************************************************
                          twerkstoff.h  -  description
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

#ifndef TWERKSTOFF_H
#define TWERKSTOFF_H
#include "definitions.h"

/**Beschreibt die wichtigsten Dinge eines Werkstoffes
  *@author Holger Stock
  */

class twerkstoff {
private:
	treal rho;
	treal cp;
	treal lambda;
	treal preis_per_mass;
	
public: 
	twerkstoff( treal r=0, treal c=0, treal l=0, treal p=0)
	{
		rho=r;
		cp=c;
		lambda=l;
		preis_per_mass=p;
	}
		
	virtual ~twerkstoff(){};
	
	// setzen der Werte
	void setrho(treal in){rho=in;}
	void setcp(treal in) {cp=in;}
	void setlambda(treal in){lambda = in;}
	void setpreis(treal in) {preis_per_mass = in;}
	
	// Rückgabe der Werte
	treal getrho(void) {return rho;}
	treal getcp(void) {return cp;}
	treal getlambda(void) {return lambda;}
	treal getpreis(void) {return preis_per_mass;}

};

#endif
