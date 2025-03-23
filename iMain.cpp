
#include"iostream"
# include "iGraphics.h"
# include"time.h"
# include"stdlib.h"
#include"string.h"
#include "windows.h"

using namespace std;



#pragma comment(lib, "winmm.lib")

void ShowHomePage();
void drawStartPage();
void drawRulesPage();
void drawHighScorePage();
void drawScorePage();
void startButtonClickHandler();
void rulesButtonClickHandler();
void highScoreButtonClickHandler();
void scoreButtonClickHandler();
void backButtonHandler();
void setAll();
void render();
void change();
void showCharacter1Idle();
void showCharacter2Idle();
void handleJump();
void showCharacterJump();
void obstacleShow1();
void obstacleShow2();
void exitButtonHandler();
void coinLine();
void drawCoin();
void updateCoinPosition();
void showCharChoose();
int CoinCollisionWithCactus(int coinX,int coinY);
void showScoreButton();
void updateScore();
void updateSpeed();
void showCharacterRun();
void coinCollisionWithChar(int coinX,int coinY);
void charCollisionWithOb(int charX,int charY);
void funcCoin();
void coinCollectedShow();
void playCoinMusic();
void playBGMusic();
void playLifeMusic();
void showCharDeath();
void eggShow();
void renderEgg();
int charCollisionEgg(int charX,int charY);
void consequence(int i);
void callToMainCacRem();
void renderBird();
int charColllisionWithBird(int charX,int charY);
void loadScore();
void saveHighScores();
void takeScore(int s);
void notPlayBGMusic();
void callToMainCoinRem();
void timeFunc();
void funcForTimeFunc();


int x = 1000, y = 600, r = 20;
int startGame=0;
int GameState=0;
int frame1=0;
int frame2=0;
int frameS=0;
bool pauseScreen=false;
int whichChar;
bool chosenChar=false;

int obPosX1=923;
int obPosY1=130;
int obNum1=rand()%2;
int obPosX2=1380;
int obPosY2=130;
int obNum2=rand()%2;
int score=0;
bool char1Jump=false;
bool Jump1Up=false;
int jumpHeight=250;
int jumpSpeed =17;
int gravity=18;
bool showCoin=true;
bool playMusic=true;
int coinsCollected=0;
bool coinMusic=false;
int lives=3;
bool livesBool=true;
bool livesLost=false;
bool isDead=false;
int showOnce=0;
int eggX=1100;
int eggY=162;
bool showEgg=false;
bool showCac=true;
bool shouldIwork=false;
bool BirdBool=false;
int BirdX =1132;
int BirdY =345;
int birdCount=0;
bool didJump=false;
bool hasCollidedBird=false;
bool startAgain=false;
int high[3];
bool didTakeScore=false;
bool shouldIwork2=false;
bool forCoin=false;
int timeIndex=0;
bool boolForSurprise=false;



//For increasing speed during duration of the game hehe

int initialSpeed=5;

char moveImage[20][250]={"moving background/row-1-column-1.bmp","moving background/row-1-column-2.bmp","moving background/row-1-column-3.bmp","moving background/row-1-column-4.bmp","moving background/row-1-column-5.bmp","moving background/row-1-column-6.bmp","moving background/row-1-column-7.bmp","moving background/row-1-column-8.bmp","moving background/row-1-column-9.bmp","moving background/row-1-column-10.bmp","moving background/row-1-column-11.bmp","moving background/row-1-column-12.bmp","moving background/row-1-column-13.bmp","moving background/row-1-column-14.bmp","moving background/row-1-column-15.bmp","moving background/row-1-column-16.bmp","moving background/row-1-column-17.bmp","moving background/row-1-column-18.bmp","moving background/row-1-column-19.bmp","moving background/row-1-column-20.bmp"};

char character1Idle[12][350]={"idle1/tile000.bmp","idle1/tile000.bmp","idle1/tile000.bmp","idle1/tile001.bmp","idle1/tile001.bmp","idle1/tile001.bmp","idle1/tile002.bmp","idle1/tile002.bmp","idle1/tile002.bmp","idle1/tile003.bmp","idle1/tile003.bmp","idle1/tile003.bmp"};

char character2Idle[12][350]={"idle2/tile000.bmp","idle2/tile000.bmp","idle2/tile000.bmp","idle2/tile001.bmp","idle2/tile001.bmp","idle2/tile001.bmp","idle2/tile002.bmp","idle2/tile002.bmp","idle2/tile002.bmp","idle2/tile003.bmp","idle2/tile003.bmp","idle2/tile003.bmp"};

