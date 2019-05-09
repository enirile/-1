#include <iostream>

using namespace std;

#define MAX 100
class Sqlist {
public:
Sqlist();
void creat(); 
void creat1(int); 
void creat2(int);
void show();//遍历顺序表
bool find(int a);//查找某一个元素
void JOpaixu();//奇偶排序
bool Symmetry();//对称判断 
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
	cout << "请输入要创建的元素的个数:";
	cin >> a;
	for (int i = 0; i < a; i++)
	{
		cout << "请输入" << i + 1 << "个元素" << endl;
		cin >> b;
		data[i] = b;
		length++;
	}
}
void Sqlist::show()
{
	cout<<"顺序表元素为:"; 
	for (int i = 0; i < length; i++)
	{
		cout << data[i]<<  " ";
	}
	cout << endl;
}

bool Sqlist::find(int a)
{
    cout<<"顺序表中是否存在这个元素:";
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
	cout<<"奇偶排序结果为:";
	for(int i=0;i<length;i++)
	{
		cout<<b[i]<<" ";
	}
	cout<<endl;
}
bool Sqlist::Symmetry()
{
	cout<<"顺序表是否对称:";
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
	cout << "请输入要创建的递增数组元素的个数:";
	cin >> a;
	for(int i=0;i<a;i++)
	{
	    cout << "请输入" << i + 1 << "个元素" << endl;
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
	cout << "请输入要创建的递增数组元素的个数:";
	cin >> a;
	for(int i=0;i<a;i++)
	{
	    cout << "请输入" << i + 1 << "个元素" << endl;
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
	cout<<"两个递增数组分别为:"<<endl;
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
	while(i<length1&& j<length2)//循环将小元素放入 
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
	if(i==length1)//第一个数组元素已全部放到新的数组中，将第二个数组剩余元素全放到新数组中 
	{
		while(j<length2){
			data3[k]=data2[j];
			k++;
			j++;
		}
	}
		if(j==length2)//第个数组元素已全部放到新的数组中，将第个数组剩余元素全放到新数组中
		{
		while(i<length1){
			data3[k]=data1[i];
			k++;
			i++;
		}
	}
	cout<<"合并后的数组为:";
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
	cout << "请输入要查找的元素：";
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
