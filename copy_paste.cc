#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <time.h>

char *searchword="" ;
char *prefix ="";



int IS_Contain (char fn[50]) {
    
    //printf("\n'%s' <--> '%s' == ",fn,searchword);
    
    int i=0,j=0,k=0;
    
    for (i=0;i<strlen(fn);i++) if (fn[i]==searchword[0]) {j=i;break;}
    
    for (i=j;i<j+strlen(searchword);i++) 
        if (fn[i]!=searchword[k]) {printf("");return 0;}
        else                      k++;
    
    printf("");
    return 1;
}


void findfile(char dossier[4096]) {
    
    char ssdossier[4096];
    struct dirent *lecture;
    DIR *rep;
        

    
    rep = opendir(dossier);

    while ((lecture = readdir(rep))) {
        
        if (!strcmp(lecture->d_name, ".") || !strcmp(lecture->d_name, "..")) continue;
        
        sprintf(ssdossier, "%s%s\\", dossier, lecture->d_name);
        if (opendir(ssdossier) != NULL) {findfile(ssdossier);}
        
        
    int i=0,j=0,k=0;
    char file_name[50] = "";
    char source [4096] = "";
    char distination [4096] = "";
    char directory[4096]="";
    char sub_directory[4096]="";
    FILE *out_file;
    int file_size;
        
    
    for (i=strlen(ssdossier)-2;i>=0;i--) if (ssdossier[i]=='\\') {j=i+1;break;}
    
    for (i=j;i<strlen(ssdossier)-1;i++)
        {
        sprintf(file_name,"%s%c",file_name,ssdossier[i]);//file_name[k]=path[i];k++;
        }
    
    for (i=0;i<strlen(ssdossier)-1;i++)  { sprintf(source,"%s%c",source,ssdossier[i]);}
    
    
    for (i=strlen(source)-1;i>=0;i--) if (source[i]=='\\') {j=i;break;}
    sprintf(directory,"%s",prefix);
    for (i=3;i<=j;i++)
        {
        sprintf(directory,"%s%c",directory,source[i]);
        }    
    
    if (strcmp(searchword,"all")==0) sprintf(distination,"%s%s",directory,file_name);
    else                          {sprintf(distination,"%s%s",prefix,file_name);}
    
        
    out_file = fopen(source,"r+");
    fseek(out_file, 0, SEEK_END);
    file_size = ftell(out_file);
    fclose(out_file);
    //printf("\nname :%s , size = %d octets or %.3f Ko or %.3f Mo or %.3f Go\n",file_name, file_size, (float)file_size/1024, (float)file_size/1048576,(float)file_size/1073741824);                
    
        if (!strcmp(searchword,"all")==0) {if (IS_Contain(file_name))CopyFileA(source,distination,0); }
        else {
                for (i=0;i<strlen(directory);i++)
                if (directory[i]!='\\')         sprintf(sub_directory,"%s%c",sub_directory,directory[i]);
                else                            {sprintf(sub_directory,"%s%c",sub_directory,'\\');CreateDirectory(sub_directory,0);}

                CopyFileA(source,distination,0);
        }
    
    //Sleep(2000);
    
    }
    
    closedir(rep);
}

void detectUSB () {
    detect:
    char d[1024] = "";
    char *adr;
    int i=0;
    GetLogicalDriveStrings(1024, d);
    adr = d;
    
    while (*adr) {
        if (GetDriveType(adr) == DRIVE_REMOVABLE/*2*/)
        {
            i++;
            printf("DRIVE AMOVIBLE %d :%s\n", i, adr);
            findfile(adr);
        }
        adr += 4;
    }

    //goto detect;
    //if (i==0) printf("no drive amovible is exist!");    
}



int main ( int agrc, char *argv[] ) {
    
    if (agrc !=3) 
    {
        printf("must be entred 2 argument! for example :\n./program searchword partition(c,d,etc.)");
    }
    else 
    {
    
    searchword = argv[1];
    prefix = argv[2];
    
    if (strlen(prefix)!=1) {printf ("argument 2 must be 1 char, it represent each partition , for example c,d ...\n");exit(1);}
    
    sprintf(prefix,"%s%s%s%c",prefix,":\\",searchword,'\\');
    
    
    if (!strcmp(searchword,"all")==0) CreateDirectory(prefix,0);

        
    detectUSB();
    //findfile("D:\\k' root\\");
    
    //double timed = clock();
    //printf("%f",timed);
    //Sleep(1000);
    
    //double timef = clock()-timed;
    //printf("%f",timef);
    
    
    printf("\n###################  End  ###########################\n");
    }
    
    return 0;
}
