#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
#include <iomanip>
#include<windows.h>
using namespace std;

//设计图书类；图书属性包括：图书编号，图书书名，图书作者，图书类别，图书出版社，图书出版日期，图书价格； 
class book  
{
	private:	
		int bookId;           // 图书编号（系统自动生成） 
		string bookName;      // 图书书名 
		string bookAuthor;    // 图书作者
		string bookKind;      // 图书类别
		string bookMade;      // 图书出版社
		string bookYear;      // 图书出版日期
		float  bookPrice;     // 图书价格
	public:
	    static int count;     //静态数据成员（用于编号生成） 
		book(){};             //无参构造函数 
		book(string name,string author,string kind,string made,string year,float price);//带参构造函数 
		book(int id,string name,string author,string kind,string made,string year,float price); 
		int getbookId();                        // 用于获得图书的编号 
		void setbookName(string name);		    // 用于重置图书的书名 
		string getbookName();	                // 用于获得图书的书名 
		void setbookAuthor(string author);      // 用于重置图书的作者 
		string getbookAuthor();                 // 用于获得图书的作者  
		void setbookKind(string kind);          // 用于重置图书的类别 
		string getbookKind();                   // 用于获得图书的类别  
		void setbookMade(string made);          // 用于重置图书的出版单位 
		string getbookMade();	                // 用于获得图书的出版单位 
		void setbookYear(string year);          // 用于重置图书的出版日期 
		string getbookYear();                   // 用于获得图书的出版日期  
		void setbookPrice(float price);         // 用于重置图书的价格
		float getbookPrice();                   // 用于获得图书的价格
		void bookShown();                       // 用于显示图书信息 
		void bookShow();                        // 用于显示图书信息 

};
//**************************book类的成员函数 *************************************** 
book::book(string name,string author,string kind,string made,string year,float price)//构造函数，用于书籍录入 
{
	bookId=count++;
	bookName=name;
	bookAuthor=author;
	bookKind=kind;
	bookMade=made;
	bookYear=year;
	bookPrice=price;
}

book::book(int id,string name,string author,string kind,string made,string year,float price)//构造函数，用于书籍修改 
{
	bookId=id;
	bookName=name;
	bookAuthor=author;
	bookKind=kind;
	bookMade=made;
	bookYear=year;
	bookPrice=price;
}

int book::getbookId()    //获得图书编号 
{
	return bookId;	
}
				
void book::setbookName(string name)//重置图书书名 
{
	bookName=name;
}

string book::getbookName()//获得图书书名 
{
	return bookName;
}
		
void book::setbookAuthor(string author)//重置图书作者 
{
	bookAuthor=author;
}

string book::getbookAuthor()//获得图书作者 
{
	return bookAuthor;
}
		
void book::setbookKind(string kind)//重置图书类别 
{
	bookKind=kind;
}

string book::getbookKind()//获得图书类别 
{
	return bookKind;
}

void book::setbookMade(string made)//重置图书出版设 
{
	bookMade=made;
}

string book::getbookMade()//获得图书出版社 
{
	return bookMade;
}
		
void book::setbookYear(string year)//重置图书出版日期 
{
	bookYear=year;
}
		
string book::getbookYear()//获得图书出版日期 
{
	return bookYear;
}
		
void book::setbookPrice(float price)//重置图书价格 
{
	bookPrice=price;
}

float book::getbookPrice()//获得图书价格 
{
	return bookPrice;
}

void book::bookShown()//输出图书的信息，用于图书查找时 
{
	cout<<"登录号："<<left<<setw(10)<<bookId<<"书名："<<left<<setw(15)<<bookName<<"作者："<<left<<setw(15)<<bookAuthor<<"类别："<<left<<setw(15)<<bookKind<<"出版单位："<<left<<setw(20)<<bookMade<<"出版时间："<<left<<setw(10)<<bookYear<<"价格："<<left<<setw(10)<<bookPrice<<endl; 
}
		
