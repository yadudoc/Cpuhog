/* Its all good as long as its nice and Free 
 * Author : Yadu Nand B
 * Date   : 17.dec.09
 * 
 * compile with -O and -lm flags :)
 * 
 */


#include <stdio.h> 
#include <math.h>
#include <unistd.h>
#include <stdlib.h>

/* using timestamp counter of processor as timer 
 */ 
static inline unsigned long long read_rdtsc(void){
unsigned long long d;
__asm__ __volatile__ ("rdtsc" : "=A" (d) );
return d;
}

int main (int argc,char *argv[]) {
	int percent,i ; 
	char ch ;
	
	while ((ch=getopt(argc,argv,"p:")) != -1){
		switch(ch){
		case 'p' : percent = atoi(optarg) ;
				   break;
		case '?' : printf(" Error : Unknown argument list" );
					exit(1) ;
		}
	}
	
	srand(1) ;

	long long work1,work2,sleep ;
	double timew,times ;
	
	if(percent==0){while(1) usleep(100000); }

	do 
	{
	work1 = read_rdtsc();
	sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;
	sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;
	sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;
	sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;
	sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;
	sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;
	sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;
	sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;
	sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;
	sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;
	sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;
	sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;
	sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;
	sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;
	sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;
	sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;
	sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;
	sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;
	sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;
	sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;
	sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;
	sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;
	sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;
	sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;
	sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;
	sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;
	sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;
	sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;
	sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;
	sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;
	sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;
	sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;
	sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;sqrt(rand()) ;
	work2 = read_rdtsc();
	
	printf("\n Work time : %lld ",(work2-work1)/2000 );
	
	sleep=(int)((100-percent)*(work2-work1)/percent )  + read_rdtsc();
	
/*  spinlock for sleep , minimal work 
 */  	

	while(1){
	if( read_rdtsc() >= sleep ) break;	
	usleep(1);	 
	}	
	
	}while(1);		
	return 0 ;
}

//__asm__ __volatile__ ("nop");__asm__ __volatile__ ("nop");
		