char character1Jump[24][500]={"jump1/tile000.bmp","jump1/tile000.bmp","jump1/tile000.bmp","jump1/tile001.bmp","jump1/tile001.bmp","jump1/tile001.bmp","jump1/tile002.bmp","jump1/tile002.bmp","jump1/tile002.bmp","jump1/tile003.bmp","jump1/tile003.bmp","jump1/tile003.bmp","jump1/tile004.bmp","jump1/tile004.bmp","jump1/tile004.bmp","jump1/tile005.bmp","jump1/tile005.bmp","jump1/tile005.bmp","jump1/tile006.bmp","jump1/tile006.bmp","jump1/tile006.bmp","jump1/tile007.bmp","jump1/tile007.bmp","jump1/tile007.bmp"};

char character2Jump[24][500]={"jump2/tile000.bmp","jump2/tile000.bmp","jump2/tile000.bmp","jump2/tile001.bmp","jump2/tile001.bmp","jump2/tile001.bmp","jump2/tile002.bmp","jump2/tile002.bmp","jump2/tile002.bmp","jump2/tile003.bmp","jump2/tile003.bmp","jump2/tile003.bmp","jump2/tile004.bmp","jump2/tile004.bmp","jump2/tile004.bmp","jump2/tile005.bmp","jump2/tile005.bmp","jump2/tile005.bmp","jump2/tile006.bmp","jump2/tile006.bmp","jump2/tile006.bmp","jump2/tile007.bmp","jump2/tile007.bmp","jump2/tile007.bmp"};

char character1Run[18][350]={"run1/tile000.bmp","run1/tile000.bmp","run1/tile000.bmp","run1/tile001.bmp","run1/tile001.bmp","run1/tile001.bmp","run1/tile002.bmp","run1/tile002.bmp","run1/tile002.bmp","run1/tile003.bmp","run1/tile003.bmp","run1/tile003.bmp","run1/tile004.bmp","run1/tile004.bmp","run1/tile004.bmp","run1/tile005.bmp","run1/tile005.bmp","run1/tile005.bmp"};

char character2Run[18][350]={"run2/tile000.bmp","run2/tile000.bmp","run2/tile000.bmp","run2/tile001.bmp","run2/tile001.bmp","run2/tile001.bmp","run2/tile002.bmp","run2/tile002.bmp","run2/tile002.bmp","run2/tile003.bmp","run2/tile003.bmp","run2/tile003.bmp","run2/tile004.bmp","run2/tile004.bmp","run2/tile004.bmp","run2/tile005.bmp","run2/tile005.bmp","run2/tile005.bmp"};

char character1Death[24][500]={"lives1/tile000.bmp","lives1/tile000.bmp","lives1/tile000.bmp","lives1/tile001.bmp","lives1/tile001.bmp","lives1/tile001.bmp","lives1/tile002.bmp","lives1/tile002.bmp","lives1/tile002.bmp","lives1/tile003.bmp","lives1/tile003.bmp","lives1/tile003.bmp","lives1/tile004.bmp","lives1/tile004.bmp","lives1/tile004.bmp","lives1/tile005.bmp","lives1/tile005.bmp","lives1/tile005.bmp","lives1/tile006.bmp","lives1/tile006.bmp","lives1/tile006.bmp","lives1/tile007.bmp","lives1/tile007.bmp","lives1/tile007.bmp"};

char character2Death[24][500]={"lives2/tile000.bmp","lives2/tile000.bmp","lives2/tile000.bmp","lives2/tile001.bmp","lives2/tile001.bmp","lives2/tile001.bmp","lives2/tile002.bmp","lives2/tile002.bmp","lives2/tile002.bmp","lives2/tile003.bmp","lives2/tile003.bmp","lives2/tile003.bmp","lives2/tile004.bmp","lives2/tile004.bmp","lives2/tile004.bmp","lives2/tile005.bmp","lives2/tile005.bmp","lives2/tile005.bmp","lives2/tile006.bmp","lives2/tile006.bmp","lives2/tile006.bmp","lives2/tile007.bmp","lives2/tile007.bmp","lives2/tile007.bmp"};

char obstacle[2][50]={"obstacle/cactusB.bmp","obstacle/cactusS.bmp"};

char coins[5][50]={"coin.bmp","coin.bmp","coin.bmp","coin.bmp","coin.bmp"};

char Bird[18][200]={"surprise/tile000.bmp","surprise/tile000.bmp","surprise/tile000.bmp","surprise/tile001.bmp","surprise/tile001.bmp","surprise/tile001.bmp","surprise/tile002.bmp","surprise/tile002.bmp","surprise/tile002.bmp","surprise/tile003.bmp","surprise/tile003.bmp","surprise/tile003.bmp","surprise/tile004.bmp","surprise/tile004.bmp","surprise/tile004.bmp","surprise/tile005.bmp","surprise/tile005.bmp","surprise/tile005.bmp"};

