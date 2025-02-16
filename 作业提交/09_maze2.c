#include<stdio.h>
#define LENGTH 20
#define WIDTH 20
int map[LENGTH][WIDTH] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 2, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1},    
	{1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1},                                                                           
	{1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1},    
	{1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1},
	{1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1},
	{1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1},
	{1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1},
	{1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1},
	{1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 1}, 
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};
int x,y;
void getmap()
{
	int a, b;
	for(a = 0; a<LENGTH; a++){
		for(b = 0; b < WIDTH; b++) {
			switch(map[a][b]) {
				case 1:printf("回");break;
				case 2:printf("嬲");break;
				case 3:printf("口");break; 
				default:printf("  ");break;
			}
		}
		printf("\n");
	}
}

void move(int a,int b,int c,int d,int f,int g)
{
	if(map[a][b] == 1) {
		if(f > a) {
			x++;
		}else if(f < a){
			x--;
		}else {
			if(g > d) {
				y++;
			}else {
				y--;
			}
		}
		printf("请不要破壁！"); 
	}else if(map[a][b] == 3) {
		map[c][d] = 2; map[f][g] = 0;
	}else {
		map[c][d] = 2; map[f][g] = 0;
	}
}
void play()
{
	int a,b,c,d,f,g;
	int direction;
	while(1) {
		system("cls");
		getmap();
		if(x == 18&&y == 18) {
			break;
		}
		direction = getch();
		switch(direction) {
			case 'w':a = c = --x;b = d = g = y;f = a+1;break;
			case 's':a = c = ++x;d = b = g = y;f = a-1;break;
			case 'a':d = b = --y;a = c = f = x;g = d+1;break;
			case 'd':d = b = ++y;c = a = f = x;g = d-1;break;
			default:printf("请键入方向键！(wasd为方向键)"); 
		}
		move(a,b,c,d,f,g);	
	}
}

int main()
{
	x = 1;y = 1;
	play();
	printf("恭喜你顺利通关");
	return 0;
}
