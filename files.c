// program using fputc to put data in file
/*
#include <stdio.h>
void main(){
    int ch;
    FILE * fp;
    fp = fopen("sample.txt", "w");
    scanf("%c",&ch);
    while(ch != '#') {
        fputc(ch,fp);
        ch = getchar();
    }
    fclose(fp);
}
*/
// program using fgetc to fetch data from file
/*
#include <stdio.h>
int main() {
    int ch;
    FILE * fp;
    fp = fopen("sample.txt","r");
    while((ch = fgetc(fp)) != EOF) {  // Important note - without the parentheses around the ch = fget(fp) part, we will only get garbage values no matter what
        printf("%c",ch);// Reason - In C, the assignment operator (=) has a lower precedence than the inequality operator (!=). 
        }               // As a result, the expression ch = fgetc(fp) != EOF is evaluated as (ch = fgetc(fp)) != EOF.
    fclose(fp);         // This assigns the result of fgetc(fp) to ch and then compares it with EOF.
    return 0;
}                     
*/

// program using fputs and fgets to insert data in a file and reading it.
/*
#include <stdio.h>
void main() {
    char s[50], s1[50];
    FILE * fp;
    gets(s);
    fp = fopen("sample.txt","w");
    fputs(s,fp);
    fclose(fp);
    fp = fopen("sample.txt","r");
    fgets(s1,50,fp);
    fclose(fp);
    puts(s1);
}
*/

// program to count number of lines, words, characters in a file.
/*
#include <stdio.h>
void main() {
    char s[50];
    int col=0, coc=0, cow=0;
    FILE * fp;
    fp = fopen("sample.txt","w");
    fgets(s, sizeof(s), stdin);  // Read a line of input including whitespaces    scanf("%s",s);
    fputs(s,fp);
    for(int i = 0; s[i] != '\0' ;i++) {
        if(s[i] == '\n')
        col++;
        else if(s[i] == '\t')
        cow++;
        else
        coc++;
    }
    printf("%d\t%d\t%d",col,cow,coc);
    fclose(fp);
}
*/

//fprintf
/*
#include <stdio.h>
void main() {
    char s[50];
    FILE * fp;
    gets(s);
    fp = fopen("sample.txt","w");
    fprintf(fp,"%s",s);
    fclose(fp);
}
*/

//fscanf
/*
#include <stdio.h>
void main() {
    char s[50];
    FILE * fp;
    fp = fopen("sample.txt","r");
    while(fscanf(fp,"%s",s) != EOF) { // fscanf only reads until it encounters firs whitespace hence only one word is printed. To read multiple words, we use loop.
        printf("%s\t",s);             // But again, as fscanf doen't read whitespaces, we have to provide /t to give spaces after each word. 
    }
    fclose(fp);
}
*/

// fread and fwrite for array
/*
#include <stdio.h>
void main() {
    FILE * fp;
    int a[5],b[5];
    for(int i =0;i<5;i++)
    scanf("%d",&a[i]);
    fp = fopen("sample.txt","wb");
    fwrite(a,sizeof(int),5,fp);
    fclose(fp);
    fp = fopen("sample.txt","rb");
    fread(b,sizeof(int),5,fp);
    for(int i=0;i<5;i++)
    printf("%d\t",b[i]);
    fclose(fp);
}
*/

//fread and fwrite for structures
//fread and fwrite for array of structures
//fseek, rewind,ftell

//command line arguements
/*
#include <stdio.h>
void main(int argc, char * argv[]) {
    int i =0 ;
    for(i=0;i<argc;i++)
    printf("%s\t",argv[i]);
}
*/

//command line arguements using atoi, atof function
#include <stdio.h>
#include <stdlib.h>   // atoi and atof are in the stdlib.h headerfile
int main(int argc, char * argv[]) {
    int i, c;
    float f;
    c = atoi(argv[1]) + atoi(argv[2]);
    f = atof(argv[1]) + atof(argv[2]);
    printf("Sum as integer: %d\n", c);
    printf("Sum as float: %f\n", f);
    return 0;
}