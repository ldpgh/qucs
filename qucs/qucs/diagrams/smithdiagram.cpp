/***************************************************************************
                          smithdiagram.cpp  -  description
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

#include "smithdiagram.h"
#include "main.h"

#include <math.h>


SmithDiagram::SmithDiagram(int _cx, int _cy, bool ImpMode) : Diagram(_cx, _cy)
{
  x1 = 10;     // position of label text
  y1 = 16;
  x2 = 200;    // initial size of diagram
  y2 = 200;
  if(ImpMode)  Name = "Smith";  // with impedance circles
  else  Name = "ySmith";        // with admittance circles

  calcDiagram();    // calculate circles for smith chart with |r|=1
}

SmithDiagram::~SmithDiagram()
{
}

// ------------------------------------------------------------
// calculate the screen coordinates for the graph data
void SmithDiagram::calcCoordinate(double, double yr, double yi,
				 int *px, int *py, Axis*)
{
  *px = (x2>>1)+int(yr/ylAxis.up*double(x2>>1) + 0.5);
  *py = (y2>>1)+int(yi/ylAxis.up*double(y2>>1) + 0.5);
}


// ------------------------------------------------------------
// calculate the circles and arcs of the smith chart
int SmithDiagram::calcDiagram()
{
  Lines.clear();
  Texts.clear();
  Arcs.clear();

  if(Name.at(0) == 'y')  createSmithChart(&ylAxis, 6);
  else  createSmithChart(&ylAxis);

  // outer most circle
  Arcs.append(new Arc(0, x2, x2, x2, 0, 16*360, QPen(QPen::black,0)));

  // horizontal line Im(r)=0
  Lines.append(new Line(0, x2>>1, x2, x2>>1, GridPen));

  return 1;
}

// ------------------------------------------------------------
SmithDiagram* SmithDiagram::newOne()
{
  return new SmithDiagram();
}
