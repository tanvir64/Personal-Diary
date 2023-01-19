# include "iGraphics.h"

int x = 0, y = 0, length = 1000, height = 1000,i;
char strID[100], strID1[100],strPASS[100],strPASS1[100],PASSstar[100],name1[100],name[100];
char confPASS[100],confPASSstar[100],confPASS1[100];
char IDread[100],PASSread[100];
char strdate[100],strdate1[100],strtext[20][63],strtext1[20][63],strshowtext[1500],show_activity[15],keep[15];
char filename[100]={0};
int len,len2=0,len1,len3=0,len4,len5=0,len6,len7=0,len8,len9=0,len10[20]={0},change=0,editmode=0,slttext=0;
int mode,mode1,mode3,mode4,mode5,mode6=0,mode7=0;
///mode=userID,mode1=password,mode3=confirm password,mode4=name,mode5=date
int SignupLogin=0,login=1,signup=2,help=3,about=4,menu=5;
int enterentry=6,editentry=7,delentry=8,moodchart=9,input=10;
int moods=11,showentry=12,logout=13,activities=14,writing_text=15;
int confirmation=16,confirmation2=17,show=18,deleted=19,mooddate=25;
int mood=0,activity=0,day[7];
int window=SignupLogin;
int error=0,lenERR=0,loginerror=0,dateerror=0,dateerror1=0,save_text=0;
int IDcomp=4,PASScomp=4;

int dateerror2(char *dateerror1);

