  # include "iGraphics.h"
#define axis_x 500
#define axis_y 400
char str1[50], str2[50],str7[50];

void draw_7_seg(double x,double y,int *a);
void left_shift();
void print_7_seg();
void assign_char(char ch);
int len;
int mode;
double pos_x=axis_x,pos_x_last;
double pos_y=80;
double pos_x_velocity=1;

int bit[7]={1,1,1,1,1,1,1};
int seg_color=100;

void print_7_seg()
{
    double k=0;
    int total=strlen(str7);
    for(int i=0;i<total;i++)
    {
        if((str7[i] >= '0' && str7[i] <= '9' )|| (str7[i]>='A' && str7[i]<='F'))
        {
            assign_char(str7[i]); //for getting bit pattern
            draw_7_seg(pos_x+k,pos_y,bit);//a for making gap bet^n 2 char
            k+=60;//gap about 50+10
        }
    }
    pos_x_last=pos_x+k+50;
}
void drawTextBox()
{
	iSetColor(150, 250, 150);
	iRectangle(50, 250, 300, 30);
}
void assign_char(char ch)
{
    for(int i=0;i<7;i++)
        bit[i]=1;
    switch(ch)
    {

    case 'A':
        bit[3]=0;
        return ;
    case 'B' :
        return ;
    case 'C' :
        bit[1]=0;
        bit[2]=0;
        bit[6]=0;
        return ;

    case 'D' :
        bit[6]=0;
        return ;

    case 'E' :
        bit[1]=0;
        bit[2]=0;
        return ;

    case 'F' :
        bit[1]=0;
        bit[2]=0;
        bit[3]=0;
        return ;
         case '0':
        bit[6]=0;
        return ;
    case '1':
        bit[0]=0;
        bit[5]=0;
        bit[6]=0;
        bit[3]=0;
        bit[4]=0;
        return ;
    case '2':
        bit[5]=0;
        bit[2]=0;
        return ;
    case '3':
        bit[5]=0;
        bit[4]=0;
        return ;
    case '4' :
        bit[0]=0;
        bit[3]=0;
        bit[4]=0;
        return ;
    case '5':
        bit[1]=0;
        bit[4]=0;
        return ;
    case '6':
        bit[1]=0;
        return ;
    case '7' :
        bit[5]=0;
        bit[6]=0;
        bit[3]=0;
        bit[4]=0;
        return ;
    case '8' :
        return ;
    case '9' :
        bit[4]=0;
        return ;


    }
    return ;
}
/*
	function iDraw() is called again and again by the system.
*/
void draw_1_seg(double ax,double ay,double bx,double by)
{
    iLine(ax,ay,bx,by);
    iLine(ax,ay-1,bx,by-1);
    iLine(ax,ay-2,bx,by-2);
    iLine(ax,ay+1,bx,by+1);
    iLine(ax,ay+2,bx,by+2);// for making the line more visible(thick)
    iLine(ax-1,ay,bx-1,by);
    iLine(ax-2,ay,bx-2,by);
    iLine(ax+1,ay,bx+1,by);
    iLine(ax+2,ay,bx+2,by);
}
void draw_7_seg(double x,double y,int *p)
{

    if(p[0])
    {
        draw_1_seg(x,y+100,x+50,y+100);
    }
    if(p[1])
    {
        draw_1_seg(x+50,y+50,x+50,y+100);
    }
     if(p[2])
    {
        draw_1_seg(x+50,y,x+50,y+50);
    }
     if(p[3])
    {
        draw_1_seg(x,y,x+50,y);
    }
    if(p[4])
    {
        draw_1_seg(x,y,x,y+50);
    }
    if(p[5])
    {
        draw_1_seg(x,y+50,x,y+100);
    }
    if(p[6])
    {
        draw_1_seg(x,y+50,x+50,y+50);
    }

}
void iDraw()
{
	//place your drawing codes here

	iClear();

	drawTextBox();
	if(mode == 1)
	{
		iSetColor(0, 255, 255);//colour for text
		char * st_p=str1;
		if(len>30)
            st_p+=len-30;
		iText(55, 260, st_p);
	}

    iSetColor(seg_color,256-seg_color, seg_color/2);//color for segment
	print_7_seg();
	iSetColor(255, 255, 255);
	iText(12, 12, "Click to activate the box, enter to finish,'x' to EXIT");
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		if(mx >= 50 && mx <= 300 && my >= 250 && my <= 280 && mode == 0)
		{
			mode = 1;
		}
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	int i;
	if(mode == 1)
	{
        if(key == '\r')
		{
			mode = 0;
			strcpy(str2, str1);
			printf("%s\n", str2);
			strcpy(str7,str2);
			pos_x=axis_x;
			for(i = 0; i < len; i++)
				str1[i] = 0;
			len = 0;
		}
		else if(key==8)
        {
            if(len!=0)
            {
                str1[--len]=0;
            }
        }
		else
		{
			str1[len] = key;
			len++;
		}
	}

	if(key == 'x')
	{
		//do something with 'x'
		exit(0);
	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{
 if(key==GLUT_KEY_LEFT)
    {
        pos_x_velocity++;
    }
    if(key==GLUT_KEY_RIGHT)
    {
        pos_x_velocity--;
    }
	if(key == GLUT_KEY_END)
	{
		exit(0);
	}

	//place your codes for other keys here
}
void left_shift()
{
    seg_color=(seg_color+1)%256;
    pos_x-=pos_x_velocity;
    pos_x_last-=pos_x_velocity;
    if(pos_x_last <0)
    {
        pos_x=axis_x;
    }
}

int main()
{
	//place your own initialization codes here.
	len = 0;
	mode = 0;
	str1[0]= 0;
	iSetTimer(10,left_shift);
	iInitialize(axis_x, axis_y, "Text Input ");
	return 0;
}


