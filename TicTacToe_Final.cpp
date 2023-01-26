//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "TicTacToe_Final.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
#pragma resource ("*.Windows.fmx", _PLAT_MSWINDOWS)
#pragma resource ("*.Surface.fmx", _PLAT_MSWINDOWS)

TForm1 *Form1;

//struct Move{
//	int row;
//	int col;
//};
char board[3][3] =
		{
			{'_', '_', '_'},
			{'_', '_', '_'},
			{'_', '_', '_'}
		};
int flag = 0; //game is not terminated
char currentPlayerSymbol = 'O';
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
int TForm1::max(int a, int b){
	if(a>=b) return a;
	return b;
}
int TForm1::min(int a, int b){
	if(a<=b) return a;
	return b;
}



void TForm1::initial_window(){
//buttons
Button1->Text ="";
Button2->Text ="";
Button3->Text ="";
Button4->Text ="";
Button5->Text ="";
Button6->Text ="";
Button7->Text ="";
Button8->Text ="";
Button9->Text ="";
if(Mode->Text == "PLAYING AGAINST HUMAN"){
	Label2->Text = "Player 1 -> O    ;     Player 2 -> X" ;
}else{
    Label2->Text = "Player 1 -> O    ;     BOT -> X";
}


//labels
MainTitle->Text = "TIC TAC TOE";
MakeMove->Text = "Make your move, player";

//lines
Line1->Visible = false;
Line2->Visible = false;
Line3->Visible = false;
Line4->Visible = false;
Line5->Visible = false;
Line6->Visible = false;
Line7->Visible = false;
Line8->Visible = false;

//board
board[0][0] = '_';
board[0][1] = '_';
board[0][2] = '_';
board[1][0] = '_';
board[1][1] = '_';
board[1][2] = '_';
board[2][0] = '_';
board[2][1] = '_';
board[2][2] = '_';


//kiski baari
KiskiBaari->Text = 'O';
//cuurentPlayerSymbol
currentPlayerSymbol = 'O';
//flag
flag =0;

//aur bhi bhut kuch
}
String TForm1::winner() {
	if (Button1->Text == Button2->Text and Button2->Text ==
		Button3->Text and Button1->Text != "")
		return Button1->Text;
	if (Button4->Text == Button5->Text and Button5->Text ==
		Button6->Text and Button4->Text != "")
		return Button4->Text;
	if (Button7->Text == Button8->Text and Button8->Text ==
		Button9->Text and Button7->Text != "")
		return Button7->Text;

	if (Button1->Text == Button4->Text and Button4->Text ==
		Button7->Text and Button1->Text != "")
		return Button1->Text;
	if (Button2->Text == Button5->Text and Button5->Text ==
		Button8->Text and Button2->Text != "")
		return Button2->Text;
	if (Button3->Text == Button6->Text and Button6->Text ==
		Button9->Text and Button3->Text != "")
		return Button3->Text;

	if (Button1->Text == Button5->Text and Button5->Text ==
		Button9->Text and Button1->Text != "")
		return Button1->Text;
	if (Button3->Text == Button5->Text and Button5->Text ==
		Button7->Text and Button3->Text != "")
		return Button3->Text;

	return "IT'S A DRAW...";
}


void TForm1::termination_window(){
	flag = 1;
	String winnerPlayer = winner();
	if(winnerPlayer=="O") winnerPlayer = "O WON !!!";
	else if(winnerPlayer=="X") winnerPlayer = "X WON !!!";

	MakeMove->Text = winnerPlayer;
	KiskiBaari->Text = "";

}


