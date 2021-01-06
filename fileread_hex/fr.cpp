#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<windows.h>
#define PATH_LEN 255
#define LEN 16
#define DIV 2
using namespace std;
int main(int argc, char *argv[])
{
    FILE *fp;
    char *sad;
    int nu=0,Desktop=0,an=0,ao=0,ah=0;
    char username[PATH_LEN];
    DWORD len = PATH_LEN;
    GetUserName(username,&len);
    string desk_path = "C:\\Users\\",finpath;
    desk_path+=username;
    desk_path+="\\Desktop\\";
    string output_filename;
    sad = (char*)malloc(sizeof(char));
    int argnum = argc;
    if(argnum == 1 || !strcmp(argv[1],"-n")|| !strcmp(argv[1],"-o"))
        {printf("\n-n Line number -o specifies the file name ~ desktop\n");return 0;}
    else
        sad = argv[1];
    while(argnum -- )
    {
        if(!strcmp(argv[argnum],"-n"))
            nu=1,an=1;
        else if(!strcmp(argv[argnum],"-o"))
            output_filename = argv[argnum+1],ao=1;
        else if(!strcmp(argv[argnum],"~"))
            Desktop=1,ah=1;
    }
    string sa=sad,fn="fr";//cmd="notepad ";
    while(sa[sa.length()-1] != '.')
    {
        sa=sa.substr(0,sa.length()-1);
        if(sa.length() == 0)
            {sa=sad;break;}
    }
    fn += sa;
    fp = fopen(sad,"rb");
    int c,i=16,l=0,div=2;
    if(fp)
    {
        if(output_filename != "")
            finpath = output_filename;
        else
            finpath = fn;
        freopen(finpath.c_str(),"w",stdout);
        if(Desktop)
        {
            desk_path+=finpath;
            freopen(desk_path.c_str(),"w",stdout);
        }
        if(nu)
            printf("0x00000000: ");
        while((c = fgetc(fp))!=EOF)
        {
            printf("%02X",c);
            --div == 0?putchar(' '),div=DIV:1;
            if(nu)
                --i == 0?putchar('\n'),printf("0x%08X: ",++l),i=LEN:1;
            else
                --i == 0?putchar('\n'),i=LEN:1;
        }
        free(sad);fclose(fp);
        freopen("CON","w",stdout);
        printf("\nDone!\n");
        return 0;
    }
    else
    {freopen("CON","w",stdout);printf("\nSad Day\n");}
    return 0;
}
       /* cmd += fn.c_str();
        system(cmd.c_str());*/
