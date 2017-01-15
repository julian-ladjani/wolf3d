/*
** wireframe_foncs.c for wireframe in /home/julian-ladjani/delivery/CGP/wireframe/src
**
** Made by Julian Ladjani
** Login  <julian.ladjani@epitech.eu>
**
** Started on  May Dec 8 22:54:48 2016 Julian Ladjani
** Last update Jan Jan 15 20:34:04 2017 Julian Ladjani
*/

#include "my.h"

void		draw_raycast(t_int_tab tab)
{
  int		x;
  sfColor	color;
  t_my_raycast	rayval;
  int		type;

  x = 0;
  while (x < SCREEN_WIDTH)
    {
      rayval = raycast(tab, rayval, x);
      type = tab.tab[rayval.mappos.x][rayval.mappos.y];
      if (tab.color != NULL)
	color = tab.color[type];
      if (type > 8 || type == 0 || tab.color == NULL)
	color = sfYellow;
      if (rayval.side == 1)
	{
	  color.r = color.r / 1.2;
	  color.g = color.g / 1.2;
	  color.b = color.b / 1.2;
	}
      my_draw_line(tab.buffer, rayval.from, rayval.to, color);
      x++;
    }
}

int		draw_wireframe(t_int_tab tab)
{
  draw_raycast(tab);
  return (0);
}
