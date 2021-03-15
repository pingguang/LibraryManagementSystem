#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
#include <iomanip>
#include<windows.h>
using namespace std;

//���ͼ���ࣻͼ�����԰�����ͼ���ţ�ͼ��������ͼ�����ߣ�ͼ�����ͼ������磬ͼ��������ڣ�ͼ��۸� 
class book  
{
	private:	
		int bookId;           // ͼ���ţ�ϵͳ�Զ����ɣ� 
		string bookName;      // ͼ������ 
		string bookAuthor;    // ͼ������
		string bookKind;      // ͼ�����
		string bookMade;      // ͼ�������
		string bookYear;      // ͼ���������
		float  bookPrice;     // ͼ��۸�
	public:
	    static int count;     //��̬���ݳ�Ա�����ڱ�����ɣ� 
		book(){};             //�޲ι��캯�� 
		book(string name,string author,string kind,string made,string year,float price);//���ι��캯�� 
		book(int id,string name,string author,string kind,string made,string year,float price); 
		int getbookId();                        // ���ڻ��ͼ��ı�� 
		void setbookName(string name);		    // ��������ͼ������� 
		string getbookName();	                // ���ڻ��ͼ������� 
		void setbookAuthor(string author);      // ��������ͼ������� 
		string getbookAuthor();                 // ���ڻ��ͼ�������  
		void setbookKind(string kind);          // ��������ͼ������ 
		string getbookKind();                   // ���ڻ��ͼ������  
		void setbookMade(string made);          // ��������ͼ��ĳ��浥λ 
		string getbookMade();	                // ���ڻ��ͼ��ĳ��浥λ 
		void setbookYear(string year);          // ��������ͼ��ĳ������� 
		string getbookYear();                   // ���ڻ��ͼ��ĳ�������  
		void setbookPrice(float price);         // ��������ͼ��ļ۸�
		float getbookPrice();                   // ���ڻ��ͼ��ļ۸�
		void bookShown();                       // ������ʾͼ����Ϣ 
		void bookShow();                        // ������ʾͼ����Ϣ 

};
//**************************book��ĳ�Ա���� *************************************** 
book::book(string name,string author,string kind,string made,string year,float price)//���캯���������鼮¼�� 
{
	bookId=count++;
	bookName=name;
	bookAuthor=author;
	bookKind=kind;
	bookMade=made;
	bookYear=year;
	bookPrice=price;
}

book::book(int id,string name,string author,string kind,string made,string year,float price)//���캯���������鼮�޸� 
{
	bookId=id;
	bookName=name;
	bookAuthor=author;
	bookKind=kind;
	bookMade=made;
	bookYear=year;
	bookPrice=price;
}

int book::getbookId()    //���ͼ���� 
{
	return bookId;	
}
				
void book::setbookName(string name)//����ͼ������ 
{
	bookName=name;
}

string book::getbookName()//���ͼ������ 
{
	return bookName;
}
		
void book::setbookAuthor(string author)//����ͼ������ 
{
	bookAuthor=author;
}

string book::getbookAuthor()//���ͼ������ 
{
	return bookAuthor;
}
		
void book::setbookKind(string kind)//����ͼ����� 
{
	bookKind=kind;
}

string book::getbookKind()//���ͼ����� 
{
	return bookKind;
}

void book::setbookMade(string made)//����ͼ������� 
{
	bookMade=made;
}

string book::getbookMade()//���ͼ������� 
{
	return bookMade;
}
		
void book::setbookYear(string year)//����ͼ��������� 
{
	bookYear=year;
}
		
string book::getbookYear()//���ͼ��������� 
{
	return bookYear;
}
		
void book::setbookPrice(float price)//����ͼ��۸� 
{
	bookPrice=price;
}

float book::getbookPrice()//���ͼ��۸� 
{
	return bookPrice;
}

