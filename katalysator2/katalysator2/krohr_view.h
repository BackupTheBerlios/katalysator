/***************************************************************************
                          krohr_view.h  -  description
                             -------------------
    begin                : Mon Jun 11 2001
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

#ifndef KROHR_VIEW_H
#define KROHR_VIEW_H

#include <qwidget.h>
#include <qevent.h>
#include <qevent.h>
#include <qpainter.h>
#include <qdatetime.h>
#include <qdom.h>

#include <kpopupmenu.h>

#include "trohr.h"
#include "krohr_impl.h"

/**Darstellung eines Rohres auf dem Desktops und
Verknüpfung mit dem krohr-Dialog

  *@author Holger Stock
  */

class KRohr_View : public QWidget  {
   Q_OBJECT
public: 
	KRohr_View(QWidget *parent=0, const char *name=0);
	KRohr_View(QDomElement& r, QWidget *parent=0, const char *name=0 );
	~KRohr_View();
	  /** Setting the Trohr-object on which we are working with this class to version defined
outside of this class. */
	int attach_trohr(Trohr* r);
  /** returns the y-value of the upper-left edge of the rectangle */
  int get_y(void);
  /** sets the y-value of the upper-left edge of the rectangle */
  void set_y(int value);
  /** sets the x-value of the upper-left edge of the rectangle
 */
  void set_x(int value);
  /** Return the x-Value of the upper left edge of the rectangle */
  int get_x(void);
  /** Returns the name of this Instance of KRohr_View */
  QString getName(void);
  /** Returns a pointer of the data-object Trohr */
  Trohr* getTrohr(void);
	
public slots:
	void PaintEvent();
protected:
	void mousePressEvent(QMouseEvent *ev);
	void mouseMoveEvent(QMouseEvent *ev);
	void mouseReleaseEvent(QMouseEvent *ev);
	void paintEvent(QPaintEvent *ev);
	
private:
	bool leftDown;
	bool dragging;
	QTime timer;
	QPoint startPoint;
	KRohr_Impl *kontext;
	KPopupMenu *popup;
	
	QDomElement dom_pipe;
	bool delete_rohr;
	Trohr * rohr;
};

#endif
