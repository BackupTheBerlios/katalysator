/***************************************************************************
                          tkegelschnitt.h  -  description
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

#ifndef TKEGELSCHNITT_H
#define TKEGELSCHNITT_H

#include <tkatbasis.h>

/**
  *@author Holger Stock
  */

class Tkegelschnitt : public Tkatbasis  {
private:
	treal kl_durchmesser;
	treal hoehe;
public: 
	Tkegelschnitt(treal l=0, treal d=0, treal w=0, treal h=0, treal d2=0,
		QString n= "Kegelschnitt", int x_=0, int y_=0);
	virtual ~Tkegelschnitt();
	//setzen der Werte
	void setkl_durchmesser(treal in) {kl_durchmesser=in;}
	void sethoehe(treal in) {hoehe=in;}
	//Rückgabe der Werte
	treal getkl_durchmesser(void) {return kl_durchmesser;}
	treal gethoehe(void) {return hoehe;}
	//virtuelle Funktionen
	virtual treal volumen(void);
	virtual treal masse(void)=0;
	virtual treal preis(void)=0;
	virtual treal WKap(void)=0;
};

#endif
