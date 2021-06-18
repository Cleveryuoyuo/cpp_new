#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<bitset>
#include<stdlib.h>
#include<assert.h>
#include<fstream> //cpp的输入输出的头文件名
#include<string>
#include<sstream>
using namespace std;

void main()
{
	int a = 783952;
	string str;
	stringstream ss; //好处是 不用考虑空间 
	//先将a输出给字符串流ss
	ss << a;
	//再将处理好的ss 输入给str；
	ss >> str;
	cout << str << endl;
	//ss底层就有一个str对象
	cout << ss.str() << endl;
	//ss使用后 必须清除一下  否则原来的数据依旧存在  
	//因为以 0/ 结尾的 所以下一个进来 也看不到
	ss.clear();

	int b = 8384;
	ss << b;
	ss >> str;
	cout << str << endl;
}

/*
//整形转化字符串的情况
void main()
{
	int a = 986725;
	char str[30] = { 0 };
	//将a中的每一个末尾 处理成一个字符存入str中
	//参数是 数字 存入的位置 以几进制处理
	//itoa(a, str, 10);  

	sprintf(str, "%d", a);
	//给str中以%d的形式放a
	cout << str << endl;
}


/*
//配置管理类的作用是将ip和端口的内容，从电脑中读取出来放在一个结构体里面
struct ServerInfo
{
	char _ip[32];
	int _port;
};
class ConfigManager
{
public:
	ConfigManager(string cfg = "ghcserver.txt")
		:_configfile(cfg)
	{}
public:
	void ReadInfo(ServerInfo &info)//把结构体放进去用来存数据
	{
		ifstream ifile(_configfile.c_str(), ios::in);//.c_str() string对象转化为指针类型
		assert(ifile);
		ifile >> info._ip >> info._port;
		ifile.close();
	}
	void WriteInfo(ServerInfo &info)
	{
		ofstream ofile(_configfile.c_str(), ios::out);
		assert(ofile);
		ofile << info._ip << " " << info._port;
		ofile.close();
	}
private:
	string _configfile;
};

void main()
{
	ConfigManager config;
	ServerInfo ser_info = { "10.125.18.131", 8989 };
	config.WriteInfo(ser_info);

	//ServerInfo ser_info;
	//config.ReadInfo(ser_info);
}

/* 
//c++的读写
void main()
{
	int ar[10];
	int size = sizeof(ar) / sizeof(ar[0]);
	ifstream  ifile;
	ifile.open("Test22.txt", ios::in | ios::binary);
	//二进制写入 因为二进制没有转化 所以是乱码
	assert(ifile);
	ifile.read((char*)ar, sizeof(int)*size);
	ifile.close();
}

/*
//c++的写文件
void main()
{
	int ar[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int size = sizeof(ar) / sizeof(ar[0]);
	ofstream  ofile;
	ofile.open("Test22.txt", ios::out | ios::binary);
	//二进制写入 因为二进制没有转化 所以是乱码
	assert(ofile);
	ofile.write((const char*)ar, sizeof(int)*size);
	
	ofile.close();
}

/*
//c语言的二进制读取
void main()
{
	int ar[10];
	int size = sizeof(ar) / sizeof(ar[0]);
	FILE* fp = fopen("Test11.txt", "rb");
	//二进制读出 
	assert(fp != NULL);
	fread(ar,sizeof(int),10,fp);
	fclose(fp);
}

/*
void main()
{
	int ar[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int size = sizeof(ar) / sizeof(ar[0]);
	FILE* fp = fopen("Test11.txt", "wb");
	//二进制写入 因为二进制没有转化 所以是乱码
	assert(fp != NULL);
	fwrite(ar, size, sizeof(int), fp);
	fclose(fp);
}

/*
//通过文本文件读写  都是字符
//cpp的输入流写法
void main()
{
	int ar[10];
	ifstream ifile;
	ifile.open("Test2.txt", ios::in);
	assert(ifile);

	for (int i = 0; i < 10; ++i)
		ifile >> ar[i];
	ifile.close();
}

/*
//cpp的输出流写法
void main()
{
	int ar[] = { 11, 22, 33, 44, 55, 66, 77, 88, 99 };
	int n = sizeof(ar) / sizeof(ar[0]);

	ofstream ofile;

	ofile.open("Test2.txt", ios::out);
	assert(ofile);

	for (int i = 0; i < n; ++i)
		ofile << ar[i] << " ";
	ofile << endl;
	ofile << "end";
	ofile.close();

}


/*
//c语言的读
void main()
{
	int ar[10];
	FILE *fp = fopen("Test1.txt", "r");
	assert(fp != NULL);
	for (int i = 0; i<10; ++i)
		fscanf(fp, "%d", &ar[i]);
	fclose(fp);
}


/*
//c语言的写入
void main()
{
	int ar[] = { 10, 11, 22, 33, 44, 55, 66, 77, 88, 99 };

	int size = sizeof(ar) / sizeof(ar[0]);

	FILE* fp = fopen("Test1.txt", "w");
	assert(fp!=NULL);
	// "w" 是写入，创建一个fp的txt 功能是写入
	for (int i = 0; i < size; ++i)
	{
		fprintf(fp, "%d ", ar[i]);
		//fprintf 在fp中以整形输入ar[i]
	}
	fclose(fp);
}

/*
void main()
{
	string str;
	while (getline(cin, str))
	{
		cout << str<< endl;
	}
}
*/