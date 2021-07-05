/* # Waste Management

@author deepak sai pendyala

Instructions :

1). Enter 1 for functionalities of

  a). Calculate Average waste
  b). Reward the House which gave lowest waste 
  c). Compute the Earnings of municipality
  d). Check what percentage of the waste is from what category

    Enter 2 for functionality of

  a). As an individual family, analyzing the expense for managing the waste

2). Enter Option of functionalities

3). Enter No of Areas

4). Enter No of Houses

5). Enter No of days

6) Enter Data of quantities for individual days and Houses.


*/
#include <stdio.h>

//Function Prototyping

float avg(float degrad[],float plastic[],float elec[],int area,int h,int d,int f,float finall);
int reward(float degrad[],float plastic[],float elec[],int area,int h,int d,int a,int b,int c);
float earn(float degrad[],float plastic[],float elec[],int area,int h,int d,int f,float finall);
int percentage(float degrad[],float plastic[],float elec[],int area,int h,int d,int f,float *td,float *tp,float *te,float *ptotal);
int customer();


int main() {
 int option,choice,h,d,area,x,j,k,i,g;
 int a,b,c,m;
 float finall=0;
 float result=0;
 printf("Namaskar..! Welcome to Waste Management Calculator\nif you are consumer, please type 1\nif you are from Municipal Authority, please press 2:");
 scanf("%d", &option);
if (option==2){
  printf("Welcome back to Municipal Waste management calculator\nPlease enter no of areas in the municipality:");
  scanf("%d", &area);
  printf("Please enter no of houses in the area:");
  scanf("%d", &h);
  printf("Please enter the no of days to be calculated:");
  scanf("%d", &d);
     c=d/3;
if (d%3==2)   {
    a=(c+1)*h;
    b=(c+1)*h;
    c=c*h;    }
else if (d%3==1) {
    a=(c+1)*h;
    b=c*h;
    c=c*h;       }
else if(d%3==0){
    a=c*h;
    b=c*h;
    c=c*h;     }
float degrad[a],plastic[b],elec[c];
float td,tp,te,ptotal;
x=h;
k=0;

printf("If you want to computes the statistics of the waste collection per area, Please enter 1\n If you want to reward the house which gives less quantity of waste, please enter 2\nIf you want to Compute the total earning for the municipality, please enter 3\nIf you want to know what percentage of the waste is from what category, please enter 4:");
scanf("%d",&choice);

for (int f=0;f<area;f++){
  k=0;
  h=x;
  printf("ENTER THE DETAILS IN AREA %d\n",f+1);
  for (g=0;g<d;g=g+3)    {
    printf("enter the quantity of degradable waste in kg on day %d\n",g+1);
    j=0;
    for (i=k;i<h;i++){
      printf("Enter quantity in house %d :",j+1);
      scanf("%f",&degrad[i]);
      j=j+1;         }
     k=i;
     h=h+x;               }
  k=0;
  h=x;
  for(g=1;g<d;g=g+3)     {
     printf("enter the quantity of plastic waste in kg on day %d\n",g+1);
     j=0;
     for (i=k;i<h;i++){
      printf("Enter quantity in house %d :",j+1);
      scanf("%f",&plastic[i]);
      j=j+1;          }
     k=i;
     h=h+x;               }
  k=0;
  h=x;
  for (g=2;g<d;g=g+3)   {
    printf("enter the quantity of electronic waste in kg on day %d\n",g+1);
     j=0;
    for(i=k;i<h;i++){
      printf("Enter quantity in house %d:",j+1);
      scanf("%f",&elec[i]);
      j=j+1;        }
     k=i;
     h=h+x;              }

  if (choice==1)         {
    result=avg(degrad,plastic,elec,area,x,d,f,finall);
    finall=finall+result; }
  else if (choice==2)                           {
    reward(degrad,plastic,elec,area,x,d,a,b,c); }
  else if (choice==3)      {
    result=earn(degrad,plastic,elec,area,x,d,f,finall);
    finall=finall+result; }
  else if (choice==4)                                               {
    percentage(degrad,plastic,elec,area,h,d,f,&td,&tp,&te,&ptotal); }
  else printf("wrong input, sorry! run again");

printf("\n\n\n");    }
}
else if (option==1){
   printf("Now, You're entering as a customer\n");
   customer();     }
else printf("wrong input, sorry! run again");

return 0;
}