bool TForm1::isTerminated(){
    if (Button1->Text == Button2->Text and Button2->Text == Button3->Text)
		if (Button1->Text != ""){
		Line1->Visible = True;
		return true;
		}

	if (Button4->Text == Button5->Text and Button5->Text == Button6->Text)
		if (Button4->Text != "") {
			Line2->Visible = true;
			return true;
        }

	if (Button7->Text == Button8->Text and Button8->Text == Button9->Text)
		if (Button7->Text != "") {
			Line3->Visible = true;
			return true;
		}


	if (Button1->Text == Button4->Text and Button4->Text == Button7->Text)
		if (Button1->Text != "")  {
			Line4->Visible = true;
			return true;
        }

	if (Button2->Text == Button5->Text and Button5->Text == Button8->Text)
		if (Button2->Text != "")  {
			Line5->Visible = true;
			return true;
        }

	if (Button3->Text == Button6->Text and Button6->Text == Button9->Text)
		if (Button3->Text != ""){
			Line6->Visible = true;
			return true;
		}


	if (Button1->Text == Button5->Text and Button5->Text == Button9->Text)
		if (Button1->Text != "")   {
			Line7->Visible = true;
			return true;
        }

	if (Button3->Text == Button5->Text and Button5->Text == Button7->Text)
		if (Button3->Text != "") {
			Line8->Visible = true;
			return true;
        }


	if (Button1->Text == "" or Button2->Text == "" or Button3->Text ==
		"" or Button4->Text == "" or Button5->Text == "" or Button6->Text ==
		"" or Button7->Text == "" or Button8->Text == "" or Button9->Text == "")
		return false;
	else
		return true;

}
void TForm1::update_board(){
	if(Button1->Text=='O') board[0][0] = 'O';
	if(Button1->Text=='X') board[0][0] = 'X';

	if(Button2->Text=='O') board[0][1] = 'O';
	if(Button2->Text=='X') board[0][1] = 'X';

	if(Button3->Text=='O') board[0][2] = 'O';
	if(Button3->Text=='X') board[0][2] = 'X';

	if(Button4->Text=='O') board[1][0] = 'O';
	if(Button4->Text=='X') board[1][0] = 'X';

	if(Button5->Text=='O') board[1][1] = 'O';
	if(Button5->Text=='X') board[1][1] = 'X';

	if(Button6->Text=='O') board[1][2] = 'O';
	if(Button6->Text=='X') board[1][2] = 'X';

	if(Button7->Text=='O') board[2][0] = 'O';
	if(Button7->Text=='X') board[2][0] = 'X';

	if(Button8->Text=='O') board[2][1] = 'O';
	if(Button8->Text=='X') board[2][1] = 'X';

	if(Button9->Text=='O') board[2][2] = 'O';
	if(Button9->Text=='X') board[2][2] = 'X';


}
int TForm1::emptyslots(char board[3][3])
{
	int count = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == '_')
			{
				count++;
			}
		}
	}
	return count;
}
bool TForm1::isMovesLeft(char board[3][3])
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (board[i][j] == '_')
				return true;
	return false;
}
int TForm1::evaluate(char b[3][3])
{
	// Checking for Rows for X or O victory.
	for (int row = 0; row < 3; row++)
	{
		if (b[row][0] == b[row][1] &&
			b[row][1] == b[row][2])
		{
			if (b[row][0] == 'X')
				return +10;
			else if (b[row][0] == 'O')
				return -10;
		}
	}

	// Checking for Columns for X or O victory.
	for (int col = 0; col < 3; col++)
	{
		if (b[0][col] == b[1][col] &&
			b[1][col] == b[2][col])
		{
			if (b[0][col] == 'X')
				return +10;

			else if (b[0][col] == 'O')
				return -10;
		}
	}

	// Checking for Diagonals for X or O victory.
	if (b[0][0] == b[1][1] && b[1][1] == b[2][2])
	{
		if (b[0][0] == 'X')
			return +10;
		else if (b[0][0] == 'O')
			return -10;
	}

	if (b[0][2] == b[1][1] && b[1][1] == b[2][0])
	{
		if (b[0][2] == 'X')
			return +10;
		else if (b[0][2] == 'O')
			return -10;
	}

	// Else if none of them have won then return 0
	return 0;
}