void entrydate()
{
    iClear();

    iSetColor(204,153,255);
    iFilledRectangle(x,y,length,height);

    iSetColor(255,255,255);
    drawTexture(0,0,modes[36]);

    iSetColor(0,0,0);
    iText(100,500,"PLEASE ENTER THE DATE IN DD.MM.YYYY",GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(200,120,255);
    iFilledRectangle(250,400,250,50);

    if (mode5==1)
    {
        iSetColor(255,0,255);
        iFilledRectangle(250,400,250,50);
    }
    iSetColor(0,0,0);
    iText(260,415,strdate,GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(255,0,255);
    iFilledRectangle(450,300,100,40);
    iSetColor(0,0,0);
    iText(375,380,"(ENTER TO FINISH)");
    iText(460,310,"LET'S GO",GLUT_BITMAP_HELVETICA_18);
    dateerror=0;
    dateerror=dateerror2(strdate1);
    if(dateerror1==1){
        if (dateerror>0)
            iText(150,250,"PLEASE ENTER A VALID DATE",GLUT_BITMAP_TIMES_ROMAN_24);
        if (dateerror==0&&strlen(strdate1)==10){
                if(window==delentry)
                {
                    dateerror1=0;
                    mode5=0;
                    window=confirmation2;
                }
                else if(window==editentry||window==enterentry)
                {
                    dateerror1=0;
                    mode5=0;
                    window=input;
                }
                else if(window==showentry)
                {
                    dateerror1=0;
                    mode5=0;
                    window=show;
                }
                else if(window==mooddate)
                {
                    dateerror1=0;
                    mode5=0;
                    window=moodchart;
                    printf("%d",moodchart);
                }
            }
       }
}

void drawTextBoxID()
{
	iSetColor(255, 255, 255);
	iFilledRectangle(300, 318, 250, 30);
	if (mode==1)
    {
        mode1=0;
        iSetColor(0, 255, 255);
        iFilledRectangle(300, 318, 250, 30);
    }
}
void drawTextBoxPass()
{
	iSetColor(255, 255, 255);
	iFilledRectangle(300, 268, 250, 30);
	if (mode1==1)
    {
        mode=0;
        iSetColor(0, 255, 255);
        iFilledRectangle(300, 268, 250, 30);
    }
}
int dateerror2(char *strdate1)
{
    int dateerror=0;
    if((strdate1[3]=='1'&&strdate1[4]>'2')||(strdate1[3]=='0'&&strdate1[4]=='0')||strdate1[3]>49||(strdate1[0]==48&&strdate1[1]==48))
            {
                dateerror++;
            }
            else if (strdate1[0]>51)
                dateerror++;
            else if (strdate1[3]=='0' && strdate1[4]=='1')
            {
                if (strdate1[0]==51&&strdate1[1]>49)
                dateerror++;
            }
            else if (strdate1[3]=='0' && strdate1[4]=='2')
            {
                if (strdate1[0]==50 &&strdate1[1]>56)
                dateerror++;
            }else if (strdate1[3]=='0' && strdate1[4]=='3')
            {
                if (strdate1[0]==51&&strdate1[1]>49)
                dateerror++;
            }
            else if (strdate1[3]=='0' && strdate1[4]=='4')
            {
                if (strdate1[0]==51&&strdate1[1]>48)
                dateerror++;
            }
            else if (strdate1[3]=='0' && strdate1[4]=='5')
            {
                if (strdate1[0]==51&&strdate1[1]>49)
                dateerror++;
            }
            else if (strdate1[3]=='0' && strdate1[4]=='6')
            {
                if (strdate1[0]==51&&strdate1[1]>48)
                dateerror++;
            }
            else if (strdate1[3]=='0' && strdate1[4]=='7')
            {
                if (strdate1[0]==51&&strdate1[1]>49)
                dateerror++;
            }
            else if (strdate1[3]=='0' && strdate1[4]=='8')
            {
                if (strdate1[0]==51&&strdate1[1]>49)
                dateerror++;
            }
            else if (strdate1[3]=='0' && strdate1[4]=='9')
            {
                if (strdate1[0]==51&&strdate1[1]>48)
                dateerror++;
            }
            else if (strdate1[3]=='1' && strdate1[4]=='0')
            {
                if (strdate1[0]==51&&strdate1[1]>49)
                dateerror++;
            }
            else if (strdate1[3]=='1' && strdate1[4]=='1')
            {
                if (strdate1[0]==51&&strdate1[1]>48)
                dateerror++;
            }
            else if (strdate1[3]=='1' && strdate1[4]=='2')
            {
                if (strdate1[0]==51&&strdate1[1]>49)
                dateerror++;
            }
            else dateerror=0;
            return dateerror;
}
void iDraw()
 {
    iClear();

    if (window==SignupLogin)
    {
        iClear();

        iSetColor(10, 255, 10);
	    iFilledRectangle(x,y,length,height);

	    iSetColor(255,255,255);
	    drawTexture(0,0,modes[5]);

        iSetColor(128,255,255);
        iFilledRectangle(225,500,250,40);
        iFilledRectangle(225,400,250,40);
        iFilledRectangle(225,300,250,40);
        iFilledRectangle(225,200,250,40);

        iSetColor(0,0,255);
        iText(130, 600, "WELCOME TO YOUR PERSONAL DIARY", GLUT_BITMAP_TIMES_ROMAN_24);

        iSetColor(0,0,0);
        iText(275, 510, "NEW SIGN UP",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(300, 410, "LOG IN",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(308, 310, "HELP",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(300, 210, "ABOUT",GLUT_BITMAP_TIMES_ROMAN_24);
    }
    if(window==login)
    {
	iClear();

	iSetColor(102, 217, 255);
	iFilledRectangle(x,y,length,height);

	iSetColor(255,255,255);
	drawTexture(0,0,modes[37]);

	iSetColor(255, 255, 255);
    drawTexture(100,600,modes[0]);
	drawTexture(350,600,modes[1]);
	drawTexture(600,600,modes[2]);

	drawTextBoxID();
	drawTextBoxPass();

	if(mode==1){
        iSetColor(0,255,0);
        iFilledRectangle(300,318,250,30);
	}
	if(mode1==1){
        iSetColor(0,255,0);
        iFilledRectangle(300,268,250,30);
	}

    iSetColor(0, 0, 0);
    iText(320, 323, strID,GLUT_BITMAP_TIMES_ROMAN_24);

    iSetColor(0, 0, 0);
    iText(320, 273, PASSstar ,GLUT_BITMAP_TIMES_ROMAN_24);

	iSetColor(0, 0, 0);
	iText(130, 325, "USER ID", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(560,320,"(enter to finish)");
	iText(90, 275, "PASSWORD", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(560,270,"(enter to finish)");

	iSetColor(275, 275, 275);
	iFilledRectangle(250, 198, 185, 30);
	iSetColor(0, 0, 0);
	iText(295, 205, "LOG IN", GLUT_BITMAP_TIMES_ROMAN_24);



	FILE *IDfile1;
	IDfile1=fopen("user id.txt","r+");
	fscanf(IDfile1,"%s",IDread);

	if (strlen(IDread)==0)
    {
        IDcomp=4;
    }
    else
    {
        IDcomp=strcmp(IDread,strID1);
    }
    fclose(IDfile1);

    FILE *passfile1;
	passfile1=fopen("PASSWORD.txt","r+");
	fscanf(passfile1,"%s",PASSread);

	if (strlen(PASSread)==0)
    {
         PASScomp=4;
    }
    else
    {
        PASScomp=strcmp(PASSread,strPASS1);
    }
    fclose(passfile1);

    if (loginerror>0)
    {
        iText(150,150,"CHECK YOUR USER ID AND PASSWORD AGAIN!!",GLUT_BITMAP_HELVETICA_18);
    }

        iSetColor(255,255,255);
        iFilledRectangle(620,30,70,30);
        iSetColor(0,0,0);
        iText(630,40,"return",GLUT_BITMAP_HELVETICA_18);
    }
    if (window==about)
    {
        iClear();

        iSetColor(255, 204, 153);
	    iFilledRectangle(x,y,length,height);

	    iSetColor(255,255,255);
	    drawTexture(0,0,modes[34]);
	    iSetColor(102,0,102);
	    iFilledCircle(180,560,6);
	    iFilledCircle(180,505,5);
	    iFilledCircle(180,455,5);
	    iFilledCircle(180,405,5);
	    iFilledCircle(180,310,6);
	    iFilledCircle(180,255,5);
	    iFilledCircle(180,205,5);
	    iFilledCircle(180,155,5);

	    iSetColor(0, 0, 0);
	    iText(200,550,"DEVELOPED BY",GLUT_BITMAP_TIMES_ROMAN_24);
	    iText(200,500,"PRANTIK PAUL (1705071)",GLUT_BITMAP_HELVETICA_18);
	    iText(200,450,"MD. KAMRUJJAMAN (1705081)",GLUT_BITMAP_HELVETICA_18);
	    iText(200,400,"TANVIR RAIHAN (1705064)",GLUT_BITMAP_HELVETICA_18);
	    iText(200,300,"SUPERVISED BY",GLUT_BITMAP_TIMES_ROMAN_24);
	    iText(200,250,"MD. SHOHRAB HOSSAIN",GLUT_BITMAP_HELVETICA_18);
	    iText(200,200,"ASSOCIATE PROFESSOR",GLUT_BITMAP_HELVETICA_18);
        iText(200,150,"DEPARTMENT OF CSE,BUET.",GLUT_BITMAP_HELVETICA_18);
        iSetColor(255,255,255);
        iFilledRectangle(620,30,70,30);
        iSetColor(0,0,0);
        iText(630,40,"return",GLUT_BITMAP_HELVETICA_18);
    }

    if (window == signup)
    {
        iClear();

        iSetColor(225, 127, 212);
	    iFilledRectangle(x,y,length,height);

	    iSetColor(0,0,0);
        iText(100,600,"ENTER YOUR NAME  :",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(100,525,"USER ID                         :",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(100,450,"PASSWORD                   :",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(100,375,"CONFIRM PASSWORD:",GLUT_BITMAP_TIMES_ROMAN_24);

        iSetColor(255,255,255);
        iFilledRectangle(360,595,250,40);//name
        iFilledRectangle(360,520,250,40);//user id
        iFilledRectangle(360,445,250,40);//password
        iFilledRectangle(360,370,250,40);//confirm password
        iFilledRectangle(240,200,150,30);

        iSetColor(0,0,0);
        iText(360,575,"(press enter to finish)");
        iText(360,500,"(press enter to finish)");
        iText(360,425,"(press enter to finish)");
        iText(360,350,"(press enter to finish)");
        iText(260,205,"CONFIRM",GLUT_BITMAP_TIMES_ROMAN_24);

        if (mode4==1)
        {
            iSetColor(0,255,255);
            iFilledRectangle(360,595,250,40);
        }
        if (mode==1)
        {
            iSetColor(0,255,255);
            iFilledRectangle(360,520,250,40);
        }
        if (mode1==1)
        {
            iSetColor(0,255,255);
            iFilledRectangle(360,445,250,40);
        }
        if (mode3==1)
        {
            iSetColor(0,255,255);
            iFilledRectangle(360,370,250,40);
        }


        iSetColor(0, 0, 0);
        iText(365,598 , name,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(365, 523, strID ,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(365, 448, PASSstar,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(365, 373, confPASSstar ,GLUT_BITMAP_TIMES_ROMAN_24);

        if (error>0)
        {
            iText(100,300,"BOTH PASSWORDS ARE NOT SAME!!",GLUT_BITMAP_TIMES_ROMAN_24);
            error++;
            mode=0;
            mode4=0;
        }
        if (lenERR>0)
        {
            iText(50,150,"YOU NEED TO ENTER AT LEAST FIVE CHARACTER IN EACH FIELD",GLUT_BITMAP_HELVETICA_18);
        }

        FILE *namefile;
        namefile=fopen("user name.txt","w+");
        fprintf(namefile,"%s",name1);
        fclose(namefile);

        FILE *IDfile;
        IDfile=fopen("user ID.txt","w+");
        fprintf(IDfile,"%s",strID1);
        fclose(IDfile);

        FILE *passfile;
        passfile=fopen("PASSWORD.txt","w+");
        fprintf(passfile,"%s",strPASS1);
        fclose(passfile);

        iSetColor(255,255,255);
        iFilledRectangle(620,30,70,30);
        iSetColor(0,0,0);
        iText(630,40,"return",GLUT_BITMAP_HELVETICA_18);
    }

        if (window == menu)
        {
            iClear();

            iSetColor(255,219,77);
            iFilledRectangle(x,y,length,height);

            iSetColor(255,255,255);
            drawTexture(0,0,modes[9]);
            iSetColor(255,255,255);
            iFilledRectangle(150,500,400,60);
            iFilledRectangle(150,400,400,60);
            iFilledRectangle(150,300,400,60);
            iFilledRectangle(150,200,400,60);
            iFilledRectangle(150,100,400,60);
            iFilledRectangle(150,10,400,60);

            iSetColor(0,0,0);
            iText(265,520 , "ENTER ENTRY",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(275,420 , "EDIT ENTRY",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(255,320 , "DELETE ENTRY",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(245,220 , "SEE MOOD CHART",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(255,120 , "SHOW ENTRIES",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(280,30 , "LOG OUT",GLUT_BITMAP_TIMES_ROMAN_24);
        }

        if (window==help)
        {
            iClear();

            iSetColor(252, 145, 137);
            iFilledRectangle(x,y,length,height);

            iSetColor(255,255,255);
            drawTexture(0,0,modes[32]);

            iSetColor(102,0,102);
            iFilledCircle(10,660,5);
            iFilledCircle(10,600,5);
            iFilledCircle(10,480,5);
            iFilledCircle(10,420,5);

            iSetColor(26,26,255);
            iText(20,650,"Sign up with your name, User ID, password. You must remember ",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(20,620,"them as you will need them every time you log in.",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(20,590,"You can enter, edit or delete your entries from the main menu. Enter ",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(20,560,"the date and write your feelings. You can select the happy, OK or sad ",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(20,530,"icons according to your mode of the day. You can also select your ",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(20,500,"daily activities.",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(20,470,"You can see weekly mood chart according to your moods on the ",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(20,440,"day of the week from the main menu.",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(20,410,"You have the option to choose your daily work image from the ",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(20,380,"activity window which will be added to your daily notes.",GLUT_BITMAP_TIMES_ROMAN_24);
            iSetColor(255,255,255);
            iFilledRectangle(620,30,70,30);
            iSetColor(0,0,0);
            iText(630,40,"return",GLUT_BITMAP_HELVETICA_18);
        }

        if (window==enterentry)
        {
            iClear();

            entrydate();
            iSetColor(255,255,255);
            iFilledRectangle(620,30,70,30);
            iSetColor(0,0,0);
            iText(630,40,"return",GLUT_BITMAP_HELVETICA_18);

        }

        if (window==editentry)
        {
            iClear();

            entrydate();
            iSetColor(255,255,255);
            iFilledRectangle(620,30,70,30);
            iSetColor(0,0,0);
            iText(630,40,"return",GLUT_BITMAP_HELVETICA_18);
        }
        if (window==delentry)
        {
            iClear();

            entrydate();

        }

        if (window==input)
        {
            iClear();

            iSetColor(179,179,255);
            iFilledCircle(x,y,length,height);

            iSetColor(255,255,255);
            iFilledRectangle(150,500,400,60);
            iFilledRectangle(150,350,400,60);
            iFilledRectangle(150,200,400,60);

            iSetColor(0,0,0);
            iText(265,520,"EDIT MOODS",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(240,370,"ENTER ACTIVITIES",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(290,225,"WRITE",GLUT_BITMAP_TIMES_ROMAN_24);

            iSetColor(255,255,255);
            iFilledRectangle(620,30,70,30);
            iSetColor(0,0,0);
            iText(630,40,"return",GLUT_BITMAP_HELVETICA_18);
        }

        if (window==confirmation)
        {
            iClear();

            iSetColor(255,255,77);
            iFilledRectangle(x,y,length,height);

            iSetColor(0,0,0);
            iText(150,500,"ARE YOU SURE YOU WANT TO QUIT?",GLUT_BITMAP_TIMES_ROMAN_24);

            iSetColor(77,255,77);
            iFilledRectangle(200,350,100,50);
            iSetColor(255,26,26);
            iFilledRectangle(400,350,100,50);

            iSetColor(255,255,255);
            iText(230,365,"YES",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(430,365,"NO",GLUT_BITMAP_TIMES_ROMAN_24);

        }
        if (window==confirmation2)
        {
            iClear();

            iSetColor(128,204,255);
            iFilledRectangle(x,y,length,height);

            iSetColor(0,0,0);
            iText(100,500,"DO YOU REALLY WANT TO ERASE THIS ENTRY?",GLUT_BITMAP_TIMES_ROMAN_24);

            iSetColor(77,255,77);
            iFilledRectangle(200,350,100,50);
            iSetColor(255,26,26);
            iFilledRectangle(400,350,100,50);

            iSetColor(255,255,255);
            iText(230,365,"YES",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(430,365,"NO",GLUT_BITMAP_TIMES_ROMAN_24);

        }

        if (window==logout)
        {
            iClear();

            iSetColor(102,204,153);
            iFilledRectangle(x,y,length,height);

            iSetColor(255,255,255);
            drawTexture(0,0,modes[33]);

            iSetColor(255,255,255);
            iRectangle(620,30,70,30);
            iSetColor(120,105,0);
            iText(630,40,"finish",GLUT_BITMAP_HELVETICA_18);
        }

        if (window==moods)
        {
            iClear();

            iSetColor(204,255,255);
            iFilledRectangle(x,y,length,height);

            iSetColor(255, 255, 255);
            drawTexture(150,400,modes[0]);
            drawTexture(150,250,modes[1]);
            drawTexture(150,100,modes[2]);

            if (mood==1)
            {
                iSetColor(214, 237, 239);
                drawTexture(150,400,modes[0]);
            }
            if (mood==2)
            {
                iSetColor(214, 237, 239);
                drawTexture(150,250,modes[1]);
            }
            if (mood==3)
            {
                iSetColor(214, 237, 239);
                drawTexture(150,100,modes[2]);
            }

            iSetColor(0,0,0);
            iFilledRectangle(130,550,450,60);
            iSetColor(255,51,51);
            iText(155,568,"SELECT YOUR MOOD FOR TODAY",GLUT_BITMAP_TIMES_ROMAN_24);

            iSetColor(0,0,0);
            iText(240,410,"HAPPY!",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(240,260,"OKAY!",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(240,110,"SAD!",GLUT_BITMAP_TIMES_ROMAN_24);

            strcpy(filename,strID1);
            strcat(filename,strdate1);
            strcat(filename,"mood.txt");

            FILE *moodfp=fopen(filename,"w");
            if(mood==1){
                fprintf(moodfp,"1");
            }
            if(mood==2){
                fprintf(moodfp,"2");
            }
            if(mood==3){
                fprintf(moodfp,"3");
            }

            fclose(moodfp);
            iSetColor(255,255,255);
            iFilledRectangle(620,30,70,30);
            iSetColor(0,0,0);
            iText(630,40,"return",GLUT_BITMAP_HELVETICA_18);

        }

        if (window==activities)
        {
            iClear();

            iSetColor(255,228,196);
            iFilledRectangle(x,y,length,height);

            iSetColor(0,0,0);
            iText(150,600,"SELECT YOUR TODAY'S ACTIVITIES",GLUT_BITMAP_TIMES_ROMAN_24);

            ///adding activities image
            iSetColor(255,255,255);
            drawTexture(0,0,modes[38]);
            drawTexture(50,500,modes[4]);
            drawTexture(50,400,modes[6]);
            drawTexture(50,300,modes[7]);
            drawTexture(50,200,modes[10]);
            drawTexture(50,100,modes[11]);
            drawTexture(600,500,modes[15]);
            drawTexture(600,400,modes[16]);
            drawTexture(600,300,modes[19]);
            drawTexture(600,200,modes[21]);
            drawTexture(600,100,modes[30]);
            drawTexture(300,500,modes[27]);
            drawTexture(300,300,modes[28]);
            drawTexture(300,100,modes[12]);

            iSetColor(0,0,0);
            iText(50,480,"work",GLUT_BITMAP_HELVETICA_18);
            iText(50,380,"friends",GLUT_BITMAP_HELVETICA_18);
            iText(50,280,"hangout",GLUT_BITMAP_HELVETICA_18);
            iText(50,180,"gaming",GLUT_BITMAP_HELVETICA_18);
            iText(50,80,"music",GLUT_BITMAP_HELVETICA_18);
            iText(600,480,"jogging",GLUT_BITMAP_HELVETICA_18);
            iText(600,380,"travel",GLUT_BITMAP_HELVETICA_18);
            iText(600,280,"cooking",GLUT_BITMAP_HELVETICA_18);
            iText(595,180,"photography",GLUT_BITMAP_HELVETICA_18);
            iText(600,80,"workout",GLUT_BITMAP_HELVETICA_18);
            iText(300,480,"study",GLUT_BITMAP_HELVETICA_18);
            iText(300,280,"movies",GLUT_BITMAP_HELVETICA_18);
            iText(300,80,"concert",GLUT_BITMAP_HELVETICA_18);

            if(activity==1)
            {
                iSetColor(168,246,252);
                drawTexture(50,500,modes[4]);
            }
            if(activity==2)
            {
                iSetColor(168,246,252);
                drawTexture(50,400,modes[6]);
            }
            if(activity==3)
            {
                iSetColor(168,246,252);
                drawTexture(50,300,modes[7]);
            }
            if(activity==4)
            {
                iSetColor(168,246,252);
                drawTexture(50,200,modes[10]);
            }
            if(activity==5)
            {
                iSetColor(168,246,252);
                drawTexture(50,100,modes[11]);
            }
            if(activity==6)
            {
                iSetColor(168,246,252);
                drawTexture(600,500,modes[15]);
            }
            if(activity==7)
            {
                iSetColor(168,246,252);
                drawTexture(600,400,modes[16]);
            }
            if(activity==8)
            {
                iSetColor(168,246,252);
                drawTexture(600,300,modes[19]);
            }
            if(activity==9)
            {
                iSetColor(168,246,252);
                drawTexture(600,200,modes[21]);
            }
            if(activity==10)
            {
                iSetColor(168,246,251);
                drawTexture(600,100,modes[30]);
            }
            if(activity==11)
            {
                iSetColor(168,246,252);
                drawTexture(300,500,modes[27]);
            }
            if(activity==12)
            {
                iSetColor(168,246,252);
                drawTexture(300,300,modes[28]);
            }
            if(activity==13)
            {
                iSetColor(168,246,252);
                drawTexture(300,100,modes[12]);
            }


            iSetColor(255,255,255);
            iFilledRectangle(620,30,70,30);
            iSetColor(0,0,0);
            iText(630,40,"return",GLUT_BITMAP_HELVETICA_18);
        }

        if (window==showentry)
        {
            iClear();

            entrydate();
        }
        if(window==show)
        {
            iClear();

            iSetColor(255,228,196);
            iFilledRectangle(x,y,length,height);


            iSetColor(255,255,255);
            iFilledRectangle(620,30,70,30);
            iSetColor(0,0,0);
            iText(630,40,"return",GLUT_BITMAP_HELVETICA_18);
            iSetColor(255,255,255);

            strcpy(filename,strID1);
            strcat(filename,strdate1);
            strcat(filename,"mood.txt");
            FILE *moodfp=fopen(filename,"r");
            char ch;
            ch = fgetc(moodfp);
            mood = atoi(&ch);

            if(mood==1){
                drawTexture(600,600,modes[0]);
            }
            if(mood==2){
                drawTexture(600,600,modes[1]);
            }
            if(mood==3){
                drawTexture(600,600,modes[2]);
            }
            fclose(moodfp);

            strcpy(filename,strID1);
            strcat(filename,strdate1);
            strcat(filename,"act.txt");
            FILE *actfp=fopen(filename,"r+");
            fscanf(actfp,"%s",show_activity);

            int i=0;
            for(i=0;i<strlen(show_activity);i++)
            {
                if (i<7)
                {
                    if (show_activity[i]=='a')
                    drawTexture(30,500-i*70,modes[4]);

                    if (show_activity[i]=='b')
                    drawTexture(30,500-i*70,modes[6]);

                    if (show_activity[i]=='c')
                    drawTexture(30,500-i*70,modes[7]);

                    if (show_activity[i]=='d')
                    drawTexture(30,500-i*70,modes[10]);

                    if (show_activity[i]=='e')
                    drawTexture(30,500-i*70,modes[11]);

                    if (show_activity[i]=='f')
                    drawTexture(30,500-i*70,modes[15]);

                    if (show_activity[i]=='g')
                    drawTexture(30,500-i*70,modes[16]);

                    if (show_activity[i]=='h')
                    drawTexture(30,500-(i)*70,modes[19]);

                    if (show_activity[i]=='i')
                    drawTexture(30,500-(i)*70,modes[21]);

                    if (show_activity[i]=='j')
                    drawTexture(30,500-(i)*70,modes[30]);

                    if (show_activity[i]=='k')
                    drawTexture(30,500-(i)*70,modes[27]);

                    if (show_activity[i]=='l')
                    drawTexture(30,500-(i)*70,modes[28]);

                    if (show_activity[i]=='m')
                    drawTexture(30,500-(i)*70,modes[12]);
                }

                if (i>=7)
                {
                    if (show_activity[i]=='a')
                    drawTexture(625,500-(i-7)*70,modes[4]);

                    if (show_activity[i]=='b')
                    drawTexture(625,500-(i-7)*70,modes[6]);

                    if (show_activity[i]=='c')
                    drawTexture(625,500-(i-7)*70,modes[7]);

                    if (show_activity[i]=='d')
                    drawTexture(625,500-(i-7)*70,modes[10]);

                    if (show_activity[i]=='e')
                    drawTexture(625,500-(i-7)*70,modes[11]);

                    if (show_activity[i]=='f')
                    drawTexture(625,500-(i-7)*70,modes[15]);

                    if (show_activity[i]=='g')
                    drawTexture(625,500-(i-7)*70,modes[16]);

                    if (show_activity[i]=='h')
                    drawTexture(625,500-(i-7)*70,modes[19]);

                    if (show_activity[i]=='i')
                    drawTexture(625,500-(i-7)*70,modes[21]);

                    if (show_activity[i]=='j')
                    drawTexture(625,500-(i-7)*70,modes[30]);

                    if (show_activity[i]=='k')
                    drawTexture(625,500-(i-7)*70,modes[27]);

                    if (show_activity[i]=='l')
                    drawTexture(625,500-(i-7)*70,modes[28]);

                    if (show_activity[i]=='m')
                    drawTexture(625,500-(i-7)*70,modes[12]);


                }

            }
            fclose(actfp);

            strcpy(filename,strID1);
            strcat(filename,strdate1);
            strcat(filename,"text.txt");
            FILE *textfp=fopen(filename,"r");

            fgets(strshowtext,sizeof(strshowtext),textfp);

            change=0;

            for(i=0;i<20;i++) len10[i]=0;
            int l=strlen(strshowtext);
            int k=0;

            for(i=0;i<l;i++){
                if(strshowtext[i]=='|') change++;
                else
                {
                    strtext1[change][len10[change]]=strshowtext[i];
                    len10[change]++;
                }
            }

            iSetColor(255,255,255);
            iFilledRectangle(90,550-(change*30),520,(change+1)*30);
            iSetColor(0,0,0);

            for(i=0;i<=change;i++)
            {
                iText(105,(550-(i*30)+10),strtext1[i]);
            }

            fclose(textfp);

            iSetColor(214,255,249);
            iFilledRectangle(15,640,225,44);
            iSetColor(0,0,0);
            iText(30,650,"DATE:",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(120,650,strdate1,GLUT_BITMAP_TIMES_ROMAN_24);

        }
        if(window==writing_text)
        {
            iClear();

            iSetColor(255,128,255);
            iFilledRectangle(x,y,length,height);

            iSetColor(153,0,153);
            iText(200,650,"Click on the box to start writing",GLUT_BITMAP_TIMES_ROMAN_24);

            iSetColor(255,255,255);

            if(mode6==1){
                iSetColor(102,255,102);
            }
            if(mode7==1){
                iSetColor(255,255,255);
            }
            iFilledRectangle(90,600-(change*30),520,(change+1)*30);
            iSetColor(0,0,0);
            if(editmode>0){
                strcpy(filename,strID1);
                strcat(filename,strdate1);
                strcat(filename,"text.txt");
                FILE *textfp=fopen(filename,"r");

                fgets(strshowtext,sizeof(strshowtext),textfp);

                change=0;

                for(i=0;i<20;i++) len10[i]=0;
                int l=strlen(strshowtext);

                for(i=0;i<l;i++){
                    if(strshowtext[i]=='|') {
                        printf("%s",strtext1[change]);
                        change++;
                    }
                    else
                    {
                        strtext[change][len10[change]]=strshowtext[i];
                        len10[change]++;
                    }

                }
                fclose(textfp);
                editmode=0;
                slttext=1;

            }
            //int i;
            for(i=0;i<=change;i++){
                iText(105,(600-(i*30)+10),strtext[i]);
            }

            iSetColor(255,255,255);
            iFilledRectangle(620,30,70,30);
            iSetColor(0,0,0);
            iText(630,40,"return",GLUT_BITMAP_HELVETICA_18);
            iSetColor(255,255,255);
            iFilledRectangle(20,30,70,30);
            iSetColor(0,0,0);
            iText(40,40,"save",GLUT_BITMAP_HELVETICA_18);
            if (mode7==1){
                iSetColor(0,255,255);
                iFilledRectangle(20,30,70,30);
                iSetColor(0,0,0);
                iText(40,40,"save",GLUT_BITMAP_HELVETICA_18);
            }
        }

        if (window==deleted)
        {
            iClear();

            iSetColor(132,255,175);
            iFilledRectangle(x,y,length,height);

            iSetColor(255,255,255);
            drawTexture(0,0,modes[35]);

            iSetColor(0,0,0);
            iText(100,400,"ENTRY HAS BEEN DELETED SUCESSFULLY",GLUT_BITMAP_TIMES_ROMAN_24);

            iSetColor(255,0,255);
            iFilledRectangle(620,30,70,30);
            iSetColor(0,0,0);
            iText(630,40,"return",GLUT_BITMAP_HELVETICA_18);
        }
        if(window==mooddate)
        {
            iClear();
            entrydate();
            iSetColor(255,255,255);
            iFilledRectangle(620,30,70,30);
            iSetColor(0,0,0);
            iText(630,40,"return",GLUT_BITMAP_HELVETICA_18);
        }
        if (window==moodchart)
        {
            iClear();

            iSetColor(250,250,250);
            iFilledRectangle(x,y,length,height);

            iSetColor(0,0,0);
            iLine(50,100,700,100);
            iLine(50,100,50,680);
            iLine(140,90,140,110);
            iLine(230,90,230,110);
            iLine(320,90,320,110);
            iLine(410,90,410,110);
            iLine(500,90,500,110);
            iLine(590,90,590,110);
            iLine(680,90,680,110);
            iLine(40,260,60,260);
            iLine(40,420,60,420);
            iLine(40,580,60,580);
            iSetColor(255,0,0);
            iText(300,20,"Day",GLUT_BITMAP_HELVETICA_18);
            iText(140,70,"1");
            iText(230,70,"2");
            iText(320,70,"3");
            iText(410,70,"4");
            iText(500,70,"5");
            iText(590,70,"6");
            iText(680,70,"7");
            iSetColor(255,0,255);
            iFilledRectangle(620,30,70,30);
            iSetColor(0,0,0);
            iText(630,40,"return",GLUT_BITMAP_HELVETICA_18);

            char ch;
            strcpy(keep,strdate1);
            strcpy(filename,strID1);
            strcat(filename,strdate1);
            strcat(filename,"mood.txt");
            FILE *moodfp7=fopen(filename,"r");
            ch = fgetc(moodfp7);
            day[0] = atoi(&ch);
            fclose(moodfp7);
            //printf("%d",day[0]);

            for(i=0;i<6;i++){
            if(strdate1[3]=='0'&&strdate1[4]=='2'&&strdate[1]=='8'&&strdate1[0]=='2'){
                strdate1[0]='0';
                strdate1[1]='1';
                strdate1[4]='3';
            }
            else if(strdate1[1]=='9'){

                if(strdate1[0]=='0') {
                    strdate1[0]='1';
                    strdate1[1]='0';
                }
                else if(strdate1[0]=='1') {
                    strdate1[0]='2';
                    strdate1[1]='0';
                }
                else if(strdate1[0]=='2') {
                    strdate1[0]='3';
                    strdate1[1]='0';
                }
            }
            else if(strdate1[0]=='3'){
                if(strdate1[1]==0&&((strdate1[0]=='0'&&strdate1[1]=='1')||(strdate1[4]=='3')||strdate1[4]=='5'||strdate1[4]=='7'||strdate1[4]=='8'||(strdate1[3]=='1'&&strdate1[4]!='1')))
                {
                    strdate1[1]='1';
                }
                else if(strdate1[1]=='0') {
                    strdate1[0]='0';
                    strdate1[1]='1';
                    if(strdate1[4]=='9'){
                        strdate1[3]='1';
                        strdate1[4]='0';
                    }
                    else {
                            strdate1[4]++;
                    }
                }
            }
            else {
                strdate1[1]++;
            }
            strcpy(filename,strID1);
            strcat(filename,strdate1);
            strcat(filename,"mood.txt");
            FILE *moodfpi=fopen(filename,"r");
            //printf("\n%s",filename);


            ch = fgetc(moodfpi);
            day[i+1] = atoi(&ch);
            //printf("%d",day[i+1]);
            fclose(moodfpi);
        }
        strcpy(strdate1,keep);
            int p,q,r,s;
            for(i=0;i<7;i++){
                if(i==0){
                    if(day[i]==0)
                    {
                        p=140;
                        q=0;
                    }
                    else
                    {
                    p=140;
                    q=580-(160*(day[i]-1));
                    }
                    iCircle(p,q,1);
                    iLine(50,100,p,q);
                }
                else {
                    r=50+(90*(i+1));
                    if(day[i]==0) s=q;
                    else s=580-(160*(day[i]-1));
                    iCircle(r,s,1);
                     iLine(p,q,r,s);
                     p=r;
                     q=s;
                }
            }
        }
}

void iMouseMove(int mx, int my) {
	printf("x = %d, y= %d\n",mx,my);

}

void iMouse(int button, int state, int mx, int my) {
        if (window==login){
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		if(mx >= 300 && mx <= 550 && my >= 318 && my <= 348 && mode == 0)
		{
			mode = 1;
            len2++;
		}

		if(mx >= 300 && mx <= 550 && my >= 268 && my <= 318 && mode1 == 0)
		{
			mode1 = 1;
            len3++;
		}
		if(mx >= 620 && mx <= 690 && my >= 30 && my <= 60)
		{
			window=SignupLogin;
		}

		if(mx >= 250 && mx <= 435 && my >= 198 && my <= 228 && IDcomp==0 && PASScomp==0)
		{
		    mx=800;
		    my=800;
			window=menu;
			editmode=0;
			loginerror=0;
			//printf("%d",window);
		}
		else if(mx >= 250 && mx <= 435 && my >= 198 && my <= 228)
        {
            loginerror++;
        }
	  }
	}
	if (window==SignupLogin)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            if(mx >= 225 && mx <= 475 && my >= 500 && my <= 540)
            {
                mx=800;
                my=800;
                window=signup;
            }
            if(mx >= 225 && mx <= 475 && my >= 400 && my <= 440)
            {
                mx=800;
                my=800;
                window=login;
            }
            if(mx >= 225 && mx <= 475 && my >= 300 && my <= 340)
            {
                mx=800;
                my=800;
                window=help;
            }
            if(mx >= 225 && mx <= 475 && my >= 200 && my <= 240)
            {
                mx=800;
                my=800;
                window=about;
            }
      }
    }
    if (window==signup)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            if(mx >= 360 && mx <= 610 && my >= 595 && my <= 625 && mode4 == 0)
            {
                mode4 = 1;
                mode=0;
                mode1=0;
                mode3=0;
                len7++;
            }
            if(mx >= 360 && mx <= 610 && my >= 520 && my <= 560 && mode == 0)
            {
                mode = 1;
                mode4=0;
                mode1=0;
                mode3=0;
                len2++;
            }
            if(mx >= 360 && mx <= 610 && my >= 445 && my <= 485 && mode1 == 0)
            {
                mode1 = 1;
                mode4=0;
                mode=0;
                mode3=0;
                len3++;
            }
            if(mx >= 360 && mx <= 610 && my >= 370 && my <= 410 && mode3 == 0)
            {
                mode3 = 1;
                mode4=0;
                mode=0;
                mode1=0;
                len5++;
            }
            if(mx >= 620 && mx <= 690 && my >= 30 && my <= 60)
            {
                mx=800;
                my=800;
                window=SignupLogin;
            }
            if(mx >= 240 && mx <= 390 && my >= 200 && my <= 230 && strlen(strID1) > 4 && strlen(strPASS1) > 4 && strlen(name1) > 4)
            {
                lenERR=0;
                if(strcmp(confPASS1,strPASS1)==0)
                {
                    error=0;
                    mode=0;
                    mode1=0;
                    mode3=0;
                    mode4=0;
                    mx=800;
                    my=800;
                    window=login;
                }
                else
                {
                    error++;
                }
            }
            else if(mx >= 240 && mx <= 390 && my >= 200 && my <= 230)
            {
                lenERR++;
            }

        }
    }
    if (window==help)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            if(mx >= 620 && mx <= 690 && my >= 30 && my <= 60)
                {
                    mx=800;
                    my=800;
                    window=SignupLogin;
                }
            }
    }
    if (window==about)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            if(mx >= 620 && mx <= 690 && my >= 30 && my <= 60)
            {
                mx=800;
                my=800;
                window=SignupLogin;
            }
        }
    }
    if (window==menu)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            if(mx >= 150 && mx <= 550 && my >= 500 && my <= 560)
            {
                mx=800;
                my=800;
                window=enterentry;
            }
        if(mx >= 150 && mx <= 550 && my >= 400 && my <= 460)
		{
		    mx=800;
		    my=800;
			window=editentry;
			editmode++;
		}
        if(mx >= 150 && mx <= 550 && my >= 300 && my <= 360)
		{
		    mx=800;
		    my=800;
			window=delentry;
		}
		if(mx >= 150 && mx <= 550 && my >= 200 && my <= 260)
		{
		    mx=800;
		    my=800;
			window=mooddate;
		}
		if(mx >= 150 && mx <= 550 && my >= 100 && my <= 160)
		{
		    mx=800;
		    my=800;
			window=showentry;
		}
		if(mx >= 150 && mx <= 550 && my >= 10 && my <= 70)
		{
		    mx=800;
		    my=800;
			window=confirmation;
		}

      }
    }

    if (window==enterentry)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if(mx >= 250 && mx <= 500 && my >= 400 && my <= 450 && mode5 == 0)
            {
                mode5 = 1;
                len9++;
            }

            if(mx >= 450 && mx <= 550 && my >= 300 && my <= 340)
            {
                mx=800;
                my=800;
                dateerror1=1;
            }
            if (mx >= 620 && mx <= 690 && my >= 30 && my <= 60)
            {
                mx=800;
                my=800;
                window=menu;
                editmode=0;
            }
        }
    }

    if (window==editentry)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if(mx >= 250 && mx <= 500 && my >= 400 && my <= 450 && mode5 == 0)
            {
                mode5 = 1;
                len9++;
            }
            if(mx >= 450 && mx <= 550 && my >= 300 && my <= 340)
            {
                mx=800;
                my=800;
                dateerror1=1;
            }
            if (mx >= 620 && mx <= 690 && my >= 30 && my <= 60)
            {
                mx=800;
                my=800;
                window=menu;
                editmode=0;
            }
        }
    }

    if (window==delentry)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if(mx >= 250 && mx <= 500 && my >= 400 && my <= 450 && mode5 == 0)
            {
                mode5 = 1;
                len9++;
            }
            if(mx >= 450 && mx <= 550 && my >= 300 && my <= 340)
            {
                mx=800;
                my=800;
                dateerror1=1;
            }
        }
    }

    if (window==input)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if (mx >= 150 && mx <= 550 && my >= 500 && my <= 560)
            {
                mx=800;
                my=800;
                window=moods;
            }
            if (mx >= 150 && mx <= 550 && my >= 350 && my <= 410)
            {
                mx=800;
                my=800;
                window=activities;
            }
            if (mx >= 150 && mx <= 550 && my >= 200 && my <= 260)
            {
                mx=800;
                my=800;
                window=writing_text;
            }
            if (mx >= 620 && mx <= 690 && my >= 30 && my <= 60)
            {
                mx=800;
                my=800;
                window=menu;
                editmode=0;
                slttext=0;
                change=0;
                mode7=0;
                save_text=0;
                int j;
                for(i=0;i<20;i++){
                    for(j=0;j<63;j++){
                        strtext[i][j]=0;
                    }
                }
            }
        }
    }
    if (window==confirmation)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if (mx >= 400 && mx <= 500 && my >= 350 && my <= 400)
            {
                mx=800;
                my=800;
                window=menu;
                editmode=0;
            }
            if (mx >= 200 && mx <= 300 && my >= 350 && my <= 400)
            {
                mx=800;
                my=800;
                window=logout;
            }
        }
    }
    if (window==confirmation2)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if (mx >= 400 && mx <= 500 && my >= 350 && my <= 400)
            {
                mx=800;
                my=800;
                window=menu;
                editmode=0;
            }
            if (mx >= 200 && mx <= 300 && my >= 350 && my <= 400)
            {
                mx=800;
                my=800;

                strcpy(filename,strID1);
                strcat(filename,strdate1);
                strcat(filename,"mood.txt");
                remove(filename);

                strcpy(filename,strID1);
                strcat(filename,strdate1);
                strcat(filename,"act.txt");
                remove(filename);

                strcpy(filename,strID1);
                strcat(filename,strdate1);
                strcat(filename,"text.txt");
                remove(filename);

                window=deleted;
            }
        }
    }
    if (window==logout)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if (mx >= 620 && mx <= 690 && my >= 30 && my <= 60)
            {
               exit(0);
            }
        }
    }

    if (window==moods)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if (mx >= 150 && mx <= 214 && my >= 400 && my <= 464)
            {
                mood=1;
            }
            if (mx >= 150 && mx <= 214 && my >= 250 && my <= 314)
            {
                mood=2;
            }
            if (mx >= 150 && mx <= 214 && my >= 100 && my <= 164)
            {
                mood=3;
            }
            if (mx >= 620 && mx <= 690 && my >= 30 && my <= 60)
            {
                mx=800;
                my=800;
                window=input;
            }
        }
    }

    if (window==showentry)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if(mx >= 250 && mx <= 500 && my >= 400 && my <= 450 && mode5 == 0)
            {
                mode5 = 1;
                len9++;
            }
            if(mx >= 450 && mx <= 550 && my >= 300 && my <= 340)
            {
                mx=800;
                my=800;
                dateerror1=1;
            }
        }
    }
    if(window==activities)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            FILE *activityfp;
            strcpy(filename,strID1);
            strcat(filename,strdate1);
            strcat(filename,"act.txt");

            activityfp=fopen(filename,"a+");

            if(mx >= 50 && mx <= 100 && my >= 500 && my <= 550 )
            {
                activity=1;
                fprintf(activityfp,"a");
            }
            if(mx >= 50 && mx <= 100 && my >= 400 && my <= 450)
            {
                activity=2;
                fprintf(activityfp,"b");
            }
            if(mx >= 50 && mx <= 100 && my >= 300 && my <= 350 )
            {
                activity=3;
                fprintf(activityfp,"c");
            }
            if(mx >= 50 && mx <= 100 && my >= 200 && my <= 250)
            {
                activity=4;
                fprintf(activityfp,"d");
            }
            if(mx >= 50 && mx <= 100 && my >= 100 && my <= 150)
            {
                activity=5;
                fprintf(activityfp,"e");
            }
            if(mx >= 300 && mx <= 350 && my >= 500 && my <= 550)
            {
                activity=11;
                fprintf(activityfp,"k");
            }
            if(mx >= 300 && mx <= 350 && my >= 300 && my <= 350)
            {
                activity=12;
                fprintf(activityfp,"l");
            }
            if(mx >= 300 && mx <= 350 && my >= 100 && my <= 150)
            {
                activity=13;
                fprintf(activityfp,"m");
            }
            if(mx >= 600 && mx <= 650 && my >= 500 && my <= 550)
            {
                activity=6;
                fprintf(activityfp,"f");
            }
            if(mx >= 600 && mx <= 650 && my >= 400 && my <= 450)
            {
                activity=7;
                fprintf(activityfp,"g");
            }
            if(mx >= 600 && mx <= 650 && my >= 300 && my <= 350)
            {
                activity=8;
                fprintf(activityfp,"h");
            }
            if(mx >= 600 && mx <= 650 && my >= 200 && my <= 250)
            {
                activity=9;
                fprintf(activityfp,"i");
            }
            if(mx >= 600 && mx <= 650 && my >= 100 && my <= 150)
            {
                activity=10;
                fprintf(activityfp,"j");
            }
            fclose(activityfp);

            if (mx >= 620 && mx <= 690 && my >= 30 && my <= 60)
            {
                mx=800;
                my=800;
                window=input;
            }
        }
    }
    if(window==writing_text)
    {
       if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if(mx >= 15 && mx <= 685 && my >= 600  && my <= 630 )
            {
                mode6=1;
            }
            if(mx >= 20 && mx <= 90 && my >= 30 && my <= 60 )
            {
                mode7=1;
            }

        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if(mx >= 15 && mx <= 685 && my >= (600-(change*30))  && my <= 630 && slttext==1)
            {
                mode6=1;
                slttext=0;
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if (mx >= 620 && mx <= 690 && my >= 30 && my <= 60)
            {
                mx=800;
                my=800;
                mode7=0;
                save_text=0;
                window=input;

            }
            if (mx >= 20 && mx <= 90 && my >= 30 && my <= 60)
            {
                save_text++;
                if(save_text==1){
                FILE *wrtfp;
                strcpy(filename,strID1);
                strcat(filename,strdate1);
                strcat(filename,"text.txt");
                wrtfp=fopen(filename,"w+");
                for (i=0;i<=change;i++)
                {
                    fprintf(wrtfp,"%s",strtext[i]);
                    fprintf(wrtfp,"|");
                }
                fclose(wrtfp);
                }
            }
        }
    }

    if (window==deleted)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if (mx >= 620 && mx <= 690 && my >= 30 && my <= 60)
            {
                mx=800;
                my=800;
                window=menu;
                editmode=0;
            }
        }
    }

    if (window==show)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if (mx >= 620 && mx <= 690 && my >= 30 && my <= 60)
            {
                mx=800;
                my=800;
                int j;
                for(i=0;i<20;i++){
                    for(j=0;j<63;j++){
                        strtext[i][j]=0;
                    }
                }
                window=menu;
                editmode=0;
            }
        }
    }
    if (window==mooddate)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if(mx >= 250 && mx <= 500 && my >= 400 && my <= 450 && mode5 == 0)
            {
                mode5 = 1;
                len9++;
            }
            if(mx >= 450 && mx <= 550 && my >= 300 && my <= 340)
            {
                mx=800;
                my=800;
                dateerror1=1;
            }
            if (mx >= 620 && mx <= 690 && my >= 30 && my <= 60)
            {
                mx=800;
                my=800;
                window=menu;
            }
        }
    }
    if (window==moodchart)  {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if(mx >= 620 && mx <= 690 && my >= 30 && my <= 60)
            {
                mx=800;
                my=800;
                window=menu;
            }
        }
    }
}

