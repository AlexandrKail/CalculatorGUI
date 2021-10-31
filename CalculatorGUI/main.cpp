#include"function.h"

//Глобальные переменные
//static CHAR str[256]{};

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_MYDIALOG), 0, (DlgProc), 0);

	return 0;
}

BOOL CALLBACK DlgProc(HWND hWnd, UINT uMsg,WPARAM wParam, LPARAM lParam)
{
	static Input inp;
	switch (uMsg)
	{
	case WM_INITDIALOG:
		inp.hEdit = GetDlgItem(hWnd, IDC_MYEDIT);
		break;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
//=====================Кнопки от 1 до 9========================================
			{
		case IDC_ONE:
			inp.setBuf('1');
			break;
		case IDC_TWO:
			inp.setBuf('2');
			break;
		case IDC_TREE:
			inp.setBuf('3');
			break;
		case IDC_FOUR:
			inp.setBuf('4');
			break;		
		case IDC_FIVE:	
			inp.setBuf('5');
			break;		
		case IDC_SIX:	
			inp.setBuf('6');
			break;		
		case IDC_SEVEN:	
			inp.setBuf('7');
			break;		
		case IDC_EIGHT:	
			inp.setBuf('8');
			break;		
		case IDC_NINE:	
			inp.setBuf('9');
			break;		
		case IDC_ZERO:	
			inp.setBuf('0');
			break;
			}
//=============================================================================
//=====================Кнопки <--, +, -, /, *, =, ',', +/-, C================== 
			{
		case IDC_BACKSPACE:
			inp.idx--;
			if (inp.idx < 0)
			{
				inp.idx = 0;
				break;
			}
			inp.input[inp.idx] = '\0';
			SendMessage(inp.hEdit, WM_SETTEXT, 0, LPARAM(inp.input));
			break;
		case IDC_PLUS:
			inp.setSign('+');
			break;
		case IDC_MINUS:
			inp.setSign('-');
			break;
		case IDC_MUL:
			inp.setSign('*');
			break;
		case IDC_DIV:
			inp.setSign('/');
			break;
		case IDC_POINT:
			if (!inp.checkPoint())
				inp.setSign(',');
			break;		   
		case IDC_SIGN:	   
			inp.doSignVal('-');
			break;
		case IDC_EQ:
			//Отправляет сообщение окну, минуя очередь
			inp.idx = SendMessage(inp.hEdit, WM_GETTEXT, 256, (LPARAM)inp.input);
			if (inp.checkInput())
				inp.idx = doColculations(inp.input);
			else
				strcpy(inp.input,"Invalid input");
			SendMessage(inp.hEdit, WM_SETTEXT, 0, LPARAM(inp.input));
			break;
		case IDC_NULL:
			inp.idx = 0;
			inp.input[inp.idx] = '\0';
			SendMessage(inp.hEdit, WM_SETTEXT, 0, LPARAM(inp.input));
			break;
			}
//=============================================================================
//=====================Кнопки x2, 2Vx===============================================
		case IDC_EXP:
			inp.setSign('^');
			break;

		case IDC_SQRT:
			inp.doSignVal('V');
			break;
//=============================================================================
		}
		break;

	case WM_CLOSE:
		EndDialog(hWnd, 0);
		return FALSE;
	}

	return FALSE;
}