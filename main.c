/* # Waste Management

@author deepak sai pendyala

Instructions: 

 

Step 1: Enter 1 for the functionalities of Municipal Authority: 

             Enter 2 for the functionality of consumer: 

Step 2: Enter No of Areas 

Step 3: Enter No of Houses 

Step 4: Enter No of days 

Step 5: If Option ‘1’ is chosen in Step 1: 

           Enter one of the functionalities below: 

1). Calculate Average waste  

2). Reward the House which gave lowest waste   

3). Compute the Earnings of municipality  

4). Check what percentage of the waste is from what category  

 Else if Option ‘2’ is chosen, the Program will Automatically proceed to functionality of “As an individual family, analyzing the expense for managing the waste” 
 

Step 6: Enter Data of quantities for individual days and Houses of different houses. 

Step 7: The program will display the output as per functionalities selected 

Step 8: The Program will create the file named “output.txt” automatically & the output will be saved to it. 


*/
#include <stdio.h>
#include <string.h>

FILE *filePointer ;
//Function Prototyping

float avg(float degrad[],float plastic[],float elec[],int area,int h,int d,int f,float finall,int a,int b,int c);
int reward(float degrad[],float plastic[],float elec[],int area,int h,int d,int a,int b,int c);
float earn(float degrad[],float plastic[],float elec[],int area,int h,int d,int f,int a,int b,int c);
int percentage(float degrad[],float plastic[],float elec[],int area,int h,int d,int f,float *td,float *tp,float *te,float *ptotal,int a,int b,int c);
int customer();

int main() {
  filePointer = fopen("output.txt", "a+") ;
 int option,choice,h,d,area,x,j,k,i,g;
 int a,b,c;
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
float td=0,tp=0,te=0,ptotal=0;
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
      printf("Enter quantity in house %d :",j+1);
      scanf("%f",&elec[i]);
      j=j+1;        }
     k=i;
     h=h+x;              }

switch(choice){
  case 1:
      finall=avg(degrad,plastic,elec,area,x,d,f,finall,a,b,c);
      break;
  case 2:
      reward(degrad,plastic,elec,area,x,d,a,b,c);
      break;
  case 3:
      earn(degrad,plastic,elec,area,x,d,f,a,b,c);
      break;
  case 4:
      percentage(degrad,plastic,elec,area,x,d,f,&td,&tp,&te,&ptotal,a,b,c);
      break;
  default:
      printf("wrong input, sorry! run again");

}

printf("\n\n\n");    }
}
else if (option==1){
   printf("Now, You're entering as a customer\n");
   customer();     }
else printf("wrong input, sorry! run again");

fprintf(filePointer, "%s"," END OF PROGRAM \n");
fclose(filePointer);
return 0;
}

/*charges : 1kg degredable waste - 5rs
1kg plastic waste - 10rs
1kg electronic waste - 15rs */



float avg(float degrad[],float plastic[],float elec[],int area,int h,int d,int f,float finall,int a,int b,int c){
filePointer = fopen("output.txt", "a+") ;


float tdeg=0,tplas=0,telec=0,total,avg=0;
int i;
for (i=0;i<a;i++){
    tdeg+=degrad[i];}
for (i=0;i<b;i++){
     tplas+=plastic[i]; }
for(i=0;i<c;i++){
    telec+=elec[i]; } 

total=tdeg+tplas+telec;
avg=total/3;
finall+=avg;

if(area==f+1){
printf("So Finally, Average waste in all Categories of waste in Municipality for %d days in %d Area/Areas is %.2f kgs",d,f+1,finall);
fprintf(filePointer, "%s","Average waste function:\n");
fprintf(filePointer, "%s %d %s %d %s %f %s", "So Finally, Average waste in all Categories of waste in Municipality for ", d," days in ", f+1," Area/Areas is ",finall," kgs\n");
return 0;
}
return finall;
}





