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
	cout<<_ia.m_data<<endl;}//friend关系可以访问私有数据成员
	void print(){a.display();}
	void kk(){}//派生类中无法访问父类私有数据,friend关系可以访问私有数据成员
	 static int getValue(){return value;}
	//cout<<"isn't friend"<<a.m_data<<endl;//无法编译通过，如果不是friend的话
	public:
   //static 
	   A a;//不能是静态的类实例
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