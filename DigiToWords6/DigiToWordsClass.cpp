#include "stdafx.h"

#include "DigiToWordsClass.h"
//////////////////////////////////////////////////
CString& CDigiToWords::Convert (int nVal, unsigned short unParam)
  {
  CString sTmpDigi;
  if (unParam == DEC)
    m_sDigiStrOrig.Format (L"%d", nVal);
  else if (unParam == OCT)
    m_sDigiStrOrig.Format (L"%o", nVal);
  else
    {
    m_sDigiStrConv = "0";
    return m_sDigiStrConv;
    }

  m_nNumOfDigi = m_sDigiStrOrig.GetLength ();
  if (m_nNumOfDigi > 4)
    {
    m_sDigiStrConv = "0";
    return m_sDigiStrConv;
    }

  for (int n (0); ((n < m_nNumOfDigi) && !m_sDigiStrOrig.IsEmpty ()); n++)
    {
    sTmpDigi = m_sDigiStrOrig[0];
    wchar_t *pBufer = sTmpDigi.GetBuffer ();
    wchar_t nVal = _wtoi (pBufer);
    switch (m_nNumOfDigi - n)
      {
      case 4:
        ConvertThousand (nVal);
        break;
      case 3:
        ConvertHundred (nVal);
        break;
      case 2:
        {
        ConvertDicker (nVal);
        if (nVal == 1)
          n++;
        }
        break;
      case 1:
        ConvertUnit (nVal);
        break;
      }
    }
  return m_sDigiStrConv;
  }
//////////////////////////////////////////////////
bool CDigiToWords::AddDicker (UINT uID)
  {
  bool bSuccess (false);
  CString sTmpDigi;
  if (sTmpDigi.LoadStringW (uID))
    {
    m_sDigiStrConv.Append (sTmpDigi);
    bSuccess = true;
    }
  return bSuccess;
  }
//////////////////////////////////////////////////
bool CDigiToWords::AddHundred (UINT uID)
  {
  bool bSuccess (false);
  CString sTmpDigi;

  if(sTmpDigi.LoadStringW (uID))
    {
    m_sDigiStrConv.Append (sTmpDigi);
    if (sTmpDigi.LoadStringW (IDS_HUNDRED))
      {
      m_sDigiStrConv.Append (sTmpDigi);
      bSuccess = true;
      }
    else
      {
      bSuccess = false;
      sTmpDigi = "";
      }
    }

  return bSuccess;
  }
//////////////////////////////////////////////////
bool CDigiToWords::AddThousand (UINT uID)
  {
  bool bSuccess (false);
  CString sTmpDigi;

  if (sTmpDigi.LoadStringW (uID))
    {
    m_sDigiStrConv.Append (sTmpDigi);
    if (sTmpDigi.LoadStringW (IDS_THOUSAND))
      {
      m_sDigiStrConv.Append (sTmpDigi);
      bSuccess = true;
      }
    }
  return bSuccess;
  }
//////////////////////////////////////////////////
void CDigiToWords::Reset ()
  {
  m_nDigiVal     =  0;
  m_sDigiStrOrig = "";
  m_sDigiStrConv = "";
  m_nNumOfDigi   =  0;;
  }
//////////////////////////////////////////////////
void CDigiToWords::ConvertThousand (int nSymbol)
  {
  switch (nSymbol)
    {
    case 0:
      //sTmpDigi.LoadStringW (IDS_HANDRED);
      //m_sDigiStrConv.Append (sTmpDigi);
      break;
    case 1:
      AddThousand (IDS_ONE);
      break;
    case 2:
      AddThousand (IDS_TWO);
      break;
    case 3:
      AddThousand (IDS_THREE);
      break;
    case 4:
      AddThousand (IDS_FOUR);
      break;
    case 5:
      AddThousand (IDS_FIVE);
      break;
    case 6:
      AddThousand (IDS_SIX);
      break;
    case 7:
      AddThousand (IDS_SEVEN);
      break;
    case 8:
      AddThousand (IDS_EIGHTH);
      break;
    case 9:
      AddThousand (IDS_NINE);
      break;
    default:
      break;
    }
  m_sDigiStrOrig.Delete (0);
  }