char timeStamp[6][100]={"timestamp/tile1.bmp","timestamp/tile1.bmp","timestamp/tile2.bmp","timestamp/tile3.bmp","timestamp/tile4.bmp","timestamp/tile5.bmp"};


struct startBackground
{
	int posX;
	int posY;
	
};



struct startBackground  STARTbackground[20];

struct coinStructure
{
	int coinPosX;
	int coinPosY;
	bool collected;
	
};

struct coinStructure coinIndividual[5];

struct character1Jump
{
	int char1JumpPosX;
	int char1JumpPosY;
};

struct character1Jump char1JumpStruct;

void iDraw() {
	
	iClear();
	
	
	if(GameState==0)
	{
		ShowHomePage();
		
	}
	else if(GameState==1)
	{
		
		if(!startGame)
		{
			drawStartPage();
			
			if(whichChar==1)
			{
				showCharacter1Idle();
			}
			if(whichChar==2)
			{
				showCharacter2Idle();
			}
			score=0;
	        iShowBMP2(320,250,"start.bmp",0);
			iSetColor(32,172,32);
			iText(389,368,"Press S to Start Running",GLUT_BITMAP_TIMES_ROMAN_24);
			iShowBMP2(38,1,"button.bmp",0);
	        iSetColor(255,255,255);
	        iText(100,90,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);
			livesBool=true;
			lives=3;
			coinsCollected=0;
			initialSpeed=5;
		    obPosX1=923;
            obPosY1=130;
			obPosX2=1380;
            obPosY2=130;
			eggX=1132;
			isDead=false;
			showOnce=0;
			playMusic=true;
			didTakeScore=false;
			timeIndex=0;


		}
		if(startGame)
        {
			
			iSetColor(76,153,0);
			iFilledRectangle(0,0,1000,600);
			
			
            render();
			
			
			if(showCac)
			{
				
				obstacleShow1();
			    obstacleShow2();
			
			}

			if(BirdBool)
			{
				renderBird();
			}


			if(showEgg)
			{
				renderEgg();
			}
			
			
			if(lives>0)
			{

				showCharacterRun();
			    handleJump();
			    showCharacterJump();
			}
			else
			{
				
				isDead=true;
				pauseScreen=true;
			}
			
	
			//coinLine();
			//drawCoin();
			timeFunc();
			funcCoin();
			
			if(!pauseScreen)
			{
				updateScore();
			}
			coinCollectedShow();
			showScoreButton();
			iSetColor(32,172,32);
			iText(55,500,"LIVES: ",GLUT_BITMAP_TIMES_ROMAN_24);
			
			if(lives==3)
			{
				iShowBMP2(130,490,"life.bmp",0);
			    iShowBMP2(192,490,"life.bmp",0);
			    iShowBMP2(252,490,"life.bmp",0);
			}
			else if(lives==2)
			{
				iShowBMP2(130,490,"life.bmp",0);
		    	iShowBMP2(192,490,"life.bmp",0);
			}
			else  if(lives==1)
			{
				iShowBMP2(130,490,"life.bmp",0);
			}
			
			if(pauseScreen)
			{
				iPauseTimer(0);
				
				if(isDead)
				{
					showOnce++;
					if(showOnce<=10)
					{
						showCharDeath();
						Sleep(48);
					}
					else
					{
						
						didTakeScore=true;
						startAgain=true;
						drawScorePage();
					}
				}
				if(!isDead)
				{
					iShowBMP2(757,18,"button.bmp",0);
					iSetColor(255,255,255);
				    iText(830,108,"EXIT",GLUT_BITMAP_TIMES_ROMAN_24);
				}
			}
			else
			{
				iResumeTimer(0);
			}

			
        }

		
	}
	else if(GameState==2)
	{
		drawRulesPage();
	}
	else if(GameState==3)
	{
		drawHighScorePage();
	}
	else if(GameState==4)
	{
		drawScorePage();
	}
	else if(GameState==5)
	{
		showCharChoose();
	}
	
	
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my)
 {
	printf("x = %d, y= %d\n",mx,my);
	
	
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my)
 {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		
		printf("x = %d, y= %d\n",mx,my);
		
		if((GameState==0)&&(mx>=470 && mx<=570)&&(my>=390&&my<=450))
		{
			startButtonClickHandler();
		}
		else if((GameState==0)&&(mx>=470 && mx<=570)&&(my>=290&&my<=350))
		{ 
			rulesButtonClickHandler();
		}
		else if((GameState==0)&&(mx>=470 && mx<=570)&&(my>=190&&my<=250))
		{
			highScoreButtonClickHandler();
		}
		else if((GameState==2)&&(mx>=150 && mx<=250)&&(my>=110&&my<=170))
		{
			backButtonHandler();
		}
		else if((GameState==3)&&(mx>=150 && mx<=250)&&(my>=110&&my<=170))
		{
			backButtonHandler();
		}
		else if((GameState==1)&&(mx>=100 && mx<=200)&&(my>=90&&my<=150))
		{
			backButtonHandler();
		}
		else if((GameState==1)&&(mx>=830 && mx<=930)&&(my>=108&&my<=168)&&pauseScreen)
		{
			exitButtonHandler();
	
		}
		else if((GameState==5)&&(mx>=233 && mx<=333)&&(my>=378&&my<=438))
		{
			GameState=1;
		    whichChar=1;
		}
		else if((GameState==5)&&(mx>=683 && mx<=783)&&(my>=378&&my<=438))
		{
			GameState=1;
		    whichChar=2;
		}
		else if((GameState==0)&&(mx>=900 && mx<=940)&&(my>=90&&my<=110))
		{
			if(playMusic)
			{
				playMusic=false;
				notPlayBGMusic();
				
			}
			else
			{
				playMusic=true;
				playBGMusic();
			}
		}
		else if((startAgain)&&(mx>=357 && mx<=400)&&(my>=215&&my<=270))
		{
			GameState=1;
			startGame=false;
			pauseScreen=false;
			startAgain=false;
			if(playMusic)
			{
				playMusic=true;
				playBGMusic();
				
			}
			
			
		}
		else if((startAgain)&&(mx>=480 && mx<=550)&&(my>=215&&my<=270))
		{
			GameState=5;
			startGame=false;
			pauseScreen=false;
			startAgain=false;
			if(playMusic)
			{
				playMusic=true;
				playBGMusic();
				
			}
		}
		else if((startAgain)&&(mx>=613&& mx<=660)&&(my>=215&&my<=270))
		{
			GameState=0;
			startGame=false;
			pauseScreen=false;
			startAgain=false;
			if(playMusic)
			{
				playMusic=true;
				playBGMusic();
				
			}
		}
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		//place your codes here
		x -= 10;
		y -= 10;
	}
}