int TForm1::minimax(char board[3][3], int depth, bool isMax)
{
	int score = evaluate(board);

	// If Maximizer has won the game return his/her
	// evaluated score
	if (score == 10)
		return score + emptyslots(board);

	// If Minimizer has won the game return his/her
	// evaluated score
	if (score == -10)
		return score - emptyslots(board);

	// If there are no more moves and no winner then
	// it is a tie
	if (isMovesLeft(board) == false)
		return 0;

	// If this maximizer's move
	if (isMax)
	{
		int best = -1000;

		// Traverse all cells
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				// Check if cell is empty
				if (board[i][j] == '_')
				{
					// Make the move
					board[i][j] = 'X';

					// Call minimax recursively and choose
					// the maximum value
					best = max(best,
							   minimax(board, depth + 1, !isMax));

					// Undo the move
					board[i][j] = '_';
				}
			}
		}
		return best;
	}

	// If this minimizer's move
	else
	{
		int best = 1000;

		// Traverse all cells
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				// Check if cell is empty
				if (board[i][j] == '_')
				{
					// Make the move
					board[i][j] = 'O';

					// Call minimax recursively and choose
					// the minimum value
					best = min(best,
							   minimax(board, depth + 1, !isMax));

					// Undo the move
					board[i][j] = '_';
				}
			}
		}
		return best;
	}
}



struct::Move TForm1::findBestMove(){
    int bestVal = -1000;
	struct::Move bestMove;
	bestMove.row = -1;
	bestMove.col = -1;

    for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			// Check if cell is empty
			if (board[i][j] == '_')
			{
				// Make the move
				board[i][j] = 'X';

				int moveVal = minimax(board, 0, false);

                // Undo the move
				board[i][j] = '_';

                if (moveVal > bestVal)
				{
					bestMove.row = i;
					bestMove.col = j;
					bestVal = moveVal;
				}








			}
		}
	}
	return bestMove;
}

void __fastcall TForm1::ButtonClick(TObject *Sender)
{
	if(flag==0){
		TButton* clickedButton = dynamic_cast<TButton*>(Sender);
		if(clickedButton->Text != 'O' and clickedButton->Text != 'X'){
			clickedButton->Text = currentPlayerSymbol;
			update_board();
			//if terminated, then display termination window and return;
			if (isTerminated()) {
				termination_window();
				return;
			}
			//change currentPlayerSymbol
			currentPlayerSymbol == 'O' ? currentPlayerSymbol = 'X' : currentPlayerSymbol = 'O' ;
			//kiski baari->text = cuurentplayersymbol
			KiskiBaari -> Text = currentPlayerSymbol;

			//if player vs player, do nothing
			//if player vs comp
			if(Mode->Text == "PLAYING AGAINST BOT"){
//          	  find the best move
				  struct::Move bestMove = findBestMove();


//          	  then bestmovebutton->text = X
				if(bestMove.row==0 and bestMove.col==0) Button1->Text = currentPlayerSymbol;
				else if(bestMove.row==0 and bestMove.col==1) Button2->Text = currentPlayerSymbol;
				else if(bestMove.row==0 and bestMove.col==2) Button3->Text = currentPlayerSymbol;
				else if(bestMove.row==1 and bestMove.col==0) Button4->Text = currentPlayerSymbol;
				else if(bestMove.row==1 and bestMove.col==1) Button5->Text = currentPlayerSymbol;
				else if(bestMove.row==1 and bestMove.col==2) Button6->Text = currentPlayerSymbol;
				else if(bestMove.row==2 and bestMove.col==0) Button7->Text = currentPlayerSymbol;
				else if(bestMove.row==2 and bestMove.col==1) Button8->Text = currentPlayerSymbol;
				else Button9->Text = currentPlayerSymbol;

				update_board();

//                check for termination also
					if (isTerminated()) {
					termination_window();
					return;
					}

			//change currentPlayerSymbol if player vs comp
			currentPlayerSymbol == 'O' ? currentPlayerSymbol = 'X' : currentPlayerSymbol = 'O' ;
			//kiski baari->text = cuurentPlayerSymbol
			KiskiBaari -> Text = currentPlayerSymbol;
			}
		} //if clicked button is empty
	}   // if flag==0
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ModeClick(TObject *Sender)
{
Mode->Text=="PLAYING AGAINST HUMAN" ? Mode->Text = "PLAYING AGAINST BOT" : Mode->Text = "PLAYING AGAINST HUMAN";
initial_window();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RestartClick(TObject *Sender)
{
initial_window();
}
//---------------------------------------------------------------------------

