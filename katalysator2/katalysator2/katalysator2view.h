/***************************************************************************
                          katalysator2view.h  -  description
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

#ifndef KATALYSATOR2VIEW_H
#define KATALYSATOR2VIEW_H

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif 

// include files for Qt
#include <qscrollview.h>

// include files from local project
#include <krohr_view.h>

//includes from Standard Library
#include <qlist.h>

// self defined headers
#include <trohr.h>

class Katalysator2Doc;

/** The Katalysator2View class provides the view widget for the Katalysator2App instance.	
 * The View instance inherits QWidget as a base class and represents the view object of a KMainWindow. As Katalysator2View is part of the
 * docuement-view model, it needs a reference to the document object connected with it by the Katalysator2App class to manipulate and display
 * the document structure provided by the Katalysator2Doc class.
 * 	
 * @author Source Framework Automatically Generated by KDevelop, (c) The KDevelop Team.
 * @version KDevelop version 0.4 code generation
 */
class Katalysator2View : public QScrollView
{

  Q_OBJECT
  public:
    /** Constructor for the main view */
    Katalysator2View(QWidget *parent = 0, const char *name=0);
    /** Destructor for the main view */
    ~Katalysator2View();

    /** returns a pointer to the document connected to the view instance. Mind that this method requires a Katalysator2App instance as a parent
     * widget to get to the window document pointer by calling the Katalysator2App::getDocument() method.
     *
     * @see Katalysator2App#getDocument
     */
    Katalysator2Doc *getDocument() const;

    /** contains the implementation for printing functionality */
    void print(QPrinter *pPrinter);
  /** Creates a new View of KRohr */
  void NewPipe(Trohr * r1);
//  void clear_objekte(void) {objekte.clear();}
	
  private:
  QList<QWidget> objekte;
	
public slots: // Public slots

  /** Neu zeichnen der Arbeitsberfläche */
  void paintEvent(QPaintEvent * ev);
};

#endif // KATALYSATOR2VIEW_H
