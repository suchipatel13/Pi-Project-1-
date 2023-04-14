#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "FBCurses.h"

void convertTime(int num1, colorcode_t oncolor, colorcode_t offcolor,int column){
        int count = 7;
        while(num1 !=0){
                if (num1 %2 ==0){
                        setPixel(count,column,offcolor);

        }
        else{
                setPixel(count,column,oncolor);
        }
        num1 = num1/2;
        count --;

        }

        for (int i = count; i> = 0; i--){
                setPixel(i,column,offcolor);
        }
}

void showTime(colorcode_t oncolor,colorcode_t offcolor){
        time_t latestime;
        struct tm * timeinfo;
        time(&latestime);
        timeinfo = localtime (&latestime);

        binaryTime(timeinfor->tm_hour, oncolor,offcolor,1)
         binaryTime(timeinfor->tm_min, oncolor,offcolor,3);
         binaryTime(timeinfor->tm_sec, oncolor,offcolor,5);
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
                sleep(0.5);  //sleep for 1 second
        }
        cleanupScreen();
}
     





                                                     
