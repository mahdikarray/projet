#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "enig.h"

void init_enigme(enigme * e)//
{
	e->p.x=0;
	e->p.y=0;
	e->img=NULL;


}

 void generer (SDL_Surface * screen  , char image [],enigme *e,int *alea)
{
	
    srand(time(NULL));

 *alea = 1+ rand()%6;

 sprintf(image ,"%d.png",*alea);
e->img = IMG_Load(image);
 SDL_BlitSurface(e->img,NULL,screen,&(e->p)) ;
  SDL_Flip(screen) ;
}

 int solution (char image [])
 {
 	int solution =0 ;

 	if(strcmp(image,"1.png")==0)
 	{
     		solution =2 ;
 	}
 	else  	if(strcmp(image,"2.png")==0)
 	{
 		solution =1;

 	}
 	else 	if(strcmp(image,"3.png")==0)
 	{
 		solution =3;
 	}
	else  	if(strcmp(image,"4.png")==0)
 	{
 		solution =3;

 	}
 	else 	if(strcmp(image,"5.png")==0)
 	{
 		solution =2;
 	}
	else  	if(strcmp(image,"6.png")==0)
 	{
 		solution =1;

 	}
 	

 	return solution;
 }

int resolution (int * running,int *run )//
{
	SDL_Event event ;
  int r=0 ;
	SDL_PollEvent(&event);
	switch(event.type)
	{
		  case SDL_QUIT:
			        *running= 0 ;
                                *run = 0;
				break ;

       case SDL_KEYDOWN :
            switch( event.key.keysym.sym )
                {
			  case  SDLK_a:                        //fl main.c
			  r= 1;
			   break ;
			   case  SDLK_z :
			   r= 2;
			   break;
			   case SDLK_e:
			   r=3 ;
			   break;

			    }
       break ;


	}
  return r ;
}

 void afficher_resultat (SDL_Surface * screen,int s,int r,enigme *e)//
 {

 	if (r==s)
 	{       

 		e->img=IMG_Load("00.png");
 		SDL_BlitSurface(e->img, NULL, screen, &(e->p)) ;
        SDL_Flip(screen);
 	}                                                                        //mmain.c
 	else
 	{
 		e->img=IMG_Load("11.png");
 		SDL_BlitSurface(e->img, NULL, screen, &(e->p)) ;
        SDL_Flip(screen);
 	}
 }
