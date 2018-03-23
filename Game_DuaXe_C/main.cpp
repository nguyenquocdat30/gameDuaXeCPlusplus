#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

char map[50][50];// mang 2 chieu tao game
int mang=5;
int diemso=0;
int x=28,y=19;// toa do xe Player	
int x1 = 0,y1 = 2; // toa do xe Computer Tinh~
int x2 = 4,y2 = 7;
int x3 = 3,y3 = 12;
int x4 = 0,y4 = 17;
int x5 = 9,y5 = 22;
int x6 = 10,y6 = 27;
int x7 = 7,y7 = 32;
int x8 = 1,y8 = 37;
//toa do vat pham
int x10 = 0,y10 = 18;
int x11 = 0,y11 = 23;
int a=0;// khoi tao 
//ham thay doi kich thuoc cmd 
void resizeConsole(int width,int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console,&r);
	MoveWindow(console,r.left,r.top,width,height,TRUE);
}
// ham to mau (x la ma mau )
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}
// ham dich chuyen con tro den toa do x,y
void gotoxy(int x,int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = {x-1,y-1};
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput,Cursor_an_Pos);
}
// ham xoa man hinh 
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle (STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut,Position);
}
//ham ve mau do hoa
void Picture(int x,int y,string str , int color)
{
	gotoxy(x,y);// tro den vi tri can to mau
	textcolor(color);
	cout<<str;
	textcolor(7);//tra ve mau trang binh thuong 
}

//ve map cho game 1
void VeMap1()
{
	for (int i=0;i<30;i++)
	{
		map[i][0] = ' ';
		map[i][39] = ' ';
		if(i%2==0)
			{
				map[i][9] = '|';
			    map[i][19] = '|';
			    map[i][29] = '|';
			}
		for(int j=1 ; j<39 && j != 9 && j != 19 && j != 29;j++)
		{
			map[i][j]= ' ';	
		}
		textcolor(7);
	}
}
//ve map cho game 2
void VeMap2()
{
	for (int i=0;i<30;i++)
	{
		map[i][0] = ' ';
		map[i][39] = ' ';
		if(i%2!=0)
			{
				map[i][9] = '|';
			    map[i][19] = '|';
			    map[i][29] = '|';
			}
		for(int j=1 ; j<39 && j != 9 && j != 19 && j != 29;j++)
		{
			map[i][j]= ' ';	
		}
		textcolor(7);
	}
}
//In Map Ra Console
void InMap()
{
	for (int i=0;i<30;i++)
	{
		for(int j=0;j<40;j++)
		{
			if(j==0||j==39)
			{
				textcolor(46);
				cout<<map[i][j];
				textcolor(7);
			}
			// in xe player
			else if(map[i][j]=='X'|| map[i][j]=='@' || map[i][j]=='#')
			{
				textcolor(144);
				cout<<map[i][j];
				textcolor(7);
			}
			// in xe computer
			else if(map[i][j]=='H')
			{
				textcolor(93);
				cout<<map[i][j];
				textcolor(7);
			}
			else if(map[i][j]=='$')
			{
				textcolor(14);
				cout<< map[i][j];
				textcolor(7);
			}
			// in lan` duong`
			else if(j==9 || j==19 || j==29)
			{
				cout<< map[i][j];
				map[i][j]=' ';
			}
			else
			{
				textcolor(12);
			    cout<<map[i][j];
			}
		}
		cout<<endl;
	}
}
//Ham tao loi gioi thieu Game va tac gia
void GioiThieuTacGia()
{
	gotoxy(48,2);
	ifstream FileIn ("phattrien.txt");
	while(!FileIn.eof())
	{
		char gioithieu;
		FileIn.get(gioithieu);
		Sleep(15);
		textcolor(14);
		cout<<gioithieu;
	}
	FileIn.close();
	textcolor(7);
	XoaManHinh();
	
}
void GioiThieuGame()
{
	ifstream FileIn ("GioiThieu.txt");
	resizeConsole(450,400);
	while(!FileIn.eof())
	{
		char gioithieu;
		FileIn.get(gioithieu);
		Sleep(1);
		textcolor(14);
		cout<<gioithieu;
	}
	FileIn.close();
	textcolor(7);
}

