/*
** my_draw_line.c for wireframe in /home/julian-ladjani/delivery/CGP/wireframe/src
**
** Made by Julian Ladjani
** Login  <julian.ladjani@epitech.eu>
**
** Started on  Mar Dec 6 18:07:55 2016 Julian Ladjani
** Last update Jan Dec 11 19:42:30 2016 Julian Ladjani
*/

#include "my.h"

void		my_draw_line_case_1(t_my_framebuffer *buffer, sfVector2i from,
			     sfVector2i to, sfColor color)
{
  int		x;
  int		y;
  double 	a;
  double	 b;

  a = (double) (to.y - from.y) / (double)(to.x - from.x);
  b = from.y - a * from.x;
  x = from.x;
  while (x <= to.x)
    {
      y = (int) (a * x + b);
      my_put_pixel(buffer, x, y, color);
      x += 1;
    }
}

void		my_draw_line_case_2(t_my_framebuffer *buffer, sfVector2i from,
			     sfVector2i to, sfColor color)
{
  int		x;
  int		y;
  double 	a;
  double	 b;

  if ((to.x - from.x) != 0)
    a = (double) (to.y - from.y) / (double)(to.x - from.x);
  else
    a = 0;
  b = from.y - a * from.x;
  x = from.x;
  y = from.y;
  while (y <= to.y)
    {
      if (a != 0)
	x = (y - b) / a;
      else
	x = from.x;
      my_put_pixel(buffer, x, y, color);
      y += 1;
    }
}

void		my_draw_line(t_my_framebuffer *buffer, sfVector2i from,
			     sfVector2i to, sfColor color)
{
  if (abs(to.x - from.x) >= abs(to.y - from.y))
    {
      if (to.x >= from.x)
	my_draw_line_case_1(buffer, from, to, color);
      else
	my_draw_line_case_1(buffer, to, from, color);
    }
  else
    {
      if (to.y >= from.y)
	my_draw_line_case_2(buffer, from, to, color);
      else
	my_draw_line_case_2(buffer, to, from, color);
    }
}
