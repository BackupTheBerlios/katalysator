/***************************************************************************
                          tkonus.cpp  -  description
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

#include "tkonus.h"

Tkonus::Tkonus(treal l, treal d, treal w, treal h, treal d2, treal r, treal c, treal lam, treal p,
	QString n, int x_, int y_):
Tkegelschnitt(l,d,w,h,d2,n,x_,y_), twerkstoff(r,c,lam,p)
{
}
Tkonus::~Tkonus(){
}
treal Tkonus::volumen(){
treal r1=getdurchmesser()/2-getwandstaerke();
treal r2=getkl_durchmesser()/2-getwandstaerke();
return Tkegelschnitt::volumen()-M_PI *gethoehe()/3*(r1*r1+r1*r2+r2*r2);
}
treal Tkonus::masse(){
return volumen()*getrho();
}
treal Tkonus::preis(){
return masse()*getpreis();
}
treal Tkonus::WKap(){
return masse()*getcp();
}
