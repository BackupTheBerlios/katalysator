/***************************************************************************
                          tedelmetall.cpp  -  description
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

#include "tedelmetall.h"

TEdelmetall::TEdelmetall(){
}
TEdelmetall::~TEdelmetall(){
}
/** Setzen der Masse des Platin */
void TEdelmetall::setm_platin(treal in){
	m_platin=in;
}
/** Setzt die Masse des Paladiums */
void TEdelmetall::setm_paladium(treal in){
	m_paladium=in;
}
/** Setzen der Masse des Rhodium */
void TEdelmetall::setm_rhodium(treal in){
	m_rhodium=in;
}
/** Setzt den Preis des Platins */
void TEdelmetall::setpreis_platin(treal in){
	preis_platin=in;
}
/** Setzt den Preis des Paladiums */
void TEdelmetall::setpreis_paladium(treal in){
	preis_paladium=in;
}
/** Setzt den Preis des Rhodiums */
void TEdelmetall::setpreis_rhodium(treal in){
	preis_rhodium=in;
}
