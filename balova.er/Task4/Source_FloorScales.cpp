#include "Header_FloorScales.h"

vector <FloorScales> pers;
vector <FloorScales> date;




void AddFloorScales() {
  FloorScales a;
  system("cls");
  int day = -1, mes = -1, year = -1, weight = -1;
  string sbuf;
  FloorScales bufPers;
  FloorScales bufNabl;
  cout << endl;
  cout << endl;
  cout << "���(��������� �����): ";
  cin >> sbuf;
  bufPers.SetName(sbuf);
  cout << endl;
  cout << "����: ";
  cout << endl;
  cout << "���� (�� 1 �� 31): ";
  while (day < 1 || day > 31) {
    cin >> day;
  }
  cout << "�����(�� 1 �� 12): ";
  while (mes < 1 || mes >12) {
    cin >> mes;
  }
  cout << "��� (������������� �����): ";
  while (year < 1) {
    cin >> year;
  }
  cout << endl;
  cout << "���(������������� �����):";
  while (weight < 1) {
    cin >> weight;
  }
  bufNabl.SetNabl(day, mes, year, weight);
  date.push_back(bufNabl);
  bufPers.SetNABL(date);
  pers.push_back(bufPers);
  cout << "----------------------------------------------------------------" << endl;
  vibor();
}

