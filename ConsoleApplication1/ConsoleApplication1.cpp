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

		//�������б�
		float Table_diff[6] = { 0, 0, 0, 0, 0, 0 };

		//����״̬�б�(��/��)
		bool Table_isbuying[6] = { false, false, false, false, false, false, };
		//����״̬�ȼ�
		int Table_buyingLevel[6] = { 0, 0, 0, 0, 0, 0, };
		//��������ע�ۼ�
		int Table_buyingNum[6] = { 0, 0, 0, 0, 0, 0 };
		//Ӫ��ͳ�Ƶ�
		int Num_get = 0;
		
		//���������������
		for (int i = 0; i < _count; i++)
		{
			/*
			for (int j = 0; j < 3; j++){
				AllTable[i][j] = int(_random(0, 6)) + 1;
			}
			*/

			int _cur[3];
			//���嵱ǰ��Ŀ
			for (int j = 0; j < 3; j++){
				_cur[j] = int(_random(0, 6)) + 1;
			}
			//��Ŀ����
			for (int j = 0; j < 3; j++){
				AllTable[i][j] = _cur[j];
			}

			//���㵱ǰ�������ֻع飿���ҵó�������
			float _result[6] = { 0, 0, 0, 0, 0, 0 };
			for (int k = 0; k < i + 1; k++)
			{
				if (AllTable[k][0] == AllTable[k][1] && AllTable[k][1] == AllTable[k][2]){
					//������ͬ,��Ӧ���ּ�2.5
					_result[AllTable[k][0] - 1] = _result[AllTable[k][0] - 1] + 2.5;
				}
				else{

					if (AllTable[k][0] == AllTable[k][1]){
						//2����ͬ,��Ӧ���ּ�1.5		(0,1)
						_result[AllTable[k][0] - 1] = _result[AllTable[k][0] - 1] + 1.5;
						_result[AllTable[k][2] - 1] = _result[AllTable[k][2] - 1] + 0.5;
					}
					else{
						if (AllTable[k][1] == AllTable[k][2]){
							//2����ͬ,��Ӧ���ּ�1.5		(1,2)
							_result[AllTable[k][1] - 1] = _result[AllTable[k][1] - 1] + 1.5;
							_result[AllTable[k][0] - 1] = _result[AllTable[k][0] - 1] + 0.5;
						}
						else{
							if (AllTable[k][0] == AllTable[k][2]){
								//2����ͬ,��Ӧ���ּ�1.5		(0,2)
								_result[AllTable[k][0] - 1] = _result[AllTable[k][0] - 1] + 1.5;
								_result[AllTable[k][1] - 1] = _result[AllTable[k][1] - 1] + 0.5;
							}
							else{
								//���Ի�����ͬ
								for (int j = 0; j < 3; j++){
									_result[AllTable[k][j] - 1] = _result[AllTable[k][j] - 1] + 0.5;
								}
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

				for (int j = 0; j < 6; j++){
					float _maxdif = fabs(_result[j]);
					if (_maxdif > fabs(Table_diff[j])){
						Table_diff[j] = _result[j];
							cout << _result[j] << "...����Ϊ" << j+1 << endl;
					}
				}
			}
			//----------------------------------------------------
			for (int j = 0; j < 6; j++){
				if (Table_isbuying[j] == true){
					if (_result[j] > (Table_buyingLevel[j] - 1) * (-3) - 1.5){
						//���һ��Ӯ����
						Num_get = Num_get + 1;
						Table_buyingLevel[j] = Table_buyingLevel[j] - 1;
						if (Table_buyingLevel[j] = 0){
							//�ȼ�һ�Ļ� ֹͣ����
							Table_isbuying[j] = false;
						}
					}
					else{
						//����Ƿ����
						if (_result[j] < Table_buyingLevel[j] * (-3)){
							Table_buyingLevel[j] = Table_buyingLevel[j] + 1;
						}
					}
				}
				else{
					if (_result[j] < (-3)){
						Table_isbuying[j] = true;
						Table_buyingLevel[j] = floor(Table_isbuying[j] / 3);
					}
				}
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
			cout << "����1��ȡ�������ֻع�\n����2Ϊ��ȡ�������ֳ��ִ���\n����3��ȡ������\n����4��ȡӯ������\n����0��������" << endl;
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
				case 3:
					////////////////////////////////////////////
					cout << "��ȡ��������������" << endl;
					for (int i = 0; i < 6; i++){
						cout << i + 1 << "*******" << Table_diff[i] << endl;
					}
					break; // ��ѡ��
				case 4:
					////////////////////////////////////////////
					cout << "ӯ������Ϊ:" << Num_get << endl;
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