/***************************************************************************
                          tkatbasis.cpp  -  description
                             -------------------
    begin                : Thu Feb 15 2001
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

#include <ksimpleconfig.h>
#include <kurl.h>
#include <iostream.h>

#include "tkatbasis.h"

Tkatbasis::Tkatbasis(treal l, treal d, treal w, QString n, int x_, int y_){
//	neu();
	name=n;
	x=x_;
	y=y_;
	laenge=l;
	durchmesser=d;
	wandstaerke=w;
}
Tkatbasis::~Tkatbasis(){
//	geloescht();
}
treal Tkatbasis::volumen(){
	return M_PI_4*durchmesser*durchmesser*laenge;
}
treal Tkatbasis::querschnitt(){
	return M_PI_4*durchmesser*durchmesser;
}

/** speichern dieses Elements */
void Tkatbasis::speichere(KURL datei){
	QString dat =datei.path();
	KSimpleConfig *conf=new KSimpleConfig(dat);
	conf->setGroup(getname());
	conf->writeEntry("durchmesser", getdurchmesser());
	conf->writeEntry("laenge", getlaenge());
	conf->writeEntry("wandstaerke", getwandstaerke());
	conf->writeEntry("x",get_x());
	conf->writeEntry("y",get_y());
	delete conf;
}
