/*
** raycast.c for wolf3d in /home/julian-ladjani/delivery/CGP/Wolf3d/wolf3d/src
**
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
**
** Started on  Thu Jan 12 13:21:47 2017 julian ladjani
** Last update Jan Jan 15 21:15:21 2017 Julian Ladjani
*/

#include "my.h"

t_my_raycast	raycast(t_int_tab tab, t_my_raycast rayval, int x)
{
  rayval.hit = 0;
  rayval.camerax = 2 * x / (float)tab.buffer->width - 1;
  rayval.raypos.x = tab.pos.x;
  rayval.raypos.y = tab.pos.y;
  rayval.raydir.x = tab.dir.x + tab.plane.x * rayval.camerax;
  rayval.raydir.y = tab.dir.y + tab.plane.y * rayval.camerax;
  rayval.mappos.x = (int)rayval.raypos.x;
  rayval.mappos.y = (int)rayval.raypos.y;
  rayval.deltadist.x = sqrt(1 + (rayval.raydir.y * rayval.raydir.y)
			    / (rayval.raydir.x * rayval.raydir.x));
  rayval.deltadist.y = sqrt(1 + (rayval.raydir.x * rayval.raydir.x)
      / (rayval.raydir.y * rayval.raydir.y));
  rayval = calc_sidedist(rayval);
  rayval = calc_dda(tab, rayval);
  rayval = calc_line(tab, rayval, x);
  return (rayval);
}

t_my_raycast	calc_sidedist(t_my_raycast rayval)
{
  if (rayval.raydir.x < 0)
    {
      rayval.step.x = -1;
      rayval.sidedist.x = (rayval.raypos.x - rayval.mappos.x);
      rayval.sidedist.x *= rayval.deltadist.x;
    }
  else
    {
      rayval.step.x = 1;
      rayval.sidedist.x = (rayval.mappos.x + 1.0 - rayval.raypos.x);
      rayval.sidedist.x *= rayval.deltadist.x;
    }
  if (rayval.raydir.y < 0)
    {
      rayval.step.y = -1;
      rayval.sidedist.y = (rayval.raypos.y - rayval.mappos.y);
      rayval.sidedist.y *= rayval.deltadist.y;
    }
  else
    {
      rayval.step.y = 1;
      rayval.sidedist.y = (rayval.mappos.y + 1.0 - rayval.raypos.y);
      rayval.sidedist.y *= rayval.deltadist.y;
    }
  return (rayval);
}

t_my_raycast	calc_dda(t_int_tab tab, t_my_raycast rayval)
{
  while (rayval.hit == 0)
    {
      if (rayval.sidedist.x < rayval.sidedist.y)
	{
	  rayval.sidedist.x += rayval.deltadist.x;
	  rayval.mappos.x += rayval.step.x;
	  rayval.side = 0;
	}
      else
	{
	  rayval.sidedist.y += rayval.deltadist.y;
	  rayval.mappos.y += rayval.step.y;
	  rayval.side = 1;
	}
      if (tab.tab[rayval.mappos.x][rayval.mappos.y] > 0)
	rayval.hit = 1;
    }
  return (rayval);
}

t_my_raycast	calc_line(t_int_tab tab, t_my_raycast rayval, int x)
{
  int		lineheight;

  if (rayval.side == 0)
    rayval.perpwalldist = (rayval.mappos.x - rayval.raypos.x +
			   (1 - rayval.step.x) / 2) / rayval.raydir.x;
  else
    rayval.perpwalldist = (rayval.mappos.y - rayval.raypos.y +
			   (1 - rayval.step.y) / 2) / rayval.raydir.y;
  lineheight = (int)(SCREEN_HEIGHT / rayval.perpwalldist);
  rayval.from.x = x;
  rayval.to.x = x;
  rayval.from.y = -lineheight / 2 + tab.buffer->height / 2;
  if (rayval.from.y < 0)
    rayval.from.y = 0;
  rayval.to.y = lineheight / 2 + tab.buffer->height / 2;
  if (rayval.to.y >= SCREEN_HEIGHT)
    rayval.to.y = SCREEN_HEIGHT - 1;
  return (rayval);
}
