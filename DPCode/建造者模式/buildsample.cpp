///*
//** FileName     : BuilderPattern
//** Author       : Jelly Young
//** Date         : 2013/11/23
//** Description  : More information, please go to http://www.jellythink.com
//*/
//
//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Builder;
//
//// Product
//class Product
//{
//public:
//	void AddPart(const char *info) { m_PartInfoVec.push_back(info); }
//	void ShowProduct()
//	{
//		for (std::vector<const char *>::iterator item = m_PartInfoVec.begin(); 
//			item != m_PartInfoVec.end(); ++item)
//		{
//			cout<<*item<<endl;
//		}
//	}
//
//private:
//	std::vector<const char *> m_PartInfoVec;
//};
//
//// Builder
//class Builder
//{
//public:
//	virtual void BuildPartA() {}
//	virtual void BuildPartB() {}
//	virtual Product *GetProduct() { return NULL; }
//};
//
//// ConcreteBuilder
//class ConcreteBuilder : public Builder
//{
//public:
//	ConcreteBuilder() { m_Product = new Product(); }
//	void BuildPartA()
//	{
//		m_Product->AddPart("PartA completed");
//	}
//
//	void BuildPartB()
//	{
//		m_Product->AddPart("PartB completed");
//	}
//
//	Product *GetProduct() { return m_Product; }
//
//private:
//	Product *m_Product;
//};
//
//// Director
//class Director
//{
//public:
//	Director(Builder *builder) { m_Builder = builder; }
//	void CreateProduct()
//	{
//		m_Builder->BuildPartA();
//		m_Builder->BuildPartB();
//	}
//
//private:
//	Builder *m_Builder;
//};
//
//// main
//int main()
//{
//	Builder *builderObj = new ConcreteBuilder();
//	Director directorObj(builderObj);
//	directorObj.CreateProduct();
//	Product *productObj = builderObj->GetProduct();
//	if (productObj == NULL)
//	{
//		return 0;
//	}
//	productObj->ShowProduct();
//
//        delete productObj;
//        productObj = NULL; // 谢谢宾零同学的review
//	delete builderObj;
//	builderObj = NULL;
//}











/*
** FileName     : BuilderPattern
** Author       : Jelly Young
** Date         : 2013/11/22
** Description  : More information, please go to http://www.jellythink.com
*/

#include <iostream>
using namespace std;

typedef enum MANTYPETag
{
	kFatMan,
	kThinMan,
	kNormal
}MANTYPE;

class Man
{
public:
	void SetHead(MANTYPE type){ m_Type = type; }
	void SetBody(MANTYPE type){ m_Type = type; }
	void SetLeftHand(MANTYPE type){ m_Type = type; }
	void SetRightHand(MANTYPE type){ m_Type = type; }
	void SetLeftFoot(MANTYPE type){ m_Type = type; }
	void SetRightFoot(MANTYPE type){ m_Type = type; }
	void ShowMan()
	{
		switch (m_Type)
		{
		case kFatMan:
			cout << "I'm a fat man" << endl;
			return;

		case kThinMan:
			cout << "I'm a thin man" << endl;
			return;

		default:
			cout << "I'm a normal man" << endl;
			return;
		}
	}

private:
	MANTYPE m_Type;
};

// Builder
class Builder
{
public:
	virtual void BuildHead(){}
	virtual void BuildBody(){}
	virtual void BuildLeftHand(){}
	virtual void BuildRightHand(){}
	virtual void BuildLeftFoot(){}
	virtual void BuildRightFoot(){}
	virtual Man *GetMan(){ return NULL; }
};

// FatManBuilder
class FatManBuilder : public Builder
{
public:
	FatManBuilder(){ m_FatMan = new Man(); }
	void BuildHead(){ m_FatMan->SetHead(kFatMan); }
	void BuildBody(){ m_FatMan->SetBody(kFatMan); }
	void BuildLeftHand(){ m_FatMan->SetLeftHand(kFatMan); }
	void BuildRightHand(){ m_FatMan->SetRightHand(kFatMan); }
	void BuildLeftFoot(){ m_FatMan->SetLeftFoot(kFatMan); }
	void BuildRightFoot(){ m_FatMan->SetRightFoot(kFatMan); }
	Man *GetMan(){ return m_FatMan; }

private:
	Man *m_FatMan;
};

// ThisManBuilder
class ThinManBuilder : public Builder
{
public:
	ThinManBuilder(){ m_ThinMan = new Man(); }
	void BuildHead(){ m_ThinMan->SetHead(kThinMan); }
	void BuildBody(){ m_ThinMan->SetBody(kThinMan); }
	void BuildLeftHand(){ m_ThinMan->SetLeftHand(kThinMan); }
	void BuildRightHand(){ m_ThinMan->SetRightHand(kThinMan); }
	void BuildLeftFoot(){ m_ThinMan->SetLeftFoot(kThinMan); }
	void BuildRightFoot(){ m_ThinMan->SetRightFoot(kThinMan); }
	Man *GetMan(){ return m_ThinMan; }

private:
	Man *m_ThinMan;
};

// Director
class Director
{
public:
	Director(Builder *builder) { m_Builder = builder; }
	void CreateMan();

private:
	Builder *m_Builder;
};

void Director::CreateMan()
{
	m_Builder->BuildHead();
	m_Builder->BuildBody();
	m_Builder->BuildLeftHand();
	m_Builder->BuildRightHand();
	m_Builder->BuildLeftHand();
	m_Builder->BuildRightHand();
}

int main(int argc, char *argv[])
{
	Builder *builderObj = new FatManBuilder();
	Director directorObj(builderObj);
	directorObj.CreateMan();
	Man *manObj = builderObj->GetMan();
	if (manObj == NULL)
		return 0;

	manObj->ShowMan();

	delete manObj; // 感谢张小张同学的review
	manObj = NULL;

	delete builderObj;
	builderObj = NULL;

	return 0;
};