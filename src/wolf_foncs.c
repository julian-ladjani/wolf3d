/*
** wireframe_foncs.c for wireframe in /home/julian-ladjani/delivery/CGP/wireframe/src
**
** Made by Julian Ladjani
** Login  <julian.ladjani@epitech.eu>
**
** Started on  May Dec 8 22:54:48 2016 Julian Ladjani
** Last update Jan Jan 15 22:51:43 2017 Julian Ladjani
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
      if (type == 0 || tab.color == NULL)
	color = sfYellow;
      if (rayval.side == 1)
	{
	  color.r = color.r / 1.2;
	  color.g = color.g / 1.2;
	  color.b = color.b / 1.2;
	}
      my_draw_line(tab.buffer, rayval.from, rayval.to, color);
      my_put_pixel(tab.buffer, rayval.from.x, rayval.from.y, sfBlack);
      x++;
    }
}

void		draw_aim(t_int_tab tab)
{
  sfVector2i	from;
  sfVector2i	to;

  from.x = tab.buffer->width / 2;
  to.x = tab.buffer->width / 2;
  from.y = (tab.buffer->height / 2) - 10;
  to.y = (tab.buffer->height / 2) + 10;
  my_draw_line(tab.buffer, from, to, sfBlack);
  from.y = tab.buffer->height / 2;
  to.y = tab.buffer->height / 2;
  from.x = (tab.buffer->width / 2) - 10;
  to.x = (tab.buffer->width / 2) + 10;
  my_draw_line(tab.buffer, from, to, sfBlack);
}

void		draw_sky(t_int_tab tab)
{
  int		x;
  int		y;
  sfColor	color;

  x = 0;
  y = 0;
  color.r = 0;
  color.g = 0;
  color.b = 80;
  color.a = 255;
  while (y < (tab.buffer->height / 2))
    {
      while (x < (tab.buffer->width))
	{
	  my_put_pixel(tab.buffer, x, y, color);
	  x++;
	}
      y++;
      x = 0;
    }
}

int		draw_wireframe(t_int_tab tab)
{
  draw_sky(tab);
  draw_raycast(tab);
  draw_aim(tab);
  return (0);
}
