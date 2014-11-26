#include "stdafx.h"
#include "DataTransform.h"


DataTransform::DataTransform(){

	g_byNUM0 = gcnew array<BYTE>{ 7, 1, 2, 4, 6, 5, 3, 1 };
	g_byNUM1 = gcnew array<BYTE>{ 2, 2, 6 };
	g_byNUM2 = gcnew array<BYTE>{ 6, 1, 2, 4, 3, 5, 6 };
	g_byNUM3 = gcnew array<BYTE>{ 7, 1, 2, 4, 3, 4, 6, 5 };
	g_byNUM4 = gcnew array<BYTE>{ 6, 1, 3, 4, 2, 4, 6 };
	g_byNUM5 = gcnew array<BYTE>{ 6, 2, 1, 3, 4, 6, 5 };
	g_byNUM6 = gcnew array<BYTE>{ 7, 2, 1, 3, 4, 6, 5, 3 };
	g_byNUM7 = gcnew array<BYTE>{ 3, 1, 2, 6 };
	g_byNUM8 = gcnew array<BYTE>{ 9, 1, 2, 4, 6, 5, 3, 1, 3, 4 };
	g_byNUM9 = gcnew array<BYTE>{ 7, 4, 2, 1, 3, 4, 6, 5 };
	g_byNUM09 = gcnew array<cli::array<BYTE>^>{ g_byNUM0, g_byNUM1, g_byNUM2, 
		g_byNUM3, g_byNUM4, g_byNUM5, g_byNUM6, g_byNUM7, g_byNUM8, g_byNUM9 };

	g_byORG0 = gcnew array<BYTE>{0, 0};
	g_byORG1 = gcnew array<BYTE>{6, 0};
	g_byORG2 = gcnew array<BYTE>{0, 6};
	g_byORG3 = gcnew array<BYTE>{6, 6};
	g_byORG4 = gcnew array<BYTE>{0, 12};
	g_byORG5 = gcnew array<BYTE>{6, 12};
	g_byORG = gcnew array<cli::array<BYTE>^>{ g_byORG0, g_byORG1, g_byORG2, 
		g_byORG3, g_byORG4, g_byORG5};
}