void book::bookShow()//输出图书信息，用于图书浏览时 
{
	cout<<setw(15)<<bookId<<setw(25)<<bookName<<setw(15)<<bookAuthor<<setw(15)<<bookKind<<setw(25)<<bookMade<<setw(15)<<bookYear<<setw(15)<<bookPrice<<endl; 
}

//*****************************比较函数用于排序**************************** 
bool compareName(book a,book b)
{
    if(a.getbookName()<b.getbookName())
	    return true;
	else
	    return false;	
}
	
bool compareAuthor(book a,book b)
{
	if(a.getbookAuthor()<b.getbookAuthor())
		return true;
	else
		return false;
}
bool compareYear(book a,book b)
{
	if(a.getbookYear()<b.getbookYear())
		return true;
	else
		return false;
}
bool comparePrice(book a,book b)
{
	if(a.getbookPrice()<b.getbookPrice())
		return true;
	else
		return false;
}
vector<int>  op;     //定义一个全局变量，用于存放对象的下标
	
//**************************************书籍管理类的设计 ******************************* 
class library  
{
    private:
		vector<book> Lib;     //动态数组Lib用于存放书籍 
	public:
		library();            //构造函数，从文本文件中读取数据初始化数组Lib 
	    void Exit();	      //退出函数，退出主菜单时调用，将Lib中的信息写回文本文件 
	    void addBook();		  //添加图书 
	    void showBook()	;	  //浏览图书信息 
		void showbook_index(int index);	   //根据下标显示图书信息 
	    vector<book> getLib();	           //获得Lib数组 
		int find_bookId(int id);		   //根据图书编号查询并返回图书在数组中的下标 
	    void find_show();	   	           //将所查找到的数据全部输出 
		int indexOfId(int id);	           //根据编号查找 
		void indexOfName(string name);	   //根据书名查找	
		void indexOfAuthor(string author); //根据作者查找 
		void indexOfMade(string made);	   //根据出版社查找 
		void indexOfKind(string kind);     //根据类别查找 
		void indexOfYear(string year);	   //根据出版日期查找 
		void indexOfPrice(float price);	   //根据价格查找		
		void delete_book();	               //删除图书 
		void changebookName(int i,string name);	     //根据编号修改书名 
		void changebookAuthor(int i,string author);	 //根据编号修改作者	
		void changebookYear(int i,string year);	     //根据编号修改出版日期 
		void changebookPrice(int i,float price);	 //根据编号修改价格 
		void changebookAll(int i,book b);		     //根据编号修改所有信息 
        void sortbookName();                         //按照书名排序 
	    void sortbookAuthor();                       //按照作者排序 
	    void sortbookYear();                         //按照出版日期排序 
	    void sortbookPrice();                        //按照价格排序 
};
//**************************library类的成员函数*************************** 
library::library()     //构造函数，用于初始化Lib数组 
{
	ifstream f("book.txt");  //以文本文件方式打开book.txt文件 
    if(!f)
	{
	    cout<<"file can not be opened"<<endl;
		return ;
	}
	string name,author,kind,made,year;
    int id;        
	float price;		    
	while(f>>id>>name>>author>>kind>>made>>year>>price)		    
	{			  
		book b(id,name,author,kind,made,year,price);			  
		book::count=id+1;			  
		Lib.push_back(b); 	    	
	}		    
	f.close();	    
}
   
void library::Exit()	    //退出函数，当退出主菜单的时候将使用者进行的操作保存到文件当中 
{	    
	ofstream output("book.txt");            
	if(!output)
	{	          
		cout<<"File cannot be opened."<<endl;	       
	}	        
	for(int i=0;i<Lib.size();i++)	        //图书信息写入 
	{	           
		output<<Lib[i].getbookId()<<'\t'<<Lib[i].getbookName()<<'\t'<<Lib[i].getbookAuthor()<<'\t'<<Lib[i].getbookKind()<<'\t'<<Lib[i].getbookMade()<<'\t'<<Lib[i].getbookYear()<<'\t'<<Lib[i].getbookPrice()<<'\t'<<endl;
	        
	}	        
	output.close();	   
}
	    
