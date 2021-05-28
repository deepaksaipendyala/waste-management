#include <stdio.h>

int avg();
int reward();
int earn();
int percentage();
int customer();

int main() {
 int option,choice,h,d,area,x,j,k;
 printf("Namaskar..! Welcome to Waste Management Calculator\nif you are consumer, please type 1\nif you are from Municipal Authority, please press 2:");
 scanf("%d", &option);
if (option==2){
  printf("Welcome back to Municipal Waste management calculator\nPlease enter no of areas in the municipality:");
  scanf("%d", &area);
  printf("Please enter no of houses in the area:");
  scanf("%d", &h);
  printf("Please enter the no of days to be calculated:");
  scanf("%d", &d);
  x=h;
  k=0;
  float degrad[d*h],plastic[d*h],elec[d*h];
  for (int f=0;f<area;f++){
    printf("ENTER THE DETAILS IN AREA %d\n",f+1);
    for (int g=0;g<d;g=g+3){
    printf("enter the quantity of degradable waste in kg on day %d\n",g+1);
    j=0;
  for (int i=k;i<h;i++){
  printf("Enter quantity in house %d :",j+1);
  scanf("%f",&degrad[i]);
  j=j+1;
}
k=k+h;
h=h+h;
 }
    k=0;
    h=x;
    for(int g=1;g<d;g=g+3){
    printf("enter the quantity of plastic waste in kg on day %d\n",g+1);
    j=0;
    for (int i=k;i<h;i++){
      printf("Enter quantity in house %d :",j+1);
      scanf("%f",&plastic[i]);
      j=j+1;             }
      k=k+h;
      h=h+h;
                      }
  k=0;
  h=x;
  for (int g=2;g<d;g=g+3){
   printf("enter the quantity of electronic waste in kg on day %d\n",g+1);
     j=0;
   for(int i=k;i<h;i++){
     printf("Enter quantity in house %d:",j+1);
     scanf("%f",&elec[i]);
    j=j+1;             }
      k=k+h;
      h=h+h;
  }
  }
  printf("If you want to computes the statistics of the waste collection per area, Please enter 1\n If you want to reward the house which gives less quantity of waste, please enter 2\nIf you want to Compute the total earning for the municipality, please enter 3\nIf you want to know what percentage of the waste is from what category, please enter 4:");
scanf("%d",&choice);
if (choice==1){
  avg(degrad,plastic,elec,area,h,d);
}else if (choice==2){
  reward(degrad,plastic,elec,area,h,d);
}else if (choice==3){
  earn(degrad,plastic,elec,area,h,d);
}else if (choice==4){
  percentage(degrad,plastic,elec,area,h,d);
}else printf("wrong input, sorry! run again");

}
else if (option==1){
  customer();
}else printf("wrong input, sorry! run again");

/*charges : 1kg degredable waste - 5rs
1kg plastic waste - 10rs
1kg electronic waste - 15rs */

return 0;
}





int avg(float degrad[],float plastic[],float elec[],int area,int h,int d){


return 0;
}

int reward(float degrad[],float plastic[],float elec[],int area,int h,int d){



return 0;
}


int earn(float degrad[],float plastic[],float elec[],int area,int h,int d){


float tdeg,tplas,telec,total,finall;
int a,b,c,g,f,x,k,j;
tdeg=0;
x=h;
k=0;


for (int f=0;f<area;f++){
    for (int g=0;g<d;g=g+3){
  for (int i=k;i<h;i++){
    a=0;
    a=degrad[i];
    a=a*5;
    tdeg=tdeg+a;
}
k=k+h;
h=h+h;
 }
    tplas=0;
    k=0;
    h=x;
    for(int g=1;g<d;g=g+3){
    for (int i=k;i<h;i++){
     b=0;
     b=plastic[i];
     b=b*10;
     tplas=tplas+b;    }
      k=k+h;
      h=h+h;
                      }
  telec=0;
  k=0;
  h=x;
  for (int g=2;g<d;g=g+3){
   for(int i=k;i<h;i++){
     c=0;
     c=elec[i];
     c=c*15;
    telec=telec+c; }
      k=k+h;
      h=h+h;
  }
  total=tdeg+tplas+telec;
  finall+=total;
  k=0;
  h=x;
    }
printf("So Finally, Total Earnings of the Municipality for %d days in %d Area/Areas is %.2f rupees",x,area,finall);

return 0;
}

int percentage(float degrad[],float plastic[],float elec[],int area,int h,int d){



return 0;
}

int customer(){

  return 0;
}