Byte* DataTransform::getImageData(String^ strData){

				int nLength = strData->Length;
				LPBYTE lpbyBmpData = (LPBYTE)malloc(470);
				array<BYTE>^ byInput = gcnew array<BYTE>(nLength);
				array<WCHAR>^ chData = strData->ToCharArray();
				
				for(int i = 0; i < nLength; i ++){
					byInput[i] = (BYTE)(chData[i] - 0x30);
				}
				for(int i = 0; i < 470; i ++){
					*(lpbyBmpData + i) = (BYTE)0xff;
				}

				// λͼ�ļ������ͣ�����ΪBM
			lpbyBmpData[0x00] = 0x42;		// B
			lpbyBmpData[0x01] = 0x4D;		// M

			// λͼ�ļ��Ĵ�С�����ֽ�Ϊ��λ
			lpbyBmpData[0x02] = 0xD6;
			lpbyBmpData[0x03] = 0x01;
			//��4��ͼƬ�ϳ���һ��4 �� 470
//			lpbyBmpData[0x02] = 0x58;
//			lpbyBmpData[0x03] = 0x07;
			//
			lpbyBmpData[0x04] = 0x00;
			lpbyBmpData[0x05] = 0x00;

			// λͼ�ļ������֣�����Ϊ0
			lpbyBmpData[0x06] = 0x00;
			lpbyBmpData[0x07] = 0x00;
			lpbyBmpData[0x08] = 0x00;
			lpbyBmpData[0x09] = 0x00;

			// λͼ���ݵ���ʼλ�ã��������λͼ
			lpbyBmpData[0x0A] = 0x3E;
			lpbyBmpData[0x0B] = 0x00;
			lpbyBmpData[0x0C] = 0x00;
			lpbyBmpData[0x0D] = 0x00;

			// λͼ��Ϣͷ�ĳ���
			lpbyBmpData[0x0E] = 0x28;
			lpbyBmpData[0x0F] = 0x00;
			lpbyBmpData[0x10] = 0x00;
			lpbyBmpData[0x11] = 0x00;

			// λͼ�Ŀ��
			lpbyBmpData[0x12] = 0xC0;
			lpbyBmpData[0x13] = 0x00;
			lpbyBmpData[0x14] = 0x00;
			lpbyBmpData[0x15] = 0x00;

			// λͼ�ĸ߶�
			lpbyBmpData[0x16] = 0x11;
//			lpbyBmpData[0x16] = 0x44;		//Ϊ��4��ͼƴ����һ��
			lpbyBmpData[0x17] = 0x00;
			lpbyBmpData[0x18] = 0x00;
			lpbyBmpData[0x19] = 0x00;

			// λͼ��λ����
			lpbyBmpData[0x1A] = 0x01;
			lpbyBmpData[0x1B] = 0x00;

			// ÿ�����ص�λ��
			lpbyBmpData[0x1C] = 0x01;
			lpbyBmpData[0x1D] = 0x00;

			// ѹ��˵��
			lpbyBmpData[0x1E] = 0x00;
			lpbyBmpData[0x1F] = 0x00;
			lpbyBmpData[0x20] = 0x00;
			lpbyBmpData[0x21] = 0x00;

			// ���ֽ�����ʾ��λͼ���ݵĴ�С������������4�ı���
			lpbyBmpData[0x22] = 0x98;
			lpbyBmpData[0x23] = 0x01;
			
//			lpbyBmpData[0x22] = 0x1a;
//			lpbyBmpData[0x23] = 0x07;
			
			lpbyBmpData[0x24] = 0x00;
			lpbyBmpData[0x25] = 0x00;

			// ������/�ױ�ʾ��ˮƽ�ֱ���
			lpbyBmpData[0x26] = 0x00;
			lpbyBmpData[0x27] = 0x00;
			lpbyBmpData[0x28] = 0x00;
			lpbyBmpData[0x29] = 0x00;

			// ������/�ױ�ʾ�Ĵ�ֱ�ֱ���
			lpbyBmpData[0x2A] = 0x00;
			lpbyBmpData[0x2B] = 0x00;
			lpbyBmpData[0x2C] = 0x00;
			lpbyBmpData[0x2D] = 0x00;

			// λͼʹ�õ���ɫ��
			lpbyBmpData[0x2E] = 0x00;
			lpbyBmpData[0x2F] = 0x00;
			lpbyBmpData[0x30] = 0x00;
			lpbyBmpData[0x31] = 0x00;

			// ָ����Ҫ����ɫ��
			lpbyBmpData[0x32] = 0x00;
			lpbyBmpData[0x33] = 0x00;
			lpbyBmpData[0x34] = 0x00;
			lpbyBmpData[0x35] = 0x00;

			// ��ɫ�� (��ɫ)
			lpbyBmpData[0x36] = 0x00;
			lpbyBmpData[0x37] = 0x00;
			lpbyBmpData[0x38] = 0x00;
			lpbyBmpData[0x39] = 0x00;

			// ��ɫ�� (��ɫ)
			lpbyBmpData[0x3A] = 0xFF;
			lpbyBmpData[0x3B] = 0xFF;
			lpbyBmpData[0x3C] = 0xFF;
			lpbyBmpData[0x3D] = 0x00;

			int xstart = 0;
			switch(nLength){
			case 15:
			case 16:
				xstart = 0;
				break;
				
			case 13:
			case 14:
				xstart = 12;
				break;
				
			case 11:
			case 12:
				xstart = 24;
				break;
				
			case 9:
			case 10:
				xstart = 36;
				break;
			
			case 7:
			case 8:
				xstart = 48;
				break;
				
			case 5:
			case 6:
				xstart = 60;
				break;
			
			case 3:
			case 4:
				xstart = 72;
				break;	
				
			case 1:
			case 2:
				xstart = 84;
				break;		
				
			default:
				break;
				
				
			}

			int ystart = 0;
			
			for(int i = 0; i < nLength; i ++){
				BYTE num = (BYTE)(byInput[i] & 0x0f);
				display7Seg(xstart, ystart, g_byNUM09[num], lpbyBmpData);
				xstart += 12;
			}
			return lpbyBmpData;
		}
		