void library::addBook()	    //图书录入函数 
{ 	      
	while(1)	     
	{ 	        
		int choice=0;	        
		string name,author,kind,made,year;			
		float price; 	    	
		cout<<"请输入书名: ";            
		cin>>name;		    
		cout<<"请输入作者: ";            
		cin>>author;            
		cout<<"请输入类别: ";            
		cin>>kind;            
		cout<<"请输入出版社: ";            
		cin>>made;            
		cout<<"请输入出版日期: ";            
		cin>>year;            
		cout<<"请输入价格: ";            
		cin>>price;            
		book b(name,author,kind,made,year,price);             
		Lib.push_back(b);            
		cout<<"是否继续录入：（1/0）";             
		cin>>choice;           
		if(choice==0)              
			break;		  
	}		
}
				
void library::showBook()	//图书信息输出函数，用于查找时 
{
	 int i;
	 cout<<setw(15)<<"书籍编号"<<setw(25)<<"书籍名称"<<setw(15)<<"书籍作者"<<setw(15)<<"书籍类别"<<setw(25)<<"出版单位"<<setw(15)<<"出版时间"<<setw(15)<<"书籍价格"<<endl; 
	 for(i=0;i<Lib.size();i++)
	 {
	   	Lib[i].bookShow();  //调用book类的成员函数输出图书信息 
	 }
	system("pause");
}
		
void library::showbook_index(int index) //根据下标输出对应位置的图书信息 
{
	Lib[index].bookShown();
}
	
vector<book> library::getLib()    //返回Lib数组 
{
	return Lib;
}

int library::find_bookId(int id)    //根据编号查找其对应的下标，采用二分法查找 
{
	int low=0,mid,high=Lib.size();
	while(low<=high)
	{
		mid=(low+high)/2;
		if(Lib[mid].getbookId()==id)
		    return mid;                 //若找到，返回下标 
		else if(id<Lib[mid].getbookId())
			high=mid-1;
	    else
			low=mid+1;
	}
	return -1;     //若未找到，返回-1 
}
		
int library::indexOfId(int id)  //根据编号查找 
{
	int i;
	for(i=0;i<Lib.size();i++)
	{
		if(Lib[i].getbookId()==id)
		   op.push_back(i);    //若找到，把改书籍的下标放进op数组当中 
	}
}
		
void library::indexOfName(string name)//根据书名查找 
{
	int i;
	for(i=0;i<Lib.size();i++)
	{                        //将所查找到的全部书籍的下标放进op数组当中 
		if(Lib[i].getbookName()==name)
		  op.push_back(i);
	}
} 
		
void library::indexOfAuthor(string author)//根据作者查找 
{
	int i;
	for(i=0;i<Lib.size();i++)
	{                        //将所查找到的全部书籍的下标放进op数组当中 
		if(Lib[i].getbookAuthor()==author)
		  op.push_back(i);
	}
} 
		
void library::indexOfMade(string made)//根据出版社查找 
{
	int i;
	for(i=0;i<Lib.size();i++)
	{                        //将所查找到的全部书籍的下标放进op数组当中 
    	if(Lib[i].getbookMade()==made)
		   op.push_back(i);
	}
} 
		
void library::indexOfKind(string kind)//根据图书类别查找	
{			
	int i;			
	for(i=0;i<Lib.size();i++)
	{			            //将所查找到的全部书籍的下标放进op数组当中 
		if(Lib[i].getbookKind()==kind)				
			op.push_back(i);			
	}		
} 
		
void library::indexOfYear(string year)//根据出版日期查找	
{			
	int i;			
	for(i=0;i<Lib.size();i++)			
	{                        //将所查找到的全部书籍的下标放进op数组当中 				
		if(Lib[i].getbookYear()==year)				   
			op.push_back(i);			
	}		
} 
		