void book::bookShown()//���ͼ�����Ϣ������ͼ�����ʱ 
{
	cout<<"��¼�ţ�"<<left<<setw(10)<<bookId<<"������"<<left<<setw(15)<<bookName<<"���ߣ�"<<left<<setw(15)<<bookAuthor<<"���"<<left<<setw(15)<<bookKind<<"���浥λ��"<<left<<setw(20)<<bookMade<<"����ʱ�䣺"<<left<<setw(10)<<bookYear<<"�۸�"<<left<<setw(10)<<bookPrice<<endl; 
}
		
void book::bookShow()//���ͼ����Ϣ������ͼ�����ʱ 
{
	cout<<setw(15)<<bookId<<setw(25)<<bookName<<setw(15)<<bookAuthor<<setw(15)<<bookKind<<setw(25)<<bookMade<<setw(15)<<bookYear<<setw(15)<<bookPrice<<endl; 
}

//*****************************�ȽϺ�����������**************************** 
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
vector<int>  op;     //����һ��ȫ�ֱ��������ڴ�Ŷ�����±�
	
//**************************************�鼮���������� ******************************* 
class library  
{
    private:
		vector<book> Lib;     //��̬����Lib���ڴ���鼮 
	public:
		library();            //���캯�������ı��ļ��ж�ȡ���ݳ�ʼ������Lib 
	    void Exit();	      //�˳��������˳����˵�ʱ���ã���Lib�е���Ϣд���ı��ļ� 
	    void addBook();		  //���ͼ�� 
	    void showBook()	;	  //���ͼ����Ϣ 
		void showbook_index(int index);	   //�����±���ʾͼ����Ϣ 
	    vector<book> getLib();	           //���Lib���� 
		int find_bookId(int id);		   //����ͼ���Ų�ѯ������ͼ���������е��±� 
	    void find_show();	   	           //�������ҵ�������ȫ����� 
		int indexOfId(int id);	           //���ݱ�Ų��� 
		void indexOfName(string name);	   //������������	
		void indexOfAuthor(string author); //�������߲��� 
		void indexOfMade(string made);	   //���ݳ�������� 
		void indexOfKind(string kind);     //���������� 
		void indexOfYear(string year);	   //���ݳ������ڲ��� 
		void indexOfPrice(float price);	   //���ݼ۸����		
		void delete_book();	               //ɾ��ͼ�� 
		void changebookName(int i,string name);	     //���ݱ���޸����� 
		void changebookAuthor(int i,string author);	 //���ݱ���޸�����	
		void changebookYear(int i,string year);	     //���ݱ���޸ĳ������� 
		void changebookPrice(int i,float price);	 //���ݱ���޸ļ۸� 
		void changebookAll(int i,book b);		     //���ݱ���޸�������Ϣ 
        void sortbookName();                         //������������ 
	    void sortbookAuthor();                       //������������ 
	    void sortbookYear();                         //���ճ����������� 
	    void sortbookPrice();                        //���ռ۸����� 
};
//**************************library��ĳ�Ա����*************************** 
library::library()     //���캯�������ڳ�ʼ��Lib���� 
{
	ifstream f("book.txt");  //���ı��ļ���ʽ��book.txt�ļ� 
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
   
void library::Exit()	    //�˳����������˳����˵���ʱ��ʹ���߽��еĲ������浽�ļ����� 
{	    
	ofstream output("book.txt");            
	if(!output)
	{	          
		cout<<"File cannot be opened."<<endl;	       
	}	        
	for(int i=0;i<Lib.size();i++)	        //ͼ����Ϣд�� 
	{	           
		output<<Lib[i].getbookId()<<'\t'<<Lib[i].getbookName()<<'\t'<<Lib[i].getbookAuthor()<<'\t'<<Lib[i].getbookKind()<<'\t'<<Lib[i].getbookMade()<<'\t'<<Lib[i].getbookYear()<<'\t'<<Lib[i].getbookPrice()<<'\t'<<endl;
	        
	}	        
	output.close();	   
}
	    
void library::addBook()	    //ͼ��¼�뺯�� 
{ 	      
	while(1)	     
	{ 	        
		int choice=0;	        
		string name,author,kind,made,year;			
		float price; 	    	
		cout<<"����������: ";            
		cin>>name;		    
		cout<<"����������: ";            
		cin>>author;            
		cout<<"���������: ";            
		cin>>kind;            
		cout<<"�����������: ";            
		cin>>made;            
		cout<<"�������������: ";            
		cin>>year;            
		cout<<"������۸�: ";            
		cin>>price;            
		book b(name,author,kind,made,year,price);             
		Lib.push_back(b);            
		cout<<"�Ƿ����¼�룺��1/0��";             
		cin>>choice;           
		if(choice==0)              
			break;		  
	}		
}
				
void library::showBook()	//ͼ����Ϣ������������ڲ���ʱ 
{
	 int i;
	 cout<<setw(15)<<"�鼮���"<<setw(25)<<"�鼮����"<<setw(15)<<"�鼮����"<<setw(15)<<"�鼮���"<<setw(25)<<"���浥λ"<<setw(15)<<"����ʱ��"<<setw(15)<<"�鼮�۸�"<<endl; 
	 for(i=0;i<Lib.size();i++)
	 {
	   	Lib[i].bookShow();  //����book��ĳ�Ա�������ͼ����Ϣ 
	 }
	system("pause");
}
		
void library::showbook_index(int index) //�����±������Ӧλ�õ�ͼ����Ϣ 
{
	Lib[index].bookShown();
}
	
vector<book> library::getLib()    //����Lib���� 
{
	return Lib;
}

int library::find_bookId(int id)    //���ݱ�Ų������Ӧ���±꣬���ö��ַ����� 
{
	int low=0,mid,high=Lib.size();
	while(low<=high)
	{
		mid=(low+high)/2;
		if(Lib[mid].getbookId()==id)
		    return mid;                 //���ҵ��������±� 
		else if(id<Lib[mid].getbookId())
			high=mid-1;
	    else
			low=mid+1;
	}
	return -1;     //��δ�ҵ�������-1 
}
		
int library::indexOfId(int id)  //���ݱ�Ų��� 
{
	int i;
	for(i=0;i<Lib.size();i++)
	{
		if(Lib[i].getbookId()==id)
		   op.push_back(i);    //���ҵ����Ѹ��鼮���±�Ž�op���鵱�� 
	}
}
		
void library::indexOfName(string name)//������������ 
{
	int i;
	for(i=0;i<Lib.size();i++)
	{                        //�������ҵ���ȫ���鼮���±�Ž�op���鵱�� 
		if(Lib[i].getbookName()==name)
		  op.push_back(i);
	}
} 
		
void library::indexOfAuthor(string author)//�������߲��� 
{
	int i;
	for(i=0;i<Lib.size();i++)
	{                        //�������ҵ���ȫ���鼮���±�Ž�op���鵱�� 
		if(Lib[i].getbookAuthor()==author)
		  op.push_back(i);
	}
} 
		
void library::indexOfMade(string made)//���ݳ�������� 
{
	int i;
	for(i=0;i<Lib.size();i++)
	{                        //�������ҵ���ȫ���鼮���±�Ž�op���鵱�� 
    	if(Lib[i].getbookMade()==made)
		   op.push_back(i);
	}
} 
		
void library::indexOfKind(string kind)//����ͼ��������	
{			
	int i;			
	for(i=0;i<Lib.size();i++)
	{			            //�������ҵ���ȫ���鼮���±�Ž�op���鵱�� 
		if(Lib[i].getbookKind()==kind)				
			op.push_back(i);			
	}		
} 
		
void library::indexOfYear(string year)//���ݳ������ڲ���	
{			
	int i;			
	for(i=0;i<Lib.size();i++)			
	{                        //�������ҵ���ȫ���鼮���±�Ž�op���鵱�� 				
		if(Lib[i].getbookYear()==year)				   
			op.push_back(i);			
	}		
} 
		
void library::indexOfPrice(float price)	//����ͼ��۸����	
{			
	int i;			
	for(i=0;i<Lib.size();i++)			
	{                        //�������ҵ���ȫ���鼮���±�Ž�op���鵱�� 				
		if(Lib[i].getbookPrice()==price)
			op.push_back(i);
	}
} 
	
void library::find_show()	    //���Ҳ�������������ҵ���ȫ����Ϣ��� 
{
	int i;
	for(i=0;i<op.size();i++)
	{
	  	Lib[op[i]].bookShown();
	}
}
				
void library::delete_book()	  //ɾ��ȫ������Ҫ����鼮 
{		
	int i;
	for(i=op.size()-1;i>=0;i--)
	Lib.erase(Lib.begin()+op[i]);
}


void library::changebookName(int i,string name)//�޸��±�Ϊi���鼮������ 
{
	Lib[i].setbookName(name);
}

void library::changebookAuthor(int i,string author)//�޸��±�Ϊi���鼮������ 
{
	Lib[i].setbookAuthor(author);
}
void library::changebookYear(int i,string year)//�޸��±�Ϊi���鼮�ĳ�������
{
	Lib[i].setbookYear(year);
}
void library::changebookPrice(int i,float price)//�޸��±�Ϊi���鼮�ļ۸�
{
	Lib[i].setbookPrice(price);
}
void library::changebookAll(int i,book b)//�޸��±�Ϊi���鼮��ȫ����Ϣ 
{
	Lib[i]=b;
}
 
void library::sortbookName()  //�����������򣨴�С���� 
{
    sort(Lib.begin(),Lib.end(),compareName);
   	showBook();     //��ʾ������ͼ����Ϣ 
}
void library::sortbookAuthor()//�����������򣨴�С����
{
    sort(Lib.begin(),Lib.end(),compareAuthor);
    showBook();
}
void library::sortbookYear()//���ճ����������򣨴�С����
{
    sort(Lib.begin(),Lib.end(),compareYear);
    showBook();
}
void library::sortbookPrice()//���ռ۸����򣨴�С����
{
    sort(Lib.begin(),Lib.end(),comparePrice);
    showBook();
}

int book::count=0; 

void menuDelete()//ɾ������˵� 
{
	 cout<<endl<<endl<<endl;
	 cout<<"         ========================================================="<<endl;
	 cout<<"                                                                  "<<endl;
	 cout<<"                                 ɾ���˵�                         "<<endl;
	 cout<<"                                                                  "<<endl;
	 cout<<"                 1.���ձ��ɾ��              2.��������ɾ��       "<<endl;
     cout<<"                                                                  "<<endl;
     cout<<"                 3.��������ɾ��              4.�������ɾ��       "<<endl;
     cout<<"                                                                  "<<endl;
     cout<<"                                0.�˳�ɾ���˵�                    "<<endl;
     cout<<"                                                                  "<<endl;
     cout<<"         ========================================================="<<endl; 
} 
void menuFind()//���ҽ���˵� 
{
	 cout<<endl<<endl<<endl;
	 cout<<"         ========================================================="<<endl;
	 cout<<"                                                                  "<<endl;
	 cout<<"                                 ��ѯ�˵�                         "<<endl;
	 cout<<"                                                                  "<<endl;
	 cout<<"                 1.��Ų���                  2.��������           "<<endl;
     cout<<"                                                                  "<<endl;
     cout<<"                 3.���߲���                  4.������           "<<endl;
     cout<<"                                                                  "<<endl;
     cout<<"                 5.�������ڲ���              6.�۸����           "<<endl;
     cout<<"                                                                  "<<endl;
     cout<<"                               0.�˳���ѯ                         "<<endl;
     cout<<"                                                                  "<<endl;
     cout<<"         ========================================================="<<endl;
} 

void menuChange()//�޸Ľ���˵� 
{
	 cout<<endl<<endl<<endl;
	 cout<<"         ========================================================="<<endl;
	 cout<<"                                                                  "<<endl;
	 cout<<"                                 �޸Ĳ˵�                         "<<endl;
	 cout<<"                                                                  "<<endl;
	 cout<<"                 1.�޸�����                  2.�޸�����           "<<endl;
     cout<<"                                                                  "<<endl;
     cout<<"                 3.�޸�����                  4.�޸ļ۸�           "<<endl;
     cout<<"                                                                  "<<endl;
     cout<<"                 5.�޸�������Ϣ              0.�˳��޸�           "<<endl;
     cout<<"                                                                  "<<endl;
     cout<<"         ========================================================="<<endl; 
} 


void menuSort()//�������˵� 
{
	 cout<<endl<<endl<<endl;
	 cout<<"         ========================================================="<<endl;
	 cout<<"                                                                  "<<endl;
	 cout<<"                                 ����˵�                         "<<endl;
	 cout<<"                                                                  "<<endl;
	 cout<<"                 1.����������               2.������������        "<<endl;
     cout<<"                                                                  "<<endl;
     cout<<"                 3.���ճ�����������         4.���ռ۸�����        "<<endl;
     cout<<"                                                                  "<<endl;
     cout<<"                               0.�˳�����˵�                     "<<endl;
     cout<<"                                                                  "<<endl;
     cout<<"         ========================================================="<<endl; 
}

 
void menuShow()//���˵� 
{
	 cout<<endl<<endl<<endl;
	 cout<<"         ========================================================="<<endl;
	 cout<<"                                                                  "<<endl;
	 cout<<"                           ͼ�����ϵͳ�˵�                       "<<endl;
	 cout<<"                                                                  "<<endl;
	 cout<<"                              1.���ͼ��                          "<<endl;
     cout<<"                                                                  "<<endl;
     cout<<"                              2.����ͼ��                          "<<endl;
     cout<<"                                                                  "<<endl;
     cout<<"                              3.ɾ��ͼ��                          "<<endl;
     cout<<"                                                                  "<<endl;
     cout<<"                              4.����ͼ��                          "<<endl;
     cout<<"                                                                  "<<endl;
     cout<<"                              5.�޸�ͼ��                          "<<endl;
     cout<<"                                                                  "<<endl;
     cout<<"                              6.����ͼ��                          "<<endl;
     cout<<"                                                                  "<<endl;
     cout<<"                              0.�˳��˵�                          "<<endl;
     cout<<"                                                                  "<<endl;
     cout<<"         ========================================================="<<endl;
} 

void deleteFunction(library &l)  //ɾ������ 
{
	bool state = true; 
	int choice,no,select;
	string ss;
	while(state)
	{ 
	     system("cls");    //���� 
	     menuDelete();
	     cout<<"         ����������ѡ��";	
	     cin>>choice;
	     switch(choice)
	     {
	     	case 1: 
	     	    {
					cout<<"��������׼��ɾ���鼮�ı�ţ�";
					cin>>no; 
			        l.indexOfId(no);    //���Ҹñ���Ƿ���� 
			       	if(op.size()==0)
			        {
					    cout<<"û���ҵ������Ƶ��鼮����"<<endl; 
					} 
					else               
					{
						l.find_show();
					    cout<<"������ȷ��ɾ����Щ�鼮�𣿣�1/0��";  //ѯ���Ƿ�ɾ�����鼮 
					    cin>>select;
					    if(select==1)   
					    {   
					        l.delete_book();
			        	    cout<<"ɾ���ɹ�����"<<endl; 
			        	    op.clear();
						}
						else
						{
							cout<<"���ѷ���ɾ������"<<endl;
						}
					}
					system("pause");
			        break;
			    }
	     	case 2: 
			    {
					cout<<"��������׼��ɾ���鼮��������";
					cin>>ss; 
			        l.indexOfName(ss);
			        if(op.size()==0)
			        {
					    cout<<"û���ҵ������Ƶ��鼮����"<<endl; 
					} 
					else               
					{
						l.find_show();
					    cout<<"������ȷ��ɾ����Щ�鼮�𣿣�1/0��";  //ѯ���Ƿ�ɾ�����鼮 
					    cin>>select;
					    if(select==1)   
					    {   
					        l.delete_book();
			        	    cout<<"ɾ���ɹ�����"<<endl; 
			        	    op.clear();
						}
						else
						{
							cout<<"���ѷ���ɾ������"<<endl;
						}
					}
					system("pause");
			        break;
			    }
	     	case 3:
			    { 
			        cout<<"��������׼��ɾ���鼮�����ߣ�";
					cin>>ss; 
			        l.indexOfAuthor(ss);
			        if(op.size()==0)
			        {
					    cout<<"û���ҵ������Ƶ��鼮����"<<endl; 
					} 
					else               
					{
						l.find_show();
					    cout<<"������ȷ��ɾ����Щ�鼮�𣿣�1/0��";  //ѯ���Ƿ�ɾ�����鼮 
					    cin>>select;
					    if(select==1)   
					    {   
					        l.delete_book();
			        	    cout<<"ɾ���ɹ�����"<<endl; 
			        	    op.clear();
						}
						else
						{
							cout<<"���ѷ���ɾ������"<<endl;
						}
					}
					system("pause");
			        break;
			    }
	     	case 4: 
	     	    {
			        cout<<"��������׼��ɾ���鼮�ĳ������ڣ�";
					cin>>ss; 
			        l.indexOfYear(ss);
			        if(op.size()==0)
			        {
					    cout<<"û���ҵ������Ƶ��鼮����"<<endl; 
					} 
					else               
					{
						l.find_show();
					    cout<<"������ȷ��ɾ����Щ�鼮�𣿣�1/0��";  //ѯ���Ƿ�ɾ�����鼮 
					    cin>>select;
					    if(select==1)   
					    {   
					        l.delete_book();
			        	    cout<<"ɾ���ɹ�����"<<endl; 
			        	    op.clear();
						}
						else
						{
							cout<<"���ѷ���ɾ������"<<endl;
						}
					}
					system("pause");
			        break;
			    }
	     	case 0: state =false;    break;  //�˳�ɾ���˵��� 
	     	default:  cout<<"�ף����������   ";   system("pause");  break;
		 }
	} 
}

void findFunction(library l)//���Һ��� 
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
	     cout<<"         ����������ѡ��";	
	     cin>>choice;
	     switch(choice)
	     {
	     	case 1: 
			        cout<<"��������׼�������鼮�ı�ţ�";
					cin>>no;
					l.indexOfId(no);
			        if(op.size()!=0)
			        {
			        	l.find_show();
			        	op.clear();
					}
					else
					{
						cout<<"û���ҵ������ߵ��鼮����"<<endl; 
					}
				system("pause");
			        break;
	     	case 2:
			        cout<<"��������׼�������鼮��������";
					cin>>ss;
					l.indexOfName(ss);    //�ҵ���������Ϊss���鼮 ���±����op���� 
			        if(op.size()!=0)
			        {
			        	l.find_show();    //��������鼮��Ϊss���鼮��Ϣ 
			        	op.clear();       //���op���� 
					}
					else
					{
						cout<<"û���ҵ������ߵ��鼮����"<<endl; 
					}
					system("pause");
			        break;
	     	case 3: 
			        cout<<"��������׼�������鼮�����ߣ�";
					cin>>ss;
					l.indexOfAuthor(ss);
			        if(op.size()!=0)
			        {
			        	l.find_show();
			        	op.clear();
					}
					else
					{
						cout<<"û���ҵ������ߵ��鼮����"<<endl; 
					}
					system("pause");
			        break;
	     	case 4: 
			        cout<<"��������׼�������鼮�����";
					cin>>ss;
					l.indexOfKind(ss);
			        if(op.size()!=0)
			        {
			        	l.find_show();
			        	op.clear();
					}
					else
					{
						cout<<"û���ҵ��������鼮����"<<endl; 
					}
					system("pause");
			        break;	     	
			case 5: 
			        cout<<"��������׼�������鼮�ĳ������ڣ�";
					cin>>ss;
					l.indexOfYear(ss);
			        if(op.size()!=0)
			        {
			        	l.find_show();
			        	op.clear();
					}
					else
					{
						cout<<"û���ҵ������ߵ��鼮����"<<endl; 
					}
					system("pause");
			        break;
			case 6: 
			        cout<<"��������׼�������鼮�ļ۸�";
					cin>>price;
					l.indexOfPrice(price);
			        if(op.size()!=0)
			        {
			        	l.find_show();
			        	op.clear();
					}
					else
					{
						cout<<"û���ҵ������ߵ��鼮����"<<endl; 
					}
					system("pause");
			        break;
	     	case 0: state =false;    break;   //�˳���ѯ�˵� 
	     	default:  cout<<"�ף����������   ";   system("pause");  break;
		 }
	} 
}