int reward(float degrad[],float plastic[],float elec[],int area,int h,int d,int a,int b,int c){
  filePointer = fopen("output.txt", "a+") ;
  fprintf(filePointer, "%s","Rewards function:\n");
int i,j,k=0;
float dh[a],ph[b],eh[c];
float dhd[a],phd[b],ehd[c];
for(i=0;i<h;i++){
  dh[i]=0;
  for(j=k;j<a;j+=h){
      dh[i]+=degrad[j];
  }k+=1;
}
for(int i=0;i<h;i++){
  printf("House %d gives %.2f kgs degradable waste \n",i+1,dh[i]);
  fprintf(filePointer,"%s %d %s %f %s","House ",i+1," gives ",dh[i],"kgs degradable waste \n");
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
       printf("The house which gives low quantity of degradable waste is rewarded with badminton kit i.e house %d with %.2f kgs bio degradable waste\n",i+1,min);
         fprintf(filePointer,"%s %d %s %f %s","The house which gives low quantity of degradable waste is rewarded with badminton kit i.e house ",i+1," with ",min," kgs bio degradable waste \n");
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
  fprintf(filePointer,"%s %d %s %f %s","House ",i+1," gives ",ph[i],"kgs plastic waste  \n");
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
       fprintf(filePointer,"%s %d %s %f %s","The house which gives low quantity of plastic waste is rewarded with cricket kit i.e ",i+1," with ",min," kgs bio degradable waste \n");
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
    fprintf(filePointer,"%s %d %s %f %s","House ",i+1," gives ",eh[i],"kgs electronic waste \n");
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
              fprintf(filePointer,"%s %d %s %f %s","The house which gives low quantity of electronic waste is rewarded with footbal kit i.e house ",i+1," with ",min," kgs electronic waste \n");
      }
    }
return 0;
}


float earn(float degrad[],float plastic[],float elec[],int area,int h,int d,int f,int a,int b,int c){

  filePointer = fopen("output.txt", "a+") ;

static float finall;
float tdeg=0,tplas=0,telec=0,total;
int i;

for (i=0;i<a;i++){
    tdeg+=degrad[i]*5;}
for (i=0;i<b;i++){
     tplas+=plastic[i]*10; }
for(i=0;i<c;i++){
    telec+=elec[i]*15; }    
total=tdeg+tplas+telec;
finall+=total;
if(area==f+1){
printf("So Finally, Total Earnings of the Municipality for %d days in %d Area/Areas is ₹%.2f ",d,f+1,finall);
fprintf(filePointer, "%s","Earings function:\n");
fprintf(filePointer, "%s %d %s %d %s %f\n", "So Finally, Total Earnings of the Municipality for ", d," days in ", f+1," Area/Areas is ₹",finall);
}
return 0;
}


int percentage(float degrad[],float plastic[],float elec[],int area,int h,int d,int f,float *td,float *tp,float *te,float *ptotal,int a,int b,int c){

filePointer = fopen("output.txt", "a+") ;

float tdeg=0,tplas=0,telec=0,total;
int i;
for (i=0;i<a;i++){
    tdeg+=degrad[i];}
for (i=0;i<b;i++){
     tplas+=plastic[i]; }
for(i=0;i<c;i++){
    telec+=elec[i]; } 

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

fprintf(filePointer, "%s %d %s","percentage function in area",f+1," :\n");
fprintf(filePointer, "%s %f %s", "total wastage is ",*ptotal ,"KGS\n");
fprintf(filePointer, "%f %s",*td ," %% is from degradable waste category\n");
fprintf(filePointer, "%f %s",*tp ," %% is from plastic waste category\n");
fprintf(filePointer, "%f %s",*te ," %% is from electronic waste category\n");
                          }
return 0;
}

int customer(){
  filePointer = fopen("output.txt", "a+") ;
  fprintf(filePointer, "%s","customer function:");
int d,g;
printf("Please enter the no of days to be calculated:");
scanf("%d", &d);
float arr[d];
float tdeg=0,tplas=0,telec=0,total;
for (g=0;g<d;g=g+3){
   printf("enter the quantity of degradable waste in kg on day %d:",g+1);
   scanf("%f",&arr[g]);
   tdeg+=(arr[g]*5);
}

for(g=1;g<d;g=g+3){
    printf("enter the quantity of plastic waste in kg on day %d:",g+1);
    scanf("%f",&arr[g]);
    tplas=(arr[g]*10);
 }
  for (g=2;g<d;g=g+3){
    printf("enter the quantity of electronic waste in kg on day %d:",g+1);
    scanf("%f",&arr[g]);
    telec+=(arr[g]*15);
  }

total=tdeg+tplas+telec;
printf("Total expenditure on waste management for %d days is ₹%.2f",d,total);
fprintf(filePointer, "Total expenditure on waste management for %d days is ₹ %f\n",d,total);
  return 0;
}