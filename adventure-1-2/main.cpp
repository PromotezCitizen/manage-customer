#include "airplanePriority.h"

int main() {
	ifstream fin;
	char temp[100];
	int dataLine = 0;

	customerData* person;

	double maxDate = 0, maxMile = 0;
	int arySize = 0;
	string tempDateStr;
	int tempdata = 0;

	time_t nowTime, userSigninTime;

	//fin.open("C:\\Users\\gkstk\\OneDrive\\���� ȭ��\\test.txt");
	fin.open("C:\\Users\\gkstk\\oneDrive\\���� ȭ��\\����1_data\\����1.3 ����ڸ��.txt");

	if (!fin.is_open()) {
		cout << "������ ã�� �� ����";
	}
	else {
		while (!fin.eof()) {
			fin.getline(temp, 100);
			dataLine++;
		}
		fin.seekg(0, ios::beg);

		customerData* person = new customerData[dataLine];

		nowTimeSet(nowTime);

		for (int i = 0; i < dataLine; i++) {
			/*------------------- ���� --------------------*/
			getUserOrder(person[i].order, fin);
			arySize = 0;
			/*---------------------------------------------*/

			/*------------------- �̸� --------------------*/
			setUserName(person[i].name, fin);
			/*---------------------------------------------*/

			/*--------------- ���ϸ��� �հ� ----------------*/
			getUserMile(person[i].mile, maxMile, fin);
			arySize = 0;
			/*---------------------------------------------*/

			/*------------------ ������ -------------------*/
			getUserTime(person[i].useDate, tempDateStr, fin);
			userTimeSet(nowTime, userSigninTime, tempDateStr, tempdata);
			getMaxDate(maxDate, tempdata);
			/*---------------------------------------------*/
		}
		fin.close();

		for (int i = 0; i < dataLine; i++) {
			userPrioritySet(person[i], maxMile, maxDate, tempdata);
		}
		cout << "max Mile = " << maxMile << ", max Signin : " << maxDate << endl;
		proritySort(person, dataLine);

		printResult(person, dataLine);
	}

	fin.close();
}