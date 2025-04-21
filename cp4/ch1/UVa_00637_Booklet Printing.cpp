/*
    author: arv
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int pages, top, bottom, blanks, sheets;
    while(scanf("%d", &pages) == 1, pages != 0){
        sheets = ceil(pages / 4.0);
        blanks = 4 - (pages % 4);
        if(blanks == 4) blanks = 0; //if blanks = 4; no blank pages
        top = 1; 
        bottom = sheets * 4; // if pages = 14 make it 16; for 16 and 15 page print blank

        printf("Printing order for %d pages:\n", pages);

        for(int sheet = 1; sheet <= sheets; sheet++){
            // front
            if(blanks){
                printf("Sheet %d, front: Blank, %d\n", sheet, top);
                pages--;
                blanks--;
            } else {
                printf("Sheet %d, front: %d, %d\n", sheet, bottom, top);
                pages-=2;
            }

            bottom--;
            top++;

            // back
            if(pages){// if pages then only print; if t = 1; b = 4; then blank = 3; but should not print 2 blanks
                // if not pages, don't print back
                if(blanks){
                    printf("Sheet %d, back : %d, Blank\n", sheet, top);
                    blanks--;
                } else {
                    printf("Sheet %d, back : %d, %d\n", sheet, top, bottom);
                }
            }

            bottom--;
            top++;            
        }
    }

    return 0;
}