//
//  main.cpp
//  task10
//
//  Created by Виталий on 21.12.2020.
//


#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;



int main() {
    setlocale(LC_ALL,"Russian");
    char file_from[20], file_to[20];
     cout << "Введите имя файла, из которого считается текст: ";
     gets(file_from);
     FILE *from = fopen(file_from, "r");
     cout << "Введите имя файла, в который запишется полученный текст: ";
     gets(file_to);
     FILE *to = fopen(file_to, "w");
    
     char c[200], s;
     int count = 0, cs = 0;
    while((s = fgetc(from)) == ' ') {
        continue;
    }
    c[count++] = s;
    
    while((s=fgetc(from)) != EOF) {
        if (s==' '){
            if (cs==0){
                c[count++]=s;
                cs=1;
            }
        }
        else if (s=='.'){
            if (cs==1){
            c[count-1]=s;
            cs=0;
            }
            else {
                c[count++]=s;
                cs=0;
            }
            //break; - если точкой строка должна оканчиваться всегда
        }
        else {
            c[count++]=s;
            cs=0;
        }
    }
    if(c[count-1]==' ') c[--count]='\0';
    else c[count]='\0';
    fprintf(to, "Строка после удаления пробелов: %s\n", c);
    
    
    count--;
    int id2=count, id1;
    char a[200]="";
    char dot=c[count];
    while (dot=='.') dot=c[--id2];
    id1=id2;
    while (dot!=' ') dot=c[--id1];
    char word[20];
    int wrd=0;
    for(int i=id1+1; i<=id2; i++) word[wrd++]=c[i];
    word[wrd]='\0';
    
    char *compare = strtok(c, " ");
    while (compare != NULL) {
        if (strcmp(word, compare) != 0)
        {
            strcat(a, compare);
            strcat(a, " ");
        }
        compare = strtok(NULL, "  .");
    }
    if(a[strlen(a)-1]==' ') a[strlen(a)-1]='\0';
    fprintf(to, "Строка без слов, совпадающих с последним: %s\n", a);



//Если длина слова максимальна.(‘abcad as’->’abcad’)
    float l=0;
    char *maxw = strtok(a, " ");
    char max[100]="";
    while (maxw!=NULL){
        cout<<endl<<maxw<<strlen(maxw);
        if (l<strlen(maxw)){
            for (int i=0; i<100; i++) max[i]='\0';
            cout<<"        "<<max;
            for (int i=0; i<strlen(maxw); i++) max[i]=maxw[i];
            l=strlen(maxw);
            cout<<l;
        }
        else if (strlen(maxw)==l){
            strcat(max, " ");
            strcat(max, maxw);
        }
        maxw = strtok(NULL, "  .");
    }
    
    //cout<<max;
    fprintf(to, "Слова с максимальной длиной в оставшейся строке: %s\n", max);
    
}
