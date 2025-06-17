# include<stdio.h>
# include<myself.h>
# include<stdlib.h>

int main(){
    const int size = 3;
    int cout1,cout2,flag=0,over=0;
    int i,j;
    int board[3][3] = {{1,1,1},
                       {1,0,1},
                       {0,1,0}};

    while(flag < 6 && over == 0){
    for(i=0; i<size && over == 0; i++){
        cout1 = 0;
        cout2 = 0;
        for(j=0; j<size;j++){
            if(flag >= 3){
               if(board[j][i] == 0)
                cout1 ++;
                else
                cout2 ++;
            }
            //? 检查完行后，检查列
            else{
            if(board[i][j] == 0)
            cout1 ++;
            else
            cout2 ++;}
            printf("here1\n");
        }
        if(cout1 == size){
        printf("it's O win\n");over = 1;}
        else if(cout2 == size){
        printf("it's X(1) win\n");over = 1;}//? 因为只有 0 或 1，
        printf("here2\n");
        flag++;
        }
    }



system("pause");
return 0;

        }