void changeFunction(library &l)//�޸Ĳ˵� 
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
	     cout<<"         ����������ѡ��";	
	     cin>>choice;
	     switch(choice)
	     {
	     	case 1: 
	           	{
			        cout<<"��������׼���޸��鼮�ı�ţ�";
					cin>>no;
					int index=l.find_bookId(no);    //�ҵ����Ϊno���鼮���±� 
					if(index==-1)     //����Ϊ-1��˵��û���ҵ��ˣ������ʾ��� 
					{
						cout<<"û��������ı�ţ�����"<<endl;
					}
					else               //���ز�Ϊ-1��˵���ҵ���
					{
						l.showbook_index(index);  //������鼮��ȫ����Ϣ 
					    cout<<"������ȷ���޸ĸ��鼮�𣿣�1/0��";  //ѯ���Ƿ��޸ĸ��鼮 
					    cin>>select;
					    if(select==1)   //��ȷ���޸ģ�������޸� 
					    {   
					        cout<<"�������µ�������" ;
							cin>>ss; 
					    	l.changebookName(index,ss);  //����changebookName()�����޸����� 
						    cout<<"�޸ĳɹ�����"<<endl; 
						}
						else   //����ȷ���޸ģ��������ʾ��� 
						{
							cout<<"���ѷ����޸ģ���"<<endl;
						}
					}
					system("pause");
			        break;
			    }
	     	case 2: 
	     	   {
			        cout<<"��������׼���޸��鼮�ı�ţ�";
					cin>>no;
					int index=l.find_bookId(no);
					if(index==-1)
					{
						cout<<"û��������ı�ţ�����"<<endl;
					}
					else
					{
						l.showbook_index(index);
					    cout<<"������ȷ���޸ĸ��鼮�𣿣�1/0��";
					    cin>>select;
					    if(select==1)
					    {   
					        cout<<"�������µ����ߣ�" ;
							cin>>ss; 
					    	l.changebookAuthor(index,ss);
						    cout<<"�޸ĳɹ�����"<<endl; 
						}
						else
						{
							cout<<"���ѷ����޸ģ���"<<endl;
						}
					}
					system("pause"); 
					break;
					
				}
	     	case 3: 
	     	   {   
			        cout<<"��������׼���޸��鼮�ı�ţ�";
					cin>>no;
					int index=l.find_bookId(no);
					if(index==-1)
					{
						cout<<"û��������ı�ţ�����"<<endl;
					}
					else
					{
						l.showbook_index(index);
					    cout<<"������ȷ���޸ĸ��鼮�𣿣�1/0��";
					    cin>>select;
					    if(select==1)
					    {   
					        cout<<"�������µĳ������ڣ�" ;
							cin>>ss; 
					    	l.changebookYear(index,ss);
						    cout<<"�޸ĳɹ�����"<<endl; 
						}
						else
						{
							cout<<"���ѷ����޸ģ���"<<endl;
						}
					}  
					system("pause"); 
					break;
				}
	     	case 4:
	     		{
			        cout<<"��������׼���޸��鼮�ı�ţ�";
					cin>>no;
					int index=l.find_bookId(no);
					if(index==-1)
					{
						cout<<"û��������ı�ţ�����"<<endl;
					}
					else
					{
						l.showbook_index(index);
					    cout<<"������ȷ���޸ĸ��鼮�𣿣�1/0��";
					    cin>>select;
					    if(select==1)
					    {   
					        cout<<"�������µļ۸�" ;
							cin>>price; 
					    	l.changebookPrice(index,price);
						    cout<<"�޸ĳɹ�����"<<endl; 
						}
						else
						{
							cout<<"���ѷ����޸ģ���"<<endl;
						}
					}  
					system("pause");   
					break;
				}
	     	case 5: 
	     	   {
	     	        string name,author,kind,year,made;
	     	        float price;
			        cout<<"��������׼���޸��鼮�ı�ţ�";
					cin>>no;
					int index=l.find_bookId(no);
					if(index==-1)
					{
						cout<<"û��������ı�ţ�����"<<endl;
					}
					else
					{
						l.showbook_index(index);
					    cout<<"������ȷ���޸ĸ��鼮�𣿣�1/0��";
					    cin>>select;
					    if(select==1)
					    {   
					        cout<<"������������������Ϣ>>>" <<endl;  //�޸ĸñ���鼮��ȫ����Ϣ 
					        cout<<"����            ����          ���          ������           ��������        �۸�  "<<endl;
							cin>>name>>author>>kind>>made>>year>>price;
							book b(no,name,author,kind,made,year,price);
					    	l.changebookAll(index,b);
						    cout<<"�޸ĳɹ�����"<<endl; 
						}
						else
						{
							cout<<"���ѷ����޸ģ���"<<endl;
						}
					}   
					system("pause"); 
					break;
				} 
	     	case 0: state =false;    break;
	     	default:  cout<<"�ף����������   ";   system("pause");  break;
		 }
	} 
}

