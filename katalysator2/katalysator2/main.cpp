/***************************************************************************
                          main.cpp  -  description
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

#include <kcmdlineargs.h>
#include <kaboutdata.h>
#include <klocale.h>

#include "katalysator2.h"

static const char *description =
	I18N_NOOP("Katalysator2");
// INSERT A DESCRIPTION FOR YOUR APPLICATION HERE
	
	
static KCmdLineOptions options[] =
{
  { "+[File]", I18N_NOOP("file to open"), 0 },
  { 0, 0, 0 }
  // INSERT YOUR COMMANDLINE OPTIONS HERE
};

int main(int argc, char *argv[])
{

	KAboutData aboutData( "katalysator2", I18N_NOOP("Katalysator2"),
		VERSION, description, KAboutData::License_GPL,
		"(c) 2001, Holger Stock", 0, 0, "hstock@users.berlios.de");
	aboutData.addAuthor("Holger Stock",0, "hstock@users.berlios.de");
	KCmdLineArgs::init( argc, argv, &aboutData );
	KCmdLineArgs::addCmdLineOptions( options ); // Add our own options.

  KApplication app;
 
  if (app.isRestored())
  {
    RESTORE(Katalysator2App);
  }
  else 
  {
    Katalysator2App *katalysator2 = new Katalysator2App();
    katalysator2->show();

    KCmdLineArgs *args = KCmdLineArgs::parsedArgs();
		
		if (args->count())
		{
        katalysator2->openDocumentFile(args->arg(0));
		}
		else
		{
		  katalysator2->openDocumentFile();
		}
		args->clear();
  }

  return app.exec();
}  