void library::indexOfPrice(float price)	//根据图书价格查找	
{			
	int i;			
	for(i=0;i<Lib.size();i++)			
	{                        //将所查找到的全部书籍的下标放进op数组当中 				
		if(Lib[i].getbookPrice()==price)
			op.push_back(i);
	}
} 
	
void library::find_show()	    //查找并输出，将所查找到的全部信息输出 
{
	int i;
	for(i=0;i<op.size();i++)
	{
	  	Lib[op[i]].bookShown();
	}
}
				
void library::delete_book()	  //删除全部符合要求的书籍 
{		
	int i;
	for(i=op.size()-1;i>=0;i--)
	Lib.erase(Lib.begin()+op[i]);
}


void library::changebookName(int i,string name)//修改下标为i的书籍的书名 
{
	Lib[i].setbookName(name);
}

void library::changebookAuthor(int i,string author)//修改下标为i的书籍的作者 
{
	Lib[i].setbookAuthor(author);
}
void library::changebookYear(int i,string year)//修改下标为i的书籍的出版日期
{
	Lib[i].setbookYear(year);
}
void library::changebookPrice(int i,float price)//修改下标为i的书籍的价格
{
	Lib[i].setbookPrice(price);
}
void library::changebookAll(int i,book b)//修改下标为i的书籍的全部信息 
{
	Lib[i]=b;
}
 
void library::sortbookName()  //按照书名排序（从小到大） 
{
    sort(Lib.begin(),Lib.end(),compareName);
   	showBook();     //显示排序后的图书信息 
}
void library::sortbookAuthor()//按照作者排序（从小到大）
{
    sort(Lib.begin(),Lib.end(),compareAuthor);
    showBook();
}
void library::sortbookYear()//按照出版日期排序（从小到大）
{
    sort(Lib.begin(),Lib.end(),compareYear);
    showBook();
}
void library::sortbookPrice()//按照价格排序（从小到大）
{
    sort(Lib.begin(),Lib.end(),comparePrice);
    showBook();
}

int book::count=0; 

void menuDelete()//删除界面菜单 
{
	 cout<<endl<<endl<<endl;
	 cout<<"         ========================================================="<<endl;
	 cout<<"                                                                  "<<endl;
	 cout<<"                                 删除菜单                         "<<endl;
	 cout<<"                                                                  "<<endl;
	 cout<<"                 1.按照编号删除              2.按照书名删除       "<<endl;
     cout<<"                                                                  "<<endl;
     cout<<"                 3.按照作者删除              4.按照年份删除       "<<endl;
     cout<<"                                                                  "<<endl;
     cout<<"                                0.退出删除菜单                    "<<endl;
     cout<<"                                                                  "<<endl;
     cout<<"         ========================================================="<<endl; 
} 
void menuFind()//查找界面菜单 
{
	 cout<<endl<<endl<<endl;
	 cout<<"         ========================================================="<<endl;
	 cout<<"                                                                  "<<endl;
	 cout<<"                                 查询菜单                         "<<endl;
	 cout<<"                                                                  "<<endl;
	 cout<<"                 1.编号查找                  2.书名查找           "<<endl;
     cout<<"                                                                  "<<endl;
     cout<<"                 3.作者查找                  4.类别查找           "<<endl;
     cout<<"                                                                  "<<endl;
     cout<<"                 5.出版日期查找              6.价格查找           "<<endl;
     cout<<"                                                                  "<<endl;
     cout<<"                               0.退出查询                         "<<endl;
     cout<<"                                                                  "<<endl;
     cout<<"         ========================================================="<<endl;
} 

void menuChange()//修改界面菜单 
{
	 cout<<endl<<endl<<endl;
	 cout<<"         ========================================================="<<endl;
	 cout<<"                                                                  "<<endl;
	 cout<<"                                 修改菜单                         "<<endl;
	 cout<<"                                                                  "<<endl;
	 cout<<"                 1.修改书名                  2.修改作者           "<<endl;
     cout<<"                                                                  "<<endl;
     cout<<"                 3.修改日期                  4.修改价格           "<<endl;
     cout<<"                                                                  "<<endl;
     cout<<"                 5.修改所有信息              0.退出修改           "<<endl;
     cout<<"                                                                  "<<endl;
     cout<<"         ========================================================="<<endl; 
} 


