/***************************************************************************
                          krohr_view.cpp  -  description
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

#include "krohr_view.h"
#include <math.h>

KRohr_View::KRohr_View(QWidget *parent, const char *name ) : QWidget(parent,name) {
	rohr = new Trohr;
	delete_rohr=true;
	kontext=new KRohr_Impl(rohr);
  connect(kontext->buttonApply, SIGNAL(clicked()), SLOT(PaintEvent()));
  connect(kontext->buttonOk, SIGNAL(clicked()), SLOT(PaintEvent()));
//	kontext->show();
}

KRohr_View::KRohr_View(Trohr* r, QWidget *parent, const char *name ) : QWidget(parent,name) {
	rohr=r;
	delete_rohr=false;
	kontext=new KRohr_Impl(rohr);
  connect(kontext->buttonApply, SIGNAL(clicked()), SLOT(PaintEvent()));
  connect(kontext->buttonOk, SIGNAL(clicked()), SLOT(PaintEvent()));
//	kontext->show();
}

KRohr_View::~KRohr_View(){
if (delete_rohr) delete rohr;
}

void KRohr_View::paintEvent(QPaintEvent *ev)
{
	int dx=int(rohr->getlaenge()*1000);
	int dy=int(rohr->getdurchmesser()*1000);
	if (dx==0) dx=10;
	if (dy==0) dy=10;
	setGeometry(get_x(),get_y(),dx,dy);

	QPainter p(this);
	QBrush brush(white);
	p.setBrush(white);
	p.drawRect(0,0,dx,dy);
	p.drawText(fabs(dx/2),fabs(dy/2), rohr->getname());
}

void KRohr_View::mouseMoveEvent(QMouseEvent *ev)
{
	if (!leftDown) return;
	if (!dragging)
		if(timer.elapsed()>=300||
			 (startPoint.x() - ev->pos().x())>10 ||
			 (startPoint.y() - ev->pos().y())>10)
			dragging=true;
		if (dragging)
		{
		QPoint punkt= mapToParent(ev->pos());
		set_x(punkt.x());
		set_y(punkt.y());
		paintEvent(0);			
		}
}

void KRohr_View::mousePressEvent(QMouseEvent *ev)
{
	if(leftDown) return;

	if(ev->button()==RightButton)
		kontext->show();
		
	else if (ev->button()==LeftButton){
		leftDown=true;
		dragging=false;
		timer.start();
		startPoint=ev->pos();
  }
}

void KRohr_View::mouseReleaseEvent(QMouseEvent *ev)
{
	if(!leftDown||ev->button()!=LeftButton) return;
	mouseMoveEvent(ev);
	leftDown=false;
	if(dragging)
	{
		QPoint punkt= mapToParent(ev->pos());
		set_x(punkt.x());
		set_y(punkt.y());
		paintEvent(0);
	}
	else
	{}
}

int KRohr_View::attach_trohr(Trohr* r)
{
	if (delete_rohr) delete rohr;
	rohr=r;
	return 0;
	
}

/** Return the x-Value of the upper left edge of the rectangle */
int KRohr_View::get_x(void){
	return rohr->get_x();
}
/** sets the x-value of the upper-left edge of the rectangle
 */
void KRohr_View::set_x(int value){
	rohr->set_x(value);
}
/** sets the y-value of the upper-left edge of the rectangle */
void KRohr_View::set_y(int value){
	rohr->set_y(value);
}
/** returns the y-value of the upper-left edge of the rectangle */
int KRohr_View::get_y(void){
	return rohr->get_y();
}
