/***************************************************************************
                          tedelmetall.h  -  description
                             -------------------
    begin                : Tue Mar 6 2001
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

#ifndef TEDELMETALL_H
#define TEDELMETALL_H

#include <tkatbasis.h>

/**
  *@author Holger Stock
  */

class TEdelmetall {
private: // Private attributes
  //Massen in g
  /** Masse an Platin*/
  treal m_platin;
  /** Gewicht an Paladium */
  treal m_paladium;
  /** Gewicht an Rhodium */
  treal m_rhodium;
  // Preis der Edelmetalle
  /** Preis des Platins in EUR/g */
  treal preis_platin;
  /** Preis des  Paladiums in EUR/g */
  treal preis_paladium;
  /** Preis des Rhodiums in EUR/g */
  treal preis_rhodium;


public: 
	TEdelmetall();
	~TEdelmetall();
  /** Setzen der Masse des Platin */
  void setm_platin(treal in);
  /** Setzt die Masse des Paladiums */
  void setm_paladium(treal in);
  /** Setzen der Masse des Rhodium */
  void setm_rhodium(treal in);
  /** Setzt den Preis des Platins */
  void setpreis_platin(treal in);
  /** Setzt den Preis des Paladiums */
  void setpreis_paladium(treal in);
  /** Setzt den Preis des Rhodiums */
  void setpreis_rhodium(treal in);
	
};

#endif