void menuSort()//排序界面菜单 
{
	 cout<<endl<<endl<<endl;
	 cout<<"         ========================================================="<<endl;
	 cout<<"                                                                  "<<endl;
	 cout<<"                                 排序菜单                         "<<endl;
	 cout<<"                                                                  "<<endl;
	 cout<<"                 1.按书名排序               2.按照作者排序        "<<endl;
     cout<<"                                                                  "<<endl;
     cout<<"                 3.按照出版日期排序         4.按照价格排序        "<<endl;
     cout<<"                                                                  "<<endl;
     cout<<"                               0.退出整理菜单                     "<<endl;
     cout<<"                                                                  "<<endl;
     cout<<"         ========================================================="<<endl; 
}

 
void menuShow()//主菜单 
{
	 cout<<endl<<endl<<endl;
	 cout<<"         ========================================================="<<endl;
	 cout<<"                                                                  "<<endl;
	 cout<<"                           图书管理系统菜单                       "<<endl;
	 cout<<"                                                                  "<<endl;
	 cout<<"                              1.浏览图书                          "<<endl;
     cout<<"                                                                  "<<endl;
     cout<<"                              2.增加图书                          "<<endl;
     cout<<"                                                                  "<<endl;
     cout<<"                              3.删除图书                          "<<endl;
     cout<<"                                                                  "<<endl;
     cout<<"                              4.查找图书                          "<<endl;
     cout<<"                                                                  "<<endl;
     cout<<"                              5.修改图书                          "<<endl;
     cout<<"                                                                  "<<endl;
     cout<<"                              6.排序图书                          "<<endl;
     cout<<"                                                                  "<<endl;
     cout<<"                              0.退出菜单                          "<<endl;
     cout<<"                                                                  "<<endl;
     cout<<"         ========================================================="<<endl;
} 

void deleteFunction(library &l)  //删除函数 
{
	bool state = true; 
	int choice,no,select;
	string ss;
	while(state)
	{ 
	     system("cls");    //清屏 
	     menuDelete();
	     cout<<"         请输入您的选择：";	
	     cin>>choice;
	     switch(choice)
	     {
	     	case 1: 
	     	    {
					cout<<"请输入您准备删除书籍的编号：";
					cin>>no; 
			        l.indexOfId(no);    //查找该编号是否存在 
			       	if(op.size()==0)
			        {
					    cout<<"没有找到该名称的书籍！！"<<endl; 
					} 
					else               
					{
						l.find_show();
					    cout<<"请问你确定删除这些书籍吗？（1/0）";  //询问是否删除该书籍 
					    cin>>select;
					    if(select==1)   
					    {   
					        l.delete_book();
			        	    cout<<"删除成功！！"<<endl; 
			        	    op.clear();
						}
						else
						{
							cout<<"您已放弃删除！！"<<endl;
						}
					}
					system("pause");
			        break;
			    }
	     	case 2: 
			    {
					cout<<"请输入您准备删除书籍的书名：";
					cin>>ss; 
			        l.indexOfName(ss);
			        if(op.size()==0)
			        {
					    cout<<"没有找到该名称的书籍！！"<<endl; 
					} 
					else               
					{
						l.find_show();
					    cout<<"请问你确定删除这些书籍吗？（1/0）";  //询问是否删除该书籍 
					    cin>>select;
					    if(select==1)   
					    {   
					        l.delete_book();
			        	    cout<<"删除成功！！"<<endl; 
			        	    op.clear();
						}
						else
						{
							cout<<"您已放弃删除！！"<<endl;
						}
					}
					system("pause");
			        break;
			    }
	     	case 3:
			    { 
			        cout<<"请输入您准备删除书籍的作者：";
					cin>>ss; 
			        l.indexOfAuthor(ss);
			        if(op.size()==0)
			        {
					    cout<<"没有找到该名称的书籍！！"<<endl; 
					} 
					else               
					{
						l.find_show();
					    cout<<"请问你确定删除这些书籍吗？（1/0）";  //询问是否删除该书籍 
					    cin>>select;
					    if(select==1)   
					    {   
					        l.delete_book();
			        	    cout<<"删除成功！！"<<endl; 
			        	    op.clear();
						}
						else
						{
							cout<<"您已放弃删除！！"<<endl;
						}
					}
					system("pause");
			        break;
			    }
	     	case 4: 
	     	    {
			        cout<<"请输入您准备删除书籍的出版日期：";
					cin>>ss; 
			        l.indexOfYear(ss);
			        if(op.size()==0)
			        {
					    cout<<"没有找到该名称的书籍！！"<<endl; 
					} 
					else               
					{
						l.find_show();
					    cout<<"请问你确定删除这些书籍吗？（1/0）";  //询问是否删除该书籍 
					    cin>>select;
					    if(select==1)   
					    {   
					        l.delete_book();
			        	    cout<<"删除成功！！"<<endl; 
			        	    op.clear();
						}
						else
						{
							cout<<"您已放弃删除！！"<<endl;
						}
					}
					system("pause");
			        break;
			    }
	     	case 0: state =false;    break;  //退出删除菜单， 
	     	default:  cout<<"亲，您输入错误   ";   system("pause");  break;
		 }
	} 
}

