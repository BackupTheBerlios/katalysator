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
#include <list.h>

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
void Katalysator2View::NewPipe(QDomElement & r1){
  KRohr_View * r = new KRohr_View(r1,viewport());
  addChild(r);
  objekte.append(r);
  r->show();
}

/** Redrawing the View */
void Katalysator2View::paintEvent(QPaintEvent *ev){
	objekte.clear();
	Katalysator2Doc *doc;
	doc=getDocument();
	/** Getting the XML-Document */
	QDomDocument* XMLdoc=doc->getDocument();
	/** Getting the list of the used KRohr-View-Widgets in this View */
	list<QString> name_list;
	list<QString>::iterator p;
  QObjectList * l = topLevelWidget()->queryList( "KRohr_View" );
//  l->setAutoDelete( TRUE );
  QObjectListIt it( *l );             // iterate over the widgets
  QObjectListIt it2( *l );
  QObject * obj;
  QString name;
  while ( (obj=it.current()) != 0 ) { // for each found object...
      ++it;
      if((( KRohr_View*)obj)->isHidden()){
				cout<<"loesche Eintrag weil versteckt (katalysator2view::paintevent): "<<name<<endl;
				it2=it;
				--it;
				l->remove(it2);
				delete obj;		
			}
			else{
        name = (( KRohr_View*)obj)->getName();
	      p=std::find(name_list.begin(),name_list.end(), name);
	      if(p==name_list.end()){
	        name_list.push_back(name);
	      }
	      else{
					cout<<"loesche Eintrag wegen Namen (katalysator2view::paintevent): "<<name<<endl;
					it2=it;
					--it;
					(( KRohr_View*)obj)->hide();
					l->remove(it2);
					delete obj;		
 	     }
 	   }
   //   ((QButton*)obj)->setEnabled( FALSE );
  }
  delete l;                           // delete the list, not the objects

	QDomElement docElem = XMLdoc->documentElement();
  QDomNode & n = docElem.firstChild();
  while( !n.isNull() ) {
      QDomElement & e = n.toElement(); // try to convert the node to an element.
      if( !e.isNull() ) { // the node was really an element.
          cout << e.tagName() << endl;
          if (e.tagName()=="pipe"){
          	p=std::find(name_list.begin(),name_list.end(), e.attribute("name"));
          	
          	if(p==name_list.end()){
  						NewPipe(e);
  					}
  					else name_list.erase(p);
  	      }

      }
      n = n.nextSibling();
  }
	for (p=name_list.begin();p!=name_list.end();p++)
		cout <<"remaining: "<<*p<<endl;
}

/** Called if the view has been changed to update the document */
void Katalysator2View::SlotUpdateDocument(void){
//	objekte.clear();
	Katalysator2Doc *doc;
	doc=getDocument();
	/** Getting the XML-Document */
	QDomDocument* XMLdoc=doc->getDocument();
	
	QDomElement docElem = XMLdoc->documentElement();
	
  QDomNode n = docElem.firstChild();
  while( !n.isNull() ) {
      QDomElement e = n.toElement(); // try to convert the node to an element.
      if( !e.isNull() ) { // the node was really an element.
          if(e.tagName()=="pipe") docElem.removeChild(e);
      }
      n = n.nextSibling();
  }

	/** Getting the list of the used KRohr-View-Widgets in this View */
	list<QString> name_list;
	list<QString>::iterator p;
  QObjectList * l = topLevelWidget()->queryList( "KRohr_View" );
//  l->setAutoDelete( TRUE );
  QObjectListIt it( *l );             // iterate over the widgets
  QObjectListIt it2( *l );
  QObject * obj=0;
  QString name;
  while ( (obj=it.current()) != 0 ) { // for each found object...
      ++it;
      if((( KRohr_View*)obj)->isHidden()){
				cout<<"loesche Eintrag weil versteckt (katalysator2view::paintevent): "<<name<<endl;
				it2=it;
				--it;
				l->remove(it2);
				delete obj;	
				obj=0;	
			}
			else{
        name = (( KRohr_View*)obj)->getName();
	      p=std::find(name_list.begin(),name_list.end(), name);
	      if(p==name_list.end()){
	        name_list.push_back(name);
	      }
	      else{
					cout<<"loesche Eintrag wegen Namen (katalysator2view::paintevent): "<<name<<endl;
					it2=it;
					--it;
					(( KRohr_View*)obj)->hide();
					l->remove(it2);
					delete obj;
					obj=0;		
 	     }
 	   }
 	   if(obj!=0) {
 			 Trohr* rohr =( (KRohr_View*)obj)->getTrohr();
 	
  		 QDomElement elem = XMLdoc->createElement( "pipe" );
       elem.setAttribute( "x", rohr->get_x() );
       elem.setAttribute( "y", rohr->get_y() );
       elem.setAttribute( "length", rohr->getlaenge() );
       elem.setAttribute( "diameter", rohr->getdurchmesser() );
       elem.setAttribute( "wall_thickness", rohr->getwandstaerke() );
       elem.setAttribute( "number", rohr->getnummer() );
       elem.setAttribute( "name", rohr->getname() );
       docElem.appendChild( elem );
       }

   //   ((QButton*)obj)->setEnabled( FALSE );
  }
  delete l;                           // delete the list, not the objects

}