void sortFunction(library l)  //����˵� 
{
	bool state = true; 
	int choice;
	while(state)
	{ 
	     system("cls"); 
	     menuSort();
	     cout<<"         ����������ѡ��";	
	     cin>>choice;
	     switch(choice)
	     {
	     	case 1: l.sortbookName();    break;     //���������� 
	     	case 2: l.sortbookAuthor();  break;     //���������� 
	     	case 3: l.sortbookYear();    break;     //�������������� 
	     	case 4: l.sortbookPrice();   break;     //���۸����� 
	     	case 0: state =false;        break;
	     	default:  cout<<"�ף����������   ";   system("pause");  break;
		 }
	} 
}


void menuMain()  //���˵� 
{
	bool state = true; 
	int choice;
	library l;
	while(state)
	{ 
	     system("cls"); 
	     menuShow();
	     cout<<"         ����������ѡ��";	
	     cin>>choice; 
	     switch(choice)
	     {
	     	case 1: 
			    if(l.getLib().size()!=0)      
			    {
			    	l.showBook();  
				}
			    else       //��Lib����Ϊ�գ���˵���ļ�Ϊ�գ���Ҫʹ����¼���鼮��Ϣ 
				{
					cout<<"Ŀǰϵͳ��û��ͼ����Ϣ��������¼����Ϣ������"<<endl;
					system("pause"); 
				}        
			    break;
	     	case 2: l.addBook();         break;
	     	case 3: deleteFunction(l);   break;    //�����޸Ĳ˵� 
	     	case 4: findFunction(l);     break;    //�����ѯ�˵� 
	     	case 5: changeFunction(l);   break;    //�����޸Ĳ˵� 
	     	case 6: sortFunction(l);     break;    //��������˵� 
	     	case 0: state =false;    l.Exit();    break;    //�˳����˵��������ڼ��ȫ������ 
	     	default:  cout<<"�ף����������   ";   system("pause");  break;
		 }
	} 
}

int main()//������ 
{
	int choice; 
	while(1)
	{
		system("cls");               //���� ��������� 
		 cout<<endl<<endl<<endl;
	     cout<<"         ========================================================="<<endl;
	     cout<<"                                                                  "<<endl;
	     cout<<"                        ��ӭ����ͼ����Ϣ����ϵͳ                  "<<endl;
	     cout<<"                                                                  "<<endl;
	     cout<<"                                 1.�˵�                           "<<endl;
         cout<<"                                                                  "<<endl;
         cout<<"                                 0.�˳�                           "<<endl;
         cout<<"                                                                  "<<endl;
         cout<<"         ========================================================="<<endl;
	     cout<<"         ����������ѡ��";
	     cin>>choice;
	     switch(choice)
	     {                               //ѡ��1���������˵� ��ѡ��0���˳�ϵͳ 
	     	case 1:    menuMain();      break;    
	     	case 0:    cout<<'\n'<<'\n'<<'\t'<<"��ӭ���´μ���ʹ�ã���"<<endl;   exit(0);
	     	default:   cout<<"         �ף����������    ";      system("pause");     break;
		 }
	} 
	return 0;
} 
