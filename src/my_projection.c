/*
** my_projection.c for wireframe in /home/julian-ladjani/delivery/CGP/wireframe/src
**
** Made by Julian Ladjani
** Login  <julian.ladjani@epitech.eu>
**
** Started on  Feb Dec 12 00:40:15 2016 Julian Ladjani
** Last update Feb Dec 12 01:15:24 2016 Julian Ladjani
*/

#include "my.h"

sfVector2i 	my_julian_projection(sfVector3f pos3d)
{
  sfVector2i	point;

  point.x = (pos3d.x - pos3d.z) / sqrt(2);
  point.y = (pos3d.x + 2 * pos3d.y + pos3d.z) / sqrt(6);
  return (point);
}
