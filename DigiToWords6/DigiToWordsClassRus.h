#pragma once
#include "DigiToWordsClass.h"

class CDigiToWordsRus : public CDigiToWords
  {
  protected:
    virtual bool      AddHundred        (UINT uID);
    virtual bool      AddThousand       (UINT uID);
    virtual bool      AddThousand2      (UINT uID);
    virtual bool      AddThousand3      (UINT uID);
    virtual void      ConvertThousand  (int nSymbol);
    virtual void      ConvertHundred   (int nSymbol);
    virtual void      ConvertDicker    (int nSymbol);
    virtual void      ConvertUnit      (int nSymbol);
  };