//////////////////////////////////////////////////
void CDigiToWords::ConvertHundred (int nSymbol)
  {
  switch (nSymbol)
    {
    case 0:
      //sTmpDigi.LoadStringW (IDS_HANDRED);
      //m_sDigiStrConv.Append (sTmpDigi);
      break;
    case 1:
      AddHundred (IDS_ONE);
      break;
    case 2:
      AddHundred (IDS_TWO);
      break;
    case 3:
      AddHundred (IDS_THREE);
      break;
    case 4:
      AddHundred (IDS_FOUR);
      break;
    case 5:
      AddHundred (IDS_FIVE);
      break;
    case 6:
      AddHundred (IDS_SIX);
      break;
    case 7:
      AddHundred (IDS_SEVEN);
      break;
    case 8:
      AddHundred (IDS_EIGHTH);
      break;
    case 9:
      AddHundred (IDS_NINE);
      break;
    default:
      break;
    }
  m_sDigiStrOrig.Delete (0);
  }
//////////////////////////////////////////////////
void CDigiToWords::ConvertDicker (int nSymbol)
  {
  wchar_t *pBufer;
  if (nSymbol == 1)
    {
    pBufer = m_sDigiStrOrig.GetBuffer ();
    switch (_wtoi (pBufer))
      {
      case 10:
        AddDicker (IDS_TEN);
        break;
      case 11:
        AddDicker (IDS_ELEVEN);
        break;
      case 12:
        AddDicker (IDS_TWELVE);
        break;
      case 13:
        AddDicker (IDS_THIRTEEN);
        break;
      case 14:
        AddDicker (IDS_FOURTEEN);
        break;
      case 15:
        AddDicker (IDS_FIFTEEN);
        break;
      case 16:
        AddDicker (IDS_SIXTEEN);
        break;
      case 17:
        AddDicker (IDS_SEVENTEEN);
        break;
      case 18:
        AddDicker (IDS_EIGHTEEN);
        break;
      case 19:
        AddDicker (IDS_NINETEEN);
        break;
      }
    m_sDigiStrOrig.Delete (0, 2);
    }
  else
    {
    switch (nSymbol)
      {
      case 2:
        AddDicker (IDS_TWENTY);
        break;
      case 3:
        AddDicker (IDS_THIRTY);
        break;
      case 4:
        AddDicker (IDS_FORTY);
        break;
      case 5:
        AddDicker (IDS_FIFTY);
        break;
      case 6:
        AddDicker (IDS_SIXTY);
        break;
      case 7:
        AddDicker (IDS_SEVENTY);
        break;
      case 8:
        AddDicker (IDS_EIGHTY);
        break;
      case 9:
        AddDicker (IDS_NINETY);
        break;
      }
    m_sDigiStrOrig.Delete (0);
    pBufer = m_sDigiStrOrig.GetBuffer ();
    if (_wtoi (pBufer) == 0)
      m_sDigiStrOrig.Delete (0);
    }
  }
//////////////////////////////////////////////////
void CDigiToWords::ConvertUnit (int nSymbol)
  {
  switch (nSymbol)
    {
    case 0:
      AddDicker (IDS_ZERO);
      break;
    case 1:
      AddDicker (IDS_ONE);
      break;
    case 2:
      AddDicker (IDS_TWO);
      break;
    case 3:
      AddDicker (IDS_THREE);
      break;
    case 4:
      AddDicker (IDS_FOUR);
      break;
    case 5:
      AddDicker (IDS_FIVE);
      break;
    case 6:
      AddDicker (IDS_SIX);
      break;
    case 7:
      AddDicker (IDS_SEVEN);
      break;
    case 8:
      AddDicker (IDS_EIGHTH);
      break;
    case 9:
      AddDicker (IDS_NINE);
      break;
    default:
      break;
    }
  m_sDigiStrOrig.Delete (0, m_sDigiStrOrig.GetLength ());
  }
//////////////////////////////////////////////////