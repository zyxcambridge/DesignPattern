//main.cpp
//State ģʽ�ܺõ�ʵ���˶����״̬�߼��Ͷ���ʵ�ֵķ��룬 

//״̬�߼��ֲ��� State ����������ʵ�֣�

//������ʵ������Է���Context����ʵ


//ʹ�õ�ʱ��  ֱ�� �л�״̬ ��ֱ�ӵ���



//�֣���Ҳ��Ϊʲô State ��������Ҫӵ��һ��ָ�� Context ��ָ�룩�� ��ʹ�����ߵı仯�໥������ �ı� State ��״̬�߼����Ժ����׸���
//Context�Ķ����� Ҳ�����ڲ�Ӱ�� State �������ǰ���´��� Context �����������Ļ��滻����ʵ�֡�
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