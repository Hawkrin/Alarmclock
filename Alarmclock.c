#include <stdio.h>
#include <time.h>

/*functions*/
int alarm_function ();
int clock_function ();

/*global variabels*/
int hour, minute, second, alarminput;


int main () {

	int input;
    
   	printf ("What's the current time? Enter in format HHMMSS: \n");
    	scanf ("%d", &input);
    	printf ("When do you want the alarm to go off? Enter in format HHMMSS: \n");
   	scanf ("%d", &alarminput);
    
    	/*math to split HHMMSS into hour/minute/second*/
    	hour = input / 10000;		
    	minute = (input - (hour * 10000)) / 100;
    	second = (input - (hour * 10000)) % 100;	

    	clock_function (); 
    
     	return 0;
}


int clock_function() {
   
	 int ALARM;

  	while (1) {
      		printf ("%02d : %02d : %02d \n", hour, minute, second);
      		if (second == 60) {
    	  		minute += 1;
    	 		second = 0;
		}
      		if (minute == 60) {
    			hour += 1;
    	  		minute = 0;
      		}
      		if (hour == 24) {
    	  		hour = 0;
    	  		minute = 0;
    	  		second = 0;
      		}

      		ALARM = alarm_function ();
      		if (ALARM == 1)  {
    			printf ("ALARM!");
    	 		 return 0;
          		}
      		second++;
		/* sleep delays the printing */
      		sleep (1);
		/* "clear" keeps the screen from flickering */
      		system ("clear");
    		}
	}


int alarm_function () {

    	int alarmHour, alarmMinute, alarmSecond;
    
    	alarmHour = alarminput / 10000;
    	alarmMinute = (alarminput - (alarmHour * 10000)) / 100;
    	alarmSecond = (alarminput - (alarmHour * 10000)) % 100;
    
    	if (hour == alarmHour && minute == alarmMinute && second == alarmSecond) {
       	 return 1;
        	}
	return 0;
}
