//---------------------------------------------------------------------------

#ifndef TicTacToe_FinalH
#define TicTacToe_FinalH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Colors.hpp>
#include <FMX.Types.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Objects.hpp>
#include <FMX.WebBrowser.hpp>
//---------------------------------------------------------------------------


struct Move{
	int row;
	int col;
};


class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TColorBox *Z;
	TButton *Button1;
	TButton *Button10;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TButton *Button7;
	TButton *Button8;
	TButton *Button9;
	TLabel *KiskiBaari;
	TLabel *Label2;
	TLine *Line1;
	TLine *Line2;
	TLine *Line3;
	TLine *Line4;
	TLine *Line5;
	TLine *Line6;
	TLine *Line7;
	TLine *Line8;
	TLabel *MainTitle;
	TLabel *MakeMove;
	TButton *Mode;
	TButton *Restart;
	TLabel *Label1;
	void __fastcall ButtonClick(TObject *Sender);
	void __fastcall ModeClick(TObject *Sender);
	void __fastcall RestartClick(TObject *Sender);
private:	// User declarations
void initial_window();
bool isTerminated();
void termination_window();
String winner();
struct::Move findBestMove();
void update_board();
int minimax(char board[3][3], int depth, bool isMax);
int max(int a, int b);
int emptyslots(char board[3][3]);
int min(int a, int b);
bool isMovesLeft(char board[3][3]);
int evaluate(char b[3][3]);
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
