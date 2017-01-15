/*
** calc2.c for wireframe in /home/julian-ladjani/delivery/CGP/wireframe/src/calc
**
** Made by Julian Ladjani
** Login  <julian.ladjani@epitech.eu>
**
** Started on  Jul Dec 10 18:55:30 2016 Julian Ladjani
** Last update Jan Jan 15 17:36:02 2017 Julian Ladjani
*/

#include "my.h"

t_int_tab	bonus_reset(t_int_tab tab)
{

  return (tab);
}

t_int_tab	move_updown(t_int_tab tab, sfEvent event)
{
  float		speed;

  if (sfKeyboard_isKeyPressed(sfKeyLShift))
    speed = tab.run;
  else
    speed = tab.walk;
  if (sfKeyboard_isKeyPressed(sfKeyZ))
    {
      if (tab.tab[(int)(tab.pos.x + tab.dir.x * speed)][(int)tab.pos.y] < 1)
	tab.pos.x += tab.dir.x * speed;
      if (tab.tab[(int)tab.pos.x][(int)(tab.pos.y + tab.dir.y * speed)] < 1)
	tab.pos.y += tab.dir.y * speed;
    }
  else if (sfKeyboard_isKeyPressed(sfKeyS))
    {
      if (tab.tab[(int)(tab.pos.x - tab.dir.x * 0.1)][(int)tab.pos.y] < 1)
	tab.pos.x -= tab.dir.x * 0.1;
      if (tab.tab[(int)tab.pos.x][(int)(tab.pos.y - tab.dir.y * 0.1)] < 1)
	tab.pos.y -= tab.dir.y * 0.1;
    }
  return (tab);
}

t_int_tab	move_rightleft(t_int_tab tab, sfEvent event)
{
  float		speed;

  if (sfKeyboard_isKeyPressed(sfKeyLShift))
    speed = tab.run;
  else
    speed = tab.walk;
  if (sfKeyboard_isKeyPressed(sfKeyQ))
    {
      if (tab.tab[(int)tab.pos.x][(int)(tab.pos.y + fabs(tab.dir.x) * speed)] < 1)
	tab.pos.y += fabs(tab.dir.x) * speed;
      if (tab.tab[(int)(tab.pos.x + fabs(tab.dir.y) * speed)][(int)tab.pos.y] < 1)
	tab.pos.x += fabs(tab.dir.y) * speed;
    }
  else if (sfKeyboard_isKeyPressed(sfKeyD))
    {
      if (tab.tab[(int)tab.pos.x][(int)(tab.pos.y - tab.dir.x * speed)] < 1)
	tab.pos.y -= tab.dir.x * speed;
      if (tab.tab[(int)(tab.pos.x - tab.dir.y * speed)][(int)tab.pos.y] < 1)
	tab.pos.x -= tab.dir.y * speed;
    }
  return (tab);
}

t_int_tab	move_dir(t_int_tab tab, sfEvent event)
{
  float		dirtmp;
  float		planetmp;

  dirtmp = tab.dir.x;
  planetmp = tab.plane.x;
  if (sfKeyboard_isKeyPressed(sfKeyA))
    {
      tab.dir.x = tab.dir.x * cos(tab.rotspeed) - tab.dir.y * sin(tab.rotspeed);
      tab.dir.y = dirtmp * sin(tab.rotspeed) + tab.dir.y * cos(tab.rotspeed);
      tab.plane.x = tab.plane.x * cos(tab.rotspeed) -
	  tab.plane.y * sin(tab.rotspeed);
      tab.plane.y = planetmp * sin(tab.rotspeed) +
	  tab.plane.y * cos(tab.rotspeed);
    }
  else if (sfKeyboard_isKeyPressed(sfKeyE))
    {
      tab.dir.x = tab.dir.x * cos(-tab.rotspeed) - tab.dir.y * sin(-tab.rotspeed);
      tab.dir.y = dirtmp * sin(-tab.rotspeed) + tab.dir.y * cos(-tab.rotspeed);
      tab.plane.x = tab.plane.x * cos(-tab.rotspeed) -
	  tab.plane.y * sin(-tab.rotspeed);
      tab.plane.y = planetmp * sin(-tab.rotspeed) +
	  tab.plane.y * cos(-tab.rotspeed);
    }
  return (tab);
}

t_int_tab	action_bonus(t_int_tab tab, sfEvent event)
{
  tab = move_updown(tab, event);
  tab = move_rightleft(tab, event);
  tab = move_dir(tab, event);
  return (tab);
}
