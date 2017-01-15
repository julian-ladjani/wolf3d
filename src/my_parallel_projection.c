/*
** my_parallel_projection.c for wireframe in /home/julian-ladjani/delivery/CGP/wireframe/src
**
** Made by Julian Ladjani
** Login  <julian.ladjani@epitech.eu>
**
** Started on  Apr Dec 7 21:25:05 2016 Julian Ladjani
** Last update Jul Dec 10 18:35:21 2016 Julian Ladjani
*/

#include "my.h"

sfVector2i	my_parallel_projection(sfVector3f pos3d, float angle)
{
  sfVector2i	point;

  point.x = (int) (pos3d.x - pos3d.y * sinf(angle));
  point.y = (int) (pos3d.y * cosf(angle) - pos3d.z);
  return (point);
}