void DataTransform::display7Seg (int nx, int ny, array<BYTE>^ g_byNUM09, LPBYTE lpbyBmpData)
		{
			int		z = 0;
			array<cli::array<BYTE>^>^ p = gcnew array<cli::array<BYTE>^>(6);			
			for(int i = 0; i < 6; i ++)
				p[i] = gcnew array<BYTE>(2);
			Random^	rand = gcnew Random;
			
			
			
			int x1, y1, x2 = 0, y2 = 0;

			for ( z = 0; z < 6; z++ )
			{
				BYTE random = (BYTE)(rand->Next(3));
				
				
				p[z][0] = g_byORG[z][0] + random;
				random = (BYTE)(rand->Next(3));
				p[z][1] = g_byORG[z][1] + random;
			}
			
			x1 = p[g_byNUM09[1] - 1][0];
			y1 = p[g_byNUM09[1] - 1][1];
			for ( z = 2; z <= g_byNUM09[0]; z++ )
			{
				x2 = p[g_byNUM09[z] - 1][0];
				y2 = p[g_byNUM09[z] - 1][1];
				drawLine (nx + x1, ny + y1, nx + x2, ny + y2, 0, lpbyBmpData);
/*
				if((ny + y2) < 0 ){
					Log.v("zdmatrix", "��ʾ7�δ��������n2 = " + ny + "�������y2 = " + y2);
				}
				drawLine (nx + x1, ny + y1, nx + x2, ny + y2, 0, buf);
	
				// �����߼ӿ�
				if ( x1 < 7 && x2 < 7 )
					drawLine ( nx + x1 - 1, ny + y1, nx + x2 - 1, ny + y2, 0, buf );
				else if ( x1 >= 7 && x2 >= 7 )
					drawLine ( nx + x1 + 1, ny + y1, nx + x2 + 1, ny + y2, 0, buf );
				else if ( y1 < 7 && y2 < 7 )
					drawLine ( nx + x1, ny + y1 - 1, nx + x2, ny + y2 - 1, 0, buf );
				else
					drawLine ( nx + x1, ny + y1 + 1, nx + x2, ny + y2 + 1, 0, buf );
*/	
				// ��������

				x1 = x2;
				y1 = y2;
				x2 = 0;
				y2 = 0;
			}
			
		 }

void DataTransform::drawLine(BYTE x0, BYTE y0, BYTE x1, BYTE y1, BYTE color, LPBYTE lpbyBmpData){
			Boolean steep = false;
			int deltax;
			int deltay;
			int error;
			int ystep;
			int x;
			int y;
			
			steep = Math::Abs(y1 - y0) > Math::Abs(x1 - x0);
			if ( steep )
			{
				int tmp = 0;
				tmp = x0;
				x0 = y0;
				y0 = tmp;
				
				tmp = x1;
				x1 = y1;
				y1 = tmp;
//				swap ( x0, y0 );
//				swap ( x1, y1 );
			}

			if ( x0 > x1 )
			{
				int tmp = x0;
				x0 = x1;
				x1 = tmp;
				
				tmp = y0;
				y0 = y1;
				y1 = tmp;
//				swap ( x0, x1 );
//				swap ( y0, y1 );
			}

			deltax = x1 - x0;

			deltay = Math::Abs( y1 - y0 );

			error = deltax / 2;

			y = y0;

			if ( y0 < y1 )
				ystep = 1;
			else
				ystep = -1;

			for ( x = x0; x <= x1; x ++ )
			{

				if ( steep )
					setPixel ( y, x, color, lpbyBmpData);
					
				else{
					
//					if(y < 0)
//						Log.v("zdmatrix", "�����y���ش���Ϊ��" + y);
					setPixel ( x, y, color, lpbyBmpData);
				}
				error = error - deltay;

				if ( error < 0 )
				{
					y = y + ystep;
					error = error + deltax;
				}
			}
		}

void DataTransform::setPixel(int x, int y, int color, LPBYTE lpbyBmpData){
			int gx = (0x3E + ((16 - y) * 24) + (x / 8));
			int gPixelMask = (BYTE)((0x80 >> (x % 8)));
			*(lpbyBmpData + gx) &= ~gPixelMask;
		}	