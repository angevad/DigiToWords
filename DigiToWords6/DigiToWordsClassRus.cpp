#include "stdafx.h"
#include "DigiToWordsClassRus.h"

//////////////////////////////////////////////////
void CDigiToWordsRus::ConvertUnit (int nSymbol)
  {
    switch (nSymbol)
    {
    case 0:
      AddDicker (IDS_ZERO2);
      break;
    case 1:
      AddDicker (IDS_ONE2);
      break;
    case 2:
      AddDicker (IDS_TWO2);
      break;
    case 3:
      AddDicker (IDS_THREE2);
      break;
    case 4:
      AddDicker (IDS_FOUR2);
      break;
    case 5:
      AddDicker (IDS_FIVE2);
      break;
    case 6:
      AddDicker (IDS_SIX2);
      break;
    case 7:
      AddDicker (IDS_SEVEN2);
      break;
    case 8:
      AddDicker (IDS_EIGHTH2);
      break;
    case 9:
      AddDicker (IDS_NINE2);
      break;
    default:
      break;
    }
  m_sDigiStrOrig.Delete (0, m_sDigiStrOrig.GetLength ());
  }
//////////////////////////////////////////////////
void CDigiToWordsRus::ConvertDicker (int nSymbol)
  {
  wchar_t *pBufer;
  if (nSymbol == 1)
    {
    pBufer = m_sDigiStrOrig.GetBuffer ();
    switch (_wtoi (pBufer))
      {
      case 10:
        AddDicker (IDS_TEN2);
        break;
      case 11:
        AddDicker (IDS_ELEVEN2);
        break;
      case 12:
        AddDicker (IDS_TWELVE2);
        break;
      case 13:
        AddDicker (IDS_THIRTEEN2);
        break;
      case 14:
        AddDicker (IDS_FOURTEEN2);
        break;
      case 15:
        AddDicker (IDS_FIFTEEN2);
        break;
      case 16:
        AddDicker (IDS_SIXTEEN2);
        break;
      case 17:
        AddDicker (IDS_SEVENTEEN2);
        break;
      case 18:
        AddDicker (IDS_EIGHTEEN2);
        break;
      case 19:
        AddDicker (IDS_NINETEEN2);
        break;
      }
    m_sDigiStrOrig.Delete (0, 2);
    }
  else
    {
    switch (nSymbol)
      {
      case 2:
        AddDicker (IDS_TWENTY2);
        break;
      case 3:
        AddDicker (IDS_THIRTY2);
        break;
      case 4:
        AddDicker (IDS_FORTY2);
        break;
      case 5:
        AddDicker (IDS_FIFTY2);
        break;
      case 6:
        AddDicker (IDS_SIXTY2);
        break;
      case 7:
        AddDicker (IDS_SEVENTY2);
        break;
      case 8:
        AddDicker (IDS_EIGHTY2);
        break;
      case 9:
        AddDicker (IDS_NINETY2);
        break;
      }
    m_sDigiStrOrig.Delete (0);
    pBufer = m_sDigiStrOrig.GetBuffer ();
    if (_wtoi (pBufer) == 0)
      m_sDigiStrOrig.Delete (0);
    }
  }
//////////////////////////////////////////////////
void CDigiToWordsRus::ConvertHundred   (int nSymbol)
  {
  switch (nSymbol)
    {
    case 0:
      //sTmpDigi.LoadStringW (IDS_HANDRED);
      //m_sDigiStrConv.Append (sTmpDigi);
      break;
    case 1:
      //sTmpDigi.LoadStringW (IDS_ONE);
      //m_sDigiStrConv.Append (sTmpDigi);
      //sTmpDigi.LoadStringW (IDS_HANDRED);
      //m_sDigiStrConv.Append (sTmpDigi);
      AddHundred (IDS_1HUNDRED);
      break;
    case 2:
      AddHundred (IDS_2HUNDRED);
      break;
    case 3:
      AddHundred (IDS_3HUNDRED);
      break;
    case 4:
      AddHundred (IDS_4HUNDRED);
      break;
    case 5:
      AddHundred (IDS_5HUNDRED);
      break;
    case 6:
      AddHundred (IDS_6HUNDRED);
      break;
    case 7:
      AddHundred (IDS_7HUNDRED);
      break;
    case 8:
      AddHundred (IDS_8HUNDRED);
      break;
    case 9:
      AddHundred (IDS_9HUNDRED);
      break;
    default:
      break;
    }
  m_sDigiStrOrig.Delete (0);
  }
//////////////////////////////////////////////////
bool CDigiToWordsRus::AddHundred (UINT uID)
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
void CDigiToWordsRus::ConvertThousand  (int nSymbol)
  {
  switch (nSymbol)
    {
    case 0:
      //sTmpDigi.LoadStringW (IDS_HANDRED);
      //m_sDigiStrConv.Append (sTmpDigi);
      break;
    case 1:
      //sTmpDigi.LoadStringW (IDS_ONE);
      //m_sDigiStrConv.Append (sTmpDigi);
      //sTmpDigi.LoadStringW (IDS_HANDRED);
      //m_sDigiStrConv.Append (sTmpDigi);
      AddThousand (IDS_ONE3);
      break;
    case 2:
      AddThousand2 (IDS_TWO3);
      break;
    case 3:
      AddThousand2 (IDS_THREE2);
      break;
    case 4:
      AddThousand2 (IDS_FOUR2);
      break;
    case 5:
      AddThousand3 (IDS_FIVE2);
      break;
    case 6:
      AddThousand3 (IDS_SIX2);
      break;
    case 7:
      AddThousand3 (IDS_SEVEN2);
      break;
    case 8:
      AddThousand3 (IDS_EIGHTH2);
      break;
    case 9:
      AddThousand3 (IDS_NINE2);
      break;
    default:
      break;
    }
  m_sDigiStrOrig.Delete (0);
  }
//////////////////////////////////////////////////
bool CDigiToWordsRus::AddThousand (UINT uID)
  {
  bool bSuccess (false);
  CString sTmpDigi;

  if (sTmpDigi.LoadStringW (uID))
    {
    m_sDigiStrConv.Append (sTmpDigi);
    if (sTmpDigi.LoadStringW (IDS_THOUSAND2))
      {
      m_sDigiStrConv.Append (sTmpDigi);
      bSuccess = true;
      }
    }
  return bSuccess;
  }
//////////////////////////////////////////////////
bool CDigiToWordsRus::AddThousand2 (UINT uID)
  {
  bool bSuccess (false);
  CString sTmpDigi;

  if (sTmpDigi.LoadStringW (uID))
    {
    m_sDigiStrConv.Append (sTmpDigi);
    if (sTmpDigi.LoadStringW (IDS_THOUSAND3))
      {
      m_sDigiStrConv.Append (sTmpDigi);
      bSuccess = true;
      }
    }
  return bSuccess;
  }
//////////////////////////////////////////////////
bool CDigiToWordsRus::AddThousand3 (UINT uID)
  {
  bool bSuccess (false);
  CString sTmpDigi;

  if (sTmpDigi.LoadStringW (uID))
    {
    m_sDigiStrConv.Append (sTmpDigi);
    if (sTmpDigi.LoadStringW (IDS_THOUSAND4))
      {
      m_sDigiStrConv.Append (sTmpDigi);
      bSuccess = true;
      }
    }
  return bSuccess;
  }
//////////////////////////////////////////////////