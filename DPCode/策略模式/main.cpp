//main.cpp
#include "Context.h"
#include "Strategy.h"
#include <iostream>
using namespace std;
int main(int argc,char* argv[]){
    Strategy* ps = new ConcreteStrategyA();


	// ʹ�õ�ʱ���벻ͬ�Ĳ��ԣ����Ե�ִ�� �Ѿ������ ��װ
	// ÿһ����Ϊ������װ

    Context* pc = new Context(ps);
    pc->DoAction();
    if (NULL != pc)
        delete pc;


	Strategy* psB = new ConcreteStrategyB();
	Context* pcB = new Context(psB);
	pcB->DoAction();
	if (NULL != pcB)
		delete pcB;




    return 0;
}
