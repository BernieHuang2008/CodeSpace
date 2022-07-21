#include<stdio.h>
#include"../cs50.h"
#include"../cs50.c"
#include<string.h>
int main(){
    float L,S;
    string text;
    text=get_string(NULL, "Text: ");
    int word=0,sp=1,dot=0;
    int i=0;
    for(i=0;i<strlen(text);i++){
        if(('a'<=text[i]&&text[i]<='z')||('A'<=text[i]&&text[i]<='Z'))
            word++;
        else if(text[i]==' ')
            sp++;
        else if(text[i]=='.'||text[i]=='!'||text[i]=='?')
            dot++;
    }
    L=word*1.0/sp*100.0;
    S=dot*1.0/sp*100.0;
    int index=0.0588 * L - 0.296 * S - 15.8+0.5;
    printf("Grade %i\n", index);

}