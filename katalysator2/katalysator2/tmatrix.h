/***************************************************************************
                          tmatrix.h  -  description
                             -------------------
    begin                : Wed Mar 14 2001
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

#ifndef TMATRIX_H
#define TMATRIX_H

#include "tkatbasis.h"

/**
  *@author Holger Stock
  */

class Tmatrix: public Tkatbasis{
private:
	treal zelldichte;
	treal dh;
	treal cp;
public: 
	Tmatrix();
	~Tmatrix();
	
	void setzelldichte(treal in) {zelldichte=in;}
	void setdh(treal in) {dh=in;}
	void setcp(treal in) {cp=in;}
	
	treal getzelldichte(void) {return zelldichte;}
	treal getdh(void) {return dh;}
	treal getcp(void) {return cp;}
	
};

#endif
