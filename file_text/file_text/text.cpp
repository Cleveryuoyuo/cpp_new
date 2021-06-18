#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<bitset>
#include<stdlib.h>
#include<assert.h>
#include<fstream> //cpp�����������ͷ�ļ���
#include<string>
#include<sstream>
using namespace std;

void main()
{
	int a = 783952;
	string str;
	stringstream ss; //�ô��� ���ÿ��ǿռ� 
	//�Ƚ�a������ַ�����ss
	ss << a;
	//�ٽ�����õ�ss �����str��
	ss >> str;
	cout << str << endl;
	//ss�ײ����һ��str����
	cout << ss.str() << endl;
	//ssʹ�ú� �������һ��  ����ԭ�����������ɴ���  
	//��Ϊ�� 0/ ��β�� ������һ������ Ҳ������
	ss.clear();

	int b = 8384;
	ss << b;
	ss >> str;
	cout << str << endl;
}

/*
//����ת���ַ��������
void main()
{
	int a = 986725;
	char str[30] = { 0 };
	//��a�е�ÿһ��ĩβ �����һ���ַ�����str��
	//������ ���� �����λ�� �Լ����ƴ���
	//itoa(a, str, 10);  

	sprintf(str, "%d", a);
	//��str����%d����ʽ��a
	cout << str << endl;
}


/*
//���ù�����������ǽ�ip�Ͷ˿ڵ����ݣ��ӵ����ж�ȡ��������һ���ṹ������
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
	void ReadInfo(ServerInfo &info)//�ѽṹ��Ž�ȥ����������
	{
		ifstream ifile(_configfile.c_str(), ios::in);//.c_str() string����ת��Ϊָ������
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
//c++�Ķ�д
void main()
{
	int ar[10];
	int size = sizeof(ar) / sizeof(ar[0]);
	ifstream  ifile;
	ifile.open("Test22.txt", ios::in | ios::binary);
	//������д�� ��Ϊ������û��ת�� ����������
	assert(ifile);
	ifile.read((char*)ar, sizeof(int)*size);
	ifile.close();
}

/*
//c++��д�ļ�
void main()
{
	int ar[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int size = sizeof(ar) / sizeof(ar[0]);
	ofstream  ofile;
	ofile.open("Test22.txt", ios::out | ios::binary);
	//������д�� ��Ϊ������û��ת�� ����������
	assert(ofile);
	ofile.write((const char*)ar, sizeof(int)*size);
	
	ofile.close();
}

/*
//c���ԵĶ����ƶ�ȡ
void main()
{
	int ar[10];
	int size = sizeof(ar) / sizeof(ar[0]);
	FILE* fp = fopen("Test11.txt", "rb");
	//�����ƶ��� 
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
	//������д�� ��Ϊ������û��ת�� ����������
	assert(fp != NULL);
	fwrite(ar, size, sizeof(int), fp);
	fclose(fp);
}

/*
//ͨ���ı��ļ���д  �����ַ�
//cpp��������д��
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
//cpp�������д��
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
//c���ԵĶ�
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
//c���Ե�д��
void main()
{
	int ar[] = { 10, 11, 22, 33, 44, 55, 66, 77, 88, 99 };

	int size = sizeof(ar) / sizeof(ar[0]);

	FILE* fp = fopen("Test1.txt", "w");
	assert(fp!=NULL);
	// "w" ��д�룬����һ��fp��txt ������д��
	for (int i = 0; i < size; ++i)
	{
		fprintf(fp, "%d ", ar[i]);
		//fprintf ��fp������������ar[i]
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