#include <iostream>

using namespace std;

#define MAX 100
class Sqlist {
public:
Sqlist();
void creat(); 
void creat1(int); 
void creat2(int);
void show();//����˳���
bool find(int a);//����ĳһ��Ԫ��
void JOpaixu();//��ż����
bool Symmetry();//�Գ��ж� 
void Insert1();
void Insert2();
void dizpaixu(); 
void hebing();
private:
	int data[MAX];
	int data1[MAX];
	int data2[MAX];
	int data3[MAX];
	int length;
	int length1;
	int length2;
};

 Sqlist::Sqlist()
{
     data[MAX]=0;
     data1[MAX]=0;
     data2[MAX]=0;
     length=0;
     length1=0;
     length2=0;
}

void Sqlist::creat()
{
	int a, b;
	cout << "������Ҫ������Ԫ�صĸ���:";
	cin >> a;
	for (int i = 0; i < a; i++)
	{
		cout << "������" << i + 1 << "��Ԫ��" << endl;
		cin >> b;
		data[i] = b;
		length++;
	}
}
void Sqlist::show()
{
	cout<<"˳���Ԫ��Ϊ:"; 
	for (int i = 0; i < length; i++)
	{
		cout << data[i]<<  " ";
	}
	cout << endl;
}

bool Sqlist::find(int a)
{
    cout<<"˳������Ƿ�������Ԫ��:";
	for (int i = 0; i < length; i++)
	{
		if (data[i] == a)
			return true;
	}
     return false;
     cout<<endl;
}

void Sqlist::JOpaixu()
{
	int k = 0;
	int b[length];
	for (int i = 0; i < length; i++)
	{
		if (data[i] % 2 == 1)
			b[k++] = data[i];
	}
	for (int j = 0; j < length; j++)
	{
		if (data[j] % 2 == 0)
			b[k++] = data[j];
	}
	cout<<"��ż������Ϊ:";
	for(int i=0;i<length;i++)
	{
		cout<<b[i]<<" ";
	}
	cout<<endl;
}
bool Sqlist::Symmetry()
{
	cout<<"˳����Ƿ�Գ�:";
	for (int i = 0; i < (length / 2); i++)
	{
		if (data[i] == data[length - 1 - i])
		{
			return true;
		}else{
			return false;
		}
	}
	
}
int r=0;
int y=0;
void Sqlist::creat1(int b)
{
		data1[r] = b;
		r++;
}
void Sqlist::Insert1()
{
	int a,b;
	cout << "������Ҫ�����ĵ�������Ԫ�صĸ���:";
	cin >> a;
	for(int i=0;i<a;i++)
	{
	    cout << "������" << i + 1 << "��Ԫ��" << endl;
	    cin>>b;
		creat1(b);
		length1++;
	}
}
void Sqlist::creat2(int b)
{
		data2[y] = b;
		y++;
}
void Sqlist::Insert2()
{
	int a,b;
	cout << "������Ҫ�����ĵ�������Ԫ�صĸ���:";
	cin >> a;
	for(int i=0;i<a;i++)
	{
	    cout << "������" << i + 1 << "��Ԫ��" << endl;
	    cin>>b;
		creat2(b);
		length2++;
	}
}
void Sqlist::dizpaixu()
{
	int temp;
	for(int i=0;i<length1-1;i++)
	{
		for(int j=0;j<length1-1-i;j++)
		{
			if(data1[j]>data1[j+1])
			{
				temp=data1[j];
				data1[j]=data1[j+1];
				data1[j+1]=temp;
			}
		}
	}
	for(int i=0;i<length2-1;i++)
	{
		for(int j=0;j<length2-1-i;j++)
		{
			if(data2[j]>data2[j+1])
			{
				temp=data2[j];
				data2[j]=data2[j+1];
				data2[j+1]=temp;
			}
		}
	}
	cout<<"������������ֱ�Ϊ:"<<endl;
	for(int i=0;i<length1;i++)
	{
		cout<<data1[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<length2;i++)
	{
		cout<<data2[i]<<" ";
	}
}
void Sqlist::hebing()
{
	int d=length1+length2;
     int k=0,i=0,j=0;
	while(i<length1&& j<length2)//ѭ����СԪ�ط��� 
	{
		if(data1[i]<data2[j]){
			data3[k]=data1[i];
			i++;
			k++;
		}else{
			data3[k]=data2[j];
			j++;
			k++;
		}
	}
	if(i==length1)//��һ������Ԫ����ȫ���ŵ��µ������У����ڶ�������ʣ��Ԫ��ȫ�ŵ��������� 
	{
		while(j<length2){
			data3[k]=data2[j];
			k++;
			j++;
		}
	}
		if(j==length2)//�ڸ�����Ԫ����ȫ���ŵ��µ������У����ڸ�����ʣ��Ԫ��ȫ�ŵ���������
		{
		while(i<length1){
			data3[k]=data1[i];
			k++;
			i++;
		}
	}
	cout<<"�ϲ��������Ϊ:";
	for(int i=0;i<d;i++)
	{
		cout<<data3[i]<<" ";
	}
}
int main()
{
	Sqlist S;
	S.creat();
	S.show();
	int a;
	cout << "������Ҫ���ҵ�Ԫ�أ�";
	cin >> a;
    cout<<S.find(a)<<endl;
    S.JOpaixu();
    cout<< S.Symmetry()<<endl;;
    S.Insert1();
    S.Insert2();
    S.dizpaixu();
    cout<<endl;
    S.hebing();
	return 0;
}
