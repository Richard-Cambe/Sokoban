#include "../inc/sokoban.h"

void move_box(game * sokoban, char * move)
{
    if(compare_positions(sokoban->player, sokoban->box) == 1)
    {
        if(strcmp(move, "up") == 0)
        {
            if(sokoban->box.pos_y > 0)
            {
                sokoban->box.pos_y--;
            }
        }
        else if(strcmp(move, "down") == 0)
        {
            if(sokoban->box.pos_y < 9)
            {
                sokoban->box.pos_y++;
            }
        }
        else if(strcmp(move, "left") == 0)
        {
            if(sokoban->box.pos_x > 0)
            {
                sokoban->box.pos_x--;
            }
        }
        else if(strcmp(move, "right") == 0)
        {
            if(sokoban->box.pos_x < 9)
            {
                sokoban->box.pos_x++;
            }
        }
    }
}

void move_up(game * sokoban)
{
    if(sokoban->player.pos_y > 0) // if the player is not already on top of the map
    {
        position tmp;
        tmp.pos_y = sokoban->player.pos_y - 1;
        tmp.pos_x = sokoban->player.pos_x;

	sokoban->map[sokoban->player.pos_y][sokoban->player.pos_x]=' ';
	sokoban->player=tmp; //THAT IS REAL
	sokoban->map[sokoban->player.pos_y][sokoban->player.pos_x]='o'; //ZAT IS POUDROZIEU = AFFICHAGE
        move_box(sokoban, "up");
    }
}

void move_down(game * sokoban)
{
    if(sokoban->player.pos_y < 9) // if the player is not already on the bottom of the map
    {
        position tmp;
        tmp.pos_y = sokoban->player.pos_y + 1;
        tmp.pos_x = sokoban->player.pos_x;

        	sokoban->map[sokoban->player.pos_y][sokoban->player.pos_x]=' ';
	sokoban->player=tmp; //THAT IS REAL
	sokoban->map[sokoban->player.pos_y][sokoban->player.pos_x]='o'; //ZAT IS POUDROZIEU = AFFICHAGE
        move_box(sokoban, "down");
    }
}

void move_left(game * sokoban)
{
    if(sokoban->player.pos_x > 0) // if the player is not already on the left of the map
    {
        position tmp;
        tmp.pos_y = sokoban->player.pos_y;
        tmp.pos_x = sokoban->player.pos_x - 1;

       	sokoban->map[sokoban->player.pos_y][sokoban->player.pos_x]=' ';
	sokoban->player=tmp; //THAT IS REAL
	sokoban->map[sokoban->player.pos_y][sokoban->player.pos_x]='o'; //ZAT IS POUDROZIEU = AFFICHAGE 
        
       
        move_box(sokoban, "left");
    }
}

void move_right(game * sokoban)
{
    if(sokoban->player.pos_x < 9) // if the player is not already on the right of the map
    {
        position tmp;
        tmp.pos_y = sokoban->player.pos_y;
        tmp.pos_x = sokoban->player.pos_x + 1;

        sokoban->map[sokoban->player.pos_y][sokoban->player.pos_x]=' ';
        sokoban->player=tmp; //THAT IS REAL
        sokoban->map[sokoban->player.pos_y][sokoban->player.pos_x]='o'; //ZAT IS POUDROZIEU = AFFICHAGE

        move_box(sokoban, "right");
    }
}

void handle_move(game * sokoban, char * move)
{
  // here code the if / else if to call the appropriate move function

   if(strcmp(move, "UP") == 0)
    {
        move_up(sokoban);
    }
    else if(strcmp(move, "DOWN") == 0)
    {
        move_down(sokoban);
    }
    else if(strcmp(move, "RIGHT") == 0)
    {
        move_right(sokoban);
    }
    else if(strcmp(move, "LEFT") == 0)
    {
        move_left(sokoban);
    }
}

void ask_for_move(game * sokoban){
// here code asking the user for the move
    printf ("Where do you want to go ?\n UP-DOWN-LEFT-RIGHT \n");

    char userinput[10];
    scanf ("%s" , userinput);

    handle_move(sokoban , userinput);
}