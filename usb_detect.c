#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    char d[1024] = "";
    char *adr;
    char USB [2]="";
    int i=0;
    GetLogicalDriveStrings(1024, d);
    adr = d;


    while (*adr) {

        if (GetDriveType(adr) == DRIVE_UNKNOWN/*0*/)            printf("DRIVE_UNKNOWN :%s\n",adr);
        if (GetDriveType(adr) == DRIVE_NO_ROOT_DIR/*1*/)        printf("DRIVE_NO_ROOT_DIR :%s\n",adr);
        if (GetDriveType(adr) == DRIVE_REMOVABLE/*2*/)          printf("DRIVE_REMOVABL :%s\n",adr);
        if (GetDriveType(adr) == DRIVE_FIXED/*3*/)              printf("DRIVE_FIXED :%s\n",adr);
        if (GetDriveType(adr) == DRIVE_REMOTE/*4*/)             printf("DRIVE_REMOTE :%s\n",adr);
        if (GetDriveType(adr) == DRIVE_CDROM/*5*/)              printf("DRIVE_CDROM:%s\n",adr);
        if (GetDriveType(adr) == DRIVE_RAMDISK/*6*/)            printf("DRIVE_RAMDISK :%s\n",adr);        
        adr += 4;
    }
    
    
    //ShellExecuteA();
    //CopyFileA("E:\\P2P.doc","G:\\P2P.doc",0);
    
    //if (i==0) printf("no drive removable is exist!");
    
    return 0;
}
