#include <ncurses.h>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;
int sw=0;
void menu2 ()
{

int i=0;
string input;
	initscr();
	cbreak();
	curs_set(0);
int yMax, xMax;
getmaxyx(stdscr, yMax, xMax);

WINDOW * menuwin = newwin (0, xMax, 0, 0);
WINDOW * win2 = newwin(0, xMax, 0, 0);
refresh();
wrefresh(menuwin);


keypad(menuwin, true);
keypad(win2, true);

string ytchoices[4] = {"Subscriptions", "Search","History","Back"};
int ytchoice;
int highlight2 = 0;
int option = 0;
string showin;

keypad(win2, true);
while(5)
{
	for (int k=0;k < 4; k++)
{		
	if(k == highlight2)
		wattron(win2, A_REVERSE);
		mvwprintw(win2, k+1, 1, ytchoices[k].c_str());
		wattroff(win2, A_REVERSE);


 }
ytchoice = wgetch(win2);

switch(ytchoice)
{
case KEY_UP:
  highlight2--;
  if(highlight2 == -1)
	highlight2 = 3;  
  break;
case KEY_DOWN:
  highlight2++;
  if(highlight2 == 4)
	  highlight2 = 0;
  break;
default:
break;
}

if(ytchoice == 10)
{
	break;

}

}
werase(win2);

switch(highlight2)
{
	case 0:
		endwin();
		system("clear");
		system("ytfzf -St");
		break;
	case 1:
		{
	mvwprintw(win2, 1,1,"What's on your mind?");
	mvwprintw(win2, 3,1,"Search:");
	wmove(win2, 4, 1);
	wrefresh(win2);
curs_set(1);
int c;
    do {
    c=getchar();
    if ( c == '\b' || c == KEY_DC || c == 127 || c == KEY_BACKSPACE) {
	    wrefresh(win2);
	    printf("\b");
	    showin.pop_back();
	    wrefresh(win2);
        }
    else{

    putchar (c);
    showin.append(1,c);
    }
  } while (c != '\r');

char command[300];
sprintf(command,"ytfzf -tl %s",showin.c_str());
endwin();
system("clear");
system(command);
	}

break;
	case 2:
{
	system("ytfzf -H");
	break;
}
	case 3:
{
	sw=1;
	break;
}
	default:
break;
}
}
void menu3 ()
{

int i=0;
initscr();
noecho();
cbreak();
curs_set(0);

int yMax, xMax;
getmaxyx(stdscr, yMax, xMax);
reset_prog_mode();
WINDOW * win3 = newwin (0, xMax, 0, 0);
refresh();
wrefresh(win3);
keypad(win3, true);

int highlight=0;
int choice;
string choices[4] = {"Search","History","Back"};

while(1)
{
	for (i=0;i < 3; i++)
{		
	if(i == highlight)
		wattron(win3, A_REVERSE);
		mvwprintw(win3, i+1, 1, choices[i].c_str());
		wattroff(win3, A_REVERSE);


 }
choice = wgetch(win3);

switch(choice)
{
case KEY_UP:
  highlight--;
  if(highlight == -1)
	highlight = 2;  
  break;
case KEY_DOWN:
  highlight++;
  if(highlight == 3)
	  highlight = 0;
  break;
default:
break;
}
if(choice == 10)
{
	break;

}

}
wclear(win3);
wrefresh(win3);
switch(highlight)
{
	case 0:
     {
wrefresh(win3);
string music;
curs_set(1);
mvwprintw (win3,1,1,"What's on your mind?");
mvwprintw (win3,4,1,"Search:");
wmove(win3,5,1);
def_prog_mode();
wrefresh(win3);
int c;
    do {
    c=getchar();
    if ( c == '\b' || c == KEY_DC || c == 127 || c == KEY_BACKSPACE) {
	    wrefresh(win3);
	    printf("\b");
	    music.pop_back();
	    wrefresh(win3);
        }
    else{

    putchar (c);
    music.append(1,c);
    }
  } while (c != '\r');

char command[150]="ytfzf-ml ";
sprintf (command," ytfzf -ml %s", music.c_str());
endwin();
system("clear");
system(command);
break;
     }
	case 1:
     {
	system("ytfzf -Hm");
	break;
     }
	case 2:
     {
sw=1;
break;

     }
default:
     break;
}

}
void menu4()
{
int i=0;
initscr();
noecho();
cbreak();
curs_set(0);

int yMax, xMax;
getmaxyx(stdscr, yMax, xMax);

WINDOW * win4 = newwin (0, xMax, 0, 0);
leaveok(win4,true);
refresh();
wrefresh(win4);

string anime;
curs_set(1);
werase(win4);
wrefresh(win4);
endwin();
	system("clear");
	system("ani-cli");
}
int main(int argc, char ** argv)
{ 
int i=0;
string input;
	initscr();
	noecho();
	cbreak();
	curs_set(0);
int yMax, xMax;
getmaxyx(stdscr, yMax, xMax);

WINDOW * menuwin = newwin (0, xMax, 0, 0);
WINDOW * win2 = newwin(0, xMax, 0, 0);
refresh();
wrefresh(menuwin);


keypad(menuwin, true);
keypad(win2, true);
do
{
curs_set(0);
wrefresh(menuwin);
refresh();
system("clear");
do {
sw=0;
string choices[4] = {"Youtube","Music","Anime"};
int choice;
int highlight = 0;
int option = 0;

while(1)
{
	for (i=0;i < 3; i++)
{		
	if(i == highlight)
		wattron(menuwin, A_REVERSE);
		mvwprintw(menuwin, i+1, 1, choices[i].c_str());
		wattroff(menuwin, A_REVERSE);


 }
choice = wgetch(menuwin);

switch(choice)
{
case KEY_UP:
  highlight--;
  if(highlight == -1)
	highlight = 2;  
  break;
case KEY_DOWN:
  highlight++;
  if(highlight == 3)
	  highlight = 0;
  break;
default:
break;
}
if(choice == 10)
{
	break;

}

}
werase(menuwin);
switch(highlight)
{
	case 0:
		{
	 wmove(win2,5,1);
	 wrefresh(win2);
      	 menu2();
	  break;
		}
	case 1:
		{
	  menu3();
	  break;
		}
	case 2:
		{
	  menu4();
	  break;
		}
	default:
	 break;
}
endwin();
}while(sw==1);
}while(2);
wrefresh(menuwin);


endwin();

return 0;
}
