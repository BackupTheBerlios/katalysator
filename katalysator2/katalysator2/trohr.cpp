/***************************************************************************
                          trohr.cpp  -  description
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

#include "trohr.h"
#include <iostream>

Trohr::Trohr(treal l, treal d, treal w, treal r, treal c, treal lam, treal p,
	QString n, int x_, int y_):
		Tkatbasis(l,d,w,n,x_,y_),twerkstoff(r,c,lam,p){
}
Trohr::~Trohr(){
}

treal Trohr::masse(){
	return (volumen()-M_PI_4*Innendurchmesser()*Innendurchmesser()*getlaenge())*getrho();
}

treal Trohr::preis(){
	treal pr=masse()*getpreis();
	cout << pr<<endl;
	return pr;
}

treal Trohr::WKap(){
	return masse()*getcp();
}