//ham huong dan cach choi 
void HuongDan()
{
	Picture(46,8,"Diem So : ",12);
	Picture(46,9,"Mang : ",12);
	Picture(46,14,"Huong Dan Choi Game : ",12);
	Picture(46,16,"Di Chuyen Bang Phim Mui Ten",12);
	Picture(46,18,"Up : Chuyen DOi",12);
	Picture(46,20,"Down : Di Xuong",12);
	Picture(46,22,"Left : Qua Trai",12);
	Picture(46,24,"Right : Qua Phai",12);
	Picture(46,25,"Reset Game : SHIFT",12);
	Picture(46,27,"Di Chuyen De Tranh Cac Chuong",12);
	Picture(46,28,"Ngai Vat",12);
	GioiThieuTacGia();
}
//ham tao Khoi  tao Xe Player
void XePlayer(int x,int y)
{
	map[x][y] = 'X';// than xe
	map[x][y-1] = '#';// ben trai than xe
	map[x][y+1] = '#';// ben phai than xe
	map[x-1][y-1] = '@';// banh xe tren ben trai
	map[x+1][y-1] = '@';// banh xe duoi ben trai
	map[x-1][y+1] = '@';// banh xe tren ben phai
	map[x+1][y+1] = '@';// banh xe duoi ben phai
}
//Ham tao Xe Computer
void XeComputer(int x,int y)
{
	map[x][y] = 'H';// than xe
	map[x][y-1] = 'H';// ben trai than xe
	map[x][y+1] = 'H';// ben phai than xe
	map[x-1][y-1] = 'H';// banh xe tren ben trai
	map[x+1][y-1] = 'H';// banh xe duoi ben trai
	map[x-1][y+1] = 'H';// banh xe tren ben phai
	map[x+1][y+1] = 'H';// banh xe duoi ben phai
}
// ham xoa xe ;
void XoaXe(int x,int y)
{
	map[x][y] = ' ';//xoa than xe
	map[x][y-1] = ' ';// xoa ben trai than xe
	map[x][y+1] = ' ';//xoa ben phai than xe
	map[x-1][y-1] = ' ';// xoa banh xe tren ben trai
	map[x+1][y-1] = ' ';//xoa banh xe duoi ben trai
	map[x-1][y+1] = ' ';// xoa banh xe tren ben phai
	map[x+1][y+1] = ' ';//xoa banh xe duoi ben phai
}
// ham tao vat pham
void VatPham(int x , int y)
{
	map[x][y] = '$';
}
// xoa vat pham
void XoaVatPham(int x,int y)
{
	map[x][y]=' ';
}
//ham khi 2 xe cham nhau
int VaCham(int x,int y)
{
	if(map[x-1][y-1]== 'H' || map[x+1][y-1]=='H' || map[x-1][y+1]=='H' ||map[x+1][y+1]=='H'||map[x][y]=='H'||map[x][y-1]=='H'||map[x][y+1]=='H')
	{
		return 1;
	}
}
// ham tang mang khi an $
int ThemMang(int x,int y)
{
	if(map[x-1][y-1]== '$' || map[x+1][y-1]=='$' || map[x-1][y+1]=='$' ||map[x+1][y+1]=='$'||map[x][y]=='$'||map[x][y-1]=='$'||map[x][y+1]=='$')
	{
		return 1;
	}
}
// ham reset xe player 
void ResetGame(int &x,int &y,int &mang)
{
	mang = mang -1;
	XoaXe(x,y);
	x=26;
	y=19;
}
// ham tang mang khi an vat pham
void TangMang(int &mang)
{
	mang =mang +1;
}
//ham di chuyen Xe
void DiChuyenXe(int &x,int &y)
{
	/*
     trai Tren Cung : 2 , 2
     trai duoi cung : 27 ,2
     phai tren cung : 2,37
    phai duoi cung : 27,37
    */ 
	if(GetAsyncKeyState(VK_LEFT))
	{
		if(y!=2)
		{
			if(VaCham(x,y)==1)
			{
				ResetGame(x,y,mang);
			}
			else if(ThemMang(x,y)==1)
			{
				TangMang(mang);
			}
			XoaXe(x,y);
	    	y--;
	    	XePlayer(x,y);
		}
	}
	else if (GetAsyncKeyState(VK_RIGHT))
	{
		if(y!=37)
		{
			if(VaCham(x,y)==1)
			{
				ResetGame(x,y,mang);
			}
			else if(ThemMang(x,y)==1)
			{
				TangMang(mang);
			}
			XoaXe(x,y);
	    	y++;
	    	XePlayer(x,y);
		}
	}
	else if(GetAsyncKeyState(VK_UP))
	{
		if(x!=1)
		{
			if(VaCham(x,y)==1)
			{
				ResetGame(x,y,mang);
			}
			else if(ThemMang(x,y)==1)
			{
				TangMang(mang);
			}
			XoaXe(x,y);
	    	x--;
	    	XePlayer(x,y);
		}
	}
	else if(GetAsyncKeyState(VK_DOWN))
	{
		if(x!=28)
		{
			if(VaCham(x,y)==1)
			{
				ResetGame(x,y,mang);
			}
			else if(ThemMang(x,y)==1)
			{
				TangMang(mang);
			}
			XoaXe(x,y);
	    	x++;
	    	XePlayer(x,y);
		}
	}
}
//ham gia tri diem so vs mang
void DiemSo(int x,int x1,int &diemso)
{
		diemso=diemso+1;
}
// xac dinh dieu kien xe chay
void DieuKienXeDiChuyen(int &x,int &y)
{
	if(x>31)
	    {
		    x= 0;
		    srand(time(0));
	    	y = 2 +rand() % 36;
	    }
}
// dieu kien xe chay thang lien tuc
void DieuKienXeDiChuyen2(int &x)
{
	if(x>31)
	    {
		    x= 0;
	    }
}
void DieuKienTangMang(int &x,int &y,int &mang)
{
	if(x>31)
	{	
		x=0;
		y = 2+rand() % 36;
	}
	else if(map[x][y]=='@'||map[x][y]=='#'||map[x][y]=='X')
	{
		TangMang(mang);
		x=0;
		y= 2+rand() %36;
	}
}
//Ham bat dau game 
void StartGame()
{
	XePlayer(x,y);
	XeComputer(x1,y1);
	XeComputer(x2,y2);
	XeComputer(x3,y3);
	XeComputer(x4,y4);
	XeComputer(x5,y5);
	XeComputer(x6,y6);
	XeComputer(x7,y7);
	XeComputer(x8,y8);
	VatPham(x10,y10);
	VatPham(x11,y11);
	InMap();
	XoaManHinh();
	DiChuyenXe(x,y);
	DiemSo(x,x1,diemso);
	Sleep(0);
}

