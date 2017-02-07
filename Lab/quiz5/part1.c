#include <stdio.h>
int calc_hist(int sentinel,int *hist0,int *hist1,int *hist2,int *hist3,
                int *hist4,int *hist5,int *hist6,int *hist7,int *hist8,
                int *hist9);
 
int main()
{
    int *hist0,*hist1,*hist2, *hist3, *hist4,*hist5,*hist6, *hist7, *hist8,
    *hist9;
    int sonuc;
   
    sonuc=calc_hist(-1,hist0,hist1,hist2, hist3, hist4,hist5,hist6,hist7,hist8
                ,hist9);
    printf("sonuc=%d",sonuc);
    return 0;
}
int calc_hist(int sentinel,int *hist0,int *hist1,int *hist2,int *hist3,
                int *hist4,int *hist5,int *hist6,int *hist7,int *hist8,
                int *hist9)
{
    int s0,s1,s2,s3,s4,s5,s6,s7,s8,s9;
    int digit,totaldigit;
    if(sentinel >=0 && sentinel <=9)
    {
        return -2;
    } 
   
    *hist0=0;
    *hist1=0;
    *hist2=0;
    *hist3=0;
    *hist4=0;
    *hist5=0;
    *hist6=0;
    *hist7=0;
    *hist8=0;
    *hist9=0;       
    
    while(digit!=sentinel)
    {
        printf("Enter a digit");
        scanf("%d",&digit);
            if(digit<10 && digit >=0 && digit!=sentinel)
            {
                switch(digit)
                {
                        case 0:
                            *hist0 +=1;
                            break;
                        case 1:
                            *hist1 +=1;
                            break;
                        case 2:
                            *hist2 +=1;
                            break;
                        case 3:
                            *hist3 +=1;
                            break;
                        case 4:
                            *hist4 +=1;
                            break;
                        case 5:
                            *hist5 +=1;
                            break;
                        case 6:
                            *hist6 +=1;
                            break;
                        case 7:
                            *hist7 +=1;
                            break;
                        case 8:
                            *hist8 +=1;
                            break;
                        case 9:
                            *hist9 +=1;
                            break;
                 }
            }
     }
     totaldigit=*hist0+*hist1+*hist2+*hist3+*hist4+*hist5+*hist6+*hist7+*hist8+
                *hist9;
     if(totaldigit==0)
             return -1;    
      return totaldigit;     
    
}
       

