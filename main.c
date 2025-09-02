/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 08:42:28 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/09/02 09:58:46 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int ft_min(int a, int b, int c) {
    int temp;

    temp = 0;

    if (a < b){
        temp=a;
    }else{
        temp=b;
    }
    if(temp<c)
        return temp;
    return c;
}

void ft_print_maps(char map[][28],int rows){
    int i;
    int j;

    i=0;
    while (i < rows) {
        j = 0;
        while (map[i][j]) {
            write(1, &map[i][j], 1);
            j++;
        }
        write(1, "\n", 1); 
        i++;
    }
}

void ft_mark_square(char map[][28], int max_i, int max_j, int size_max) {
    int i;
    int j;

    i = max_i;
    while (i > max_i - size_max) {
        j = max_j;
        while (j > max_j - size_max) {
            map[i][j] = 'x';
            j--;
        }
        i--;
    }
}

void ft_maps(char map[][28], int rows, int cols){
    int dp[rows][cols];
    int max;
    int max_i;
    int max_j;
    int i;
    int j;

    max = 0;
    max_i = 0;
    max_j = 0;
    i = 0;

    while (i < rows) {
        j = 0;
        while (j < cols) {
            if (map[i][j] == 'o')
                dp[i][j] = 0;
            else if (i == 0 || j == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = 1 + ft_min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);

            if (dp[i][j] > max) {
                max = dp[i][j];
                max_i = i;
                max_j = j;
            }
            j++;
        }
        i++;
    }
    ft_mark_square(map, max_i, max_j, max);
    ft_print_maps(map,rows);
}

int main(void) {
    // int argc, char **argv
    // if (argc != 2) {
    //     write(2, "Usage: ./bsq example_file", xx);
    //     return NULL;
    // }
    int rows; 
    int cols;

    rows=9;
    cols=28;
    
    char map[9][28] = {
            "...........................",
            "....o......................",
            "............o..............",
            "...........................",
            "....o......................",
            "...............o...........",
            "...........................",
            "......o..............o.....",
            "..o.......o................",
    };
    ft_maps(map, rows, cols);
    // ft_print_maps(map,rows);
    return 0;
}
