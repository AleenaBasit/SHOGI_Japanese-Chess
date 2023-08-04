#include <iostream>
#include<windows.h>
#include<fstream>
#include<conio.h>
using namespace std;

//enum BOOL{WHITE,BLACK};
#define WHITE 0
#define BLACK 1



void getRowColbyLeftClick(int& rpos, int& cpos)
{
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD Events;
	INPUT_RECORD InputRecord;
	SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
	do
	{
		ReadConsoleInput(hInput, &InputRecord, 1, &Events);
		if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			cpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
			rpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
			break;
		}
	} while (true);
}
struct Position
{
	int ri, ci;
};
void init(char**& B, int& dim, string PNames[], int& turn, char Y[], char Z[], int Y1[], int Z1[])
{
	int n;
	cout << "Enter 1 to continue last last or enter 0 for new game." << endl;
	cin >> n;
	if (n == 0)
	{
		ifstream Rdr("New.txt");
		Rdr >> dim;
		B = new char* [dim];
		for (int ri = 0; ri < dim; ri++)
		{
			B[ri] = new char[dim];
		}
		for (int ri = 0; ri < dim; ri++)
		{
			for (int ci = 0; ci < dim; ci++)
				Rdr >> B[ri][ci];
		}
	}
	else if (n == 1)
	{
		ifstream Rdr("Save.txt");
		Rdr >> dim;
		B = new char* [dim];
		for (int ri = 0; ri < dim; ri++)
		{
			B[ri] = new char[dim];
		}
		for (int ri = 0; ri < dim; ri++)
		{
			for (int ci = 0; ci < dim; ci++)
				Rdr >> B[ri][ci];
		}
		ifstream y1("Save2.txt");
		int d;
		y1 >> d;
		for (int i = 0; i < d; i++)
		{
			y1 >> Y1[i];
		}
		int f;
		ifstream z1("Save3.txt");
		z1 >> f;
		for (int i = 0; i < f; i++)
		{
			z1 >> Z1[i];
		}

	}
	cout << "Enter player1 name" << endl;
	cin >> PNames[0];
	cout << "Enter player2 name" << endl;
	cin >> PNames[1];
	turn = WHITE;
	ifstream y("Text1.txt");
	for (int ri = 0; ri < 7; ri++)
	{
		y >> Y[ri];
	}
	ifstream z("Text2.txt");
	for (int ri = 0; ri < 7; ri++)
	{
		z >> Z[ri];
	}
}
void turnMsg(string PName[], int turn)
{
	cout << PName[turn] << "'s turn" << endl;
}
//void selectPos(Position& P, int size)
//{
// int x, y;
// cout << endl << endl << endl;
// cout << "Give Coordinate(A1:H8):";
// /*char c;
// int d;
// cin >> c >> d;
// c = toupper(c);*/
// getRowColbyLeftClick(x, y);
//
// /*P.ri = d - 1;
// P.ci = c - 'A';*/
// P.ri = x / size;
// P.ci = y / size;
//
// cout << "You selected " << char(P.ci + 65) << " and " << P.ri + 1 << endl;
//}
void turnChange(int& turn)
{
	turn = (turn + 1) % 2;
}
void gotoRowCol(int rpos, int cpos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = cpos;
	scrn.Y = rpos;
	SetConsoleCursorPosition(hOuput, scrn);
}

void drawPawn(int cr, int  cc)
{
	gotoRowCol(cr - 2, cc);
	cout << char(-37);
	for (int i = 0; i < 5; i++)
	{
		gotoRowCol(cr - 1, cc - 2 + i);
		cout << char(-37);
	}
	for (int i = 0; i < 3; i++)
	{
		gotoRowCol(cr, cc - 1 + i);
		cout << char(-37);
	}
	for (int i = 0; i < 7; i++)
	{
		gotoRowCol(cr + 1, cc - 3 + i);
		cout << char(-37);
	}
}
void drawBishop(int cr, int cc)
{
	gotoRowCol(cr - 2, cc);
	cout << char(-37);
	for (int i = 0; i < 5; i++)
	{
		gotoRowCol(cr - 1, cc - 2 + i);
		cout << char(-37);
	}
	for (int i = 0; i < 3; i++)
	{
		gotoRowCol(cr, cc - 1 + i);
		cout << char(-37);
	}
	for (int i = 0; i < 3; i++)
	{
		gotoRowCol(cr + 1, cc - 1 + i);
		cout << char(-37);
	}
	for (int i = 0; i < 7; i++)
	{
		gotoRowCol(cr + 2, cc - 3 + i);
		cout << char(-37);
	}
}
void drawRook(int cr, int cc)
{
	gotoRowCol(cr - 3, cc);
	cout << char(-37);
	for (int i = 0; i < 5; i++)
	{
		gotoRowCol(cr - 2, cc - 2 + i);
		cout << char(-37);
	}
	for (int i = 0; i < 5; i++)
	{
		gotoRowCol(cr - 1, cc - 2 + i);
		cout << char(-37);
	}
	for (int i = 0; i < 3; i++)
	{
		gotoRowCol(cr, cc - 1 + i);
		cout << char(-37);
	}
	for (int i = 0; i < 3; i++)
	{
		gotoRowCol(cr + 1, cc - 1 + i);
		cout << char(-37);
	}
	for (int i = 0; i < 7; i++)
	{
		gotoRowCol(cr + 2, cc - 3 + i);
		cout << char(-37);
	}

}
void drawLance(int cr, int cc)
{
	gotoRowCol(cr - 2, cc);
	cout << char(-37);
	for (int i = 0; i < 3; i++)
	{
		gotoRowCol(cr - 1, cc - 1 + i);
		cout << char(-37);
	}
	for (int i = 0; i < 3; i++)
	{
		gotoRowCol(cr, cc - 1 + i);
		cout << char(-37);
	}
	for (int i = 0; i < 3; i++)
	{
		gotoRowCol(cr + 1, cc - 1 + i);
		cout << char(-37);
	}
	for (int i = 0; i < 5; i++)
	{
		gotoRowCol(cr + 2, cc - 2 + i);
		cout << char(-37);
	}
}
void drawKnight(int cr, int cc)
{
	gotoRowCol(cr - 2, cc - 1);
	cout << char(-37) << char(-37);
	for (int i = 0; i < 5; i++)
	{
		gotoRowCol(cr - 1, cc - 2 + i);
		cout << char(-37);
	}
	gotoRowCol(cr, cc - 3);
	cout << char(-37) << char(-37) << char(-37) << char(-37)
		<< " " << char(-37) << char(-37);
	for (int i = 0; i < 3; i++)
	{
		gotoRowCol(cr + 1, cc - 2 + i);
		cout << char(-37);
	}
	gotoRowCol(cr + 2, cc - 1);
	cout << char(-37) << char(-37);
	for (int i = 0; i < 7; i++)
	{
		gotoRowCol(cr + 3, cc - 3 + i);
		cout << char(-37);
	}
}
void drawSilverGen(int cr, int cc)
{
	gotoRowCol(cr - 2, cc);
	cout << char(-37);
	for (int i = 0; i < 5; i++)
	{
		gotoRowCol(cr - 1, cc - 2 + i);
		cout << char(-37);
	}
	for (int i = 0; i < 3; i++)
	{
		gotoRowCol(cr, cc - 1 + i);
		cout << char(-37);
	}
	for (int i = 0; i < 3; i++)
	{
		gotoRowCol(cr + 1, cc - 1 + i);
		cout << char(-37);
	}
	for (int i = 0; i < 5; i++)
	{
		gotoRowCol(cr + 2, cc - 2 + i);
		cout << char(-37);
	}
	for (int i = 0; i < 7; i++)
	{
		gotoRowCol(cr + 3, cc - 3 + i);
		cout << char(-37);
	}

}
void drawGoldGen(int cr, int cc)
{
	gotoRowCol(cr - 2, cc - 2);
	cout << char(-37) << "   " << char(-37);
	for (int i = 0; i < 5; i++)
	{
		gotoRowCol(cr - 1, cc - 2 + i);
		cout << char(-37);
	}
	for (int i = 0; i < 3; i++)
	{
		gotoRowCol(cr, cc - 1 + i);
		cout << char(-37);
	}
	for (int i = 0; i < 3; i++)
	{
		gotoRowCol(cr + 1, cc - 1 + i);
		cout << char(-37);
	}
	for (int i = 0; i < 5; i++)
	{
		gotoRowCol(cr + 2, cc - 2 + i);
		cout << char(-37);
	}
	for (int i = 0; i < 7; i++)
	{
		gotoRowCol(cr + 3, cc - 3 + i);
		cout << char(-37);
	}

}
void drawKing(int cr, int cc)
{
	gotoRowCol(cr - 3, cc - 3);
	cout << char(-37) << "  " << char(-37) << "  " << char(-37);
	for (int i = 0; i < 7; i++)
	{
		gotoRowCol(cr - 2, cc - 3 + i);
		cout << char(-37);
	}
	for (int i = 0; i < 5; i++)
	{
		gotoRowCol(cr - 1, cc - 2 + i);
		cout << char(-37);
	}
	for (int i = 0; i < 3; i++)
	{
		gotoRowCol(cr, cc - 1 + i);
		cout << char(-37);
	}
	for (int i = 0; i < 3; i++)
	{
		gotoRowCol(cr + 1, cc - 1 + i);
		cout << char(-37);
	}
	for (int i = 0; i < 5; i++)
	{
		gotoRowCol(cr + 2, cc - 2 + i);
		cout << char(-37);
	}
	for (int i = 0; i < 7; i++)
	{
		gotoRowCol(cr + 3, cc - 3 + i);
		cout << char(-37);
	}
}

