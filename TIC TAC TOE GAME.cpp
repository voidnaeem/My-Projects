#include<iostream>
using namespace std;
char brd[3][3]={{'1','2','3',},{'4','5','6',},{'7','8','9',},};
char turn='O';
int row,column;
bool drow = false;
void bord()
{
	system("cls");
cout<<"\n\n\t This is  T I C   T A C    T O E    Game!"<<endl;
cout<<"\n\tplayer1[X]";
cout<<"\n\tPlayer2[O]\n";
	cout<<"\t\t      |     |     \n";
	cout<<"\t\t  "<<brd[0][0] <<"   |  "<<brd[0][1] <<"  |  "<<brd[0][2] <<"  \n";
	cout<<"\t\t      |     |     \n";
	cout<<"\t\t _____|_____|_____\n";
	cout<<"\t\t      |     |     \n";
	cout<<"\t\t  "<<brd[1][0] <<"   |  "<<brd[1][1] <<"  |  "<<brd[1][2] <<"  \n";
	cout<<"\t\t      |     |     \n";
	cout<<"\t\t _____|_____|_____\n";
	cout<<"\t\t      |     |     \n";
	cout<<"\t\t  "<<brd[2][0] <<"   |  "<<brd[2][1] <<"  |  "<<brd[2][2] <<"  \n";
	cout<<"\t\t      |     |     \n";
	cout<<"\t\t      |     |     \n";
}
  void player_turn()
{
     int choice;
    if(turn=='X')
        cout<<"\t\nEnter your location to mark[1-9] Player1 turn[X]:";
	if(turn=='O')
	   cout<<"\t\nEnter your location to mark[1-9]  Player2 turn[O]:";
	   cin>>choice;
	switch(choice){
		case 1:row=0; column=0;break;
		case 2: row=0; column=1; break;
		case 3:row=0; column=2;break;
		case 4:row=1; column=0;break;
		case 5:row=1; column=1;break;
		case 6:row=1; column=2;break;
		case 7:row=2; column=0;break;
		case 8:row=2; column=1;  break;
		case 9:row=2; column=2;   break;
		default:
			cout<<"invalid Choice:";
			break;
      }
         if(turn=='X'&& brd[row][column]!='X'&& brd[row][column]!='O')
         {
	      brd[row][column]='X';
	     turn='O';
	      }
	     else if(turn=='O'&& brd[row][column]!='X'&& brd[row][column]!='O')
	     {
	     brd[row][column]='O';
	     turn='X';
	     }
	     else
	     {
		 cout<<"Box already filed! Try again!!\n\n";
	     player_turn();
	    }
	    bord ();
  }
  bool gameover()
  {
  	// any win
  	for(int i=0;i<3;i++)
  	if(brd[i][0]==brd[i][1] && brd[i][0]==brd[i][2] ||brd[0][i]==brd[1][i] && brd[0][i]==brd[2][i])
  	return false;
	  if(brd[0][0]==brd[1][1]&&brd[0][0]==brd[2][2] || brd[0][2]==brd[1][1] &&brd[0][0]==brd[2][0])
  	return false;
  	//game continue
  		for(int i=0;i<3;i++)
  			for(int j=0;j<3;j++)
  			if(brd[i][j]!='X' && brd[i][j]!='O')
  			return true;
  			//game drow
  			drow = true;
  			return false;
  			
  }
int main()
{
	while(gameover())
	{
    bord();
    player_turn();
	gameover();
    }

if(turn='X' && drow ==false )
cout<<"Player2 [O] Wins!! Congratulations\n";
else if(turn='O' && drow ==false )
cout<<"Player1 [X] Wins!! Congratulations\n";
else
cout<<"Game is Drow!!\n";
}

