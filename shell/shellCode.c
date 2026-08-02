#include <stdio.h>
#include <unistd.h>
#include <direct.h>
#include <string.h>
#include <windows.h>
#include <io.h>
#include <process.h>
#include <signal.h>

// A FULL ASS TERMINAL (still being built, ima add child process to open exe files and etc etc)

void pwd();
int cd();
void pid();
void mkdirs();
void rmdirs();
void deletes();
int ls();
void openFile();
void createFile();
int editFile();
int prcs();
//void handleSig();

void handleSig(int sig){
    printf("\n");

    fflush(stdout);
}

int main()
{
    char user[50];
    signal(SIGINT,handleSig);

    do
    {
        printf("$ ");

        if (fgets(user, sizeof(user), stdin) != NULL)
        {
            user[strcspn(user, "\n")] = '\0';

            if (strcmp(user, "pwd") == 0)
            {
                pwd();
            }
            else if (strcmp(user, "cd") == 0)
            {
                cd();
            }
            else if (strcmp(user, "pid") == 0)
            {
                pid();
            }
            else if (strcmp(user, "mkdir") == 0)
            {
                mkdirs();
            }
            else if (strcmp(user, "rmdir") == 0)
            {
                rmdirs();
            }
            else if (strcmp(user, "exit") == 0)
            {
                printf("Goodbye");
                break;
            }
            else if (strcmp(user, "delete") == 0)
            {
                deletes();
            }
            else if (strcmp(user, "ls") == 0)
            {
                ls();
            }
            else if (strcmp(user, "cat") == 0)
            {
                openFile();
            }
            else if (strcmp(user, "echo") == 0)
            {
                createFile();
            }
            else if (strcmp(user, "nano") == 0)
            {
                editFile();
            }
            else if (strcmp(user, "run") == 0)
            {
                prcs();
            }
            else if (strcmp(user, "clear") == 0)
            {
                system("cls");
            }
            else
            {
                printf("Enter Valid Shit\n");
            }
        }
    } while (1);
    return 0;
}

void pwd()
{
    char buffer[1024];

    if (_getcwd(buffer, sizeof(buffer)) != NULL)
    {
        printf("Current Directory : %s\n", buffer);
    }
    else
    {
        perror("Failed to fetch directory\n");
    }
}

int cd()
{
    char cd[260];

    printf("Specify the path : ");

    if (fgets(cd, sizeof(cd), stdin) != NULL)
    {

        cd[strcspn(cd, "\n")] = '\0';

        if (_chdir(cd) == 0)
        {
            printf("Changed to %s \n", cd);
        }

        else
        {
            printf("Error");
            return 1;
        }
    }

    else
    {
        return 1;
    }
}

void pid()
{
    DWORD id = GetCurrentProcessId();

    printf("Current Process ID - %lu \n", id);
}

void mkdirs()
{

    char mk[260];

    printf("Name of the file: ");

    if (fgets(mk, sizeof(mk), stdin) != NULL)
    {

        mk[strcspn(mk, "\n")] = '\0';

        if (_mkdir(mk) == 0)
        {
            printf("Sucessfully created new dir %s\n", mk);
        }
        else
        {
            printf("Failed");
        }
    }
}

void rmdirs()
{

    char rm[260];

    printf("Name of the file: ");

    if (fgets(rm, sizeof(rm), stdin) != NULL)
    {

        rm[strcspn(rm, "\n")] = '\0';

        if (_rmdir(rm) == 0)
        {
            printf("Sucessfully deleted dir %s\n", rm);
        }
        else
        {
            printf("Failed\n");
        }
    }
}

void deletes()
{
    char file[250];

    printf("Enter Name: ");

    if (fgets(file, sizeof(file), stdin) != NULL)
    {
        file[strcspn(file, "\n")] = '\0';

        if (remove(file) == 0)
        {
            printf("File removed sucesfully\n");
        }
        else
        {
            printf("Failed\n");
        }
    }
}

int ls()
{
    struct _finddata_t c_file;
    intptr_t hfile;

    hfile = _findfirst("*.*", &c_file);

    if (hfile == -1)
    {
        printf("Acess Denied\n");
        return 1;
    }

    printf("----- Contents -----\n");
    do
    {
        printf("%s\n", c_file.name);

    } while (_findnext(hfile, &c_file) == 0);
    _findclose(hfile);
    return 0;
}

void openFile()
{
    char file[250];
    char buffer[1024];

    printf("Enter Name: ");

    if (fgets(file, sizeof(file), stdin) != NULL)
    {
        file[strcspn(file, "\n")] = '\0';

        FILE *pFile = fopen(file, "r");

        if (pFile != NULL)
        {
            while (fgets(buffer, sizeof(buffer), pFile) != NULL)
            {
                printf("%s\n", buffer);
            }
            fclose(pFile);
        }
        else
        {
            printf("Error Opening File\n");
            // return 1;
        }
    }
}

void createFile()
{
    char file[250];
    char text[1024];

    printf("Enter Name: ");

    if (fgets(file, sizeof(file), stdin) != NULL)
    {
        file[strcspn(file, "\n")] = '\0';

        printf("Enter Contents -\n>> ");
        if (fgets(text, sizeof(text), stdin) != NULL)
        {
            text[strcspn(text, "\n")] = '\0';

            FILE *pFile = fopen(file, "w");
            if (pFile != NULL)
            {
                fprintf(pFile, "%s", text);
                printf("%s created sucesfully \n", file);
                fclose(pFile);
            }
            else
            {
                printf("Error Opening File\n");
            }
        }
    }
}

int editFile()
{
    char file[250];
    char text[1024];
    char buffer[1024];

    printf("Enter Name: ");

    if (fgets(file, sizeof(file), stdin) != NULL)
    {
        file[strcspn(file, "\n")] = '\0';

        FILE *pFile = fopen(file, "r");

        if (pFile != NULL)
        {
            while (fgets(buffer, sizeof(buffer), pFile) != NULL)
            {
                printf("%s\n", buffer);
            }
            fclose(pFile);
        }
        else
        {
            printf("Error Opening File\n");
            return 1;
        }

        printf("");

        if (fgets(text, sizeof(text), stdin) != NULL)
        {
            text[strcspn(text, "\n")] = '\0';

            FILE *apFile = fopen(file, "a");
            fprintf(apFile, "%s", text);

            printf("%s edited sucesfully \n", file);
            fclose(apFile);
            return 0;
        }
    }
}

int prcs()
{
    char file[250];

    printf("Enter Name: ");

    if (fgets(file, sizeof(file), stdin) != NULL)
    {
        file[strcspn(file, "\n")] = '\0';

        const char *args[] = {file, NULL};

        intptr_t result = _spawnvp(_P_WAIT, file, args);
        
        if (result == -1)
        {
            printf("Error\n");
            return 1;
        }
        else
        {
            //printf("Sucesfully Ran Program\n");
            return 0;
        }
    }
}
