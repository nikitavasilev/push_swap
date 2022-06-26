/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:13:18 by nvasilev          #+#    #+#             */
/*   Updated: 2022/06/26 18:13:20 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

struct node {
	int val, len;
	struct node *next;
};

void lis(int *v, int len)
{
	int i;
	struct node *p, *n = calloc(len, sizeof *n);
	for (i = 0; i < len; i++)
		n[i].val = v[i];

	for (i = len; i--; ) {
		// find longest chain that can follow n[i]
		for (p = n + i; p++ < n + len; ) {
			if (p->val > n[i].val && p->len >= n[i].len) {
				n[i].next = p;
				n[i].len = p->len + 1;
			}
		}
	}

	// find longest chain
	for (i = 0, p = n; i < len; i++)
		if (n[i].len > p->len) p = n + i;

	do printf(" %d", p->val); while ((p = p->next));
	putchar('\n');

	free(n);
}

int main(void)
{
	int x[] = { 3, 2, 6, 4, 5, 1 };
	int y[] = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
	int z[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
	int	w[] = { 427, 196185, -3794, 527, -614476, 75375, 7283, -24, 51, 0, -309402330, -100228292, -4, -946, 76087, 267583, -22, 229468087, -28036, -90418, 514705, 8317, -12278, -5614948, 4173323, 43, 69, 1712221, -312519784, 649, -12691720, -218293578, -5468528, -5822548, 5385305, 2163, -356, -52250, -545737654, 1, 651917601, -148362020, 175172175, -3900, 377830107, -200212, -8, -861164, 529, 806597, -476112, 5, -2140, -482337434, -426, 34027, -857218, 9789427, 142099, -13150796, 74307, -964648, 1052453, -70, -630299972, 9, -57445072, -89874162, -32987932, 373417881, 935479151, 228360319, 18273469, -24625504, 201, -71101616, -83406, 18559, -53439050, -610260184, -938, -812620, -420049612, -6479768, 7823919, -86592038, 7532221, -916892010, 82881383, -14, 341, 893317675, 273, -96, -35556, 10381, -870499896, -87052, -5125400, 908122253 };

	lis(x, sizeof(x) / sizeof(int));
	lis(y, sizeof(y) / sizeof(int));
	lis(z, sizeof(z) / sizeof(int));
	lis(w, sizeof(w) / sizeof(int));
	return (0);
}
