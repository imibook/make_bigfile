#include <iostream>
using namespace std;
class A{
public:
	//friend class B;
	A():m_data(3){}	
	void display(){cout<<m_data<<endl;}
private:
	int m_data;
};

class C{
public:
	//friend class B;
	C():m_data(3){}	
	void display(){cout<<m_data<<endl;}
private:
	int m_data;
};

class B:public C{
public:
	B(){}
	void initA(A&_ia){a=_ia;
	cout<<_ia.m_data<<endl;}//friend��ϵ���Է���˽�����ݳ�Ա
	void print(){a.display();}
	void kk(){}//���������޷����ʸ���˽������,friend��ϵ���Է���˽�����ݳ�Ա
	 static int getValue(){return value;}
	//cout<<"isn't friend"<<a.m_data<<endl;//�޷�����ͨ�����������friend�Ļ�
	public:
   //static 
	   A a;//�����Ǿ�̬����ʵ��
private:
	static int value;
};
int main(int argc,char**argv){
	A a;
	B b;
	b.initA(a);
	b.print();
	//b.kk();

	//cout<<B::getValue()<<endl;
	return 0;
}