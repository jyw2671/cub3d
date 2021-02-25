/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 18:15:30 by yjung             #+#    #+#             */
/*   Updated: 2021/02/25 18:04:39 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_player_pos(t_cub3d *g, float x, float y)
{
	t_vec	pos;

	if ('1' == g->map.data[(int)y][(int)x])
		return ;
	if ('2' == g->map.data[(int)y][(int)x])
	{
		pos = new_vec(x - floor(x), y - floor(y));
		// <math.h>의 함수 -> 소수점 아래를 버린다
		if ((0.2 < pos.x && pos.x < 0.8) && (0.2 < pos.y && pos.y < 0.8))
			return ;
	}
	g->pos.x = x;
	g->pos.y = y;
	return ;
}

void		update_player(t_cub3d *g)
{
	t_ivec	turn_dir;
	t_ivec	walk_dir;
	t_vec	turn_vec;
	t_vec	new_pos;

	turn_dir.x = g->key.left ? -1 : 0;
	turn_dir.x += g->key.right ? 1 : 0;
	turn_dir.y = g->key.up ? 1 : 0;
	turn_dir.y += g->key.down ? -1 : 0;
	walk_dir.y = g->key.w ? 1 : 0;
	walk_dir.y += g->key.s ? -1 : 0;
	walk_dir.x = g->key.a ? -1 : 0;
	walk_dir.x += g->key.d ? 1 : 0;
	g->dir = rot_vec(g->dir, turn_dir.x * TURN_S * M_PI_180);
	// g->key.left는 x축에서 왼쪽이므로 -1, g->key.right는 x축에서 오른쪽이므로 1을
	// 누적해서 더해준다. 그 후 키가 눌러진만큼 3도씩을 곱해 앵글을 회전시켜준다
	g->plane = rot_vec(g->plane, turn_dir.x * TURN_S * M_PI_180);
	turn_vec = rot_vec(g->dir, 90 * M_PI_180);
	if (walk_dir.x != 0 || walk_dir.y != 0)
	{
		new_pos.x = g->pos.x + g->dir.x * (walk_dir.y * WALK_S);
		new_pos.y = g->pos.y + g->dir.y * (walk_dir.y * WALK_S);
		new_pos.x += turn_vec.x * (walk_dir.x * WALK_S);
		new_pos.y += turn_vec.y * (walk_dir.x * WALK_S);
		check_player_pos(g, new_pos.x, new_pos.y);
	}
}
// turn_dir.y에서 up & down 키 입력시에는 제한 범위가 있어야 할 것 같다
// 일정 값 이상 위 아래 회전시 제한 범위가