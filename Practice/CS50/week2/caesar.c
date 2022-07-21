#include"../cs50.c"
#include<stdio.h>
int main(int argc, string argv[])
{
    if(argc!=2)
    {
        printf("Usage: ./caesar key, 1");
        return 1;
    }
    if(argv[1][0]>'9'||argv[1][0]<'0')
    {
        printf("Usage: ./caesar key");
        return 2;
    }
    string pt = get_string(NULL, "plaintext:  ");
    int k=strtol(argv[1],NULL,NULL);
    // printf("%i", k);
    int i;
    for(i=0;i<strlen(pt);i++){
        if(pt[i]>='A'&&pt[i]<='Z')
            pt[i]=(pt[i]-'A'+k)%26+'A';
        else if(pt[i]>='a'&&pt[i]<='z')
            pt[i]=(pt[i]-'a'+k)%26+'a';
    }
    printf("ciphertext: %s\n", pt);
}