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

// include files for Qt
#include <qprinter.h>
#include <qpainter.h>

// application specific includes
#include "katalysator2view.h"
#include "katalysator2doc.h"
#include "katalysator2.h"
#include "krohr_view.h"

Katalysator2View::Katalysator2View(QWidget *parent, const char *name) : QWidget(parent, name)
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
/** Creates a new View of KRohr */
void Katalysator2View::NewPipe(Trohr * r1){
  KRohr_View * r = new KRohr_View(r1,this);
  r->show();
	
}
