#include <iostream>
#include <string>
using namespace std;

void inti(char [3][3]); //intical board 
void display(char [3][3]);
void pick(); //picking row and col 
void assx(int r, int c, char [3][3]); //assigning given values to player x
void asso(int r, int c, char [3][3]); //assigning given values to player o
void check(int r, int c, char [3][3]); // checking if spot has a value
char win(char [3][3]); //checking for wins 
char end(char [3][3]); //no wins towards the end 
int main()
{
    cout<<"Welcome to Tic-Tac-Toe"<<endl;
    cout<<"======================"<<endl;
    char grid[3][3];  //board 
    inti(grid);
    int ansr, ansc;  //user input for row&col
    int a=0; //counter for while loop

    do{

        if(a%2 == 0){ //if even player 1 , odd player 2
            cout<<"Player 1 turn 'x'"<<endl;
            cout<<"Which row would you like?"<<endl;
            cin>>ansr;
            cout<<"Which col would you like?"<<endl;
            cin>>ansc;
            check(ansr, ansc, grid);
            assx(ansr, ansc, grid);
            if(win(grid)=='x'){
                cout<<"Player 1 WINS!"<<endl;
                a=9;
            }
        }else{
            cout<<"Player 2 turn 'o'"<<endl;
            cout<<"Which row would you like?"<<endl;
            cin>>ansr;
            cout<<"Which col would you like?"<<endl;
            cin>>ansc;
            check(ansr, ansc, grid);
            asso(ansr, ansc, grid);
            if(win(grid)=='o'){
                cout<<"Player 2 WINS!"<<endl;
                a=9;
            }
        }
        display(grid);
        a++;
        cin.clear(); //delete prior values
    }while (a<9); //will exit once a=9
    cout<<"thanks for playing!";
    return 0;
}//end of main
void inti(char grid[3][3]){
    for(int r=0; r<3; r++){
        for(int c=0; c<3; c++){
            grid[r][c]=' ';
            cout<<grid[r][c]<<"|";
        }
        cout<<endl;
    }
}//end of inti
void display(char grid [3][3]){
    for(int r=0; r<3; r++){
        for(int c=0; c<3; c++){
            cout<<grid[r][c]<<"|";
        }
        cout<<endl;
    }
}//end of display
void assx(int r, int c, char grid[3][3]){
    grid[r][c]='x';
}//end of assx
void asso(int r, int c, char grid[3][3]){
    grid[r][c]='o';
}
void check(int r, int c, char grid [3][3]){
     if(grid[r][c] == 'x' || grid[r][c] =='o'){
                cout<<"invalid"<<endl;
            }
}//end of check 
char win(char grid [3][3]){
    char w=0; 
    for (int i=0; i<=2; i++){
        if(grid[i][0]==grid[i][1] && grid[i][1]==grid[i][2] && grid[i][0]!=0){
            w = grid[i][0]; // any row the same
            return w;
        }
    }//for loop
    for(int i=0; i<=2; i++){
        if(grid[0][i]==grid[1][i] && grid[1][i]==grid[2][i] && grid[0][i]!=0){
            w=grid[0][i]; //any col the same 
            return w;
        }
    }//end of for
    
    if(grid[0][2]==grid[1][1] && grid[1][1]==grid[2][0] && grid[0][2]!=0){
        w=grid[0][2]; //diag right top to left bottom
        return w;
    }
    
    if(grid[0][0]==grid[1][1] && grid[1][1]==grid[2][2] && grid[2][2]!=0){
        w=grid[0][0]; //diag left top to right bottom
        return w; 
    }
    
    for(int i=0; i<=2; i++){
        for(int j=0; j<=2; j++){
            if(grid[i][j]==0){
                w=-1; // no wins, CAT GAME
            }
        }
    }
}//end of win





