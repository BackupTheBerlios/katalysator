/***************************************************************************
                          tkatbasis.h  -  description
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

#ifndef TKATBASIS_H
#define TKATBASIS_H
#include "definitions.h"

/**eine Art Zylinder, als Grundlage für die
nächsten Teile
  *@author Holger Stock
  */


#include <math.h>
#include <qstring.h>

#include <kurl.h>

class Tkatbasis {
private:
	treal laenge;
	treal durchmesser;
	treal wandstaerke;
	QString name;
	int x;
	int y; // Standort des Objekts auf dem Bildschirm (notwendig zur Trennung von Doc.- und View-Objekten)
	
protected:
	static int nummer;
	static void neu(){nummer++;}
	static void geloescht(){nummer--;}
	static int getnummer(){return nummer;}
public:

	Tkatbasis(treal l=0, treal d=0, treal w=0, QString n="katBasis", int x_=0, int y_=0);
	virtual ~Tkatbasis();
	// Setzen der beschreibenden Variablen
	void setlaenge(treal dat){laenge=dat;}
	void setdurchmesser(treal dat) {durchmesser=dat;}
	void setwandstaerke(treal dat) {wandstaerke=dat;}
	void setname(QString& data) {name=data;}
	void set_x(int dat) {x=dat;}
	void set_y(int dat) {y=dat;}
	// Rückgabe der gesetzten Variablen
	treal getlaenge(void) { return laenge;}
	treal getdurchmesser(void) {return durchmesser;}
	treal getwandstaerke(void) {return wandstaerke;}
	QString getname(void) {return name;}
	int get_x(void) {return x;}
	int get_y(void) {return y;}
	// Berechnung verschiedener charakteristischer Größen
	virtual treal volumen(void);
	virtual treal querschnitt(void);
	//virtuelle Funktionen
	virtual treal preis(void)=0;
	virtual treal masse(void)=0;
	virtual treal WKap(void)=0;
  /** speichern dieses Elements */
  virtual void speichere(KURL datei);
};



#endif
