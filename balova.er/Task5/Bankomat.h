#pragma once
#include "ProcCenter.h"

class Bankomat {
private:
	int count1;
	int count2;
	int count5;
	int count10;
	int count20;
	int count50;



	int clientcount;
	int bufsize;

	/*BUG ��� ������ ���� � ProcCenter  */

	ProcCenter card;   /*BUG ��� ��� �����?  */
	ProcCenter* cards;
public:

	Bankomat(int _size, int _buf, ProcCenter* _cards);
	/*BUG ��� �����? �� ������������? ���!!! */
	Bankomat(string filename);
	int CashDeposit(int _mon);
	int CashWithdraw(int _mon);
	int InsertCard(int _num);
	void PrintAnsw(int _answ);
	bool IsCount();
	string GetNameByCardNum(int _num);
	void PrintStatus();
	int PinSt(string _pin);
	friend istream& operator >> (istream&, Bankomat&);
};