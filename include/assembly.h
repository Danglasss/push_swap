/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembly.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 18:03:09 by danglass          #+#    #+#             */
/*   Updated: 2019/04/30 20:06:33 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSEMBLY_H

# define ASSEMBLY_H
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

/*
** ft_redirection :
*/

int		ft_sort(int *list_a, int *list_b, int *len);
int		ft_check_instruc(char *num);
void	ft_sort_rb(int *list_a, int *list_b, int *len, int *lin);
void	ft_sort_ra(int *list_a, int *list_b, int *len, int *lin);
void	ft_redirection(int *list_a, int *list_b, int *len, char **nombre);

/*
** ft_tool_ope :
*/

int		ft_letter_tab(char **tab, int argc);
int		ft_letter(char *tab);
void	ft_try_rotate(int *list_a, int *list_b, int *len, int *index);
void	ft_try_reverse(int *list_a, int *list_b, int *len, char letter);
void	ft_try_swap(int *list_a, int *list_b);
int		ft_path_first(int *list_a, int len_a, int index);

/*
** help_algo_sort :
*/

void	ft_restore(int *list_a, int *list_b, int *len, char **nombre);
int		ft_checkright(int *list_a, int len);
int		ft_countlen(int *list_b, int len, int index, int pivot_mix);
int		ft_len_sort(int *list, int len, int lin, int count);
int		ft_countlen_a(int *list_a, int len, int index, int pivot_mix);

/*
** algo_sort :
*/

void	ft_qsort(int *list_a, int *list_b, int *len);
void	ft_main_qsort_b(int *list_a, int *list_b, int *len, int *lin);
void	ft_sort_list_0(int *list_a, int *list_b, int *len, int *lin);
void	ft_main_qsort_a(int *list_a, int *list_b, int *len, int *lin);
int		ft_select_sort(int *list_a, int *list_b, int *len, int len_m);
int		ft_qsort_a(int *list_a, int *list_b, int *len, int *lin);
void	ft_sort_list_1(int *list_a, int *list_b, int *len, int *lin);
void	ft_selectsort(int *list_a, int *list_b, int *len);
void	ft_make_swap(int *list_a, int *list_b, int *len);

/*
** operateur :
*/

void	ft_swap(int *pile, char letter);
void	ft_swap_all(int *pile_a, int *pile_b);
void	ft_push(int *pile_1, int *pile_2, int *len_1, int *len_2);
void	ft_rotate(int *pile, int len, char letter);
void	ft_rotate_all(int *pile_1, int *pile_2, int len_1, int len_2);
void	ft_reverse(int *pile, int len, char letter);
void	ft_reverse_all(int *pile_1, int *pile_2, int len_1, int len_2);

/*
** ft_tool_swap :
*/

void	ft_free(char **tab);
int		ft_checker_sort(int *list, int len, int len_b);
int		ft_doublon(int *list_a, int len);
int		ft_checks(int *list, int len);
int		ft_check_sort_a(int *list, int *len);
int		ft_check_sort(int *list, int len);
void	ft_join_list(int *list_a, int *list_b, int *len);
int		ft_moyenne(int *list_a, int len_a);
int		ft_path_step(int len, int index, char letter);
int		ft_check_down(int *list, int len, int chiffre);
int		ft_check_up(int *list, int len, int chiffre);
void	ft_sort_back(int *list_b, int *list_a, int *len, int sens);
int		ft_mediane(int *list_o, int len, int sens);

/*
** Optimisation :
*/

void	ft_sort_list_a(int *list_a);
int		ft_number_a(int *list, int len);

/*
** fonction test :
*/

void	ft_putint(int *list_a, int len);
void	ft_putintn(int *list_a, int len);

/*
**	ft_check_error :
*/

int		ft_check_erreur_sort(int *list_a, int *len, char **i);
int		ft_check_erreur(int *list_a, int *len, char **nombre);
int		ft_error(char **content);

/*
**	ft_check_operateur :
*/

void	ft_swap_checker(int *list_a, int *list_b, char *l, int *len);
void	ft_push_checker(int *list_a, int *list_b, int *len, char *l);
void	ft_rotate_checker(int *list_a, int *list_b, int *len, char *l);
void	ft_reverse_checker(int *list_a, int *list_b, int *len, char *l);
void	ft_reverse_all_checker(int *list_a, int *list_b, int *len);
void	ft_rotate_all_checker(int *list_a, int *list_b, int *len);
void	ft_swap_all_checker(int *list_a, int *list_b, int *len);
void	ft_main_sort(int *list_a, int *list_b, int *len, int large);
int		ft_compte(int pivot, int sens, int *list, int len);
void	ft_quicksort(int *list_a, int *list_b, int *len, int *pivot);
void	ft_sort_swap(int *list_a, int *list_b, int *len);
void	main_quicksort(int *list_a, int *list_b, int *len);
void	ft_sortlist(int *list_a, int *list_b, int *len);
void	quicksort_a(int *list_a, int *list_b, int *len, int *size);
int		ft_stop_error(char *instruct, char *a_free);

#endif