void findFunction(library l)//查找函数 
{
	bool state = true; 
	int no;
	string ss; 
	float price;
	int choice;
	while(state)
	{ 
	     system("cls"); 
	     menuFind();
	     cout<<"         请输入您的选择：";	
	     cin>>choice;
	     switch(choice)
	     {
	     	case 1: 
			        cout<<"请输入您准备查找书籍的编号：";
					cin>>no;
					l.indexOfId(no);
			        if(op.size()!=0)
			        {
			        	l.find_show();
			        	op.clear();
					}
					else
					{
						cout<<"没有找到该作者的书籍！！"<<endl; 
					}
				system("pause");
			        break;
	     	case 2:
			        cout<<"请输入您准备查找书籍的书名：";
					cin>>ss;
					l.indexOfName(ss);    //找到所有书名为ss的书籍 ，下标放入op当中 
			        if(op.size()!=0)
			        {
			        	l.find_show();    //输出所有书籍名为ss的书籍信息 
			        	op.clear();       //清空op数组 
					}
					else
					{
						cout<<"没有找到该作者的书籍！！"<<endl; 
					}
					system("pause");
			        break;
	     	case 3: 
			        cout<<"请输入您准备查找书籍的作者：";
					cin>>ss;
					l.indexOfAuthor(ss);
			        if(op.size()!=0)
			        {
			        	l.find_show();
			        	op.clear();
					}
					else
					{
						cout<<"没有找到该作者的书籍！！"<<endl; 
					}
					system("pause");
			        break;
	     	case 4: 
			        cout<<"请输入您准备查找书籍的类别：";
					cin>>ss;
					l.indexOfKind(ss);
			        if(op.size()!=0)
			        {
			        	l.find_show();
			        	op.clear();
					}
					else
					{
						cout<<"没有找到该类别的书籍！！"<<endl; 
					}
					system("pause");
			        break;	     	
			case 5: 
			        cout<<"请输入您准备查找书籍的出版日期：";
					cin>>ss;
					l.indexOfYear(ss);
			        if(op.size()!=0)
			        {
			        	l.find_show();
			        	op.clear();
					}
					else
					{
						cout<<"没有找到该作者的书籍！！"<<endl; 
					}
					system("pause");
			        break;
			case 6: 
			        cout<<"请输入您准备查找书籍的价格：";
					cin>>price;
					l.indexOfPrice(price);
			        if(op.size()!=0)
			        {
			        	l.find_show();
			        	op.clear();
					}
					else
					{
						cout<<"没有找到该作者的书籍！！"<<endl; 
					}
					system("pause");
			        break;
	     	case 0: state =false;    break;   //退出查询菜单 
	     	default:  cout<<"亲，您输入错误   ";   system("pause");  break;
		 }
	} 
}

