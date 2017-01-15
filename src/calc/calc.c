/*
** calc.c for wireframe in /home/julian-ladjani/delivery/CGP/wireframe/src/calc
**
** Made by Julian Ladjani
** Login  <julian.ladjani@epitech.eu>
**
** Started on  Jun Dec 9 14:16:17 2016 Julian Ladjani
** Last update Jan Jan 15 22:48:44 2017 Julian Ladjani
*/

#include "my.h"

t_int_tab	player_pos(t_int_tab tab)
{
  int		x;
  int		y;

  x = 0;
  y = 0;
  while (tab.tab[x][y] != -1)
    {
      if (y == tab.xlenght)
	{
	  x++;
	  y = 0;
	}
      else
	y++;
    }
  tab.pos.x = (float) (x + 0.5);
  tab.pos.y = (float) (y + 0.5);
  return (tab);
}

t_int_tab	my_color(t_int_tab tab)
{
  if ((tab.color = malloc(9 * sizeof(sfColor) + 1)) != NULL)
    {
      tab.color[0] = sfTransparent;
      tab.color[1] = sfRed;
      tab.color[2] = sfBlue;
      tab.color[3] = sfGreen;
      tab.color[4] = sfWhite;
      tab.color[5] = sfYellow;
      tab.color[6] = sfCyan;
      tab.color[7] = sfMagenta;
      tab.color[8] = sfBlack;
    }
  tab.colorreset.r = 0;
  tab.colorreset.g = 80;
  tab.colorreset.b = 0;
  tab.colorreset.a = 255;
  return (tab);
}

t_int_tab	my_init(t_int_tab tab)
{
  tab.mapsize.x = tab.ylenght;
  tab.mapsize.y = tab.xlenght;
  tab.dir.x = -1;
  tab.dir.y = 0;
  tab.plane.x = 0;
  tab.plane.y = 0.80;
  tab.moupos.x = tab.buffer->width / 2;
  tab.moupos.y = tab.buffer->height / 2;
  tab.rotspeed = 0.05;
  tab.walk = 0.05;
  tab.run = 0.2;
  tab = my_color(tab);
  tab = player_pos(tab);
  return (tab);
}