void vivodpers() {
  cout << "�������� ��������" << endl;
  for (unsigned int n = 0; n < pers.size(); n++)
  {
    std::cout << "-------------------------------------------------" << std::endl;
    cout << (n + 1) << endl;
    pers[n].PrintName();
    std::cout << "-------------------------------------------------" << std::endl;
  }
}

  void AddNabl() {
    FloorScales a;
    system("cls");
    int v = -1;
    vivodpers();
    while (v < 1 || v > pers.size()) {
      cin >> v;
    }
    switch (v) {
    case 1: pers[0].addnablpers(); break;
    case 2: pers[1].addnablpers(); break;
    case 3: pers[2].addnablpers(); break;
    case 4: pers[3].addnablpers(); break;
    case 5: pers[4].addnablpers(); break;
    }
    vibor();
  }


  void FloorScales::addnablpers() {
    system("cls");
    FloorScales bufNabl;
    int day = -1, mes = -1, year = -1, weight = -1;
    cout << endl;
    cout << "����: ";
    cout << endl;
    cout << "����(�� 1 �� 31): ";
    while (day < 1 || day > 31) {
      cin >> day;
    }
    cout << "�����(�� 1 �� 12): ";
    while (mes < 1 || mes >12) {
      cin >> mes;
    }
    cout << "��� (������������� �����): ";
    while (year < 1) {
      cin >> year;
    }
    cout << endl;
    cout << "���(������������� �����):";
    while (weight < 1) {
      cin >> weight;
    }
    bufNabl.SetNabl(day, mes, year, weight);
    date.push_back(bufNabl);
    for (unsigned int n = 0; n < date.size() - 1; n++)
    {
      if (
        date[n].persDataDay == date[date.size() - 1].persDataDay &&
        date[n].persDataMes == date[date.size() - 1].persDataMes &&
        date[n].persDataYear == date[date.size() - 1].persDataYear
        ) {
        cout << "����� ���� ����! ��� �����������. ";
        date[n].persweight = date[date.size() - 1].persweight;
        date.pop_back();
      }
    }
  }


  void FloorScales::sredmes() {
    int  keyMes, keyYear, weight = 0, k = 0;
    double resweight;
    cout << "������� ��� � �����" << endl;
    cout << "����� ";
    cin >> keyMes;
    cout << "��� ";
    cin >> keyYear;
    bool t = true;
    for (unsigned int n = 0; n < date.size(); n++)
    {
      if (
        date[n].persDataMes == keyMes &&
        date[n].persDataYear == keyYear
        ) {
        k++;
        weight = date[n].persweight + weight;
        t = false;
      }
    }
    if (t == true) {
      cout << "������ ���� ���";
      vibor();
    }
    else {
      cout << "������� ��� �� ������ �����: ";
      resweight = weight / k;
      cout << resweight << endl;
    }
    vibor();
  }

  void FloorScales::sredw() {
    int   weight = 0, k = 0;
    double resweight;
    for (unsigned int n = 0; n < date.size(); n++)
    {
      k++;
      weight = date[n].persweight + weight;
    }
    cout << "������� ��� �� �� �����: ";
    resweight = weight / k;
    cout << resweight << endl;
    vibor();
  }

  void Sredweight() {
    int v1 = -1, v2 = -1;
    cout << "1 - ����� ������� ��� �������� � ��������� ������ " << endl;
    cout << "2 - ����� ������� ��� �������� �� ��� ������� ���������� " << endl;
    while (v1 < 1 || v1 >2) {
      cin >> v1;
    }
    switch (v1) {
    case 1:
      vivodpers();
      while (v2 < 1 || v2 > pers.size()) {
        cin >> v2;
      }
      switch (v2) {
      case 1:
        pers[0].sredmes();
        break;
      case 2:
        pers[1].sredmes();
        break;
      case 3:
        pers[2].sredmes();
        break;
      case 4:
        pers[3].sredmes();
        break;
      case 5:
        pers[4].sredmes();
        break;
      }
      break;
    case 2:
      vivodpers();
      while (v2 < 1 || v2 > pers.size()) {
        cin >> v2;
      }
      switch (v2) {
      case 1:
        pers[0].sredw();
        break;
      case 2:
        pers[1].sredw();
        break;
      case 3:
        pers[2].sredw();
        break;
      case 4:
        pers[3].sredw();
        break;
      case 5:
        pers[4].sredw();
        break;
      }
      break;
    }
  }


  void FloorScales::minmes() {
    int  keyMes, keyYear, weight = 999999;
    cout << "������� ��� � �����" << endl;
    cout << "����� ";
    cin >> keyMes;
    cout << "��� ";
    cin >> keyYear;
    bool t = true;
    for (unsigned int n = 0; n < date.size(); n++)
    {
      if (
        date[n].persDataMes == keyMes &&
        date[n].persDataYear == keyYear
        ) {
        if (weight > date[n].persweight) {
          weight = date[n].persweight;
          t = false;
        }
      }
    }
    if (t == true) {
      cout << "������ ���� ���" << endl;
      vibor();
    }
    else {
      cout << "����������� ��� �� ������ �����: ";
      cout << weight << endl;
    }
    vibor();
  }


  void FloorScales::minw() {
    int  weight = 999999;
    for (unsigned int n = 0; n < date.size(); n++)
    {
      if (weight > date[n].persweight) {
        weight = date[n].persweight;
      }
    }
    cout << "����������� ��� �� ��� �����: ";
    cout << weight << endl;
    vibor();
  }

  void Minweight() {
    int v1 = -1, v2 = -1;
    cout << "1 - ����� ����������� ��� �������� � ��������� ������ " << endl;
    cout << "2 - ����� ����������� ��� �������� �� ��� ������� ���������� " << endl;
    while (v1 < 1 || v1 >2) {
      cin >> v1;
    }
    switch (v1) {
    case 1:
      vivodpers();
      while (v2 < 1 || v2 > pers.size()) {
        cin >> v2;
      }
      switch (v2) {
      case 1:
        pers[0].minmes();
        break;
      case 2:
        pers[1].minmes();
        break;
      case 3:
        pers[2].minmes();
        break;
      case 4:
        pers[3].minmes();
        break;
      case 5:
        pers[4].minmes();
        break;
      }
      break;
    case 2:
      vivodpers();
      while (v2 < 1 || v2 > pers.size()) {
        cin >> v2;
      }
      switch (v2) {
      case 1:
        pers[0].minw();
        break;
      case 2:
        pers[1].minw();
        break;
      case 3:
        pers[2].minw();
        break;
      case 4:
        pers[3].minw();
        break;
      case 5:
        pers[4].minw();
        break;
      }
      break;
    }
  }


  void FloorScales::maxmes() {
    int  keyMes, keyYear, weight = -1;
    cout << "������� ��� � �����" << endl;
    cout << "����� ";
    cin >> keyMes;
    cout << "��� ";
    cin >> keyYear;
    bool t = true;
    for (unsigned int n = 0; n < date.size(); n++)
    {
      if (
        date[n].persDataMes == keyMes &&
        date[n].persDataYear == keyYear
        ) {
        if (weight < date[n].persweight) {
          weight = date[n].persweight;
          t = false;
        }
      }
    }
    if (t == true) {
      cout << "������ ���� ���" << endl;
      vibor();
    }
    else {
      cout << "������������ ��� �� ������ �����: ";
      cout << weight << endl;
    }
    vibor();
  }


  void FloorScales::maxw() {
    int  weight = -1;
    for (unsigned int n = 0; n < date.size(); n++)
    {
      if (weight < date[n].persweight) {
        weight = date[n].persweight;
      }
    }
    cout << "������������ ��� �� ��� �����: ";
    cout << weight << endl;
    vibor();
  }


  void Maxweight() {
    int v1 = -1, v2 = -1;
    cout << "1 - ����� ������������ ��� �������� � ��������� ������ " << endl;
    cout << "2 - ����� ������������ ��� �������� �� ��� ������� ���������� " << endl;
    while (v1 < 1 || v1 >2) {
      cin >> v1;
    }
    switch (v1) {
    case 1:
      vivodpers();
      while (v2 < 1 || v2 > pers.size()) {
        cin >> v2;
      }
      switch (v2) {
      case 1:
        pers[0].maxmes();
        break;
      case 2:
        pers[1].maxmes();
        break;
      case 3:
        pers[2].maxmes();
        break;
      case 4:
        pers[3].maxmes();
        break;
      case 5:
        pers[4].maxmes();
        break;
      }
      break;
    case 2:
      vivodpers();
      while (v2 < 1 || v2 > pers.size()) {
        cin >> v2;
      }
      switch (v2) {
      case 1:
        pers[0].maxw();
        break;
      case 2:
        pers[1].maxw();
        break;
      case 3:
        pers[2].maxw();
        break;
      case 4:
        pers[3].maxw();
        break;
      case 5:
        pers[4].maxw();
        break;
      }
      break;
    }
  }


  void FloorScales::Poisk() {
    int  keyDay, keyMes, keyYear;
    cout << endl << "������� ������ ����" << endl;
    cout << "���� ";
    cin >> keyDay;
    cout << "����� ";
    cin >> keyMes;
    cout << "��� ";
    cin >> keyYear;
    bool t = true;
    for (unsigned int n = 0; n < date.size(); n++)
    {
      if (
        date[n].persDataDay == keyDay &&
        date[n].persDataMes == keyMes &&
        date[n].persDataYear == keyYear
        ) {
        cout << "��� : ";
        cout << date[n].persweight << endl;
        t = false;
      }
    }
    if (t == true) {
      cout << "������ ���� ���" << endl;
    }
  }


  void FloorScales::Mes() {
    std::cout << "-------------------------------------------------" << std::endl;
    cout << " ���� ���������� " << endl;
    std::cout << "-------------------------------------------------" << std::endl;
    for (unsigned int n = 0; n < date.size(); n++)
    {
      cout << (n + 1) << endl;
      cout << date[n].persDataDay << ".";
      cout << date[n].persDataMes << ".";
      cout << date[n].persDataYear << endl;
      std::cout << "-------------------------------------------------" << std::endl;
    }
  }


  void Dateweight() {
    system("cls");
    int v = -1;
    vivodpers();
    while (v < 1 || v > pers.size()) {
      cin >> v;
    }
    switch (v) {
    case 1:
      pers[0].Mes();
      pers[0].Poisk();
      break;
    case 2:
      pers[1].Mes();
      pers[1].Poisk();
      break;
    case 3:
      pers[2].Mes();
      pers[2].Poisk();
      break;
    case 4:
      pers[3].Mes();
      pers[3].Poisk();
      break;
    case 5:
      pers[4].Mes();
      pers[4].Poisk();
      break;
    }
    vibor();
  }

  void FloorScales::Print()
  {
    cout << "���" << endl;
    cout << persName.c_str() << endl;
    cout << "����" << endl;
    cout << date[0].persDataDay << endl;
    cout << "�����" << endl;
    cout << date[0].persDataMes << endl;
    cout << "���" << endl;
    cout << date[0].persDataYear << endl;
    cout << "��������� ���" << endl;
    cout << date[0].persweight << endl;
  }

  void FloorScales::PrintNabl2(int n)
  {
    cout << "����" << endl;
    cout << date[0].persDataDay << endl;
    cout << "�����" << endl;
    cout << date[0].persDataMes << endl;
    cout << "���" << endl;
    cout << date[0].persDataYear << endl;
    cout << "���" << endl;
    cout << date[0].persweight << endl;
  }

  void FloorScales::PrintNabl()
  {
    system("cls");
    for (unsigned int n = 0; n < date.size(); n++)
    {
      std::cout << "-------------------------------------------------" << std::endl;
      cout << (n + 1) << ")" << endl;
      date[n].PrintNabl2(n);
      std::cout << "-------------------------------------------------" << std::endl;
    }
  }

    void PrintPers()
    {
      int v = -1;
      vivodpers();
      while (v < 1 || v > pers.size()) {
        cin >> v;
      }
      switch (v) {
      case 1: pers[0].PrintNabl(); break;
      case 2: pers[1].PrintNabl(); break;
      case 3: pers[2].PrintNabl(); break;
      case 4: pers[3].PrintNabl(); break;
      case 5: pers[4].PrintNabl(); break;
      }
      vibor();
    }

    void FloorScales::PrintName()
    {
      cout << "���" << endl;
      cout << persName.c_str() << endl;
    }
    void PrintAll()
    {
      FloorScales a;
      system("cls");
      cout << " ����� ����� � ��������� ��������� " << std::endl;
      for (unsigned int n = 0; n < pers.size(); n++)
      {
        std::cout << "-------------------------------------------------" << std::endl;
        cout << (n + 1) << ")" << endl;
        pers[n].Print();
        std::cout << "-------------------------------------------------" << std::endl;
      }
      cout << "-------------------------------------------------\n";
      vibor();
    }




    void vibor() {
      menu();
      int v = -1;
      while (v < 1 || v>10 || ((pers.size() < 1) && (v > 1 && v < 9))) {
        cin >> v;
        if (v < 1 || v>11) {
          cout << endl << "�� ����� ������������ ����� ��������. ���������:" << endl << endl;
          menu();
        }
      }
      switch (v) {
      case 1:
        if (pers.size() < 5) {
          AddFloorScales();
        }
        else {
          cout << "������������ ���������� ������� = 5 " << endl;
          vibor();
        }
        break;
      case 2:  PrintAll(); break;
      case 3:  AddNabl(); break;
      case 4:  PrintPers(); break;
      case 5:  Dateweight(); break;
      case 6:  Sredweight(); break;
      case 7:  Minweight(); break;
      case 8:  Maxweight(); break;
      case 9:  infile(); break;
      case 10:  outfile(); break;
      case 11:  exit; break;
      }
    }
  

    void menu() {
      cout << "���� ���������� ������ ������:" << endl;
      cout << "'1' �������� ����� �����." << endl;
      cout << "'2' ������ ��������� ���� � ����� ����������." << endl;
      cout << "'3' ������ ����������." << endl;
      cout << "'4' ������� ��� ��������� ���������� ��������." << endl;
      cout << "'5' ������ ��� � ����������." << endl;
      cout << "'6' ����� ������� ��� ����� ����� � ��������� ������ �� ��� ������� ����������." << endl;
      cout << "'7' ����� ����������� ��� ����� ����� � ��������� ������ �� ��� ������� ����������." << endl;
      cout << "'8' ����� ������������ ��� ����� ����� � ��������� ������ �� ��� ������� ����������." << endl;
      cout << "'9' ��������� ������� ���������� � ����." << endl;
      cout << "'10' ������� ������� ���������� �� �����." << endl;
      cout << "'11' ��������� ���������." << endl;
      cout << "�����: " << endl;
      
    }

   void infile() {
      ofstream in;
      in.open("Info.txt");
   //�������
      in.close();
    }

    void outfile() {
      string str;
      ifstream out("Info.txt");
      if (!out.is_open()) {
        cout << "�� ������� ������� ����" << endl;
      }
      else {
        while (!out.eof()) {
          str = "";
          getline(out, str);
          cout << str << endl;
        }
      }
      out.close();
    }
    /*���� �������� � ���, ��� ���������� ������������ ��� � ���� ����...�.�. ������ ���������� ������ ����� � ���� �����. 
    ��� ������ ������ ������ ����� ����� ���������� �� ���� �����.....��� ��� ������ � ������*/