#include<iostream>
using namespace std;

//�ĸ�·����
//·����������·���� һ����

//�Ȱ�IP �� ID���
typedef struct Link{
	string ID;
	string IP;
	int metric;
	Link *next;
}Link;
typedef struct Net{
		string profix;
		int metric;
		Net *next;
}Net;


typedef struct Router {
	string Router_ID;
	Link link1;
	Link link2;
	 Router *next_router;//ָ��router
}router;
