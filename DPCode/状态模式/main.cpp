//main.cpp
//State 模式很好地实现了对象的状态逻辑和动作实现的分离， 

//状态逻辑分布在 State 的派生类中实现，

//而动作实现则可以放在Context类中实


//使用的时候  直接 切换状态 ，直接调用



//现（这也是为什么 State 派生类需要拥有一个指向 Context 的指针）。 这使得两者的变化相互独立， 改变 State 的状态逻辑可以很容易复用
//Context的动作， 也可以在不影响 State 派生类的前提下创建 Context 的子类来更改或替换动作实现。
//
//


#include "Context.h"
#include "State.h"
#include <iostream>
using namespace std;
int main(int argc,char* argv[]){
    State* st = new ConcreteStateA();
    Context* con = new Context(st);
    con->OperationChangState();
    con->OperationChangState();
    con->OperationChangState();
    if (con != NULL)
        delete con;
    if (st != NULL)
        st = NULL;
    return 0;
}