// DigiToWords6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include "atlstr.h"
#include "DigiToWordsClass.h"
#include "DigiToWordsClassRus.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
  {
//  CDigiToWords DigiToWords;   //english version
  CDigiToWordsRus DigiToWords;  //russian version
  wchar_t wcYesNo;
  CString sConvertedStr;
  int nInputDigi(0);
  char buf[255];

  CString sTitle      ("��������� ��� ����������� �������� �������� � � ��������� �������������.\n");
  CString sInputVal   ("������� ����� (�������� �� 0 �� 9999): ");
  CString sConvDECstr ("���������������� ������ � ���������� �������: \t");
  CString sConvOCTstr ("���������������� ������ � ������������ �������: \t");
  CString sRepeat     ("��������� (y/n)");

  CharToOem (sTitle.GetString (), buf);
  wcout << buf << endl;
  do
    {
    CharToOem (sInputVal, buf);
    wcout << buf;
    wcin >> nInputDigi;

    sConvertedStr = DigiToWords.Convert (nInputDigi, DEC);
    CharToOem (sConvDECstr.GetString (), buf);
    wcout << buf;
    CharToOem (sConvertedStr, buf);
    wcout << buf << endl;

    DigiToWords.Reset ();
    sConvertedStr = DigiToWords.Convert (nInputDigi, OCT);
    CharToOem (sConvOCTstr.GetString (), buf);
    wcout << buf;
    CharToOem (sConvertedStr.GetString (), buf);
    wcout << buf << endl;
    DigiToWords.Reset ();

    CharToOem (sRepeat, buf);
    wcout << buf;
    wcin >> wcYesNo;
    } while (wcYesNo == 'y');
  return 0;
  }

