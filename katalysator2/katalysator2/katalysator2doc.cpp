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
#include <knotifyclient.h>

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
 	lvConn=new PgDatabase("dbname=katalysator");
 	if(lvConn->ConnectionBad())
 		{
 			QString message=i18n("PostgreSQL returns the following error:\n");
 			message +=lvConn->ErrorMessage();
 			KMessageBox::error(0,message,i18n("Database Error"));
 		}
 			
	doc=new QDomDocument("katalysator");
	QString kat_content("<katalysator> \n </katalysator>");
	doc->setContent(kat_content);

}

Katalysator2Doc::~Katalysator2Doc()
{
	delete lvConn;
	delete doc;
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
        w->paintEvent(0);
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
	
	doc=new QDomDocument("katalysator");
  /////////////////////////////////////////////////
  modified=false;
  doc_url.setFileName(i18n("Untitled"));
	slotUpdateAllViews(0);
  return true;
}

bool Katalysator2Doc::openDocument(const KURL& url, const char *format /*=0*/)
{
  QString tmpfile;
  if (url.isLocalFile())
  	tmpfile=url.path();
  else if (!KIO::NetAccess::download( url, tmpfile ))
  	{
  		KNotifyClient::event(i18n("File couldn't be downloaded!"));
  		return false;
  	}
  /////////////////////////////////////////////////
  // TODO: Add your document opening code here
	
  QFile f( tmpfile );
  if ( !f.open( IO_ReadOnly ) )
      return false;
  if ( !doc->setContent( &f ) ) {
      f.close();
      return false;
  }
  f.close();
	
  /////////////////////////////////////////////////

  KIO::NetAccess::removeTempFile( tmpfile );

  modified=false;
  return true;
}

bool Katalysator2Doc::saveDocument(const KURL& url, const char *format /*=0*/)
{
  /////////////////////////////////////////////////
  // TODO: Add your document saving code here
  QString tmpfile=url.path();
  Katalysator2App *win=(Katalysator2App *) parent();

  if (url.fileName() == i18n("Untitled"))
    {
     win->slotFileSaveAs();
    }
  else
    {
		QFile qfile(tmpfile);
			if(qfile.open(IO_ReadWrite))
				{
				QString buffer=doc->toString();
				cout<<buffer<<endl;
				qfile.writeBlock(buffer, buffer.length());
				qfile.close();
				}
			else
				{
				QString qerr;
				qerr.sprintf(i18n("Cannot write to file!"));
				KNotifyClient::event(qerr);
				}
			if(!url.isLocalFile())
				{
				if(!KIO::NetAccess::upload(tmpfile, url))
					{
					KNotifyClient::event(i18n("Couldn't upload file!"));
					}
				}
	  };
  /////////////////////////////////////////////////

  modified=false;
  return true;
}

void Katalysator2Doc::deleteContents()
{
  /////////////////////////////////////////////////
  // TODO: Add implementation to delete the document contents
	delete doc;

  /////////////////////////////////////////////////

}
/** Erzeugt ein Neues Objekt vom Typ Trohr und gibt es zur�ck */
Trohr * Katalysator2Doc::NewPipe(){
	Trohr * r =new Trohr;
//	Werte.append(r);
	cout<<"NewPipe"<<endl;
	
  QDomElement docElem = doc->documentElement();
  QDomElement elem = doc->createElement( "pipe" );
  elem.setAttribute( "diameter", r->getdurchmesser() );
  docElem.appendChild( elem );

	modified=true;
	return r;
}
/** Speichert den �bergebenen Wert ab */
//void Katalysator2Doc::speichere_Werte(Tkatbasis * in){
//	in->speichere();
//}
/** Gibt eine Referenz auf die verwendeten Rohre, Kats zur�ck */
TWerte & Katalysator2Doc::getWerte(void){
	return Werte;
}
