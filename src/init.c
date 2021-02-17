/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:14:47 by yjung             #+#    #+#             */
/*   Updated: 2021/02/17 16:18:55 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_window(t_cub3d *g, int flag)
{
	if (!flag)
	{
		if (!(g->win =
			mlx_new_window(g->mlx, g->v.width, g->v.height, CUB3D_TITLE)))
			exit_cub3d_msg(g, "fail mlx_new_window()");
	}
	if (!(g->v.ptr = mlx_new_image(g->mlx, g->v.width, g->v.height)))
		exit_cub3d_msg(g, "fail mlx_new_image()");
	if (!(g->v.data = (t_color *)mlx_get_data_addr(
		g->v.ptr, &g->v.bpp, &g->v.size_l, &g->v.endian)))
		exit_cub3d_msg(g, "fail mlx_get_data_addr()");
	g->v.line = g->v.size_l / (g->v.bpp / 8);
}

// 맵의 가로 세로 최대길이를 구하고 맵에 에러가 있는지를 먼저 깊이우선 탐색해주는 함수 만들기
void		init(t_cub3d *g, char *path, int flag)
{
	(!(g->mlx = mlx_init()) ? exit_cub3d_msg(g, "fail mlx_init()") : 0);
	mlx_get_screen_size(g->mlx, &g->v.width, &g->v.height);
	// cub3d가 받을 수 있는 디스플레이 최대 사이즈를 가지고 온다
	// 저걸 이용해서 map에 디스플레이 사이즈 보다 크면
	// mlx_get_screen_size 여기서 가져온 값으로 사용하도록 했음
	init_parse(g, path);
	// file 파싱하는 부분 전부 모아둔 부분
	// init_parse 내부에서 컬러 텍스쳐 맵 등등 전부 처리 한다 (.cub 파일에 있는 정보, )
	init_window(g, flag);
	//  init_window에서 윈도우 생성하고 그 뒤 초기화 필요한 정보들을 초기화한다
	g->num_rays = g->v.width / WALL_STRIP_WIDTH;
	if (!(g->rays = malloc(sizeof(t_ray) * g->num_rays)))
		exit_cub3d_msg(g, "malloc failed");
}
