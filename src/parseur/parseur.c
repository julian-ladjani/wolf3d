/*
** parseur.c for wireframe in /home/julian-ladjani/delivery/CGP/wireframe/src/parseur
**
** Made by Julian Ladjani
** Login  <julian.ladjani@epitech.eu>
**
** Started on  May Dec 8 09:04:16 2016 Julian Ladjani
** Last update Feb Dec 12 01:55:05 2016 Julian Ladjani
*/

#include "my.h"

int		char_number_line(char *buff)
{
  int		i;
  int		nb;

  i = 0;
  nb = 0;
  while (buff[i] != '\n' && buff[i] != '\0')
    {
      if (buff[i] == ',')
	nb++;
      i++;
      if (buff[i] != '\0' && buff[i + 1] == '\0')
	nb++;
    }
  return (nb);
}

int		check_char_number_line(char *buff)
{
  int		i;
  int		nb;
  int		nb2;

  nb = char_number_line(buff);
  i = char_number(buff) + 1;
  while (buff[i] != '\0')
    {
      nb2 = char_number_line(buff + i);
      if (nb2 != nb)
	return (0);
      i += char_number(buff + i) + 1;
    }
  return (1);
}

int		char_number_dot(char *buff)
{
  int		i;

  i = 0;
  while (buff[i] != ',' && buff[i] != '\0')
    i++;
  if (buff[i] == '\0')
    i--;
  return (i);
}

t_int_tab	read_it(char *path)
{
  char		*buff;
  int		offset;
  int		len;
  int		fd;
  t_int_tab	tab;

  offset = 0;
  tab.tab = NULL;
  if ((fd = open(path, O_RDONLY)) < 0)
    return (tab);
  if ((buff = malloc(BUFF_SIZE + 1)) == NULL)
      return (tab);
  while ((len = read(fd, buff + offset, BUFF_SIZE)) > 0)
    {
      offset = offset + len;
      if (check_buffer(buff) != 1)
	return (tab);
      buff = my_realloc(buff, BUFF_SIZE + 1);
    }
  if (offset <= 0 || len < 0)
    return (tab);
  buff[offset] = '\0';
  return (parse_my_int(buff));
}

t_int_tab	parse_my_int(char *buff)
{
  int		i;
  int		**it_tab;
  t_int_tab	tab;

  i = 0;
  tab.tab = NULL;
  if ((it_tab = malloc((tab_number(buff) + 1) * sizeof(int *))) == NULL ||
      check_char_number_line(buff) < 1)
    return (tab);
  if ((tab.xlenght = char_number_line(buff)) < 2 || tab.xlenght > 500)
    return (tab);
  while (*buff != '\0')
    {
      it_tab[i] = malloc(sizeof(int) * char_number_line(buff));
      if (set_in_intab(buff, it_tab[i]) == NULL)
	return (tab);
      buff += char_number(buff) + 1;
      i++;
    }
  if ((tab.ylenght = i) < 2 || tab.ylenght > 500)
    return (tab);
  tab.tab = it_tab;
  return (tab);
}
