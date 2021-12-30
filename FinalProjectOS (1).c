
#include <stdio.h>


 int FIFO(){
int i,j,n,ref_str[50],frame[10],no,k,avail,fcount=0;  // Declaration of variable required
printf("\n Enter number of pages:\n");
scanf("%d",&n);                                        // total no. of pages in reference string
printf("\n Enter page numbers:\n");
    for(i=1;i<=n;i++)                                   // accept entire reference string
        scanf("%d",&ref_str[i]);
printf("\n Enter number of frames :");
scanf("%d",&no);
    for(i=0;i<no;i++)
                frame[i]= -1;  // initialize all page frame to -1
j=0;                           // initialize page frame pointer
printf("\n ref string  \t page frames     \tHit/Fault\n");
    for(i=1;i<=n;i++)
                {
                    printf("%d\t\t",ref_str[i]);
                    avail=0;          // Default value of available flag is 0
                    for(k=0;k<no;k++)
                    if(frame[k]==ref_str[i]) // input of  page  requested is compared with existing content of FRAME
                    {
                            avail=1;        // as page found available is turned 1
                            for(k=0;k<no;k++)
                                    printf("%d\t",frame[k]);   // Print Current state of FRAME
                            printf("H");                        // Indication of Page Hit
                    }
                    if (avail==0)  // input   page  requested NOT existing in  FRAME
                            {
                                        frame[j]=ref_str[i];         // place page requested at j th location in FRAME
                                        j=(j+1)%no;            // Update J for next Cycle
                                        fcount++;                // Increment Counter for Page Fault
                                        for(k=0;k<no;k++)
                                        printf("%d\t",frame[k]);  // Print Current state of FRAME
                                        printf("F");            // Indication of Page Fault
                            }
                            printf("\n");
                }
printf("Total Page Faults = %d",fcount);
return 0;
}
//***************************************************************************************************************

   int LRU()
   {
   

int findLRU(int time[], int n){
int i, minimum = time[0], pos = 0;
 
for(i = 1; i < n; ++i){
if(time[i] < minimum){
minimum = time[i];
pos = i;
}
}
return pos;
}
 

    int no_of_frames, no_of_pages, frames[10], pages[30], counter = 0, time[10], flag1, flag2, i, j, pos, faults = 0;

printf("Enter number of pages: ");
scanf("%d", &no_of_pages);
printf("Enter page numbers: ");
    for(i = 0; i < no_of_pages; ++i){
     scanf("%d", &pages[i]);
    }
printf("Enter number of frames: ");
scanf("%d", &no_of_frames);

    
for(i = 0; i < no_of_frames; ++i){
     frames[i] = -1;
    }
    
    for(i = 0; i < no_of_pages; ++i){
     flag1 = flag2 = 0;
    
     for(j = 0; j < no_of_frames; ++j){
     if(frames[j] == pages[i]){
     counter++;
     time[j] = counter;
   flag1 = flag2 = 1;
   break;
   }
     }
    
     if(flag1 == 0){
for(j = 0; j < no_of_frames; ++j){
     if(frames[j] == -1){
     counter++;
     faults++;
     frames[j] = pages[i];
     time[j] = counter;
     flag2 = 1;
     break;
     }
     }
     }
    
     if(flag2 == 0){
     pos = findLRU(time, no_of_frames);
     counter++;
     faults++;
     frames[pos] = pages[i];
     time[pos] = counter;
     }
    
     printf("\n");
    
     for(j = 0; j < no_of_frames; ++j){
     printf("%d\t", frames[j]);
     }
}
printf("\n\nTotal Page Faults = %d", faults);
    
    return 0;
}
//*******************************************************************************************************

int OPTIMAL()
{
    
    int no_of_frames, no_of_pages, frames[10], pages[30], temp[10], flag1, flag2, flag3, i, j, k, pos, max, faults = 0;
    
printf("Enter number of pages: ");
scanf("%d", &no_of_pages);
printf("Enter page numbers: ");
    for(i = 0; i < no_of_pages; ++i){
     scanf("%d", &pages[i]);
    }
printf("Enter number of frames: ");
scanf("%d", &no_of_frames);

    
    for(i = 0; i < no_of_frames; ++i){
        frames[i] = -1;
    }
    
    for(i = 0; i < no_of_pages; ++i){
        flag1 = flag2 = 0;
        
        for(j = 0; j < no_of_frames; ++j){
            if(frames[j] == pages[i]){
                   flag1 = flag2 = 1;
                   break;
               }
        }
        
        if(flag1 == 0){
            for(j = 0; j < no_of_frames; ++j){
                if(frames[j] == -1){
                    faults++;
                    frames[j] = pages[i];
                    flag2 = 1;
                    break;
                }
            }    
        }
        
        if(flag2 == 0){
         flag3 =0;
        
            for(j = 0; j < no_of_frames; ++j){
             temp[j] = -1;
            
             for(k = i + 1; k < no_of_pages; ++k){
             if(frames[j] == pages[k]){
             temp[j] = k;
             break;
             }
             }
            }
            
            for(j = 0; j < no_of_frames; ++j){
             if(temp[j] == -1){
             pos = j;
             flag3 = 1;
             break;
             }
            }
            
            if(flag3 ==0){
             max = temp[0];
             pos = 0;
            
             for(j = 1; j < no_of_frames; ++j){
             if(temp[j] > max){
             max = temp[j];
             pos = j;
             }
             }            
            }
frames[pos] = pages[i];
faults++;
        }
        
        printf("\n");
        
        for(j = 0; j < no_of_frames; ++j){
            printf("%d\t", frames[j]);
        }
    }
    
    printf("\n\nTotal Page Faults = %d", faults);
    
    return 0;


}
//*******************************************************************************************************
int main()
{
    int choice;
    printf("Enter your Choice");
    printf("\n1: FIFO\n");
    printf("2: LRU\n");
    printf("3: OPTIMAL\n");
    scanf("%d",&choice);
    
    
    switch(choice)
    {
        case 1:
            printf("You have chosen FIFO \n \n");
            FIFO();
            break;

        case 2:
        printf("You have chosen LRU \n \n");
        LRU();
        break;
        
       
        case 3:
        printf("You have chosen OPTIMAL \n \n");
        OPTIMAL();
        break;
        
        default:
            printf("Error! operator is not correct");
    }

    return 0;
}
   
   
    
    
 


    
    
    
    
    
    
   