/*
kbhit(void) : kiem tra xem nguoi dung co nhan 1 phim bat ki tren ban phim khong ??
=> lay gia tri cua no ra nho vao ham getch(); duoc khai bao boi thu vien #include <conio.h>

hoac dung ham 
GetAsyncKeyState(<Key can nhap >) co trong thu vien #include <windows.h>
vd
GetAsyncKeyState(VK_UP); // nguoi dung nhan vao phim mui ten di len
GetAsyncKeyState(VK_DOWN); // nguoi dung nhan vao phim mui ten di xuong
LEFT va RIGHT  va SHIFT va MENU (alt)


..................
lam chuong trinh ngu~ .
Cach 1 : dung ham delay co trong thu vien conio.h
Cach 2 : dung ham sleep co trong thu vien windows.h
Cu phap chung  : Sleep(int x);
x la so nguyen tuong trung cho miliseconds 
- Muon random 1 so nguyen trong doan [a,b] dung thu vien #include <ctime>
srand(time(0)); reset thoi gian 
int x = a + rand() % (b-a+1); // cong thuc' 
*/
int main ()
{
	char c= getch();
	GioiThieuGame();
	resizeConsole(700,450);
	HuongDan();	
	XoaManHinh();
	L: 
	if(GetAsyncKeyState(VK_SHIFT))// an ship de reset
	{
		ofstream Filee("DiemSo.txt",ios::app);// ghi diem vao file
		Filee<<endl<<diemso<<endl;
		mang= 5;
		diemso=0;
			goto R;
	}
	;
	D:
		gotoxy(56,8);
		printf("%5d",diemso);
		gotoxy(53,9);
		printf("%3d",mang);
	    XoaManHinh();
	    goto G;
	;
	R:
	while(true)
	{
		goto D;
		G:
		if(mang == 0)
		{		
			goto L;	
		}
		a++;
		if(a%2==0)
		{
			VeMap1();
		}
		else
		{
			VeMap2();
		}
		if(a>30)
		{
			a=0;
		}
		StartGame();
		if(VaCham(x,y)==1)
		{
			ResetGame(x,y,mang);
		}
		if(ThemMang(x,y)==1)
			{
				TangMang(mang);
			}
		XoaXe(x1,y1);
		x1++;// xe computer di chuyen 1
		DieuKienXeDiChuyen2(x1);// dieu kien de xe chay lai
		XoaXe(x2,y2);
		x2=x2+3;
		DieuKienXeDiChuyen(x2,y2);
		XoaXe(x3,y3);
		x3++;
		DieuKienXeDiChuyen2(x3);// xe chi chay thang ko random
		XoaXe(x4,y4);
		x4=x4+3;
		DieuKienXeDiChuyen2(x4);
		XoaXe(x5,y5);
		x5 = x5+3;
		DieuKienXeDiChuyen(x5,y5);
		XoaXe(x6,y6);
	    x6++;
	    DieuKienXeDiChuyen2(x6);
	    XoaXe(x7,y7);
	    x7=x7+2;
	    DieuKienXeDiChuyen(x7,y7);
	    XoaXe(x8,y8);
	    x8=x8+2;
	    DieuKienXeDiChuyen2(x8);
	    XoaVatPham(x10,y10);
	    x10++;
	    DieuKienTangMang(x10,y10,mang);
	    XoaVatPham(x11,y11);
		x11++;
		DieuKienTangMang(x11,y11,mang);
		;
	};
	system("pause");
	return 0;
}