void changeFunction(library &l)//修改菜单 
{
	bool state = true; 
	int choice,select;
	int no;
	string ss;
	float price;
	while(state)
	{ 
	     system("cls"); 
	     menuChange();
	     cout<<"         请输入您的选择：";	
	     cin>>choice;
	     switch(choice)
	     {
	     	case 1: 
	           	{
			        cout<<"请输入您准备修改书籍的编号：";
					cin>>no;
					int index=l.find_bookId(no);    //找到编号为no的书籍的下标 
					if(index==-1)     //返回为-1，说明没有找到了，输出提示语句 
					{
						cout<<"没有你输入的编号！！！"<<endl;
					}
					else               //返回不为-1，说明找到了
					{
						l.showbook_index(index);  //输出该书籍的全部信息 
					    cout<<"请问你确定修改该书籍吗？（1/0）";  //询问是否修改该书籍 
					    cin>>select;
					    if(select==1)   //若确认修改，则进行修改 
					    {   
					        cout<<"请输入新的书名：" ;
							cin>>ss; 
					    	l.changebookName(index,ss);  //调用changebookName()函数修改书名 
						    cout<<"修改成功！！"<<endl; 
						}
						else   //若不确定修改，则输出提示语句 
						{
							cout<<"您已放弃修改！！"<<endl;
						}
					}
					system("pause");
			        break;
			    }
	     	case 2: 
	     	   {
			        cout<<"请输入您准备修改书籍的编号：";
					cin>>no;
					int index=l.find_bookId(no);
					if(index==-1)
					{
						cout<<"没有你输入的编号！！！"<<endl;
					}
					else
					{
						l.showbook_index(index);
					    cout<<"请问你确定修改该书籍吗？（1/0）";
					    cin>>select;
					    if(select==1)
					    {   
					        cout<<"请输入新的作者：" ;
							cin>>ss; 
					    	l.changebookAuthor(index,ss);
						    cout<<"修改成功！！"<<endl; 
						}
						else
						{
							cout<<"您已放弃修改！！"<<endl;
						}
					}
					system("pause"); 
					break;
					
				}
	     	case 3: 
	     	   {   
			        cout<<"请输入您准备修改书籍的编号：";
					cin>>no;
					int index=l.find_bookId(no);
					if(index==-1)
					{
						cout<<"没有你输入的编号！！！"<<endl;
					}
					else
					{
						l.showbook_index(index);
					    cout<<"请问你确定修改该书籍吗？（1/0）";
					    cin>>select;
					    if(select==1)
					    {   
					        cout<<"请输入新的出版日期：" ;
							cin>>ss; 
					    	l.changebookYear(index,ss);
						    cout<<"修改成功！！"<<endl; 
						}
						else
						{
							cout<<"您已放弃修改！！"<<endl;
						}
					}  
					system("pause"); 
					break;
				}
	     	case 4:
	     		{
			        cout<<"请输入您准备修改书籍的编号：";
					cin>>no;
					int index=l.find_bookId(no);
					if(index==-1)
					{
						cout<<"没有你输入的编号！！！"<<endl;
					}
					else
					{
						l.showbook_index(index);
					    cout<<"请问你确定修改该书籍吗？（1/0）";
					    cin>>select;
					    if(select==1)
					    {   
					        cout<<"请输入新的价格：" ;
							cin>>price; 
					    	l.changebookPrice(index,price);
						    cout<<"修改成功！！"<<endl; 
						}
						else
						{
							cout<<"您已放弃修改！！"<<endl;
						}
					}  
					system("pause");   
					break;
				}
	     	case 5: 
	     	   {
	     	        string name,author,kind,year,made;
	     	        float price;
			        cout<<"请输入您准备修改书籍的编号：";
					cin>>no;
					int index=l.find_bookId(no);
					if(index==-1)
					{
						cout<<"没有你输入的编号！！！"<<endl;
					}
					else
					{
						l.showbook_index(index);
					    cout<<"请问你确定修改该书籍吗？（1/0）";
					    cin>>select;
					    if(select==1)
					    {   
					        cout<<"请您依次输入输入信息>>>" <<endl;  //修改该编号书籍的全部信息 
					        cout<<"书名            作者          类别          出版社           出版日期        价格  "<<endl;
							cin>>name>>author>>kind>>made>>year>>price;
							book b(no,name,author,kind,made,year,price);
					    	l.changebookAll(index,b);
						    cout<<"修改成功！！"<<endl; 
						}
						else
						{
							cout<<"您已放弃修改！！"<<endl;
						}
					}   
					system("pause"); 
					break;
				} 
	     	case 0: state =false;    break;
	     	default:  cout<<"亲，您输入错误   ";   system("pause");  break;
		 }
	} 
}

