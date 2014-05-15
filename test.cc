#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char file_name[50] = "";
char source [1024] = "";
char distination [1024] = "";
char prefix[50] = "D:\\";
char searchword [50]=".pdf";


int IS_Important (char fn[50]) {
    
    int i=0,j=0,k=0;
    
    for (i=0;i<strlen(fn);i++) if (fn[i]==searchword[0]) {j=i;break;}
    
    for (i=j;i<j+strlen(searchword);i++) 
        if (fn[i]!=searchword[k]) return 0;
        else                      k++;
    
    return 1;
}

 void Get_File_Name_Source_Distination (char p[1024] ) {
    
    char *path =p;
    int i=0,j=0,k=0;
    
    
    for (i=strlen(path)-2;i>=0;i--) if (path[i]=='\\') {j=i+1;break;}
    
    for (i=j;i<strlen(path)-1;i++)
        {
        sprintf(file_name,"%s%c",file_name,path[i]);//file_name[k]=path[i];k++;
        }
    
    for (i=0;i<strlen(path)-1;i++)  { sprintf(source,"%s%c",source,path[i]);}
    
    sprintf(distination,"%s%s",prefix,file_name);
    
    printf("\nfile_name:'%s'",file_name);    
    printf("\nsource:'%s'",source);    
    printf("\ndistination:'%s'",distination);    
    
    
}
 
 
 

int main() {
    
    if (IS_Important("dddddddddddssss.pdfsss")) printf("exist!\n");
    else                                    printf("not exist!\n");
    
    //Get_File_Name_Source_Distination("C:\\Users\\IORI-YAGAMI\\Downloads\\Nightly Start Page.xhtml\\");
    
    return 0;
}