/*charges : 1kg degredable waste - 5rs
1kg plastic waste - 10rs
1kg electronic waste - 15rs */



float avg(float degrad[],float plastic[],float elec[],int area,int h,int d,int f,float finall){

float tdeg,tplas,telec,total;
int a,b,c,g,x,k,j,i;
float avg=0;
tdeg=0;
x=h;
k=0;

    for (g=0;g<d;g=g+3){
  for (i=k;i<h;i++){
    a=0;
    a=degrad[i];
    tdeg=tdeg+a;
}
k=i;
h=h+x;
 }
    tplas=0;
    k=0;
    h=x;
    for( g=1;g<d;g=g+3){
    for (i=k;i<h;i++){
     b=0;
     b=plastic[i];
     tplas=tplas+b;    }
k=i;
h=h+x;
                      }
  telec=0;
  k=0;
  h=x;
  for (g=2;g<d;g=g+3){
   for(i=k;i<h;i++){
     c=0;
     c=elec[i];
    telec=telec+c; }
 k=i;
h=h+x;
  }
  total=tdeg+tplas+telec;
  avg=total/3;
 finall+=avg;
if(area==f+1){
printf("So Finally, Average waste in all Categories of waste in Municipality for %d days in %d Area/Areas is %.2f kgs",x,f+1,finall);
}
return finall;
}





int reward(float degrad[],float plastic[],float elec[],int area,int h,int d,int a,int b,int c){
int i,j,k=0;
float dh[h],ph[h],eh[h];
float dhd[h],phd[h],ehd[h];
for(i=0;i<h;i++){
  dh[i]=0;
  for(j=k;j<a;j+=h){
      dh[i]+=degrad[j];
  }k+=1;
}
for(int i=0;i<h;i++){
  printf("House %d gives %.2f kgs degradable waste \n",i+1,dh[i]);
}
float min = dh[0];
int hn;
for(i=0;i<h;i++){
  dhd[i]=dh[i];
}
    for (i=1;i<h;i++)
        if (dh[i]<min){
           min=dh[i];
        }
    for(i=0;i<h;i++){
      if(min==dhd[i]){
       printf("The house which gives low quantity of degradable waste is rewarded with badminton kit  house %d with %.2f kgs bio degradable waste\n",i+1,min);
      }
    }
k=0;
for(i=0;i<h;i++){
  ph[i]=0;
  for(j=k;j<b;j+=h){
ph[i]+=plastic[j];
  }k+=1;
}
for(int i=0;i<h;i++){
  printf("House %d gives %.2f kgs plastic waste \n",i+1,ph[i]);
}
min = ph[0];
for(i=0;i<h;i++){
  phd[i]=ph[i];
}
    for (i=1;i<h;i++)
        if (ph[i]<min){
           min=ph[i];
        }
    for(i=0;i<h;i++){
      if(min==phd[i]){
       printf("The house which gives low quantity of plastic waste is rewarded with cricket kit i.e house %d with %.2f kgs plastic waste \n",i+1,min);
      }
    }
k=0;
for(i=0;i<h;i++){
  eh[i]=0;
  for(j=k;j<c;j+=h){
eh[i]+=elec[j];
  }k+=1;
}
for(int i=0;i<h;i++){
  printf("House %d gives %.2f kgs electronic waste \n",i+1,eh[i]);
}
min = eh[0];
for(i=0;i<h;i++){
  ehd[i]=eh[i];
}
    for (i=1;i<h;i++)
        if (eh[i]<min){
           min=eh[i];
        }
    for(i=0;i<h;i++){
      if(min==ehd[i]){
       printf("The house which gives low quantity of electronic waste is rewarded with footbal kit i.e house %d with %.2f kgs electronic waste",i+1,min);
      }
    }
return 0;
}


