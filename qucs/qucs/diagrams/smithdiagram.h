/***************************************************************************
                          smithdiagram.h  -  description
                             -------------------
    begin                : Sat Oct 18 2003
    copyright            : (C) 2003 by Michael Margraf
    email                : michael.margraf@alumni.tu-berlin.de
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef SMITHDIAGRAM_H
#define SMITHDIAGRAM_H

#include "diagram.h"


/**
  *@author Michael Margraf
  */

class SmithDiagram : public Diagram  {
public: 
  SmithDiagram(int _cx=0, int _cy=0, bool ImpMode=true);
  ~SmithDiagram();


  SmithDiagram* newOne();
  int   calcDiagram();
  void  calcCoordinate(double, double, double, int*, int*, Axis*);
};

#endif