/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key) 
{
	if (key == 'q') 
	{
		exit(0);
	}
	if(key=='s')
	{
		startGame=1;
	}
	if(key=='p')
	{
		if(!pauseScreen)
		pauseScreen=true;
	    else
		pauseScreen=false;

	}
	if(key=='j')
	{
		if(!char1Jump)
		{
			
			PlaySound("jump audio.wav",  NULL, SND_FILENAME | SND_ASYNC);
			char1Jump=true;
			Jump1Up=true;
			didJump=true;
		}
	}
	
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
void iSpecialKeyboard(unsigned char key) {

	if (key == GLUT_KEY_END) {
		exit(0);
	}
	//place your codes for other keys here
}

void ShowHomePage()
{
	
	iSetColor(255,255,255);
	iFilledRectangle(0,0,1000,600);
	iShowBMP2(0,0,"background.bmp",0);
	
	

	iShowBMP2(150,80,"tallCactus.bmp",0);
	iShowBMP2(630,80,"cactus.bmp",0);

    iShowBMP2(300,200,"title.bmp",0);
	iShowBMP2(410,300,"button.bmp",0);
	iShowBMP2(410,200,"button.bmp",0);
	iShowBMP2(410,100,"button.bmp",0);
	

	iSetColor(255,255,255);
	iText(470,390,"START",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(470,290,"RULES",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(435,190,"HIGH SCORE",GLUT_BITMAP_TIMES_ROMAN_24);
	iShowBMP2(880,15,"play music.bmp",0);
	

}

void startButtonClickHandler()
{
	if(!chosenChar)
	{
		GameState=5;
		chosenChar=true;
	}
	else
	{
		GameState=1;
	}
}

void rulesButtonClickHandler()
{
    GameState=2;
}

void highScoreButtonClickHandler()
{
	GameState=3;
}

void scoreButtonClickHandler()
{
	GameState=4;
}

void backButtonHandler()
{
	GameState=0;
}

void exitButtonHandler()
{
	GameState=0;
	pauseScreen=false;
	startGame=0;
}

void showCharChoose()
{
	iSetColor(255,255,255);
	iFilledRectangle(0,0,1000,600);
	iShowBMP2(0,0,"background.bmp",0);
	iShowBMP2(300,270,"choose.bmp",0);

	

	showCharacter1Idle();
	showCharacter2Idle();

	iShowBMP2(190,290,"button.bmp",0);
	iShowBMP2(640,290,"button.bmp",0);
	iSetColor(255,255,255);
	iText(233,378,"Character 1",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(683,378,"Character 2",GLUT_BITMAP_TIMES_ROMAN_24);


}

void showCharDeath()
{
    if(whichChar==1)
	{
		 frame1 = (frame1 + 1) % 24;
		 iShowBMP2(192, 162, character1Death[frame1], 0);
	}
	if(whichChar==2)
	{
		 frame2 = (frame2+ 1) % 24;
		 iShowBMP2(192, 162, character2Death[frame2], 0);
	}
	
    
}

void drawStartPage()
{
	iClear();
	iSetColor(255,255,255);
	iFilledRectangle(0,0,1000,600);
	iShowBMP2(0,0,"background.bmp",0);
	
	
}


void drawRulesPage()
{
	iSetColor(255,255,255);
	iFilledRectangle(0,0,1000,600);
	iShowBMP2(0,0,"background.bmp",0);
	iShowBMP2(230,90,"rule page.bmp",0);
	iShowBMP2(359,448,"egg - Copy.bmp",0);

	iShowBMP2(80,20,"button.bmp",0);
	iSetColor(255,255,255);
	iText(150,110,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);

}

void drawHighScorePage()
{
	
	
	iSetColor(255,255,255);
	iFilledRectangle(0,0,1000,600);
	iShowBMP2(0,0,"blur background.bmp",0);
	iSetColor(153,255,51);
	iShowBMP2(450,415,"score title.bmp",0);
	iShowBMP2(270,110,"highScoreTablet.bmp",0);
	iShowBMP2(80,20,"button.bmp",0);
	iSetColor(255,255,255);
	iText(150,110,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);

	

    
	loadScore();
    
    iSetColor(255, 255, 255); 
   

    iText(300,340,"HIGHEST SCORE :",GLUT_BITMAP_TIMES_ROMAN_24);
    char scoreStr[10];
    sprintf(scoreStr, "%d", high[0]);
    iText(549, 340, scoreStr, GLUT_BITMAP_TIMES_ROMAN_24);
   

}

void drawScorePage()
{
	if(didTakeScore)
	{
		takeScore(score);
	}
	loadScore();


	didTakeScore=false;
	iSetColor(255,255,255);
	iFilledRectangle(0,0,1000,600);
	iShowBMP2(0,0,"blur background.bmp",0);
	iShowBMP2(380,350,"big score title.bmp",0);
	iShowBMP2(250,50,"scoreboard.bmp",0);
	char scoreDisplay[100];
	char coinsDisplay[100];
	char highDisplay[100];
	sprintf(scoreDisplay,"%d",score);
	sprintf(coinsDisplay,"%d",coinsCollected);
	sprintf(highDisplay,"%d",high[0]);
	iSetColor(0,102,0);
    
	iText(340,450,"SCORE: ",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(340,400,"COINS COLLECTED: ",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(340,350,"HIGH SCORE: ",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(480,450,scoreDisplay,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(600,400,coinsDisplay,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(540,350,highDisplay,GLUT_BITMAP_TIMES_ROMAN_24);
	iShowBMP2(330,150,"buttonSmall.bmp",0);
	iShowBMP2(460,150,"buttonSmall.bmp",0);
	iShowBMP2(590,150,"buttonSmall.bmp",0);
	iSetColor(0,102,0);
	iText(357,215,"PLAY AGAIN");
	iText(480,215,"CHARACTER");
	iText(485,205,"CHANGE");
	iText(613,215,"EXIT GAME");
	
}

void showScoreButton()
{
	iShowBMP2(800,390,"score .bmp",0);
	iSetColor(255,255,255);
    iText(864,573," SCORE ");
	char scoreStr[2000];
    sprintf(scoreStr, "%d", score);
    iText(859, 541, scoreStr, GLUT_BITMAP_TIMES_ROMAN_24);
	
}


void updateScore()
{
	score+=1;
}

void setAll()
{
	int sum=-50;
	for(int i=0;i<20;i++)
	{
		STARTbackground[i].posY=0;
		STARTbackground[i].posX=sum;
		sum+=50;
	}
}

void render()
{
	
	for(int i=0;i<20;i++)
	{
		iShowBMP2(STARTbackground[i].posX,STARTbackground[i].posY,moveImage[i],0);
	}
}

void change() {
    for (int i = 0; i < 20; i++)
	 {
        STARTbackground[i].posX -= 50;
        if (STARTbackground[i].posX <-50) 
		{
            STARTbackground[i].posX = 923;  
        }
    }
}

void showCharacter1Idle()
{
		if(GameState==5)
		{
			 frame1 = (frame1 + 1) % 12;
			 iShowBMP2(230, 162, character1Idle[frame1], 0);
            
		}
		else
		{
			frame1 = (frame1 + 1) % 12;
			 iShowBMP2(192, 162, character1Idle[frame1], 0);
             
		}
}

void showCharacter2Idle()
{
	 if(GameState==5)
	 {
		 frame2 = (frame2 + 1) % 12;
		iShowBMP2(680, 162, character2Idle[frame2], 0);
       
	 }
	 else
	 {
		 frame2 = (frame2 + 1) % 12;
		iShowBMP2(192, 162, character2Idle[frame2], 0);
        
	 }

}

void handleJump()
{
	
	if(char1Jump && Jump1Up)
	{
		
		if(char1JumpStruct.char1JumpPosY<162+jumpHeight)
		{
			if(!pauseScreen)
			{
				char1JumpStruct.char1JumpPosY += jumpSpeed;
			}
			
		}
		else
		{
			Jump1Up=false;
		}
		
	}
	else
	{
			if(char1JumpStruct.char1JumpPosY>162)
			{
				if(!pauseScreen)
				{
					char1JumpStruct.char1JumpPosY-=gravity;
				}
			}
			else
			{
				char1JumpStruct.char1JumpPosY=162;
				char1Jump=false;
				didJump=false;
			}
	}
	
	

}



void showCharacterJump()
{
	if(char1Jump && whichChar==1)
	{
		
        
        if(!pauseScreen)
		{
			frame1 =(frame1+1) % 24;
			iShowBMP2(192, char1JumpStruct.char1JumpPosY, character1Jump[frame1], 0);
		}
       
	   if(livesBool)
	   {
		charCollisionWithOb(192,char1JumpStruct.char1JumpPosY);
	   }
	}
	if(char1Jump && whichChar==2)
	{
		
        
        if(!pauseScreen)
		{
			 frame2 = (frame2 + 1) % 24;
			 iShowBMP2(192, char1JumpStruct.char1JumpPosY, character2Jump[frame2], 0);
		}
		if(livesBool)
		{
			charCollisionWithOb(192,char1JumpStruct.char1JumpPosY);
		}
	}


}

void showCharacterRun()
{
	if(!char1Jump && whichChar==1 )
	{
		
        
        if(!pauseScreen)
		{
			 frame1 = (frame1 + 1) % 18;
			 iShowBMP2(192,162, character1Run[frame1], 0);
		}

		if(livesBool)
		{
			charCollisionWithOb(192,162);
		}
	}
	if(!char1Jump && whichChar==2 )
	{
		
        
        if(!pauseScreen)
		{
			frame2 = (frame2 + 1) % 18;
			iShowBMP2(192, 162, character2Run[frame2], 0);
		}
		if(livesBool)
		{
			charCollisionWithOb(192,162);
		}
	}
}

//Obstacle

void obstacleShow1()
{
	
	iShowBMP2(obPosX1,obPosY1,obstacle[obNum1],0);
	if(!pauseScreen)
	  obPosX1-=initialSpeed;

	if(obPosX1<-250)
	{
		
		obPosX1=(rand()%15)+1100;
		obNum1=rand()%2;
		livesBool=true;
	}

}
void obstacleShow2()
{
	
	iShowBMP2(obPosX2,obPosY2,obstacle[obNum2],0);
	if(!pauseScreen)
	  obPosX2-=initialSpeed;
	if(obPosX2<-250)
	{
		
		obPosX2=(rand()%15)+1100;
		obNum2=rand()%2;
		livesBool=true;
	}

}
//codes for coin 

void funcCoin()
{
	
	for (int i = 0; i < 5; i++) {
       
        coinCollisionWithChar(coinIndividual[i].coinPosX, coinIndividual[i].coinPosY);
    }

    updateCoinPosition();
    drawCoin();
}

int CoinCollisionWithCactus(int coinX,int coinY)
{
	if((coinX+100>=obPosX1 && coinX<=obPosX1+100)&&(coinY+100>=obPosY1 && coinY<=obPosY1+100))
	return 1;
    if((coinX+100>=obPosX2 && coinX<=obPosX2+100)&&(coinY+100>=obPosY2 && coinY<=obPosY2+100))
	return 1;
    
    return 0;

}

void coinLine()
{
	
	for(int i=0;i<5;i++)
	{
		
		coinIndividual[i].coinPosX=1100+(72*i);
		coinIndividual[i].coinPosY=(rand()%300)+140;
		coinIndividual[i].collected=false;
	}
}

//For speed increase
void updateSpeed()
{
   initialSpeed+=1;
}

void drawCoin()
{
	
	
	for(int i=0;i<5;i++)
	{
		
		if(!coinIndividual[i].collected )
		{
		    	
			iShowBMP2(coinIndividual[i].coinPosX,coinIndividual[i].coinPosY,coins[i],0);
				
		}
		
		
	}
}

void updateCoinPosition()
{
	for(int i=0;i<5;i++)
	{
		coinIndividual[i].collected = false; 
		
		if(!pauseScreen)
		  coinIndividual[i].coinPosX-=initialSpeed;

		if(coinIndividual[i].coinPosX<-100 || startAgain)
		{
			coinIndividual[i].coinPosX=1100+(72*i);
		  
		   coinIndividual[i].coinPosY=(rand()%300)+140;

		}

	}
}

void coinCollisionWithChar(int coinX, int coinY)
{
	int x=192;
	int y;
	if(char1Jump)
	{
		y= char1JumpStruct.char1JumpPosY;
	}
	else
	{
		y=162;
	}
   	
	if(shouldIwork2||forCoin)
	{
		if (abs(x - coinX) <200 && abs(y - coinY) < 200)    
    {   for (int i = 0; i < 5; i++)
        {
            if (coinIndividual[i].coinPosX == coinX && coinIndividual[i].coinPosY == coinY)
            {
				 coinIndividual[i].coinPosX = rand() % 800 + 1100;
                coinIndividual[i].coinPosY = rand() % 400 + 123;
                coinIndividual[i].collected = true; 
				coinsCollected+=1;
				if(coinIndividual[i].collected)
				{
					coinMusic=true;
				}
				else
				{
					coinMusic=false;
				}
				playCoinMusic();
				

				
                score += 10;
              
            }
        }
    }
	}
	else
	{
		if (abs(x - coinX) <50 && abs(y - coinY) < 50)    
    {   for (int i = 0; i < 5; i++)
        {
            if (coinIndividual[i].coinPosX == coinX && coinIndividual[i].coinPosY == coinY)
            {
				 coinIndividual[i].coinPosX = rand() % 800 + 1100;
                coinIndividual[i].coinPosY = rand() % 400 + 123;
                coinIndividual[i].collected = true; 
				coinsCollected+=1;
				if(coinIndividual[i].collected)
				{
					coinMusic=true;
				}
				else
				{
					coinMusic=false;
				}
				playCoinMusic();
				
                score += 10;
              
            }
        }
    }
	}
    
	
}

void playCoinMusic()
{
     if(coinMusic )
	{
			PlaySound("coinM.wav",  NULL, SND_FILENAME | SND_ASYNC);
	}
	else
	{
			PlaySound(NULL,0,0);
	}
}

void coinCollectedShow()
{
	iSetColor(0,0,0);
	iFilledRectangle(130,555,20,30);
	iShowBMP2(101,395,"coin button.bmp",0);
	iSetColor(255,255,255);
	char CoinStr[2000];
    sprintf(CoinStr, "%d", coinsCollected);
    iText(209, 561, CoinStr, GLUT_BITMAP_TIMES_ROMAN_24);
}

void playBGMusic()
{
    
	if(playMusic)
	{
			PlaySound("BG sound.wav",  NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	}

}

void notPlayBGMusic()
{
	PlaySound(0,0,0);
}

void charCollisionWithOb(int charX,int charY)
{
    if((charX>=obPosX1 && charX<=obPosX1+50)&&(charY>=obPosY1 && charY<=obPosY1+50))
	{
		livesBool=false;
		lives--;
		livesLost=true;
		playLifeMusic();
		livesLost=false;
	}
    if((charX>=obPosX2 && charX<=obPosX2+50)&&(charY>=obPosY2 && charY<=obPosY2+50))
	{
		livesBool=false;
		lives--;
		livesLost=true;
		playLifeMusic();
		livesLost=false;
	}
}

void playLifeMusic()
{
	 if(livesLost)
	{
			PlaySound("lose life.wav",  NULL, SND_FILENAME | SND_ASYNC);
	}
	else
	{
			PlaySound(NULL,0,0);
	}
}

//Egg

void eggShow()
{
   showEgg=true;
}

void renderEgg()
{
	 
	iShowBMP2(eggX,eggY,"egg.bmp",0);
	if(!pauseScreen)
	{
		eggX-=initialSpeed;
	}
	
	int l;
	if(!didJump)
	{
		l=charCollisionEgg(eggX,eggY);
	}
	if(l)
	{
		PlaySound("eggM.wav",  NULL, SND_FILENAME | SND_ASYNC);
		eggX=1100;
	    eggY=162;
		showEgg=false;
		int i=rand()%3;
		consequence(i);
		
	}
	

	 if(eggX<-250 && !startAgain)
	 {
		
		eggX=1100;
	    eggY=162;
		showEgg=false;
		
	 }
}

int charCollisionEgg(int charX,int charY)
{
	
	if((charX+30>=162 && charX<=162+30)&&(charY+30>=192&& charY<=192+30))
	{
		return 1;
	

	}

	return 0;
	
}

void consequence(int i)
{
	
	if(i==0)
	{
		
		for(int j=0;j<50;j++)
		{
			
			iShowBMP2(350,240,"cacRem.bmp",0);
			//Sleep(30);
			boolForSurprise=true;
		}
		
		
		shouldIwork=true;
	}
	else if(i==1)
	{
	   	for(int j=0;j<50;j++)
		{
			
			iShowBMP2(350,240,"birdIntro.bmp",0);
			//Sleep(30);

		}
		
		
		BirdBool=true;
	}
	else
	{
		
		for(int j=0;j<50;j++)
		{
			
			iShowBMP2(350,240,"coinScreen.bmp",0);
			//Sleep(30);

		}
		
		shouldIwork2=true;
		forCoin=true;
		boolForSurprise=true;
	}

}

void callToMainCacRem()
{
	if(showCac && shouldIwork)
	{
		showCac=false;
		obPosX1=923;
        obPosY1=130;
        obPosX2=1380;
        obPosY2=130;
	}
	else
	{
		shouldIwork=false;
	    showCac=true;
	}
}

void callToMainCoinRem()
{
	if(shouldIwork2)
	{
		shouldIwork2=false;
	}
	else
	{
		forCoin=false;
	}
}


void renderBird()
{
	frameS=(frameS+1)%18;
	
	if(!pauseScreen)
	{
		iShowBMP2(BirdX,BirdY,Bird[frameS],0);
		BirdX-=17;
	}
	
	if(!hasCollidedBird && charColllisionWithBird(BirdX,BirdY))
	{
		hasCollidedBird=true;
	}

	 if(BirdX<-250 && !startAgain)
	 {
		BirdX=1132;
		BirdY=rand()%200+250;
		hasCollidedBird=false;
		birdCount++;
		if(birdCount>2)
		{
			BirdBool=false;
			birdCount=0;
		}
	 }
}

int charColllisionWithBird(int charX,int charY)
{
	if(Jump1Up || didJump)
	{

		int x=192;
	    int y;
	if(char1Jump)
	{
		y= char1JumpStruct.char1JumpPosY;
	}
	else
	{
		y=162;
	}
    
    if (abs(x - charX) <50 && abs(y - charY) < 50)   
    {  
		livesBool=false;
		lives--;
		livesLost=true;
		playLifeMusic();
		livesLost=false;
		return 1;

    }
	}
	return 0;
}


void loadScore()
 {
    FILE *fp = fopen("score.bin", "rb");
    if (fp == NULL) 
	{
        for (int i = 0; i < 3; i++) {
            high[i] = 0;
        }
        printf("No high scores file found. Initializing scores to 0.\n");
    } 
	else
	 {
        fread(high, sizeof(int), 3, fp);
        fclose(fp);
    }
}


void takeScore(int score) {
    loadScore();  

	
        if (high[2] < score)
	    {
            high[2]=score;
        }
    

	
    
    for (int i = 0; i < 3 - 1; i++) 
	{
        for (int j = i + 1; j < 3; j++) {
            if (high[i] < high[j]) {
                int temp = high[i];
                high[i] = high[j];
                high[j] = temp;
            }
        }
    }

    saveHighScores();
}

void saveHighScores() 
{
    FILE *fp = fopen("score.bin", "wb");
    if (fp == NULL) 
	{
        printf("Error opening file for writing.\n");
        return;
    }
    fwrite(high, sizeof(int), 3, fp);
    fclose(fp);
}


void timeFunc()
{
	if((timeIndex<6)&& boolForSurprise &&!startAgain)
	{
		iShowBMP2(790,0,timeStamp[timeIndex],0);
		
	}
	else
	{
		
		boolForSurprise=false;
	}
}

void funcForTimeFunc()
{
	if((timeIndex<=6)&& boolForSurprise)
	{
		timeIndex++;
	}
	else
	{
		timeIndex=0;
	}
}

int main() 
{
	playBGMusic();
	srand(time(NULL));
	setAll();
	iSetTimer(85,change);
	iSetTimer(5000,updateSpeed);
	iSetTimer(3500, funcForTimeFunc);
	iSetTimer(10000,callToMainCacRem);
	iSetTimer(15000,callToMainCoinRem);
	
	


	
	int Time=(rand()%500)+25000;
	iSetTimer(Time,eggShow);
	if(GameState==5)
	{
		iSetTimer(30000,showCharacter1Idle);
		iSetTimer(35000,showCharacter2Idle);
	}
	
	
	
	

	iInitialize(1000, 600, "demo");
	return 0;
}