void sortFunction(library l)  //排序菜单 
{
	bool state = true; 
	int choice;
	while(state)
	{ 
	     system("cls"); 
	     menuSort();
	     cout<<"         请输入您的选择：";	
	     cin>>choice;
	     switch(choice)
	     {
	     	case 1: l.sortbookName();    break;     //按书名排序 
	     	case 2: l.sortbookAuthor();  break;     //按作者排序 
	     	case 3: l.sortbookYear();    break;     //按出版日期排序 
	     	case 4: l.sortbookPrice();   break;     //按价格排序 
	     	case 0: state =false;        break;
	     	default:  cout<<"亲，您输入错误   ";   system("pause");  break;
		 }
	} 
}


void menuMain()  //主菜单 
{
	bool state = true; 
	int choice;
	library l;
	while(state)
	{ 
	     system("cls"); 
	     menuShow();
	     cout<<"         请输入您的选择：";	
	     cin>>choice; 
	     switch(choice)
	     {
	     	case 1: 
			    if(l.getLib().size()!=0)      
			    {
			    	l.showBook();  
				}
			    else       //若Lib数组为空，则说明文件为空，需要使用者录入书籍信息 
				{
					cout<<"目前系统中没有图书信息，请您先录入信息！！！"<<endl;
					system("pause"); 
				}        
			    break;
	     	case 2: l.addBook();         break;
	     	case 3: deleteFunction(l);   break;    //进入修改菜单 
	     	case 4: findFunction(l);     break;    //进入查询菜单 
	     	case 5: changeFunction(l);   break;    //进入修改菜单 
	     	case 6: sortFunction(l);     break;    //进入排序菜单 
	     	case 0: state =false;    l.Exit();    break;    //退出主菜单，保存期间的全部操作 
	     	default:  cout<<"亲，您输入错误   ";   system("pause");  break;
		 }
	} 
}

int main()//主函数 
{
	int choice; 
	while(1)
	{
		system("cls");               //清屏 ，方便读阅 
		 cout<<endl<<endl<<endl;
	     cout<<"         ========================================================="<<endl;
	     cout<<"                                                                  "<<endl;
	     cout<<"                        欢迎进入图书信息管理系统                  "<<endl;
	     cout<<"                                                                  "<<endl;
	     cout<<"                                 1.菜单                           "<<endl;
         cout<<"                                                                  "<<endl;
         cout<<"                                 0.退出                           "<<endl;
         cout<<"                                                                  "<<endl;
         cout<<"         ========================================================="<<endl;
	     cout<<"         请输入您的选择：";
	     cin>>choice;
	     switch(choice)
	     {                               //选择1，进入主菜单 ，选择0，退出系统 
	     	case 1:    menuMain();      break;    
	     	case 0:    cout<<'\n'<<'\n'<<'\t'<<"欢迎您下次继续使用！！"<<endl;   exit(0);
	     	default:   cout<<"         亲，您输入错误    ";      system("pause");     break;
		 }
	} 
	return 0;
} 