float earn(float degrad[],float plastic[],float elec[],int area,int h,int d,int f,float finall){

float tdeg,tplas,telec,total;
int a,b,c,g,x,k,j,i;
tdeg=0;
x=h;
k=0;

    for (g=0;g<d;g=g+3){
  for (i=k;i<h;i++){
    a=0;
    a=degrad[i];
    a=a*5;
    tdeg=tdeg+a;
}
k=i;
h=h+x;
 }
    tplas=0;
    k=0;
    h=x;
    for(g=1;g<d;g=g+3){
    for (i=k;i<h;i++){
     b=0;
     b=plastic[i];
     b=b*10;
     tplas=tplas+b;    }
k=i;
h=h+x;
                      }
  telec=0;
  k=0;
  h=x;
  for (g=2;g<d;g=g+3){
   for(i=k;i<h;i++){
     c=0;
     c=elec[i];
     c=c*15;
    telec=telec+c; }
     k=0;
     h=x;
  }
  total=tdeg+tplas+telec;
 finall+=total;
if(area==f+1){
printf("So Finally, Total Earnings of the Municipality for %d days in %d Area/Areas is ₹%.2f ",d,f+1,finall);
}
return finall;
}


int percentage(float degrad[],float plastic[],float elec[],int area,int h,int d,int f,float *td,float *tp,float *te,float *ptotal){

float tdeg,tplas,telec,total,t;
int a,b,c,g,x,k,j,i;
tdeg=0;
x=h;
k=0;

for (g=0;g<d;g=g+3)     {
  for (i=k;i<h;i++){
    a=0;
    a=degrad[i];
    tdeg=tdeg+a; }
  k=i;
  h=h+x;
                         }
tplas=0;
k=0;
h=x;
for(g=1;g<d;g=g+3)        {
  for ( i=k;i<h;i++){
     b=0;
     b=plastic[i];
     tplas=tplas+b;  }
  k=i;
  h=h+x;
                          }
telec=0;
k=0;
h=x;
for ( g=2;g<d;g=g+3)      {
  for( i=k;i<h;i++){
     c=0;
     c=elec[i];
    telec=telec+c;  }
  k=i;
  h=h+x;
                          }

total=tdeg+tplas+telec;
*td+=tdeg;
*tp+=tplas;
*te+=telec;
*ptotal+=total;

if(area==f+1)             {
 *td=(*td / *ptotal)*100;
 *tp=(*tp / *ptotal)*100;
 *te=(*te / *ptotal)*100;

 printf("total wastage is %.2f KGS\n",*ptotal);
 printf("%.2f %% is from degradable waste category\n",*td);
 printf("%.2f %% is from plastic waste category\n",*tp);
 printf("%.2f %% is from electronic waste category\n",*te);
                          }
return 0;
}



int customer(){
int d,j,k,h,x,area,g,i;
area=1;
h=1;
x=h;
printf("Please enter the no of days to be calculated:");
scanf("%d", &d);
float degrad[d],plastic[d],elec[d];

for (g=0;g<d;g=g+3){
   printf("enter the quantity of degradable waste in kg on day %d:",g+1);
   scanf("%f",&degrad[g]);
}

for(g=1;g<d;g=g+3){
    printf("enter the quantity of plastic waste in kg on day %d:",g+1);
    scanf("%f",&plastic[g]);
 }
  for (g=2;g<d;g=g+3){
    printf("enter the quantity of electronic waste in kg on day %d:",g+1);
    scanf("%f",&elec[g]);
  }
//calculation part

float tdeg,tplas,telec,total,finall;
int a,b,c;
tdeg=0;

for (g=0;g<d;g=g+3){
     a=0;
     a=degrad[g];
     a=a*5;
     tdeg=tdeg+a; }

tplas=0;

for(g=1;g<d;g=g+3){
     b=0;
     b=plastic[g];
     b=b*10;
     tplas=tplas+b;  }

telec=0;

for (g=2;g<d;g=g+3){
     c=0;
     c=elec[g];
     c=c*15;
    telec=telec+c; }

total=tdeg+tplas+telec;
finall+=total;

printf("Total expenditure on waste management for %d days is ₹%.2f",d,finall);

  return 0;
}
