// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int _count;		//��Ŀ����
	double _random(double, double);
	srand(unsigned(time(0)));
	for (;true;)
	{ 

		cout << "������������Ŀ��" << endl;
		cin >> _count;

		//�½������ݱ�
		int **AllTable;
		AllTable = new int*[_count];
		for (int i = 0; i < _count; i++)
		{
			AllTable[i] = new int[3];
		}
		
		//���������������
		for (int i = 0; i < _count; i++)
		{
			/*
			for (int j = 0; j < 3; j++){
				AllTable[i][j] = int(_random(0, 6)) + 1;
			}
			*/
			for (int j = 0; j < 3; j++){
				AllTable[i][j] = int(_random(0, 6)) + 1;
			}
		}
		cout << "----------�·��������-------------" << endl;
		//�������
		for (int i = 0; i < _count; i++)
		{
			cout << AllTable[i][0] << '\t' << AllTable[i][1] << '\t' << AllTable[i][2] << endl;
		}
		cout << "----------------------------------" << endl;

		//�жϷ���
		for (; true;){
			int _do;
			cout << "����1��ȡ�������ֻع�\n����2Ϊ��ȡ�������ֳ��ִ���\n����0��������" << endl;
			cin >> _do;

			if (_do == 0)
			{
				break;
			}
			float _result[6] = { 0, 0, 0, 0, 0, 0 };
			switch (_do)
			{
				case 1:
					///////////////////////////////////////////
					cout << "��ȡ�������ֻع�" << endl;
					for (int i = 0; i < _count; i++)
					{
						if (AllTable[i][0] == AllTable[i][1] && AllTable[i][1] == AllTable[i][2]){
							//������ͬ,��Ӧ���ּ�2.5
							_result[AllTable[i][0] - 1] = _result[AllTable[i][0] - 1] + 2.5;
							//cout << "������ͬ,��Ӧ���ּ�2.5" << endl;
						}
						else{
							
							if (AllTable[i][0] == AllTable[i][1]){
								//2����ͬ,��Ӧ���ּ�1.5		(0,1)
								_result[AllTable[i][0] - 1] = _result[AllTable[i][0] - 1] + 1.5;
								_result[AllTable[i][2] - 1] = _result[AllTable[i][2] - 1] + 0.5;
								//cout << "2����ͬ,��Ӧ���ּ�1.5" << endl;
							}
							else{
								if (AllTable[i][1] == AllTable[i][2]){
									//2����ͬ,��Ӧ���ּ�1.5		(1,2)
									_result[AllTable[i][1] - 1] = _result[AllTable[i][1] - 1] + 1.5;
									_result[AllTable[i][0] - 1] = _result[AllTable[i][0] - 1] + 0.5;
									//cout << "2����ͬ,��Ӧ���ּ�1.5" << endl;
								}
								else{
									if (AllTable[i][0] == AllTable[i][2]){
										//2����ͬ,��Ӧ���ּ�1.5		(0,2)
										_result[AllTable[i][0] - 1] = _result[AllTable[i][0] - 1] + 1.5;
										_result[AllTable[i][1] - 1] = _result[AllTable[i][1] - 1] + 0.5;
										//cout << "2����ͬ,��Ӧ���ּ�1.5" << endl;
									}
									else{
										//���Ի�����ͬ
										for (int j = 0; j < 3; j++){
											_result[AllTable[i][j] - 1] = _result[AllTable[i][j] - 1] + 0.5;
										}
										//cout << "���Ի�����ͬ" << endl;
									}
								}
								
							}

							
						}

						for (int j = 0; j < 6; j++){
							bool _need = true;//Ĭ��Ҫ����0.5
							for (int k = 0; k < 3; k++){
								if (AllTable[i][k] == j + 1){
									_need = false;
									break;
								}
							}
							if (_need == true){
								_result[j] = _result[j] - 0.5;
							}
						}
					}
					for (int i = 0; i < 6; i++){
						cout << i + 1 << "*******" << _result[i] << endl;
					}
					break; // ��ѡ��
				case 2:
					////////////////////////////////////////////
					cout << "��ȡ�������ֳ��ִ���" << endl;
					for (int i = 0; i < _count; i++)
					{
						for (int j = 0; j < 3; j++){
							_result[AllTable[i][j] - 1] = _result[AllTable[i][j] - 1] + 1;
						}
					}
					for (int i = 0; i < 6; i++){
						cout << i + 1 << "*******" << _result[i] << endl;
					}
					break; // ��ѡ��
				default:
					break;
			}
		}


		/*
		���
		*/
		system("cls");
		continue;
	}

	return 0;
}

double _random(double start, double end)
{
	return start + (end - start)*rand() / (RAND_MAX + 1.0);
}

int mathfunc(int **AllTable){
	return 0;
}