void updateBoard(char**& B, Position Sc, Position Dc, bool isPlace, char sym)
{
	if (isPlace == false)
	{
		char p = B[Sc.ri][Sc.ci];
		B[Dc.ri][Dc.ci] = p;
		B[Sc.ri][Sc.ci] = '-';
	}
	else
	{
		char p = sym;
		B[Dc.ri][Dc.ci] = p;
		//B[Sc.ri][Sc.ci] = '-';
	}

}
bool isHoriMove(Position Sc, Position Dc)
{
	return(Sc.ri == Dc.ri);
}
bool isVertiMove(Position Sc, Position Dc)
{
	return(Sc.ci == Dc.ci);
}
bool isDiagMove(Position Sc, Position Dc)
{
	int r = abs(Sc.ri - Dc.ri);
	int c = abs(Sc.ci - Dc.ci);
	return(r == c);
}
bool isHoriPathClr(char**& B, Position Sc, Position Dc)
{
	if (Sc.ci < Dc.ci)
	{
		for (int c = Sc.ci + 1; c < Dc.ci; c++)
		{
			if (B[Sc.ri][c] != '-')
				return false;
		}
		return true;
	}
	else
	{
		for (int c = Dc.ci + 1; c < Sc.ci; c++)
		{
			if (B[Sc.ri][c] != '-')
				return false;
		}
		return true;
	}
}
bool isVertiPathClr(char**& B, Position Sc, Position Dc)
{
	int rs, re;
	if (Sc.ri < Dc.ri)
	{
		rs = Sc.ri + 1, re = Dc.ri - 1;
	}
	else
	{
		rs = Dc.ri + 1, re = Sc.ri - 1;
	}
	for (int r = rs; r <= re; r++)
	{
		if (B[r][Sc.ci] != '-')
			return false;
	}
	return true;
}
bool isDiagPathClr1(char**& B, Position Sc, Position Dc)
{
	int dr;
	if (Sc.ri < Dc.ri)
	{
		dr = Dc.ri - Sc.ri - 1;
		for (int i = 1; i <= dr; i++)
		{
			if (B[Sc.ri + i][Sc.ci + i] != '-')
				return false;
		}
		return true;
	}
	else
	{
		dr = Sc.ri - Dc.ri - 1;
		for (int i = 1; i <= dr; i++)
		{
			if (B[Sc.ri - i][Sc.ci - i] != '-')
				return false;
		}
		return true;
	}
}
bool isDiagPathClr2(char**& B, Position Sc, Position Dc)
{
	int dr;
	if (Sc.ri < Dc.ri)
	{
		dr = Dc.ri - Sc.ri - 1;
		for (int i = 1; i <= dr; i++)
		{
			if (B[Sc.ri + i][Sc.ci - i] != '-')
				return false;
		}
		return true;
	}
	else
	{
		dr = Sc.ri - Dc.ri - 1;
		for (int i = 1; i <= dr; i++)
		{
			if (B[Sc.ri - i][Sc.ci + i] != '-')
				return false;
		}
		return true;
	}
}
bool isDiagPathClr(char**& B, Position Sc, Position Dc)
{
	if ((Sc.ri > Dc.ri && Sc.ci > Dc.ci) || (Sc.ri < Dc.ri && Sc.ci < Dc.ci))
		return isDiagPathClr1(B, Sc, Dc);
	else
		return isDiagPathClr2(B, Sc, Dc);
}
bool isWhite(char sym)
{
	return(sym >= 'a' && sym <= 'z');
}
bool isBlack(char sym)
{
	return(sym >= 'A' && sym <= 'Z');
}
bool IsMyPlace(char sym, int turn)
{
	if (turn == BLACK)
		return(isBlack(sym));
	else
		return(isWhite(sym));
}
bool IsValidSc(char** B, int dim, Position Sc, int turn)
{
	if (Sc.ri < 0 || Sc.ri >= dim || Sc.ci < 0 || Sc.ci >= dim)
		return false;
	return(IsMyPlace(B[Sc.ri][Sc.ci], turn));
}
bool IsValidDc(char** B, int dim, Position Sc, int turn)
{
	if (Sc.ri < 0 || Sc.ri >= dim || Sc.ci < 0 || Sc.ci >= dim)
		return false;
	return(!IsMyPlace(B[Sc.ri][Sc.ci], turn));
}
bool rookLeg(char** B, Position Sc, Position Dc)
{
	return(isHoriMove(Sc, Dc) && isHoriPathClr(B, Sc, Dc)) || (isVertiMove(Sc, Dc) && isVertiPathClr(B, Sc, Dc));
}
bool bishopLeg(char** B, Position Sc, Position Dc)
{
	return(isDiagMove(Sc, Dc) && isDiagPathClr(B, Sc, Dc));
}
bool kingLeg(char** B, Position Sc, Position Dc)
{
	int r = abs(Sc.ri - Dc.ri);
	int c = abs(Sc.ci - Dc.ci);
	return ((rookLeg(B, Sc, Dc) || bishopLeg(B, Sc, Dc)) && (r <= 1 && c <= 1));
}
bool knightLeg(Position Sc, Position Dc)
{
	int r = abs(Sc.ri - Dc.ri);
	int c = abs(Sc.ci - Dc.ci);
	return (r == 2 && c == 1);
}
bool pawnLeg(Position Sc, Position Dc)
{
	int r = abs(Sc.ri - Dc.ri);
	int c = abs(Sc.ci - Dc.ci);
	return (r == 1 && c == 0);
}
bool lancesLeg(char** B, Position Sc, Position Dc)
{
	return (isVertiMove(Sc, Dc) && isVertiPathClr(B, Sc, Dc));
}
bool silgenLeg(char** B, Position Sc, Position Dc)
{
	int r = abs(Sc.ri - Dc.ri);
	int c = abs(Sc.ci - Dc.ci);
	return ((bishopLeg(B, Sc, Dc) || pawnLeg(Sc, Dc)) && (r <= 1 && c <= 1));
}
bool goldgenLeg(char** B, Position Sc, Position Dc)
{
	int r = abs(Sc.ri - Dc.ri);
	int c = abs(Sc.ci - Dc.ci);
	if (B[Sc.ri][Sc.ci] == 'g' || B[Sc.ri][Sc.ci] == 'a' || B[Sc.ri][Sc.ci] == 'c' || B[Sc.ri][Sc.ci] == 't' || B[Sc.ri][Sc.ci] == 'i')
	{
		return(((rookLeg(B, Sc, Dc) || (bishopLeg(B, Sc, Dc) && (Sc.ri < Dc.ri))) && (r <= 1 && c <= 1)));
	}
	else
	{
		return(((rookLeg(B, Sc, Dc) || (bishopLeg(B, Sc, Dc) && (Sc.ri > Dc.ri))) && (r <= 1 && c <= 1)));
	}
}
bool isLegalMove(char** B, Position Sc, Position Dc, int dim, int turn)
{
	switch (B[Sc.ri][Sc.ci])
	{
	case'r':
	case'R':
		return rookLeg(B, Sc, Dc);
	case'b':
	case'B':
		return bishopLeg(B, Sc, Dc);
	case'k':
	case'K':
		return kingLeg(B, Sc, Dc);
	case'n':
		return Sc.ri < Dc.ri&& knightLeg(Sc, Dc);
	case'N':
		return  Sc.ri > Dc.ri && knightLeg(Sc, Dc);
	case'p':
		return Sc.ri < Dc.ri&& pawnLeg(Sc, Dc);
	case'P':
		return Sc.ri > Dc.ri && pawnLeg(Sc, Dc);
	case'l':
		return Sc.ri < Dc.ri&& lancesLeg(B, Sc, Dc);
	case'L':
		return Sc.ri > Dc.ri && lancesLeg(B, Sc, Dc);
	case's':
	case'S':
		return silgenLeg(B, Sc, Dc);
	case'g':
	case'G':
		return bishopLeg(B, Sc, Dc) || rookLeg(B, Sc, Dc);
	case 'a':          //promotedpawn
	case 'A':
	case 'c':         //promotedlance
	case 'C':
	case 't':         //promotedknight
	case 'T':
	case 'i':         //promotedsilvergen
	case 'I':
		return goldgenLeg(B, Sc, Dc);
	case 'h':        //promotedbishop
	case 'H':
		return (bishopLeg(B, Sc, Dc) || kingLeg(B, Sc, Dc));
	case 'o':        //promotedrook
	case 'O':
		return (rookLeg(B, Sc, Dc) || kingLeg(B, Sc, Dc));
	default:
		break;
	}
}
void SetClr(int clr)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clr);
}
void setconsoleclr(int textColor, int bgColor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (textColor + (bgColor * 16)));
}
void drawBox(int sr, int sc, int brows, int bcols, int col, char**& B, int r, int c, int m)
{

	for (int ri = 0; ri < brows; ri++)
	{
		for (int ci = 0; ci < bcols; ci++)
		{
			SetClr(col);
			gotoRowCol(sr + ri, sc + ci);
			if (ri != brows / 2 || ci != bcols / 2)
				cout << char(-37);
		}
	}
	for (int ri = 0; ri < brows; ri++)
	{
		for (int ci = 0; ci < bcols; ci++)
		{
			SetClr(col);
			if (ri == brows / 2 && ci == bcols / 2)
			{
				gotoRowCol(sr + ri, sc + ri);
				setconsoleclr(12, m);
				if (B[r][c] != '-')
				{
					switch (B[r][c])
					{
					case'r':
						setconsoleclr(15, m);
						drawRook(sr + ri, sc + ri);
						break;
					case'R':
						setconsoleclr(0, m);
						drawRook(sr + ri, sc + ri);
						break;
					case'b':
						setconsoleclr(15, m);
						drawBishop(sr + ri, sc + ri);
						break;
					case'B':
						setconsoleclr(0, m);
						drawBishop(sr + ri, sc + ri);
						break;
					case'k':
						setconsoleclr(15, m);
						drawKing(sr + ri, sc + ri);
						break;
					case'K':
						setconsoleclr(0, m);
						drawKing(sr + ri, sc + ri);
						break;
					case'n':
						setconsoleclr(15, m);
						drawKnight(sr + ri, sc + ri);
						break;
					case'N':
						setconsoleclr(0, m);
						drawKnight(sr + ri, sc + ri);
						break;
					case'p':
						setconsoleclr(15, m);
						drawPawn(sr + ri, sc + ri);
						break;
					case'P':
						setconsoleclr(0, m);
						drawPawn(sr + ri, sc + ri);
						break;
					case'l':
						setconsoleclr(15, m);
						drawLance(sr + ri, sc + ri);
						break;
					case'L':
						setconsoleclr(0, m);
						drawLance(sr + ri, sc + ri);
						break;
					case's':
						setconsoleclr(15, m);
						drawSilverGen(sr + ri, sc + ri);
						break;
					case'S':
						setconsoleclr(0, m);
						drawSilverGen(sr + ri, sc + ri);
						break;
					case'g':
						setconsoleclr(15, m);
						drawGoldGen(sr + ri, sc + ri);
						break;
					case'G':
						setconsoleclr(0, m);
						drawGoldGen(sr + ri, sc + ri);
						break;
					case'o':
						setconsoleclr(4, m);
						drawRook(sr + ri, sc + ri);
						break;
					case'O':
						setconsoleclr(9, m);
						drawRook(sr + ri, sc + ri);
						break;
					case'h':
						setconsoleclr(4, m);
						drawBishop(sr + ri, sc + ri);
						break;
					case'H':
						setconsoleclr(9, m);
						drawBishop(sr + ri, sc + ri);
						break;
					case't':
						setconsoleclr(4, m);
						drawKnight(sr + ri, sc + ri);
						break;
					case'T':
						setconsoleclr(9, m);
						drawKnight(sr + ri, sc + ri);
						break;
					case'a':
						setconsoleclr(4, m);
						drawPawn(sr + ri, sc + ri);
						break;
					case'A':
						setconsoleclr(9, m);
						drawPawn(sr + ri, sc + ri);
						break;
					case'c':
						setconsoleclr(4, m);
						drawLance(sr + ri, sc + ri);
						break;
					case'C':
						setconsoleclr(9, m);
						drawLance(sr + ri, sc + ri);
						break;
					case'i':
						setconsoleclr(4, m);
						drawSilverGen(sr + ri, sc + ri);
						break;
					case'I':
						setconsoleclr(9, m);
						drawSilverGen(sr + ri, sc + ri);
						break;
					default:
						break;
					}
					//cout << B[r][c];
				}
				else
					cout << " ";
			}

		}
	}
}
void compHighlight(char** B, Position Sc, int dim, int turn, bool**& Hboard)
{
	Hboard = new bool* [dim];
	for (int i = 0; i < dim; i++)
	{
		Hboard[i] = new bool[dim] {};
	}
	Position Dc;
	for (int r = 0; r < dim; r++)
	{
		for (int c = 0; c < dim; c++)
		{
			Dc.ri = r, Dc.ci = c;
			if ((IsValidDc(B, dim, Dc, turn) == true) && (isLegalMove(B, Sc, Dc, dim, turn) == true))
			{
				Hboard[r][c] = true;
			}
			else
			{
				Hboard[r][c] = false;
			}
		}
	}
}
void drawBox2(int sr, int sc, int brows, int bcols, int col, char**& B, int r, int c, int m)
{
	for (int ri = 0; ri < brows; ri++)
	{
		for (int ci = 0; ci < bcols; ci++)
		{
			if (ri == 0 || ci == 0 || ri == brows - 1 || ci == bcols - 1)
			{
				SetClr(5);
			}
			else
			{
				SetClr(col);
			}

			gotoRowCol(sr + ri, sc + ci);
			if (ri != brows / 2 || ci != bcols / 2)
				cout << char(-37);
		}
	}
	for (int ri = 0; ri < brows; ri++)
	{
		for (int ci = 0; ci < bcols; ci++)
		{
			if (ri == 0 || ci == 0 || ri == brows - 1 || ci == bcols - 1)
			{
				SetClr(5);
			}
			else
			{
				SetClr(col);
			}

			if (ri == brows / 2 && ci == bcols / 2)
			{
				gotoRowCol(sr + ri, sc + ri);
				setconsoleclr(12, m);
				if (B[r][c] != '-')
				{
					switch (B[r][c])
					{
					case'r':
						setconsoleclr(15, m);
						drawRook(sr + ri, sc + ri);
						break;
					case'R':
						setconsoleclr(0, m);
						drawRook(sr + ri, sc + ri);
						break;
					case'b':
						setconsoleclr(15, m);
						drawBishop(sr + ri, sc + ri);
						break;
					case'B':
						setconsoleclr(0, m);
						drawBishop(sr + ri, sc + ri);
						break;
					case'k':
						setconsoleclr(15, m);
						drawKing(sr + ri, sc + ri);
						break;
					case'K':
						setconsoleclr(0, m);
						drawKing(sr + ri, sc + ri);
						break;
					case'n':
						setconsoleclr(15, m);
						drawKnight(sr + ri, sc + ri);
						break;
					case'N':
						setconsoleclr(0, m);
						drawKnight(sr + ri, sc + ri);
						break;
					case'p':
						setconsoleclr(15, m);
						drawPawn(sr + ri, sc + ri);
						break;
					case'P':
						setconsoleclr(0, m);
						drawPawn(sr + ri, sc + ri);
						break;
					case'l':
						setconsoleclr(15, m);
						drawLance(sr + ri, sc + ri);
						break;
					case'L':
						setconsoleclr(0, m);
						drawLance(sr + ri, sc + ri);
						break;
					case's':
						setconsoleclr(15, m);
						drawSilverGen(sr + ri, sc + ri);
						break;
					case'S':
						setconsoleclr(0, m);
						drawSilverGen(sr + ri, sc + ri);
						break;
					case'g':
						setconsoleclr(15, m);
						drawGoldGen(sr + ri, sc + ri);
						break;
					case'G':
						setconsoleclr(0, m);
						drawGoldGen(sr + ri, sc + ri);
						break;
					case'o':
						setconsoleclr(4, m);
						drawRook(sr + ri, sc + ri);
						break;
					case'O':
						setconsoleclr(9, m);
						drawRook(sr + ri, sc + ri);
						break;
					case'h':
						setconsoleclr(4, m);
						drawBishop(sr + ri, sc + ri);
						break;
					case'H':
						setconsoleclr(9, m);
						drawBishop(sr + ri, sc + ri);
						break;
					case't':
						setconsoleclr(4, m);
						drawKnight(sr + ri, sc + ri);
						break;
					case'T':
						setconsoleclr(9, m);
						drawKnight(sr + ri, sc + ri);
						break;
					case'a':
						setconsoleclr(4, m);
						drawPawn(sr + ri, sc + ri);
						break;
					case'A':
						setconsoleclr(9, m);
						drawPawn(sr + ri, sc + ri);
						break;
					case'c':
						setconsoleclr(4, m);
						drawLance(sr + ri, sc + ri);
						break;
					case'C':
						setconsoleclr(9, m);
						drawLance(sr + ri, sc + ri);
						break;
					case'i':
						setconsoleclr(4, m);
						drawSilverGen(sr + ri, sc + ri);
						break;
					case'I':
						setconsoleclr(9, m);
						drawSilverGen(sr + ri, sc + ri);
						break;
					default:
						break;
					}
					//cout << B[r][c];
				}
				else
					cout << " ";
			}
		}
	}
}
void drawBox3(int sr, int sc, int brows, int bcols, int col, char**& B, int r, int c, int m)
{
	for (int ri = 0; ri < brows; ri++)
	{
		for (int ci = 0; ci < bcols; ci++)
		{
			if (ri == 0 || ci == 0 || ri == brows - 1 || ci == bcols - 1)
			{
				SetClr(2);
			}
			else
			{
				SetClr(col);
			}
			gotoRowCol(sr + ri, sc + ci);
			if (ri != brows / 2 || ci != bcols / 2)
				cout << char(-37);
		}
	}
	for (int ri = 0; ri < brows; ri++)
	{
		for (int ci = 0; ci < bcols; ci++)
		{
			if (ri == 0 || ci == 0 || ri == brows - 1 || ci == bcols - 1)
			{
				SetClr(2);
			}
			else
			{
				SetClr(col);
			}

			if (ri == brows / 2 && ci == bcols / 2)
			{
				gotoRowCol(sr + ri, sc + ri);
				setconsoleclr(12, m);
				if (B[r][c] != '-')
				{
					switch (B[r][c])
					{
					case'r':
						setconsoleclr(15, m);
						drawRook(sr + ri, sc + ri);
						break;
					case'R':
						setconsoleclr(0, m);
						drawRook(sr + ri, sc + ri);
						break;
					case'b':
						setconsoleclr(15, m);
						drawBishop(sr + ri, sc + ri);
						break;
					case'B':
						setconsoleclr(0, m);
						drawBishop(sr + ri, sc + ri);
						break;
					case'k':
						setconsoleclr(15, m);
						drawKing(sr + ri, sc + ri);
						break;
					case'K':
						setconsoleclr(0, m);
						drawKing(sr + ri, sc + ri);
						break;
					case'n':
						setconsoleclr(15, m);
						drawKnight(sr + ri, sc + ri);
						break;
					case'N':
						setconsoleclr(0, m);
						drawKnight(sr + ri, sc + ri);
						break;
					case'p':
						setconsoleclr(15, m);
						drawPawn(sr + ri, sc + ri);
						break;
					case'P':
						setconsoleclr(0, m);
						drawPawn(sr + ri, sc + ri);
						break;
					case'l':
						setconsoleclr(15, m);
						drawLance(sr + ri, sc + ri);
						break;
					case'L':
						setconsoleclr(0, m);
						drawLance(sr + ri, sc + ri);
						break;
					case's':
						setconsoleclr(15, m);
						drawSilverGen(sr + ri, sc + ri);
						break;
					case'S':
						setconsoleclr(0, m);
						drawSilverGen(sr + ri, sc + ri);
						break;
					case'g':
						setconsoleclr(15, m);
						drawGoldGen(sr + ri, sc + ri);
						break;
					case'G':
						setconsoleclr(0, m);
						drawGoldGen(sr + ri, sc + ri);
						break;
					case'o':
						setconsoleclr(4, m);
						drawRook(sr + ri, sc + ri);
						break;
					case'O':
						setconsoleclr(9, m);
						drawRook(sr + ri, sc + ri);
						break;
					case'h':
						setconsoleclr(4, m);
						drawBishop(sr + ri, sc + ri);
						break;
					case'H':
						setconsoleclr(9, m);
						drawBishop(sr + ri, sc + ri);
						break;
					case't':
						setconsoleclr(4, m);
						drawKnight(sr + ri, sc + ri);
						break;
					case'T':
						setconsoleclr(9, m);
						drawKnight(sr + ri, sc + ri);
						break;
					case'a':
						setconsoleclr(4, m);
						drawPawn(sr + ri, sc + ri);
						break;
					case'A':
						setconsoleclr(9, m);
						drawPawn(sr + ri, sc + ri);
						break;
					case'c':
						setconsoleclr(4, m);
						drawLance(sr + ri, sc + ri);
						break;
					case'C':
						setconsoleclr(9, m);
						drawLance(sr + ri, sc + ri);
						break;
					case'i':
						setconsoleclr(4, m);
						drawSilverGen(sr + ri, sc + ri);
						break;
					case'I':
						setconsoleclr(9, m);
						drawSilverGen(sr + ri, sc + ri);
						break;
					default:
						break;
					}
					//cout << B[r][c];
				}
				else
					cout << " ";
			}

		}
	}
}
void printBoard(int dim, int brows, int bcols, char**& B, bool** Hboard, Position Sc)
{
	//system("cls");
	bool flip = true;
	for (int ri = 0; ri < dim; ri++)
	{
		for (int ci = 0; ci < dim; ci++)
		{


			if ((ri + ci) % 2 == 0)
			{
				if (ri == Sc.ri && ci == Sc.ci)
				{
					drawBox2(ri * brows, ci * bcols, brows, bcols, 7, B, ri, ci, 7);
				}
				else if (Hboard[ri][ci] == 0)
				{
					drawBox(ri * brows, ci * bcols, brows, bcols, 7, B, ri, ci, 7);
				}
				else if (Hboard[ri][ci] == 1)
				{
					drawBox3(ri * brows, ci * bcols, brows, bcols, 7, B, ri, ci, 7);
				}

			}

			else
			{
				if (ri == Sc.ri && ci == Sc.ci)
				{
					drawBox2(ri * brows, ci * bcols, brows, bcols, 8, B, ri, ci, 8);
				}
				else if (Hboard[ri][ci] == 0)
				{
					drawBox(ri * brows, ci * bcols, brows, bcols, 8, B, ri, ci, 8);
				}
				else if (Hboard[ri][ci] == 1)
				{
					drawBox3(ri * brows, ci * bcols, brows, bcols, 8, B, ri, ci, 8);
				}
			}
		}
	}
}
void printBoard1(int dim, int brows, int bcols, char**& B, bool** Hboard, Position Sc)
{
	//system("cls");
	bool flip = true;
	for (int ri = 0; ri < dim; ri++)
	{
		for (int ci = 0; ci < dim; ci++)
		{
			if ((ri + ci) % 2 == 0)
			{
				drawBox(ri * brows, ci * bcols, brows, bcols, 7, B, ri, ci, 7);

			}
			else
			{
				drawBox(ri * brows, ci * bcols, brows, bcols, 8, B, ri, ci, 8);

			}
		}
	}
}
Position findKing(char** B, int dim, int turn)
{
	Position Dc;
	char sym;
	if (turn == WHITE)
		sym = 'k';
	else
		sym = 'K';
	for (int ri = 0; ri < dim; ri++)
	{
		for (int ci = 0; ci < dim; ci++)
		{
			if ((B[ri][ci] == sym) && IsMyPlace(sym, turn))
			{
				Dc.ri = ri, Dc.ci = ci;
				return Dc;
			}
		}
	}
}
bool check(char** B, int dim, int turn)
{
	turnChange(turn);
	Position Dc = findKing(B, dim, turn);
	turnChange(turn);
	Position Sc;
	for (int ri = 0; ri < dim; ri++)
	{
		for (int ci = 0; ci < dim; ci++)
		{
			Sc.ri = ri, Sc.ci = ci;
			if (IsValidSc(B, dim, Sc, turn) && isLegalMove(B, Sc, Dc, dim, turn))
				return true;
		}
	}
	return false;
}
bool selfCheck(char** B, int dim, int turn)
{
	turnChange(turn);
	return check(B, dim, turn);
}
void checkMsg(string PName[], int turn)
{
	turnChange(turn);
	cout << endl;
	cout << endl << endl << endl << endl;
	cout << PName[turn] << " IS IN CHECK!!! " << endl;
}
void saveLoad(char** B, int dim, int Y1[], int Z1[])
{
	ofstream Rdr("Save.txt");
	Rdr << 9 << endl;
	for (int ri = 0; ri < dim; ri++)
	{
		for (int ci = 0; ci < dim; ci++)
		{
			Rdr << B[ri][ci];
		}
		Rdr << endl;
	}
	ofstream y1("Save2.txt");
	y1 << 7 << endl;
	for (int ri = 0; ri < 7; ri++)
	{
		y1 << Y1[ri] << endl;
	}
	ofstream z1("Save3.txt");
	z1 << 7 << endl;
	for (int ri = 0; ri < dim; ri++)
	{
		z1 << Z1[ri] << endl;
	}
}
void fakeUpdateBoard(char**& F, char** B, int dim, Position Sc, Position Dc)
{
	F = new char* [dim];
	for (int ri = 0; ri < dim; ri++)
	{
		F[ri] = new char[dim];
	}
	for (int ri = 0; ri < dim; ri++)
	{
		for (int ci = 0; ci < dim; ci++)
			F[ri][ci] = B[ri][ci];
	}
	char p = F[Sc.ri][Sc.ci];
	F[Dc.ri][Dc.ci] = p;
	F[Sc.ri][Sc.ci] = '-';
}
void promotion(char**& B, int turn, int dim, Position Sc, Position Dc, bool isplace)
{
	if (isplace == false)
	{
		char sym = B[Sc.ri][Sc.ci];
		int q;
		if (turn == WHITE)
		{
			if ((sym == 'p' || sym == 'n' || sym == 'l') && (Dc.ri == 8))
			{
				switch (sym)
				{
				case 'p':
					B[Sc.ri][Sc.ci] = 'a';
					break;
				case 'l':
					B[Sc.ri][Sc.ci] = 'c';
					break;
				case 'n':
					B[Sc.ri][Sc.ci] = 't';
					break;
				default:
					break;
				}
			}
			else if (((Dc.ri > 5 && Dc.ri < 9) || Sc.ri == 6) && (sym != 'a') && (sym != 'c') && (sym != 't') && (sym != 'i') && (sym != 'h') && (sym != 'o'))
			{
				cout << "Do you want to promote the piece?If yes enter 1." << endl;
				cin >> q;
				if (q == 1)
				{
					switch (sym)
					{
					case 'p':
						B[Sc.ri][Sc.ci] = 'a';
						break;
					case 'l':
						B[Sc.ri][Sc.ci] = 'c';
						break;
					case 's':
						B[Sc.ri][Sc.ci] = 'i';
						break;
					case 'n':
						B[Sc.ri][Sc.ci] = 't';
						break;
					case 'b':
						B[Sc.ri][Sc.ci] = 'h';
						break;
					case 'r':
						B[Sc.ri][Sc.ci] = 'o';
						break;
					default:
						break;
					}
				}
			}
		}
		else
		{
			if ((sym == 'P' || sym == 'N' || sym == 'L') && (Dc.ri == 0))
			{
				switch (sym)
				{
				case 'P':
					B[Sc.ri][Sc.ci] = 'A';
					break;
				case 'L':
					B[Sc.ri][Sc.ci] = 'C';
					break;
				case 'N':
					B[Sc.ri][Sc.ci] = 'T';
					break;
				default:
					break;
				}
			}
			else if ((Dc.ri > -1 && Dc.ri < 3 || (Sc.ri == 2)) && (sym != 'A') && (sym != 'C') && (sym != 'T') && (sym != 'I') && (sym != 'H') && (sym != 'O'))
			{
				cout << "Do you want to promote the piece?If yes enter 1." << endl;
				cin >> q;
				if (q == 1)
				{
					switch (sym)
					{
					case 'P':
						B[Sc.ri][Sc.ci] = 'A';
						break;
					case 'L':
						B[Sc.ri][Sc.ci] = 'C';
						break;
					case 'S':
						B[Sc.ri][Sc.ci] = 'I';
						break;
					case 'N':
						B[Sc.ri][Sc.ci] = 'T';
						break;
					case 'B':
						B[Sc.ri][Sc.ci] = 'H';
						break;
					case 'R':
						B[Sc.ri][Sc.ci] = 'O';
						break;
					default:
						break;
					}
				}
			}
		}
	}

}
void undo2(char*** U, char**& B, int dim, int& var)
{
	if (var >= 1)
	{
		var--;
		for (int ri = 0; ri < dim; ri++)
		{
			for (int ci = 0; ci < dim; ci++)
			{
				B[ri][ci] = U[var][ri][ci];
			}
		}
	}
}
void drawBoxCol(int sr, int sc, int brows, int bcols, int col, char Y[], int r, int c, int m, int Y1[])
{

	for (int ri = 0; ri < brows; ri++)
	{
		for (int ci = 0; ci < bcols; ci++)
		{
			SetClr(col);
			gotoRowCol(sr + ri, sc + ci);
			if (ri != brows / 2 || ci != bcols / 2)
				cout << char(-37);

		}
	}
	for (int ri = 0; ri < brows; ri++)
	{
		for (int ci = 0; ci < bcols; ci++)
		{
			SetClr(col);
			if (ri == brows / 2 && ci == bcols / 2)
			{
				gotoRowCol(sr + ri, sc + ri);
				setconsoleclr(12, m);
				if (Y[r] != '-')
				{
					switch (Y[r])
					{
					case'r':
						setconsoleclr(15, m);
						drawRook(sr + ri, sc + ri);
						break;
					case'R':
						setconsoleclr(0, m);
						drawRook(sr + ri, sc + ri);
						break;
					case'b':
						setconsoleclr(15, m);
						drawBishop(sr + ri, sc + ri);
						break;
					case'B':
						setconsoleclr(0, m);
						drawBishop(sr + ri, sc + ri);
						break;
					case'k':
						setconsoleclr(15, m);
						drawKing(sr + ri, sc + ri);
						break;
					case'K':
						setconsoleclr(0, m);
						drawKing(sr + ri, sc + ri);
						break;
					case'n':
						setconsoleclr(15, m);
						drawKnight(sr + ri, sc + ri);
						break;
					case'N':
						setconsoleclr(0, m);
						drawKnight(sr + ri, sc + ri);
						break;
					case'p':
						setconsoleclr(15, m);
						drawPawn(sr + ri, sc + ri);
						break;
					case'P':
						setconsoleclr(0, m);
						drawPawn(sr + ri, sc + ri);
						break;
					case'l':
						setconsoleclr(15, m);
						drawLance(sr + ri, sc + ri);
						break;
					case'L':
						setconsoleclr(0, m);
						drawLance(sr + ri, sc + ri);
						break;
					case's':
						setconsoleclr(15, m);
						drawSilverGen(sr + ri, sc + ri);
						break;
					case'S':
						setconsoleclr(0, m);
						drawSilverGen(sr + ri, sc + ri);
						break;
					case'g':
						setconsoleclr(15, m);
						drawGoldGen(sr + ri, sc + ri);
						break;
					case'G':
						setconsoleclr(0, m);
						drawGoldGen(sr + ri, sc + ri);
						break;
					default:
						break;
					}
					//cout << B[r][c];
				}
				else
					cout << " ";
			}

		}
	}
	int i = 0;
	for (int ri = 0; ri < brows; ri++)
	{
		for (int ci = 0; ci < bcols; ci++)
		{
			setconsoleclr(4, m);
			if (ri == brows - 2 && ci == bcols - 2)
			{
				cout << Y1[r];
			}
		}
	}
}
void makeColumn1(int brows, int bcols, char Y[], char Z[], int Y1[], int Z1[])
{
	int x = 10, y = 35;
	int ci = 7;
	for (int ri = 0; ri < 7; ri++)
	{
		drawBoxCol(ri * brows + x, ci * bcols + y, brows, bcols, 7, Y, ri, ci, 7, Y1);
	}
	int y1 = 50;
	for (int ri = 0; ri < 7; ri++)
	{
		drawBoxCol(ri * brows + x, ci * bcols + y1, brows, bcols, 8, Z, ri, ci, 8, Z1);
	}
}
char isCapturing(char** B, Position Dc, int turn)
{
	char sym1;
	sym1 = B[Dc.ri][Dc.ci];
	switch (B[Dc.ri][Dc.ci])
	{
	case'o':
		sym1 = 'r';
		break;
	case'O':
		sym1 = 'R';
		break;
	case'h':
		sym1 = 'b';
		break;
	case'H':
		sym1 = 'B';
		break;
	case't':
		sym1 = 'n';
		break;
	case'T':
		sym1 = 'N';
		break;
	case'a':
		sym1 = 'p';
		break;
	case'A':
		sym1 = 'P';
		break;
	case'c':
		sym1 = 'l';
		break;
	case'C':
		sym1 = 'L';
		break;
	case'i':
		sym1 = 's';
		break;
	case'I':
		sym1 = 'S';
		break;
	default:
		break;
	}
	//char sym1 = B[Dc.ri][Dc.ci];
	turnChange(turn);
	if (IsMyPlace(sym1, turn))
	{
		return sym1;
	}
}
void capturing(char** B, Position Dc, int turn, char Y[], char Z[], int Y1[], int Z1[])
{
	char sym = isCapturing(B, Dc, turn);
	for (int i = 0; i < 7; i++)
	{
		if (sym == Y[i])
		{
			Y1[i]++;
		}
		if (sym == Z[i])
		{
			Z1[i]++;
		}
	}
}
void undoBoard(char**& B, char array[100][9][9], int& arraySize, int& turn, int cap_count1[7], int cap_count2[7], int capsave1[][7], int capsave2[][7], int& save1size, int& save2size,
	char Y[], char Z[], int Z1[7], int Y1[7], Position Sc, bool** Hb)
{
	int x = arraySize - 1;
	for (int ri = 0; ri < 9; ri++)
	{
		for (int ci = 0; ci < 9; ci++)
		{
			B[ri][ci] = array[x][ri][ci];
			array[x][ri][ci] = ' ';
		}
	}
	arraySize -= 1;


	//turn = (turn + 1) % 2;
	//DrawBoard(9, 9, 9, B, cap_count1, cap_count2);
	printBoard1(9, 9, 9, B, Hb, Sc);
	makeColumn1(9, 9, Y, Z, Y1, Z1);
}
void Undoupdate(char**& B, char undo[150][9][9], int turn, int dim, int& u)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			undo[u][i][j] = B[i][j];
		}
	}
	u += 1;
	//turnChange(turn);
}
void SelectPosition(char** B, Position& Sc, Position& Dc, char& sym, int turn, int dim, int** bmap
	, int Z1[7], int Y1[7], char undo[150][9][9], int& u, int capsave1[][7],
	int capsave2[][7], int& save1size, int& save2size, bool& isUndo, bool& isPlace, char Y[], char Z[], int size, bool** Hb)
{
	sym = 0;
	char sym2 = 0;
	isPlace = false;
	isUndo = false;
	int choice;
	if (turn == 0)
	{
		cout << "Enter 1 to undo. " << endl;
		cin >> choice;
		if (choice == 1)
		{
			isUndo = true;
			u -= 1;
			undoBoard(B, undo, u, turn, Z1, Y1, capsave1, capsave2, save1size, save2size, Y, Z, Z1, Y1, Sc, Hb);
			turnChange(turn);                 //cancommit
			//SetClr(15);
			cout << "The state is : " << u;
		}
		else
		{
			int index{};
			do
			{
				char s{};
				int x{}, y{};
				cout << endl << endl << endl << endl;
				cout << "Selection Position" << endl;
				getRowColbyLeftClick(x, y);
				if (x >= 0 && x <= 81 && y >= 0 && y <= 81)
				{
					(Sc.ri) = x / 9;
					(Sc.ci) = y / 9;
					sym = B[Sc.ri][Sc.ci];
				}
				else if (x >= 10 && x < 73 && y >= 98 && y < 107)
				{
					index = ((x - 10) / 9);
					if (Y1[index] != 0)
					{
						Y1[index]--;
						isPlace = true;
					}
					if (isPlace == true)
						break;
				}

			} while (isWhite(sym) == false);
			sym = Y[index];
		}

	}
	if (turn == 1)
	{
		cout << "Enter 1 to undo. " << endl;
		cin >> choice;
		if (choice == 1)
		{

			isUndo = true;
			u -= 1;
			undoBoard(B, undo, u, turn, Z1, Y1, capsave1, capsave2, save1size, save2size, Y, Z, Z1, Y1, Sc, Hb);
			//SetClr(15);
			cout << "The state is : " << u;

		}
		else
		{
			int index{};
			do
			{
				char s{};
				int x{}, y{};
				cout << endl << endl << endl << endl;
				cout << "Selection Position" << endl;
				getRowColbyLeftClick(x, y);
				if (x >= 0 && x <= 81 && y >= 0 && y <= 81)
				{
					(Sc.ri) = x / 9;
					(Sc.ci) = y / 9;
					sym = B[Sc.ri][Sc.ci];
				}
				else if (x >= 10 && x < 73 && y >= 113 && y < 122)
				{

					index = ((x - 10) / 9);
					if (Z1[index] != 0)
					{
						Z1[index]--;
						isPlace = true;
					}
					if (isPlace == true)
						break;
				}

			} while (isBlack(sym) == false);
			sym = Z[index];
		}

	}
}
void selectdest(char** B, Position& Dc, char sym, int turn, bool isPlace)
{
	char sym2 = 0;
	if (turn == 0)
	{
		if (isPlace == false)
		{
			do
			{
				char s{};
				int y{}, x{};
				cout << endl << endl << endl << endl;
				cout << "Placement Position" << endl;
				getRowColbyLeftClick(x, y);

				(Dc.ri) = x / 9;
				(Dc.ci) = y / 9;
				sym2 = B[Dc.ri][Dc.ci];
			} while (isWhite(sym2) == true);
		}
		if (isPlace == true)
		{
			do
			{
				char s{};
				int y{}, x{};
				cout << endl << endl << endl << endl;
				cout << "Placeemnt Position" << endl;
				getRowColbyLeftClick(x, y);

				(Dc.ri) = x / 9;
				(Dc.ci) = y / 9;
				sym2 = B[Dc.ri][Dc.ci];
			} while (B[Dc.ri][Dc.ci] != '-');
		}
	}
	if (turn == 1)
	{
		if (isPlace == false)
		{
			do
			{
				char s{};
				int y{}, x{};
				cout << endl << endl << endl << endl;
				cout << "Placement Position" << endl;
				getRowColbyLeftClick(x, y);
				(Dc.ri) = x / 9;
				(Dc.ci) = y / 9;
				sym2 = B[Dc.ri][Dc.ci];
			} while (isBlack(sym2) == true);
		}
		if (isPlace == true)
		{
			do
			{
				char s{};
				int y{}, x{};
				cout << endl << endl << endl << endl;
				cout << "Placement Position" << endl;
				getRowColbyLeftClick(x, y);
				(Dc.ri) = x / 9;
				(Dc.ci) = y / 9;
				sym2 = B[Dc.ri][Dc.ci];
			} while (B[Dc.ri][Dc.ci] != '-');
		}
	}
}
//bool checkMate(char** B, int Turn, int Dim, char** Nakli)
//{
// char** Farig = new char* [500]; int Farig_size = 0;
// for (int i = 0; 500 > i; i++)
// {
// Farig[i] = new char[50];
// for (int j = 0; Dim > j; j++)
// {
// Farig[i][j] = '-';
// }
// }
// int T = (Turn + 1) % 2;
// Position S;
// Position D;
// if (check(B, Dim,Turn))
// {
// for (int i = 0; Dim > i; i++)
// {
// for (int j = 0; Dim > j; j++)
// {
// S.ri = i; S.ci = j;
// if (IsValidSc(B, Dim,S, T))
// {
// for (int k = 0; Dim > k; k++)
// {
// for (int l = 0; Dim > l; l++)
// {
// D.ri = k; D.ci = l;
// if ((IsValidDc(B, Dim, D, T)) && isLegalMove(B, S, D,Dim, T))
// {
// //copy1to2(B, Nakli);
// //UBoard(S, D, Nakli, Farig, i);
// if (!check(Nakli, Turn, Dim))
// return false;
// }
// }
// }
// }
// }
// }
// {
// gotoRowCol(9 * 3, 15 * 9);
// cout << "CHECKMATE    ";
// if (Turn == 1)
// cout << "GREEN ";
// else
// cout << "RED ";
// cout << "WON  GAME";
// exit(1);
// return true;
// }
// }
// return false;
//}
bool Checkmate(char** Q, char** B, int dim, int turn, Position Sc, Position Dc)
{
	Q = new char* [dim];
	for (int ri = 0; ri < dim; ri++)
	{
		Q[ri] = new char[dim];
	}
	for (int ri = 0; ri < dim; ri++)
	{
		for (int ci = 0; ci < dim; ci++)
			Q[ri][ci] = B[ri][ci];
	}
	//fakeUpdateBoard(Q, B, dim, Sc, Dc);
	//turnChange(turn);
	Sc = findKing(Q, dim, turn);
	//turnChange(turn);

	for (int ri = 0; ri < dim; ri++)
	{
		for (int ci = 0; ci < dim; ci++)
		{
			Dc.ri = ri, Dc.ci = ci;
			if (!check(Q, dim, turn) && isLegalMove(Q, Sc, Dc, dim, turn))
			{
				return false;
			}
		}
	}
	return true;
}
void CheckmateMsg(string PName[], int turn)
{
	turnChange(turn);
	cout << endl;
	cout << endl << endl << endl << endl;
	cout << PName[turn] << " IS IN CHECKMATE!!! " << endl;
}
bool isWin(char** B, int dim)
{
	bool knfound = false, KNfounnd = false;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (B[i][j] == 'k')
				knfound = true;
			if (B[i][j] == 'K')
				KNfounnd = true;
		}
	}
	if (knfound == false || KNfounnd == false)
	{
		system("cls");
		return true;
	}
	return false;
}


