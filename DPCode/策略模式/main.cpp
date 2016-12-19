//main.cpp
#include "Context.h"
#include "Strategy.h"
#include <iostream>
using namespace std;
int main(int argc,char* argv[]){
    Strategy* ps = new ConcreteStrategyA();


	// 使用的时候传入不同的策略，策略的执行 已经完成了 封装
	// 每一种行为独立封装

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
