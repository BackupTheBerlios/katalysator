/***************************************************************************
                          tkegelschnitt.cpp  -  description
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

#include "tkegelschnitt.h"

Tkegelschnitt::Tkegelschnitt(treal l, treal d, treal w, treal h, treal d2, QString n, int x_, int y_ ):
	Tkatbasis(l,d,w,n,x_,y_)
{
	hoehe=h;
	kl_durchmesser=d2;
}
Tkegelschnitt::~Tkegelschnitt(){
}
treal Tkegelschnitt::volumen(){
	treal r1=getdurchmesser()/2;
	treal r2=getkl_durchmesser()/2;
	return M_PI *hoehe/3*(r1*r1+r1*r2+r2*r2);
}
