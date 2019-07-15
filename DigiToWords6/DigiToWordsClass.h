///CDigiToWordsClass.h
#pragma once
#include "atlstr.h"
#include <string>

const int DEC (0);
const int OCT (1);

class CDigiToWords
  {
  public:
    virtual CString&  Convert (int nVal, unsigned short unParam);
    virtual void      Reset   ();
  protected:
    virtual bool      AddDicker        (UINT uID);
    virtual bool      AddHundred       (UINT uID);
    virtual bool      AddThousand      (UINT uID);
    virtual void      ConvertThousand  (int nSymbol);
    virtual void      ConvertHundred   (int nSymbol);
    virtual void      ConvertDicker    (int nSymbol);
    virtual void      ConvertUnit      (int nSymbol);

    int       m_nDigiVal;
    CString   m_sDigiStrOrig;
    CString   m_sDigiStrConv;
    int       m_nNumOfDigi;
  };