void iKeyboard(unsigned char key) {


	int i;
	if(mode == 1)
	{
        if(key == '\r')
		{
			mode = 0;
			strcpy(strID1, strID);
		}
		else if (mode!=0 && key==8)
        {
            if(len>0){
            len--;
            strID[len] = 0;
            }
        }
		else if(len<10)
		{
			strID[len] = key;
			len++;
		}
	}

	if(mode1 == 1)
	{

        if(key == '\r')
		{
			mode1 = 0;
			strcpy(strPASS1, strPASS);
		}

		else if (mode1!=0 && key==8)
        {
            if(len1>0){
            len1--;
            strPASS[len1] = 0;
            PASSstar[len1]=0;
            }
        }

		else if (len1<10)
		{
			strPASS[len1] = key;
			PASSstar[len1]=42;
			len1++;
		}
	}

	if(mode4 == 1)
	{

        if(key == '\r')
		{
			mode4 = 0;
			strcpy(name1, name);
		}

		else if (mode4!=0 && key==8)
        {   if (len6>0){
            len6--;
            name[len6] = 0;
        }
        }

		else if (len6<12)
		{
			name[len6] = key;
			len6++;
		}
	}

	if(mode3 == 1)
	{

        if(key == '\r')
		{
			mode3 = 0;
			strcpy(confPASS1, confPASS);
		}

		else if (mode3!=0 && key==8)
        {
            if(len4>0)
            {
            len4--;
            confPASS[len4] = 0;
            confPASSstar[len4]=0;
        }
        }

		else if (len4<10)
		{
			confPASS[len4] = key;
			confPASSstar[len4]=42;
			len4++;
		}
	}

	if(mode5 == 1)
	{

        if(key == '\r')
		{
			mode5 = 0;
			strcpy(strdate1, strdate);
		}

		else if (mode5!=0 && key==8)
        {
            if (len8>0){
            len8--;
            strdate[len8] = 0;
            }
        }

		else if (len8<10 && ((key>47 && key<58)||key=='.'))
		{
			strdate[len8] = key;
			len8++;
		}
	}

	if(mode6 == 1)
	{
	    if(key=='\r')
	    {
            if(change<18) change++;
		}
		else if (key==8)
        {
            if (len10[change]>0){
            len10[change]--;
            strtext[change][len10[change]]=0;
            }
            else if(len10[change]==0 && change>0) change--;
        }
	     else if (len10[change]<62)
		{
		    if(len10[change]>=61)
		    {
		        if(change<18) change++;
		    }

		    if(key!='|') {
			strtext[change][len10[change]] = key;
			len10[change]++;
		    }
		    printf("%d",len10[change]);
		}
	}

}

void iSpecialKeyboard(unsigned char key) {

	if (key == GLUT_KEY_END) {
		exit(0);
	}
}

int main() {

	len = 0, len1=0, len4=0, len6=0, len8= 0;
	mode = 0, mode1 = 0, mode3 = 0,mode4 = 0, mode5 = 0;
	strID[0]= 0, strPASS[0]= 0, confPASS1[0]= 0,name[0]=0, strdate[0]= 0;

	iInitialize(700, 700, "My Personal Diary");
    return 0;
}
