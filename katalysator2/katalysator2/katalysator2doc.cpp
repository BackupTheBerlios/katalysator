/***************************************************************************
                          katalysator2doc.cpp  -  description
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
#include <qdir.h>
#include <qwidget.h>

// include files for KDE
#include <klocale.h>
#include <kmessagebox.h>
#include <kio/job.h>
#include <kio/netaccess.h>

// application specific includes
#include "katalysator2doc.h"
#include "katalysator2.h"
#include "katalysator2view.h"

#include <algorithm>

QList<Katalysator2View> *Katalysator2Doc::pViewList = 0L;

class speichereWerte{
	KURL ziel;
public:
	explicit speichereWerte(KURL x){ziel=x;}
	void operator()( Tkatbasis * in){
	in->speichere(ziel);
}
};

Katalysator2Doc::Katalysator2Doc(QWidget *parent, const char *name) : QObject(parent, name)
{
  if(!pViewList)
  {
    pViewList = new QList<Katalysator2View>();
  }

  pViewList->setAutoDelete(true);
}

Katalysator2Doc::~Katalysator2Doc()
{
}

void Katalysator2Doc::addView(Katalysator2View *view)
{
  pViewList->append(view);
}

void Katalysator2Doc::removeView(Katalysator2View *view)
{
  pViewList->remove(view);
}
void Katalysator2Doc::setURL(const KURL &url)
{
  doc_url=url;
}

const KURL& Katalysator2Doc::URL() const
{
  return doc_url;
}

void Katalysator2Doc::slotUpdateAllViews(Katalysator2View *sender)
{
  Katalysator2View *w;
  if(pViewList)
  {
    for(w=pViewList->first(); w!=0; w=pViewList->next())
    {
      if(w!=sender)
        w->repaint();
    }
  }

}

bool Katalysator2Doc::saveModified()
{
  bool completed=true;

  if(modified)
  {
    Katalysator2App *win=(Katalysator2App *) parent();
    int want_save = KMessageBox::warningYesNoCancel(win,
                                         i18n("The current file has been modified.\n"
                                              "Do you want to save it?"), i18n("Warning"));
    switch(want_save)
    {
      case KMessageBox::Yes:
           if (doc_url.fileName() == i18n("Untitled"))
           {
             win->slotFileSaveAs();
           }
           else
           {
             saveDocument(URL());
       	   };

       	   deleteContents();
           completed=true;
           break;

      case KMessageBox::No:
           setModified(false);
           deleteContents();
           completed=true;
           break;	

      case KMessageBox::Cancel:
           completed=false;
           break;

      default:
           completed=false;
           break;
    }
  }

  return completed;
}

void Katalysator2Doc::closeDocument()
{
  deleteContents();
}

bool Katalysator2Doc::newDocument()
{
  /////////////////////////////////////////////////
  // TODO: Add your document initialization code here
  Werte.clear();
  /////////////////////////////////////////////////
  modified=false;
  doc_url.setFileName(i18n("Untitled"));

  return true;
}

bool Katalysator2Doc::openDocument(const KURL& url, const char *format /*=0*/)
{
  QString tmpfile;
  KIO::NetAccess::download( url, tmpfile );
  /////////////////////////////////////////////////
  // TODO: Add your document opening code here
  /////////////////////////////////////////////////

  KIO::NetAccess::removeTempFile( tmpfile );

  modified=false;
  return true;
}

bool Katalysator2Doc::saveDocument(const KURL& url, const char *format /*=0*/)
{
  /////////////////////////////////////////////////
  // TODO: Add your document saving code here
  Katalysator2App *win=(Katalysator2App *) parent();

  if (url.fileName() == i18n("Untitled"))
    {
     win->slotFileSaveAs();
    }
  else
    {
	  for_each(Werte.begin(), Werte.end(), speichereWerte(url));
	  };
  /////////////////////////////////////////////////

  modified=false;
  return true;
}

void Katalysator2Doc::deleteContents()
{
  /////////////////////////////////////////////////
  // TODO: Add implementation to delete the document contents
  Werte.clear();
  /////////////////////////////////////////////////

}
/** Erzeugt ein Neues Objekt vom Typ Trohr und gibt es zurück */
Trohr * Katalysator2Doc::NewPipe(){
	Trohr * r =new Trohr;
	Werte.push_back(r);
	modified=true;
	return r;
}
/** Speichert den übergebenen Wert ab */
//void Katalysator2Doc::speichere_Werte(Tkatbasis * in){
//	in->speichere();
//}