int main()
{
	const int d = 7;
	int dim, n, turn, size = 9;
	int var = 0;
	int u = 0;
	char Y[d], Z[d];
	int Y1[d]{}, Z1[d]{};
	char** B;
	char** F; char** Q{};
	char U[150][9][9];
	bool** Hb{};
	int z = 0;
	char sym;
	char S;
	bool isUndo = false, isplace = false;
	int capsave1[100][7]{}, capsave2[100][7];
	int save1size{}, save2size{};
	char undo[180][9][9]{};
	int** bmap{};
	string PNames[2];
	Position Sc{};
	Position Dc{};
	init(B, dim, PNames, turn, Y, Z, Y1, Z1);
	printBoard1(dim, size, size, B, Hb, Sc);
	makeColumn1(size, size, Y, Z, Y1, Z1);
	if (isUndo == false)
	{
		Undoupdate(B, undo, turn, dim, z);
	}

	while (true)
	{
		cout << endl << endl << endl;
		cout << endl << endl << endl << endl;
		turnMsg(PNames, turn);
		/*if (Checkmate(Q, B, dim, turn, Sc, Dc))
		{
			CheckmateMsg(PNames, turn);
		}*/
		do {
			do {

				SelectPosition(B, Sc, Dc, sym, turn, dim, bmap, Z1, Y1, undo, z, capsave1, capsave2, save1size, save2size, isUndo, isplace, Y, Z, size, Hb);
				cout << endl;
				if (isplace == false)
				{
					compHighlight(B, Sc, dim, turn, Hb);
					printBoard(dim, size, size, B, Hb, Sc);
					makeColumn1(size, size, Y, Z, Y1, Z1);
				}
				/*if (Checkmate(Q, B, dim, turn, Sc, Dc))
				{
					CheckmateMsg(PNames, turn);
				}*/
				selectdest(B, Dc, sym, turn, isplace);
				printBoard1(dim, size, size, B, Hb, Sc);
				makeColumn1(size, size, Y, Z, Y1, Z1);
			} while (!isLegalMove(B, Sc, Dc, dim, turn));
			fakeUpdateBoard(F, B, dim, Sc, Dc);
		} while (selfCheck(F, dim, turn));
		promotion(B, turn, dim, Sc, Dc, isplace);
		capturing(B, Dc, turn, Y, Z, Y1, Z1);
		updateBoard(B, Sc, Dc, isplace, sym);
		makeColumn1(size, size, Y, Z, Y1, Z1);
		saveLoad(B, dim, Y1, Z1);
		printBoard1(dim, size, size, B, Hb, Sc);
		if (Checkmate(Q, B, dim, turn, Sc, Dc))
		{
			CheckmateMsg(PNames, turn);
		}
		if (check(B, dim, turn))
		{
			checkMsg(PNames, turn);
		}
		if (isUndo == false)
		{
			Undoupdate(B, undo, turn, dim, z);
		}
		if (isWin(B, dim))
		{
			cout << "GAME OVER!!!" << endl;
			exit(0);
		}
		turnChange(turn);
	}


}