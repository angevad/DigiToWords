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

  CString sTitle      ("Программа для конвертации цифровых значений в её текстовое представление.\n");
  CString sInputVal   ("Введите число (диапазон от 0 до 9999): ");
  CString sConvDECstr ("Конвертированная строка в тесятичной системе: \t");
  CString sConvOCTstr ("Конвертированная строка в восьмеричной системе: \t");
  CString sRepeat     ("Повторить (y/n)");

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

