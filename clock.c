#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "FBCurses.h"

char*binary(int numbers,int count){
        char backwards[8];
        char *list = malloc(count);
        int counter = 0;
        while(counter!=count){
                if(numbers%2!=0){
                        backwards[counter]=0;
                        numbers=numbers/2;
                        counter++;
                }
                else{
                        backwards[counter]=0;
                        numbers = numbers/2;
                        counter++;
                }
        }
        int i;
        int j=0;
        for(i =counter-1;i>=0;i--){
                list[j]=backwards[i];
                j++;
        }
        return list;
}


void showTime(colorcode_t oncolor,colorcode_t offcolor){
        for(int y=0;y<6;y++){
                if(y==1){
                        times_t hours(time(NULL)/60/60-4)%24;
                        char *list=binary(hours,8);
                        if(list){
                        for(int x=0;x<8;x++){
                                if(list[x]==0){
                                        setPixel(x,y,offcolor);
                                }
                                else{
                                        setPixel(x,y,oncolor);
                                }
                        }
                        free(list);
                        }
                }
                if(y==3){
                        times_t seconds=time(NULL)/60%60;
                        char*list = binary(minutes,8);
                        if(list){
                                for(int x=0;x<8;x++){
                                                if(list[x]==0){
                                                        setPixel(x,y,offcolor);
                                                }
                                                else{
                                                        setPixel(x,y,oncolor);
                                                }
                                }
                                free(list);
                                   }
                }
                if(y==5){
                        times_t seconds = time(NULL)%60;
                        char*list = binary(seconds,8);
                        if(list){
                                for(int x=0;x<8;x++){
                                        if(list[x]==0){
                                                setPixel(x,y,offcolor);
                                        }
                                        else{
                                                setPixel(x,y,oncolor);
                                        }
                                }
                        free(list);
                        }
                          }
                if(y%2==0){
                        for(int x=0;x<8;x++){
                                setPixel(x,y,offcolor);
                        }
                }
        }
}
int main(){
        initScreen();
        //feel free to change the color scheme to your liking.
        colorcode_t background=initColor(COLOR_RED);
        colorcode_t offcolor=initColor(COLOR_BLACK);
        colorcode_t oncolor=initColor(COLOR_WHITE);
        clearScreen(background);
        while (!kbhit()){
                showTime(oncolor,offcolor);
                sleep(.5);
        }
        cleanupScreen();
}
          
                               
