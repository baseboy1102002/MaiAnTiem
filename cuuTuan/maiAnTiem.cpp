#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

bool checknguyento (int n){
	if (n<2) return false;
	int k=sqrt(n);
	for (int i=2; i<=k;i++)
	if (n%i==0) return false;
	return true;
}

int tinhP1(int hp){
	if(checknguyento(hp)) return 1000;
	return hp;
}
int tinhP2(int hp, int d, int s){
	if(checknguyento(hp)) return ((hp+s)%1000);
	return ((hp+d)%100);
}
int tinhP3(int hp){
	if(checknguyento(hp)) return hp;
	return 1000;
}
int tinhP4(int hp, int d, int s){
	if(checknguyento(hp)) return ((hp+d)%100);
	return ((hp+s)%1000);
}

int checkAmstrong(int hp1, int hp2){
	int tong1 = hp1, tong2= hp2;
	int tachso1, tachso2;
	int s1 = 0;
	int s2 = 0;
	while (hp1!=0){
		tachso1 = hp1%10;
		s1 += pow(tachso1,3);
		hp1 /= 10;
	}
	while (hp2!=0){
		tachso2 = hp2%10;
		s2 += pow(tachso2,3);
		hp2 /= 10;
	}
	if((s1==tong1) && (s2==tong2)) return 1;
	return 0;
}

int tinhTriangleNum(int n){
	if(n==1) return 1;
	return n+tinhTriangleNum(n-1);
}

double tinhGs(int s){
	if(s%6==0) return 2.0*s;
	if(s%6==1) return 1.0*s/2;
	if(s%6==2) return -1.0*pow(s%9,3)/5;
	if(s%6==3) return -1.0*pow(s%30,2)+3*s;
	if(s%6==4) return -1.0*s;
	if(s%6==5) return -1.0*tinhTriangleNum((s%5)+5);	
}

double tinhPt(int s, char t[]){
	int n;
	if(strcmp(t, "Flood")==0) n=1;
	if(strcmp(t, "Storm")==0) n=2;
	if(strcmp(t, "Rain")==0) n=3;
	if(strcmp(t, "Shower")==0) n=4;
	if(strcmp(t, "Drizzle")==0) n=5;
	if(strcmp(t, "Cloudy")==0) n=6;
	if(s%6==0){
		switch(n){
			case 1:
				return -0.1; break;
			case 2:
				return -0.05; break;
			case 3:
				return 0.0; break;
			case 4:
				return 0.05; break;
			case 5:
				return 0.1; break;
			case 6:
				return 0.15; break;
		}
	}
	if(s%6==1){
		switch(n){
			case 1:
				return -0.15; break;
			case 2:
				return -0.1; break;
			case 3:
				return -0.05; break;
			case 4:
				return 0.0; break;
			case 5:
				return 0.05; break;
			case 6:
				return 0.1; break;
		}
	}
	if(s%6==2){
		switch(n){
			case 1:
				return -0.2; break;
			case 2:
				return -0.15; break;
			case 3:
				return -0.10; break;
			case 4:
				return -0.05; break;
			case 5:
				return 0.0; break;
			case 6:
				return 0.05; break;
		}
	}
	if(s%6==3){
		switch(n){
			case 1:
				return -0.25; break;
			case 2:
				return -0.2; break;
			case 3:
				return -0.15; break;
			case 4:
				return -0.10; break;
			case 5:
				return -0.05; break;
			case 6:
				return 0.0; break;
		}
	}
	if(s%6==4){
		switch(n){
			case 1:
				return -0.05; break;
			case 2:
				return 0.0; break;
			case 3:
				return 0.05; break;
			case 4:
				return 0.1; break;
			case 5:
				return 0.15; break;
			case 6:
				return 0.2; break;
		}
	}
	if(s%6==5){
		switch(n){
			case 1:
				return 0.0; break;
			case 2:
				return 0.05; break;
			case 3:
				return 0.10; break;
			case 4:
				return 0.15; break;
			case 5:
				return 0.2; break;
			case 6:
				return 0.25; break;
		}
	}
	
}

double tinhP(int P1,int P2,int P3,int P4,double f){ //p = 1.0*(((P1+P2*f)/(1000+abs(P2*f)))+((P3+P4*f)/(1000+abs(P4*f))))/2;
	double p;
	p = (((P1+P2*f)/(1000+abs(P2*f)))+((P3+P4*f)/(1000+abs(P4*f))))/2;
	if(p<0) return 0.0;
	if(p>1) return 1.0;
	return p;
}

int main(){
	int hp1, hp2, d, s, P1, P2, P3, P4;
	double rate, p, f;
	char t[10];
	
	FILE *fo = fopen("input.txt","r");
	fscanf(fo,"%d",&hp1);
	fscanf(fo,"%d",&hp2);
	fscanf(fo,"%d",&d);
	// weather
	int i = 0;
	char c = fgetc(fo);
	while ( (c = fgetc(fo)) != 32){
		t[i++] = c;
	}
	//
	fscanf(fo,"%d",&s);
	fclose(fo);
	//printf("%d %d %d %d %s\n", hp1, hp2, d, s, t);
	P1 = tinhP1(hp1);
	P2 = tinhP2(hp1,d,s);
	P3 = tinhP3(hp2);
	P4 = tinhP4(hp2,d,s);
	//printf("\n%d %d %d %d\n", P1,P2,P3,P4);
	if (checkAmstrong(hp1,hp2)==true){
		p = 1.0;
		FILE *fw = fopen("output.txt","w");
		fprintf(fw,"%.3f",p);
		fclose(fw);
		return 0;
	}
	if(d<200){
		f = 0.0;
		p = tinhP(P1,P2,P3,P4,f);
	}
	if(d>=200 && d<300){ 
		rate = 1.0*((d+P1+P2)+(d+P3+P4))/2000;
		if(rate>0.8){
			p = 0.0;
		}
		else{
			hp1=hp1-100; hp2=hp2-50;
			d=d+100;
			P1 = tinhP1(hp1);
			P2 = tinhP2(hp1,d,s);
			P3 = tinhP3(hp2);
			P4 = tinhP4(hp2,d,s);
		}
	}
	if(d>=300 && d<=800){ 
		f = (40-(1.0*abs(d-500)/20)+tinhGs(s))*(1+tinhPt(s,t));
		p = tinhP(P1,P2,P3,P4,f);
	} 
	if(d>800){
		f = 1.0*(-1*d*s)/1000;
		p = tinhP(P1,P2,P3,P4,f);
	}
	//printf("\n%.3f", p);
	FILE *fw = fopen("output.txt","w");
	fprintf(fw,"%.3f",p);
	fclose(fw);
	return 0;
}

