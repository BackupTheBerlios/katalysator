/***************************************************************************
                          katalysator2view.cpp  -  description
                             -------------------
    begin                : Sam Jun 16 01:22:15 CEST 2001
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


// application specific includes
#include "katalysator2doc.h"
#include "katalysator2view.h"
#include "katalysator2.h"
#include "krohr_view.h"
#include <algorithm>

// include files for Qt
#include <qprinter.h>
#include <qpainter.h>

Katalysator2View::Katalysator2View(QWidget *parent, const char *name) : QScrollView(parent, name)
{
  setBackgroundMode(PaletteBase);
}

Katalysator2View::~Katalysator2View()
{
}

Katalysator2Doc *Katalysator2View::getDocument() const
{
  Katalysator2App *theApp=(Katalysator2App *) parentWidget();

  return theApp->getDocument();
}

void Katalysator2View::print(QPrinter *pPrinter)
{
  QPainter printpainter;
  printpainter.begin(pPrinter);
	
  // TODO: add your printing code here

  printpainter.end();
}

/** Creates a new View of KRohr_View */
void Katalysator2View::NewPipe(Trohr * r1){
  KRohr_View * r = new KRohr_View(r1,viewport());
  addChild(r);
  objekte.append(r);
  r->show();
}

/** Neu zeichnen der Arbeitsberfläche */
void Katalysator2View::paintEvent(QPaintEvent *ev){
	Katalysator2Doc *doc;
	doc=getDocument();
	TWerte werte=doc->getWerte();
	Tkatbasis** it;	
	for (it=werte.begin(); it!=werte.end(); it++){
		if(Trohr* in=dynamic_cast<Trohr*>(*it)){
			NewPipe(in);
		}
		else{
			cerr<<"No TRohr!"<<endl;
		}	
			
cerr<<" paintEvent finished!"<< endl;		
	};
}
