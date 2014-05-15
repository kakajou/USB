#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

void findfile(char dossier[4096]) {
    
    char ssdossier[4096];
    struct dirent *lecture;
    DIR *rep;
    
    rep = opendir(dossier);

    while ((lecture = readdir(rep))) {
        
        if (!strcmp(lecture->d_name, ".") || !strcmp(lecture->d_name, "..")) continue;
        
        sprintf(ssdossier, "%s\\%s", dossier, lecture->d_name);
        if (opendir(ssdossier) != NULL) {findfile(ssdossier);}
        
        printf("%s \n", ssdossier);
    }
    
    closedir(rep);
}

int main(int argc, char *argv[]) {
    findfile("G:");

    return 0;
}










/*
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


void AfficherListeFichiers(char Dossier[MAX_PATH]) {
    HANDLE hFind;
    WIN32_FIND_DATA FindData;

    // Change de dossier
    SetCurrentDirectory(Dossier);

    // Début de la recherche
    hFind = FindFirstFile("*.*", &FindData);
    if (hFind != INVALID_HANDLE_VALUE) {
        // Si le fichier trouvé n'est pas un dossier mais bien un fichier, on affiche son nom
        if (!(FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
            MessageBox(NULL, FindData.cFileName, "Fichier", MB_ICONINFORMATION);
        }
        // Fichiers suivants
        while (FindNextFile(hFind, &FindData)) {
            if (!(FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
                MessageBox(NULL, FindData.cFileName, "Fichier", MB_ICONINFORMATION);
            }
        }
    }
    // Fin de la recherche
    FindClose(hFind);
}



/*void AfficherListeFichiers (CString Dossier)
{
CFileFind Find;

// Change de répertoire
SetCurrentDirectory (Dossier);

// Début de la recherche
if (Find.FindFile ("*.*"))
{
// Si le fichier trouvé n'est pas un dossier mais bien un fichier, on affiche son nom
while (Find.FindNextFile ())
{
if (!Find.IsDirectory ())
{
AfxMessageBox (Find.GetFileName ());
}
}
}
// Fin de la recherche
Find.Close ();
} *

int main() {

    AfficherListeFichiers("G:\\");
    return 0;
}

*/